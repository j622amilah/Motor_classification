import numpy as np

# Plotting
from plotly.subplots import make_subplots
import plotly.graph_objects as go
import plotly.express as px

# Data saving
import pickle

# Importing the statistics module
from statistics import mode, mean, median, multimode
import scipy.stats

# Personal python functions
import sys
#sys.path.insert(1, '/home/jamilah/Documents/Github_analysis_PROJECTS/Motor_classification/subfunctions')
sys.path.insert(1, 'C:\\Users\\jamilah\\Documents\\Github_analysis_PROJECTS\\Motor_classification\\subfunctions')

from subfunctions.check_axes_assignmentPLOT import *
from subfunctions.cut_initial_trials import *

from subfunctions.findall import *

from subfunctions.main_preprocessing_steps import *
from subfunctions.make_a_properlist import *

from subfunctions.size import *

from subfunctions.standarization_notebadtrials import *
from subfunctions.saveSSQ import *

# Creating folders for image or data saving
import os



def s1_removeBADtrials_savedata():

    # ------------------------------

    # Selecting a method of removing bad trials from the data
    # Saving the data per participant per experiment

    varr = {}
    varr['main_path'] = "C:\\Users\\jamilah\\Documents\\Github_analysis_PROJECTS\\Motor_classification"  # Windows
    #varr['main_path'] = "/home/jamilah/Documents/Github_analysis_PROJECTS/Motor_classification"

    NUMmark = 0   #  an arbitraily large number to denote a non-valid entry

    fs = 10 #  Original experimental sampling was at 250Hz, but data is downsampled to 10Hz
    ts = 1/fs

    mj_val = [0.1, 0.05, 0.01]
    
    tr_type_sub_exp = []

    # 1) Load exp : put the experiment that you wish to run
    for exp in range(2):  # 0=rotation, 1=translation

        if exp == 0:
            # Rotational data - 18 participants
            varr['which_exp'] = 'rot'
            varr['subjects'] = 'GV-123','AW-123','CDV-456','LB-000','PJ-123','PN-509','DL-777','SS-531','MD-565','CB-161','PI-112','FD-112','JMF-123','LB-195','LM-123','MBC-777','PB-123','SA-643'
            varr['sub_nom_rot'] = 'GV','AW','CDV','LB','PJ','PN','DL','SS','MD','CB','PI','FD','JMF','LB','LM','MBC','PB','SA'
            varr['anom'] = 'RO', 'PI', 'YA'
            varr['joyanom'] = '1', '2', '3'  # Numbers for standarization, because we switch axes.  For pre-processing we set an axis like in anom.
            varr['vals'] = 0.5, 1.25, 0
            varr['data_path'] = '%s\\DATA_10Hz_rot' % (varr['main_path'])  # Windows
            # varr['data_path'] = '%s/DATA_10Hz_rot' % (varr['main_path'])
            
            # 1) Orientation of joystick axes (Proven by standardization test)
            a = 17-1  # labeled (PI) - joystick movement
            b = 16-1   # labeled (RO) - joystick movement
            c = 18-1   # labeled (YA) - joystick movement
            
            rotdat = []
            
        elif exp == 1:
            # Translational data - 14 participants
            varr['which_exp'] = 'trans'
            varr['subjects'] = '20170411-TB-463','20172206-NB-777','20170413-GP-007','20172806-SM-308','20170404-AV-280','20170308-MK-160','20172008-AS-007','20170824-GL-380','p9_16102017-RW-115','p10_12102017-SG-123','p11_17102017-LG-123','p12_10102017-HS-000','p13_13102017-GB-666','p14_20171014-SL-132'
            varr['sub_nom_rot'] = 'TB','NB','GP','SM','AV','MK','AS','GL','RW','SG','LG','HS','GB','SL'        
            varr['anom'] = 'LR', 'FB', 'UD'
            varr['joyanom'] = '1', '2', '3'
            varr['vals'] = 3.75, 15, 0
            varr['data_path'] = '%s\\DATA_10Hz_trans' % (varr['main_path'])  # Windows
            # varr['data_path'] = '%s/DATA_10Hz_trans' % (varr['main_path'])
            
            # 1) Orientation of joystick axes (Proven by standardization test)
            a = 16-1  # labeled (LR) - joystick movement
            b = 17-1   # labeled (FB) - joystick movement
            c = 18-1   # labeled (UD) - joystick movement
            
            transdat = []
        
        
        # 2) Directional control orientation : (cab = cab_com - joystick),(cab = -joy)
        # (Proven by standardization test)
        dirC = 0

        # 3) Deadzone margin : 0.1 (Proven by standardization test)
        marg_joy = 0.1


        # 2) Load subjects
        subs = range(len(varr['subjects']))
        subs = make_a_properlist(subs)
        
        exp_reject_cat_vec = []
        exp_acc_tr_per = []
        
        tr_type_sub = []
        
        for s in subs:
            print('s : ' + str(s))

            # ------------------------------
            # (1) Load data
            A = np.loadtxt("%s\\%s.txt" % (varr['data_path'], varr['subjects'][s]))  # Windows
            #A = np.loadtxt("%s/%s.txt" % (varr['data_path'], varr['subjects'][s]))

            # print('Size of A matrix : ' + str(size(A)))     # result(row00=9445, col00=22)
            # ------------------------------
            
            
            # ------------------------------
            # There was confusion if yaw joystick direction was reversed
            yr = 0  # 0=keep the sign of yaw/UD joystick, 1=reverse the sign of yaw/UD joystick
            # ------------------------------
            
            
            # ------------------------------
            # a) Pre-process the data using the selected orax, dirC, and mj_val 
            starttrial_index, stoptrial_index, speed_stim_sign, speed_stim_mag, speed_stim_org, axis_out, axis_org, new3_ind_st, new3_ind_end, g_rej_vec, outJOY, outSIG, outSIGCOM, outNOISE, corr_axis_out, corr_speed_stim_out, trialnum_org, time_org, FRT, good_tr = main_preprocessing_steps(varr, A, a, b, c, s, NUMmark, yr)
            # ------------------------------

            # ------------------------------
            # Check if axes are assigned correctly to trials: PLOTTING
            # ------------------------------
            plotORnot = 0  # 1 = show figures, 0 = do not show figures
            if plotORnot == 1:
                filename = 'images_cutfinal_%s' % (varr['which_exp'])
                check_axes_assignmentPLOT(s, outJOY, outSIG, axis_out, varr, filename, time_org)
            # ------------------------------
            
            
            # ------------------------------
            # Note trial to remove based on STANDARDIZATION
            # ------------------------------
            # If cabin does not follow the cabin in the correct direction, mark trial for removal
            # Same analysis as Standardization test 
            strictness = 1  # 0=Lenient (majority of axes correct), 1=Strict (all axes correct)
            if strictness == 0:
                strictness_text = 'ln_maj_ax'
            elif strictness == 1:
                strictness_text = 'st_all_ax'
            cut_trial_standard_move, cut_trial_standard_dir = standarization_notebadtrials(starttrial_index, stoptrial_index, axis_out, outSIG, outJOY, marg_joy, varr, s, strictness, dirC, good_tr)
            
            # print('cut_trial_standard_move : ' + str(cut_trial_standard_move))
            # print('cut_trial_standard_dir : ' + str(cut_trial_standard_dir))
            
            # Decide to remove trials by joy->cabin movement or joy->cabin movementANDdirection
            strictness1 = 1  # 0=Lenient (joy->cabin movement), 1=Strict (joy->cabin movementANDdirection)
            
            if strictness1 == 0:
                strictness1_text = 'ln_mov'
                cut_trial_standard = cut_trial_standard_move
            elif strictness1 == 1:
                strictness1_text = 'st_movANDdir'
                cut_trial_standard = np.unique([cut_trial_standard_move, cut_trial_standard_dir])
            
            cut_trial_standard = [int(x) for x in cut_trial_standard] 
            g_rej_vec[cut_trial_standard] = 50
            
            # ------------------------------
            # Quick statistical analysis of how many trials were removed and why
            # ------------------------------
            cou = Counter(g_rej_vec)
            if exp == 0:
                # 30 = cut_trial_ver_short
                # 40 = cut_trial_hor_short
                # 50 = cut_trial_standard
                # bar_title = ['ver_short', 'hor_short', 'standardization']
                reject_cat_vec = [cou[30], cou[40], cou[50]]
            elif exp == 1:
                # 10 = robotjump_cutlist
                # 15 = robotstall_cutlist
                # 20 = FB_nonzero_start
                # 25 = UD_initialization
                # 30 = cut_trial_ver_short
                # 40 = cut_trial_hor_short
                # 50 = cut_trial_standard
                # bar_title = ['robotjump', 'robotstall', 'FB_nonzero_start', 'UD_initialization', 'ver_short', 'hor_short', 'standardization']
                reject_cat_vec = [cou[10], cou[15], cou[20], cou[25], cou[30], cou[40], cou[50]]
            
            
            # print('g_rej_vec : ' + str(g_rej_vec))
            
            print('reject_cat_vec : ' + str(reject_cat_vec))
            
            # Must be a column vector
            colvec = np.reshape(reject_cat_vec, (len(reject_cat_vec),1))
            acc_tr = cou[0]
            acc_tr_per = acc_tr/len(g_rej_vec)
            # fig = px.bar(colvec, title="s=%d, %s, acc tr per=%f" % (s, varr['which_exp'], acc_tr_per))
            # fig.show()
            
            exp_reject_cat_vec = exp_reject_cat_vec + [reject_cat_vec]
            exp_acc_tr_per = exp_acc_tr_per + [acc_tr_per]
            # ------------------------------
            
            
            # ------------------------------
            # j06/m01/a22 : need better statistic on how many removed trials : save g_rej_vec
            # ------------------------------
            tr_type_sub.append(g_rej_vec)
            
            
            # ------------------------------
            # Get list of good trials to save
            # ------------------------------
            newvec, good_tr = findall(g_rej_vec, '==', 0)
            good_tr_fin = [int(x) for x in good_tr]
            # print('good_tr_fin : ' + str(good_tr_fin))
            
            # ------------------------------
            # Save good trial subject data per experiment 
            # ------------------------------
            subdat = []
            
            # experimental matrix events
            speed_stim_sign = np.array(speed_stim_sign)
            e0 = speed_stim_sign[good_tr_fin] # data-driven measured stimulus direction
            
            e1 = speed_stim_mag[good_tr_fin]  # data-driven measured stimulus magnitude
            
            speed_stim_org = np.array(speed_stim_org)
            e2 = speed_stim_org[good_tr_fin]  # experimental matrix stimulus magnitude and direction
            
            axis_out = np.array(axis_out)
            e3 = axis_out[good_tr_fin]  # data-driven measured axis
            
            axis_org = np.array(axis_org)
            e4 = axis_org[good_tr_fin] # experimental matrix axis

            # correlation between axis value in experimental matrix incomparison to axis measured from data via start-stop index
            e5 = corr_axis_out
            e6 = corr_speed_stim_out

            # start-stop trial cut index
            new3_ind_st = np.array(new3_ind_st)
            e7 = new3_ind_st[good_tr_fin]
            
            new3_ind_end = np.array(new3_ind_end)
            e8 = new3_ind_end[good_tr_fin]

            # Parameters with 3 axis
            e9 = []
            e10 = []
            e11 = []
            e12 = []
            e14 = []
            for tr in good_tr_fin:
                e9 = e9 + [outSIGCOM[tr]]  # a list (num of dp,3) per trial
                e10 = e10 + [outSIG[tr]]  # a list (num of dp,3) per trial
                e11 = e11 + [outJOY[tr]]  # a list (num of dp,3) per trial
                e12 = e12 + [outNOISE[tr]]  # a list (num of dp,3) per trial
                e14 = e14 + [time_org[tr]]  # a list (num of dp;1) per trial
            
            trialnum_org = np.array(trialnum_org)
            e13 = trialnum_org[good_tr_fin]
            
            # Each [] is a 4x1 vector=[nausee, oculo_moteur, disorientation, sickness]
            e15 = saveSSQ(s, varr['which_exp']) # SSQ [[before], [after], [diff=before-after]]
            
            e16 = FRT[good_tr_fin]
            
            subdat = e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16
            
            if exp == 0:
                rotdat = rotdat + [subdat]
            elif exp == 1:
                transdat = transdat + [subdat]
            
        # end of s
        
        
        
        
        # ------------------------------
        # Bar graph
        print('exp_reject_cat_vec : ' + str(exp_reject_cat_vec))

        exp_acc_tr_per = make_a_properlist(exp_acc_tr_per)
        # print('exp_acc_tr_per : ' + str(exp_acc_tr_per))
        
        if exp == 0:
            ver_short = []
            hor_short = []
            standard = []
            subname = []
            for subs in range(len(exp_reject_cat_vec)):
                ver_short = ver_short + [exp_reject_cat_vec[subs][0]]
                hor_short = hor_short + [exp_reject_cat_vec[subs][1]]
                standard = standard + [exp_reject_cat_vec[subs][2]]
                subname = subname + ['s%d_%f' % (subs, exp_acc_tr_per[subs])]

            ver_short = make_a_properlist(ver_short)
            hor_short = make_a_properlist(hor_short)
            standard = make_a_properlist(standard)
            subname = make_a_properlist(subname)
        elif exp == 1:
            robotjump = []
            robotstall = []
            FB_nonzero = []
            UD_init = []
            ver_short = []
            hor_short = []
            standard = []
            subname = []
            for subs in range(len(exp_reject_cat_vec)):
                robotjump = robotjump + [exp_reject_cat_vec[subs][0]]
                robotstall = robotstall + [exp_reject_cat_vec[subs][1]]
                FB_nonzero = FB_nonzero + [exp_reject_cat_vec[subs][2]]
                UD_init = UD_init + [exp_reject_cat_vec[subs][3]]
                ver_short = ver_short + [exp_reject_cat_vec[subs][4]]
                hor_short = hor_short + [exp_reject_cat_vec[subs][5]]
                standard = standard + [exp_reject_cat_vec[subs][6]]
                subname = subname + ['s%d_%f' % (subs, exp_acc_tr_per[subs])]   

            robotjump = make_a_properlist(robotjump)
            robotstall = make_a_properlist(robotstall)
            FB_nonzero = make_a_properlist(FB_nonzero)
            UD_init = make_a_properlist(UD_init)
            ver_short = make_a_properlist(ver_short)
            hor_short = make_a_properlist(hor_short)
            standard = make_a_properlist(standard)
            subname = make_a_properlist(subname)
            
        if exp == 0:
            fig = go.Figure(data=[
                go.Bar(name='ver_short', x=subname, y=ver_short),
                go.Bar(name='hor_short', x=subname, y=hor_short),
                go.Bar(name='standard', x=subname, y=standard)])
        elif exp == 1:
            fig = go.Figure(data=[
                go.Bar(name='robotjump', x=subname, y=robotjump),
                go.Bar(name='robotstall', x=subname, y=robotstall),
                go.Bar(name='FB_nonzero', x=subname, y=FB_nonzero),
                go.Bar(name='UD_init', x=subname, y=UD_init),
                go.Bar(name='ver_short', x=subname, y=ver_short),
                go.Bar(name='hor_short', x=subname, y=hor_short),
                go.Bar(name='standard', x=subname, y=standard)])
        titlestr = '%s : mean acceptance=%f, strictness_axes=%s, strictness_remove=%s' % (varr['which_exp'], mean(exp_acc_tr_per), strictness_text, strictness1_text)
        fig.update_layout(title=titlestr, xaxis_title='subjects (trial acceptance percentage)', yaxis_title='Trial rejection count', barmode='stack')
        fig.show()
        naame1 = '%s\\b_data_preprocessing\\trial_reject_stats_%s_%s_%s' % (varr['main_path'], varr['which_exp'], strictness, strictness1)
        fig.write_image("%s.png" % (naame1))
        # ------------------------------
        
        # ------------------------------
        # Save data matrices to file per experiment
        file_name = "%s\\b_data_preprocessing\\%sdat.pkl" % (varr['main_path'], varr['which_exp'])
        open_file = open(file_name, "wb")
        if varr['which_exp'] == 'rot':
            pickle.dump(rotdat, open_file)
            del rotdat
        elif varr['which_exp'] == 'trans':
            pickle.dump(transdat, open_file)
            del transdat
        open_file.close()
        # ------------------------------
        
        
        # ------------------------------
        # Save data matrices to file per experiment
        file_name = "%s\\b_data_preprocessing\\exp_reject_cat_vec_%s.pkl" % (varr['main_path'], varr['which_exp'])
        open_file = open(file_name, "wb")
        pickle.dump(exp_reject_cat_vec, open_file)
        open_file.close()
        # ------------------------------
        
        
        # ------------------------------
        # j06/m01/a22 : need better statistic on how many removed trials : save g_rej_vec
        # ------------------------------
        tr_type_sub_exp.append(tr_type_sub)
        
    # end of exp
    
    # ------------------------------
    # j06/m01/a22 : Save statistic results to file - 0=good trial
    # ------------------------------
    # if exp == 0:
        # 30 = cut_trial_ver_short
        # 40 = cut_trial_hor_short
        # 50 = cut_trial_standard
        # bar_title = ['ver_short', 'hor_short', 'standardization']
    # elif exp == 1:
        # 10 = robotjump_cutlist
        # 15 = robotstall_cutlist
        # 20 = FB_nonzero_start
        # 25 = UD_initialization
        # 30 = cut_trial_ver_short
        # 40 = cut_trial_hor_short
        # 50 = cut_trial_standard
    file_name = "%s\\b_data_preprocessing\\exp_sub_statistic.pkl" % (varr['main_path'])
    open_file = open(file_name, "wb")
    pickle.dump(tr_type_sub_exp, open_file)
    open_file.close()
    # ------------------------------
    
    return 