import numpy as np

from statistics import mode

# Plotting
import plotly.graph_objects as go
from plotly.subplots import make_subplots

# Personal python functions
import sys
sys.path.insert(1, '/home/jamilah/Documents/Sourceforge_analysis_PROJECTS/Motor_classification/subfunctions')

from findall import findall
from detect_sig_change_wrt_baseline import detect_sig_change_wrt_baseline
from detect_jumps_in_index_vector import detect_jumps_in_index_vector





def UD_UD_trial_detection(axis_val, outSIG, starttrial_index, stoptrial_index, speed_stim_sign, speed_stim_mag, new3_ind_st, new3_ind_end, g_rej_vec, speed_stim_org, plotORnot, varr):

    # 1) Only look at relevant trials - only look at UD
    axis_val = [int(x) for x in axis_val] 

    
    print('axis_val : ' + str(axis_val))
    

    # Get average length of UD trials
    vals, UD_tr = findall(axis_val, '==', 3)
    
    print('vals : ' + str(vals))

    print('UD_tr : ' + str(UD_tr))

    
    i = 0
    len_dat = np.zeros((len(UD_tr)))
    for tr in UD_tr:
        print('axis_val[tr] : ' + str(axis_val[tr]-1))
        print('int(starttrial_index[tr][0]) : ' + str(int(starttrial_index[tr][0])))
        print('int(stoptrial_index[tr][0]) : ' + str(int(stoptrial_index[tr][0])))

        dat = outSIG[tr][int(starttrial_index[tr][0]):int(stoptrial_index[tr][0]), axis_val[tr]-1]
        len_dat[i] = len(dat)
        i = i + 1

    avg_len_dat = sum(len_dat)/len(len_dat)


    # the trials that are double UD UD trials
    UD_UD_detection_oldtrial = []

    # the new trial index list of variables - note that if a UD UD trial is detected we create a new trial for the 2nd UD, 
    # so the new index could be longer than the original index if a UD UD trial is found.
    # These variables need to have a non-fixed length.
    starttrial_index_temp = []
    stoptrial_index_temp = []
    speed_stim_sign_temp = []
    speed_stim_mag_temp = []
    axis3_temp = []
    new4_ind_st_temp = []
    new4_ind_end_temp = []
    g_rej_vec_temp = []
    speed_stim_org_temp = []

    

    for i in range(len(starttrial_index)):
        # Evaluation for UD trials only
        if axis_val[i] == 3:
            dat = outSIG[i][int(starttrial_index[tr][0]):int(stoptrial_index[tr][0]), axis_val[tr]-1]
            
            # Find parameters that could distinguish these situations
            # 1) Find the mode for the data
            tr_vals = np.round(dat)
            baseline = mode(tr_vals)  # mode
            dvar = 0
            for ii in range(len(tr_vals)):
                if tr_vals[ii] == baseline:
                    dvar = dvar + 1  # count
            
            
         	# 2) Number of times it goes into and out of the baseline area
            # Want to detect points around zero with a +/- margin of 0.001
            marg_around_baseline = 5
            dpOFsig_in_zone, indexOFsig_in_zone, dp_sign_not_in_zone, indexOFsig_not_in_zone = detect_sig_change_wrt_baseline(dat, baseline, marg_around_baseline)


            # Look for concectutive points in the zone - this is a start-stop areas in between trials
            index_st, break_st, index_end, break_end = detect_jumps_in_index_vector(indexOFsig_in_zone)
            
            # ------------------------------
            if plotORnot == 1:
                fig = go.Figure()
                config = dict({'scrollZoom': True, 'displayModeBar': True, 'editable': True})

                dp = np.array(range(len(dat)))
                fig.add_trace(go.Scatter(x=dp, y=dat, name='sig', line = dict(color='red', width=2, dash='dash'), showlegend=True))
                

                fig.add_trace(go.Scatter(x=indexOFsig_in_zone, y=dpOFsig_in_zone, name='sig', mode='markers', marker=dict(color='green', size=10, line=dict(width=0)), showlegend=True))

                fig.add_trace(go.Scatter(x=indexOFsig_not_in_zone, y=dp_sign_not_in_zone, name='sig', mode='markers', marker=dict(color='yellow', size=10, line=dict(width=0)), showlegend=True))
                
                # square
                fig.add_trace(go.Scatter(x=break_st, y=dat[break_st], name='break_st', mode='markers', marker=dict(color='black', size=10, line=dict(color='black', width=0)), showlegend=True))

                # triangle
                fig.add_trace(go.Scatter(x=break_end, y=dat[break_end], name='break_end', mode='markers', marker=dict(color='magenta', size=10, line=dict(color='magenta', width=0)), showlegend=True))
                fig.show(config=config)
            # ------------------------------
	        
            
	        # Based on a very SPECIFIC CASE of parameters : determine if is a joinned trial 
	        # If there are : (1) 3 brakes, and 
            # (2) the 2nd brake is about half the data length, and 
            # (3) the length of the data is larger than the data length average ---> change the start and stop index 
	        # if NOT, just keep the start-stop index
            if len(break_st) == 3:
                second_midpt = break_st[1] + (break_end[1] - break_st[1])/2
                lendat = len(dat)
                mid = lendat/2
                mar = 0.1*lendat 	# 10# of the data length
                if ( (second_midpt > mid-mar) and (second_midpt < mid+mar ) ):
                    if lendat > avg_len_dat:
                        # UD-UD trial detection: add a new trial to start-stop index
                        starttrial_index_temp = starttrial_index_temp + [starttrial_index[i]]
                        stoptrial_index_temp = stoptrial_index_temp + [break_st[1]]
                        
                        speed_stim_sign_temp = speed_stim_sign_temp + [speed_stim_sign[i]]
                        speed_stim_mag_temp = speed_stim_mag_temp + [speed_stim_mag[i]]
                        axis3_temp = axis3_temp + [axis_val[i]]
                        new4_ind_st_temp = new4_ind_st_temp + [new3_ind_st[i]]
                        new4_ind_end_temp = new4_ind_end_temp + [new3_ind_end[i]]
                        g_rej_vec_temp = g_rej_vec_temp + [g_rej_vec[i]]
                        speed_stim_org_temp = speed_stim_org_temp + [speed_stim_org[i]]
                        
                        # Save the index of the 2nd UD
                        starttrial_index_temp = starttrial_index_temp + [break_st[1] + 1]
                        stoptrial_index_temp = stoptrial_index_temp + [break_end[2]]
                        
                        UD_UD_detection_oldtrial = UD_UD_detection_oldtrial + [i]
                    else:
                        starttrial_index_temp = starttrial_index_temp + [starttrial_index[i]]
                        stoptrial_index_temp = stoptrial_index_temp + [stoptrial_index[i]]
                else:
                    starttrial_index_temp = starttrial_index_temp + [starttrial_index[i]]
                    stoptrial_index_temp = stoptrial_index_temp + [stoptrial_index[i]]
            else:
                starttrial_index_temp = starttrial_index_temp + [starttrial_index[i]]
                stoptrial_index_temp = stoptrial_index_temp + [stoptrial_index[i]]

            speed_stim_sign_temp = speed_stim_sign_temp + [speed_stim_sign[i]]
            speed_stim_mag_temp = speed_stim_mag_temp + [speed_stim_mag[i]]
            axis3_temp = axis3_temp + [axis_val[i]]
            new4_ind_st_temp = new4_ind_st_temp + [new3_ind_st[i]]
            new4_ind_end_temp = new4_ind_end_temp + [new3_ind_end[i]]
            g_rej_vec_temp = g_rej_vec_temp + [g_rej_vec[i]]
            speed_stim_org_temp = speed_stim_org_temp + [speed_stim_org[i]]
        else:
            # For LR and FB trials
            starttrial_index_temp = starttrial_index_temp + [starttrial_index[i]]
            stoptrial_index_temp = stoptrial_index_temp + [stoptrial_index[i]]

            speed_stim_sign_temp = speed_stim_sign_temp + [speed_stim_sign[i]]
            speed_stim_mag_temp = speed_stim_mag_temp + [speed_stim_mag[i]]
            axis3_temp = axis3_temp + [axis_val[i]]
            new4_ind_st_temp = new4_ind_st_temp + [new3_ind_st[i]]
            new4_ind_end_temp = new4_ind_end_temp + [new3_ind_end[i]]
            g_rej_vec_temp = g_rej_vec_temp + [g_rej_vec[i]]
            speed_stim_org_temp = speed_stim_org_temp + [speed_stim_org[i]]
	        
        # end of 'if axis_val(i,1) == 3'
    # end of 'for i = 1:length(starttrial_index)'


    # Pass temporary values to the final variables
    starttrial_index = starttrial_index_temp
    stoptrial_index = stoptrial_index_temp
    speed_stim_sign = speed_stim_sign_temp
    speed_stim_mag = speed_stim_mag_temp
    axis3 = axis3_temp
    new4_ind_st = new4_ind_st_temp
    new4_ind_end = new4_ind_end_temp
    g_rej_vec = g_rej_vec_temp
    speed_stim_org = speed_stim_org_temp

    return starttrial_index, stoptrial_index, speed_stim_sign, speed_stim_mag, axis3, new4_ind_st, new4_ind_end, g_rej_vec, speed_stim_org, UD_UD_detection_oldtrial

