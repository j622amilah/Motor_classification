import numpy as np
    
# Plotting
import plotly.graph_objects as go

# Data saving
import pickle

# Importing the statistics module
from statistics import mode, mean, median, multimode
import scipy.stats

# Personal python functions
import sys
sys.path.insert(1, '/home/jamilah/Documents/Sourceforge_analysis_PROJECTS/Motor_classification/subfunctions')

from findall import findall
from detect_sig_change_wrt_baseline import detect_sig_change_wrt_baseline
from detect_jumps_in_index_vector import detect_jumps_in_index_vector
from detect_jumps_in_data import detect_jumps_in_data
from detect_nonconsecutive_values import detect_nonconsecutive_values
from vertshift_segments_of_data_wrt_prevsegment import vertshift_segments_of_data_wrt_prevsegment
from make_a_properlist import make_a_properlist

# OR 

# Motor classification project ONLY functions
from subfunctions.full_sig_2_cell import *
from subfunctions.detectUD_trials import *
from subfunctions.detectFB_LR_trials import *
from subfunctions.detect_vertically_short_FBLR import *
from subfunctions.make_new_vec_w_index_vec import *
from subfunctions.process_index_for_UD_trials import *
from subfunctions.process_index_for_trials import *
from subfunctions.UD_UD_trial_detection import *
from subfunctions.check_axes_assignmentPLOT import *
from subfunctions.cut_initial_trials import *


#def trans_main_preprocessing_steps(varr, temp, A, s):
def trans_main_preprocessing_steps(varr, A, a, b, c, s):

    # ------------------------------
    # (1) Cut the data by looking at when the data crosses zero
    # ------------------------------
    plotORnot = 1  # 1 = show figures, 0 = do not show figures
    new3_ind_st, new3_ind_end = cut_initial_trials(varr, A, plotORnot)
    
    
    
    # ------------------------------
    # Put the joystick, cabin actual, and cabin command into a compact format: 
    # a 3D list (depth=trials, row=dp per trial, col=axis in order LR/RO, FB/PI, UD/YAW)
    # ------------------------------
    #outJOY, outSIG, outSIGCOM = full_sig_2_cell(temp, new3_ind_st, new3_ind_end, varr)
    outJOY, outSIG, outSIGCOM = full_sig_2_cell(A, a, b, c, new3_ind_st, new3_ind_end, varr)
    # ------------------------------
    
    tr_num = len(new3_ind_st)
    
    # ------------------------------
    # (2) Axis and stimulus detection
    # ------------------------------
    # print('Axis detection')

    # Way 1: Experimental collected data axis detection
    trialnum0 = np.zeros((tr_num))
    axis0 = np.zeros((tr_num))
    tas1 = np.zeros((tr_num))
    tas2 = np.zeros((tr_num))
    tas3 = np.zeros((tr_num))
    for q in range(tr_num):
        st = int(new3_ind_st[q])
        stp = int(new3_ind_end[q])
        trialnum0[q] = mode(A[st:stp, 1])   # trial number
        axis0[q:q+1] = mode(A[st:stp, 14])  # (1:roll, 2:pitch, 3:yaw)
        
        tas1[q:q+1] = mode(A[st:stp, 10])
        tas2[q:q+1] = mode(A[st:stp, 11])
        tas3[q:q+1] = mode(A[st:stp, 12])

    speed_stim0 = tas1 + tas2 + tas3  # The sum of the target angular speed will give the speed_stim column
    
    
    # Initialize EXPERIMENTAL PARAMETER list: what should have been correct, but we need to figure out from data 
    axis_out = np.zeros((tr_num))

    # Way 2: Data-driven axis detection
    UD_trials, axis_out = detectUD_trials(outSIG, axis_out)
    
    longvec = np.multiply(range(len(new3_ind_st)), 1)
    shortvec = UD_trials
    remaining_tr = np.setdiff1d(longvec, shortvec)  # idx_from_long_not_in_short
    
    FB_trials, LR_trials, axis_out = detectFB_LR_trials(outSIG, remaining_tr, new3_ind_st, new3_ind_end, axis_out)
    
    
    # :::::::::::::::::::
    # Confirmation check to see how similar data-driven axis_out is to the experimental matrix axis0
    # corr (x,y) = cov (x,y) / (std (x) * std (y))
    # Pearson correlation coefficient
    corr_out = np.corrcoef(axis0, axis_out) 
    # :::::::::::::::::::
    # ------------------------------
    
    print('LR_trials : ' + str(LR_trials))
    print('FB_trials : ' + str(FB_trials))
    print('UD_trials : ' + str(UD_trials))

    print('axis_out : ' + str(axis_out))

    
    # ------------------------------
    # Check if axes are assigned correctly to trials: PLOTTING
    # ------------------------------
    #print(':::::::::::::::::::')
    #print('PLOTTING Cut trials BEFORE bad trial removal')   
    #print(':::::::::::::::::::')
    #check_axes_assignmentPLOT(s, new3_ind_st, new3_ind_end, outJOY, outSIG, axis_out, varr)
    # ------------------------------
    
    
    
    # ------------------------------
    # (3) Detect bad trials (robot stopped, erroneous movement)
    # ------------------------------
    print('a1_1_trans_errordetect_trialselection : Check which trials are bad trials')

    g_rej_vec = np.zeros((len(axis_out)))  # global reject vector

    # :::::::::::::::::::
    # print('a1_1_trans_errordetect_trialselection : Detect when robot stopped')
    # NOTE : The entire robotic trajectory from start to finish was saved for translation,
    # therefore there should be no discontiuities in the data unless the robot stopped 
    # (when the robot stopped the the data text file was saved, when the experiment restarted a 
    # new text file was created ---> all the text files were simply concatenated, long periods of zero were
    # removed, and downsampled to 10Hz)

    # So it is just to remove these trials.  Technically, sometimes (very rare) we remove the first concatenated 
    # trial with the robot stop but other times the data curve after the cut is weird.  So, no worth saving the 
    # rest of the data in the trial.  Robot cut trials are also rare too.  
    desired_break_num = 1
    dp_jump = 15

    cut_trial_list = []
    cut_pt = []
    for k in range(3):
        for i in range(len(new3_ind_st)):
            y_index_holder = new3_ind_st[i]

            # Check if index allows us to check a vector ONLY
            if len(outSIG[i]) > 0:
                y = outSIG[i][:, k]
                c = 1
                ind_jumpPT = []
                # 1) Check the difference between consecutive points
                for j in range(len(y)-1):
                    if abs(y[j] - y[j+1]) > dp_jump:
                        ind_jumpPT = ind_jumpPT + [j] # x-axis point during trial when jumped

                        # If you want to stop searching the data after a certain number of breaks
                        # ie: for when the robot stopped put 1 (the data for that trial is not good), 
                        # if you want to search the entire length of the data put the length of y
                        if c == desired_break_num:
                            break
                        c = c + 1
            
            # We just want to store the trial number if out is not empty
            if ind_jumpPT != []:
                cut_trial_list = cut_trial_list + [i]
                cut_pt = cut_pt + [ind_jumpPT]
            
    print('cut_trial_list : ' + str(cut_trial_list))
    print('cut_pt : ' + str(cut_pt))

    cut_trial_list = np.unique(cut_trial_list, return_index=True, return_inverse=True)
    cutlist = cut_trial_list[0] 
    idx_cutlist = cut_trial_list[1]
    org_idx_cutlist = cut_trial_list[2]

    print('cut_trial_list : ' + str(cut_trial_list))
    print('cutlist : ' + str(cutlist))
    print('idx_cutlist : ' + str(idx_cutlist))
    print('org_idx_cutlist : ' + str(org_idx_cutlist))

    # Get the corresponding cut_pt from each the trials were a cut was detected
    idx_orgcutlist = np.zeros((len(cutlist)))
    for i in range(len(cutlist)):
        for j in range(len(cut_trial_list)):  # cycle through the original list of detected trials
            if idx_cutlist[i] == org_idx_cutlist[j]:  # get the index list
                idx_orgcutlist[i:i+1] = j
                break
    print('idx_orgcutlist : ' + str(idx_orgcutlist))
    
    # Take signal portion after the cut : update index
    cut_pt = np.array(np.concatenate(cut_pt).ravel())  # must be an array, to be indexed  
    idx_orgcutlist = [int(x) for x in idx_orgcutlist] # each element needs to be converted to int
    cutpt = cut_pt[idx_orgcutlist]

    print('cutpt : ' + str(cutpt))
    i = 0
    for tr in cutlist:
        new3_ind_st[tr] = new3_ind_st[tr] + cutpt[i]+1
        i = i + 1

    print('new3_ind_st : ' + str(new3_ind_st))
    print('new3_ind_end : ' + str(new3_ind_end))
    
    # update trial cut data matrices 
    outJOY, outSIG, outSIGCOM = full_sig_2_cell(temp, new3_ind_st, new3_ind_end, varr)
    # :::::::::::::::::::

    

    # :::::::::::::::::::
    print('a1_1_trans_errordetect_trialselection : Detect vertically short UD')

    # Remove UD trials that have a max height less than 50 = 50/100=0.5 meter from the initial point.  
    # A good UD trial has a height of at least 100 = 100/100=1meter from the initial point.  
    # These UD trial are the end portion of a UD trial (called reinitialization), when we cut the data 
    # into trials using the zero-deadzone above these portions were labelled as a full-trial. 
    UDmax = np.zeros((len(UD_trials)))
    
    # Only need to calculate for UD_trials, we leave the other spaces equal to zero
    c = 0  
    for UD_tr in UD_trials:
        UDmax[c] = max(outSIG[UD_tr][:,2])
        c = c + 1

    thresh = 50
    newvec, indy = findall(UDmax, '<', thresh)
    
    UD_trials = np.array(UD_trials) # UD_trials needs to be an array to be indexed by a list
    cut_trial_UDtail = np.array(UD_trials[indy])
    print('cut_trial_UDtail : ' + str(cut_trial_UDtail))
    
    if cut_trial_UDtail != []:
        g_rej_vec[cut_trial_UDtail] = 20
    # :::::::::::::::::::



    # :::::::::::::::::::
    # print('a1_1_trans_errordetect_trialselection : Detect vertically short FB LR')

    # Remove LR and FB trials that have max height less than 10 = 10/100=0.1meters from the initial point. 
    # A good sub-threshold FB and LR trial has a max height of about 50 or more short height trials could have 
    # occurred due to timing problems with the robotic system (the sampling frequency was too fast).  
    # These erroneous trials also tend to be horizontally short (data-point wise), showing that the robotic 
    # sampling frequency was running faster than 250Hz and correct motion could not be achieved.  
    cut_trial_FBLR_ver_short = detect_vertically_short_FBLR(FB_trials, LR_trials, outSIG)
    print('cut_trial_FBLR_ver_short : ' + str(cut_trial_FBLR_ver_short))
    
    # Ensure that the index of g_rej_vec are integers
    # Change each entry of the list into an integer, output is a list
    cut_trial_FBLR_ver_short = [int(x) for x in cut_trial_FBLR_ver_short]
    
    if cut_trial_FBLR_ver_short != []:
        g_rej_vec[cut_trial_FBLR_ver_short] = 30
    # :::::::::::::::::::

    

    # :::::::::::::::::::
    # print('a1_1_trans_errordetect_trialselection : Detect horizontally short trials')

    # Remove short trials (horizontally short data)
    # Justification: In translation, the data consists of detection (8secs) + control (15secs) + reinitialization (10secs) so the maximum length of a trial is 33 seconds.  The data is sampled at 10Hz, so that is 330 data points per trial maximum.  If detection time is almost 0 seconds (fast detection), then the shortest a trial should be is 15+10=25 seconds.  We try to be lenient and account for delays and set the data cut off at 22 seconds.

    # NOTE: in translation the time goes from (trial event start to trial event start), in rotation the time vector restarted for every trial event (ie: stimulus, reinitialization, rest).

    # This means that in translation: I can not use the time to improve finding a better start-stop interval as we did in rotation.
    # I could have cut the data from trial event start to trial event start, but afterward we would still need to look at the cabin movement to figure out when each trial event (reinitialization, stimulus, reinitialization, rest) started.  We need a start-stop vector, to cut the data, for when stimulus starts and stops.

    # Since the data was initially cut by the cabin movement, we only care about the slope of the time vector.  

    # Reconstruct time : So, we shift the time vector in the with respect to the y-axis, and get the time vector for each trial (cut by the cabin movement).

    # Time difference : Then we take the time difference from start to end
    # Sometimes the sampling rate of the system changed (should be seen by change in slope of time) or 
    # data was not saved when it should have been saved due to real-time system (vertical jump/shift 
    # in time vector)
    tr_t_diff = np.zeros((len(new3_ind_st)))
    dp_diff = np.zeros((len(new3_ind_st)))
    
    for i in range(len(new3_ind_st)):
        ttime = A[int(new3_ind_st[i]):int(new3_ind_end[i]), 1]  # time in seconds
        # print('ttime : ' + str(ttime))
        
        dp_jump = 1     # detect jumps in the time greater than 1 second
        tt2 = vertshift_segments_of_data_wrt_prevsegment(ttime, dp_jump)
        
        tr_t_diff[i:i+1] = tt2[len(tt2)-1] - tt2[0]     # time difference
        dp_diff[i:i+1] = len(tt2)
        
        
    # Now, check the time length of each trial
    width_cutoff = 22     # cut data with time greater than 22 seconds
    cut_trial_hor_short = []
    for i in range(len(new3_ind_st)):
        if tr_t_diff[i] < width_cutoff:
            cut_trial_hor_short = cut_trial_hor_short + [i]

    # Ensure that the index of g_rej_vec are integers
    # Change each entry of the list into an integer, output is a list
    cut_trial_hor_short = [int(x) for x in cut_trial_hor_short]
    print('cut_trial_hor_short : ' + str(cut_trial_hor_short))
        
    g_rej_vec[cut_trial_hor_short] = 40
    # :::::::::::::::::::
    
    # ------------------------------
    

    # ------------------------------
    # (4) Remove the bad trials from trials
    # ------------------------------
    print('a1_1_trans_errordetect_trialselection : Remove the bad trials from trials')
    
    cutall = cut_trial_UDtail, cut_trial_FBLR_ver_short, cut_trial_hor_short
    tr_2_cut = make_a_properlist(cutall)
    tr_2_cut.sort()
    cut_tr = np.unique(tr_2_cut)

    print('new3_ind_st : ' + str(new3_ind_st))
    print('new3_ind_end : ' + str(new3_ind_end))
    
    print('axis_out : ' + str(axis_out))
    print('speed_stim0 : ' + str(speed_stim0))

    # -------------------------------------
    # Get a total list of good trials : good_tr are the remaining trials to process
    # -------------------------------------
    longvec = np.array(range(len(new3_ind_st)))
    shortvec = cut_tr
    tr_from_long_not_in_short = np.setdiff1d(longvec, shortvec)
    good_tr = tr_from_long_not_in_short

    #print('good_tr : ' + str(good_tr))

    # -------------------------------------
    # Keep vectors the same original number of trials, put 0 for trials that are bad trials
    # -------------------------------------
    axis2 = axis_out
    speed_stim_org = speed_stim0
    for tr in cut_tr:
        new3_ind_st[int(tr)] = 0
        new3_ind_end[int(tr)] = 0
        axis2[int(tr)] = 0
        speed_stim_org[int(tr)] = 0

    #print('new3_ind_st : ' + str(new3_ind_st))
    #print('new3_ind_end : ' + str(new3_ind_end))

    # -------------------------------------
    # Next, there are two more checks to complete : 
    # 1. ensure that UD, FB, LR trials are cut correctly, 
    # 2. ensure that all trials followed the experiment expectations
    # -------------------------------------

    # -------------------------------------
    # We need a good trial list for UD, FB, and LR
    # ------------------------------------- 
    longvec = UD_trials
    shortvec = cut_tr
    tr_from_long_not_in_short = np.setdiff1d(longvec, shortvec)
    tr_from_short_not_in_long = np.setdiff1d(shortvec, longvec)

    UD_trials2 = tr_from_long_not_in_short         # UD trials without bad trials
    LR_FB_tr2remove = tr_from_short_not_in_long    # these are LR and FB trials to remove

    #print('UD_trials : ' + str(UD_trials))
    #print('UD_trials2 : ' + str(UD_trials2))


    longvec = LR_trials
    shortvec = LR_FB_tr2remove
    tr_from_long_not_in_short = np.setdiff1d(longvec, shortvec)
    tr_from_short_not_in_long = np.setdiff1d(shortvec, longvec)
    # OR
    # tr_from_short_not_in_long, tr_from_long_not_in_short = get_missing_vector(shortvec, longvec)
    LR_trials2 = tr_from_long_not_in_short      # LR trials without bad trials
    FB_tr2remove = tr_from_short_not_in_long    # these are FB trials to remove
    
    #print('LR_trials : ' + str(LR_trials))
    #print('LR_trials2 : ' + str(LR_trials2))
    

    if FB_tr2remove == []:
        # No FB trials to remove
        FB_trials2 = FB_trials
    else:
        longvec = FB_trials
        shortvec = FB_tr2remove
        tr_from_long_not_in_short = np.setdiff1d(longvec, shortvec)
        # OR
        #tr_from_short_not_in_long, tr_from_long_not_in_short = get_missing_vector(shortvec, longvec)
        FB_trials2 = tr_from_long_not_in_short      # FB trials without bad trials
    
    #print('FB_trials : ' + str(FB_trials))
    #print('FB_trials2 : ' + str(FB_trials2))
    # ------------------------------



    # ------------------------------
    # Check if axes are assigned correctly to trials: PLOTTING
    # ------------------------------
    plotORnot = 0  # 1 = show figures, 0 = do not show figures
    if plotORnot == 1:
        print(':::::::::::::::::::')
        print('PLOTTING Cut trials AFTER bad trial removal')   
        print(':::::::::::::::::::')
        check_axes_assignmentPLOT(s, new3_ind_st, new3_ind_end, outJOY, outSIG, axis_out, varr)
    # ------------------------------


    # ------------------------------
    # (5) Refine start-stop index for only stimulus period
    # ------------------------------
    print(':::::::::::::::::::')
    print('a1_1_trans_errordetect_trialselection : Refine start-stop index for only stimulus period')
    print(':::::::::::::::::::')
    Len = len(axis2)
    speed_stim_sign = np.zeros((Len, 1))
    speed_stim_mag = np.zeros((Len, 1))
    starttrial_index = np.zeros((Len, 1))
    stoptrial_index = np.zeros((Len, 1))

    
    plotORnot = 0  # 1 = show figures, 0 = do not show figures
    plotORnot_derv = 0  # 1 = show figures, 0 = do not show figures
    marg = 10  # margin around signal baseline for UD and FB, in order to search for start and stop index locations
    
    starttrial_index, stoptrial_index, speed_stim_sign, speed_stim_mag = process_index_for_UD_trials(s, UD_trials2, outSIG, marg, starttrial_index, stoptrial_index, speed_stim_sign, speed_stim_mag, plotORnot, plotORnot_derv)
    # ------------------------------
    

    # ------------------------------
    good_tr = np.concatenate((FB_trials2, LR_trials2), axis=0)
    plotORnot = 0  # 1 = show figures, 0 = do not show figures
    plotORnot_derv = 0  # 1 = show figures, 0 = do not show figures

    starttrial_index, stoptrial_index, speed_stim_sign, speed_stim_mag = process_index_for_trials(s, good_tr, outSIG, marg, varr, starttrial_index, stoptrial_index, speed_stim_sign, speed_stim_mag, plotORnot, plotORnot_derv, axis2)
    # ------------------------------      


    # ------------------------------
    # Check if axes are assigned correctly to trials: PLOTTING
    # ------------------------------
    plotORnot = 0  # 1 = show figures, 0 = do not show figures
    if plotORnot == 1:
        print(':::::::::::::::::::')
        print('PLOTTING Cut trials AFTER bad trial removal')   
        print(':::::::::::::::::::')
        check_axes_assignmentPLOT(s, starttrial_index, stoptrial_index, outJOY, outSIG, axis_out, varr)
    # ------------------------------


    # ------------------------------
    # (6) Search for UD-trial after a UD-trial and separate the trials
    # If it is a UD-trial "back-to-back", the robot does not return to zero after the first UD-trial.
    # ------------------------------
    # print('a1_1_trans_errordetect_trialselection : Do another CUT CHECK (cut the trial in half and register as 2 UD trials instead of 1 UD trial) : case UD-trial after a UD-trial')

    plotORnot = 0  # 1 = show figures, 0 = do not show figures
    
    starttrial_index, stoptrial_index, speed_stim_sign, speed_stim_mag, axis_val, new4_ind_st, new4_ind_end, g_rej_vec, speed_stim_org, UD_UD_detection_oldtrial = UD_UD_trial_detection(axis2, outSIG, starttrial_index, stoptrial_index, speed_stim_sign, speed_stim_mag, new3_ind_st, new3_ind_end, g_rej_vec, speed_stim_org, plotORnot, varr)
    
    # Redo cell function with FINAL cut index
    ind_st = new4_ind_st
    ind_end = new4_ind_end
    
    outJOY, outSIG, outSIGCOM = full_sig_2_cell(temp, ind_st, ind_end, varr)
    
    
    return starttrial_index, stoptrial_index, speed_stim_sign, speed_stim_mag, axis_val, new4_ind_st, new4_ind_end, g_rej_vec, speed_stim_org, outJOY, outSIG, outSIGCOM, corr_out
