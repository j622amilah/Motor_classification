<<<<<<< HEAD
import numpy as np

# Plotting
import plotly.graph_objects as go

# Data saving
import pickle

# module for counting values in a list
from collections import Counter

# Importing the statistics module
from statistics import mode, mean, median, multimode

# Personal python functions
import sys
#sys.path.insert(1, '/home/jamilah/Documents/Sourceforge_analysis_PROJECTS/Motor_classification/subfunctions')
sys.path.insert(1, 'C:\\Users\\jamilah\\Documents\\Sourceforge_analysis_PROJECTS\\Motor_classification\\subfunctions')

from subfunctions.make_a_properlist import *


# ------------------------------
# Idea 1 (pure data): find the index of the max value of abs(outSIG) (actual cabin movement) 
# per trial when abs(outJOY) was moved less than 0.1 (the deadzone), for all subjects. This 
# should be the original cabin stimulus movement, without joystick usage.  Plot per axis the 
# outSIG value at the index, we should get two clusters where one is slow movement and the 
# other is fast movement.
# ------------------------------
# Rotation:  (tau=20, from notes - need to check again)
# RO : sub=(K=4) , sup=(K=23)
# PI : sub=(K=3) , sup=(K=23)
# YA : sub=(K=2) , sup=(K=23)
# 
# Translation:  (tau=8, from notes - need to check again)
# LR : sub=(K=60) , sup=(K=100)
# FB : sub=(K=60) , sup=(K=100)
# UD : sub=(K=70 (decreases from 100 to 30)) , sup=(K=170 (increases from 100 to 170)) 
# you can to see the sub value in this method

def Try1_subsup_relationship4_speedstim_outSIGmax():
    
    # ------------------------------
    # Quick side analysis : to determine the speed_stim value for each max amplitude 

    # Working backward to recover the speed_stim AND to simulate the stim_ramp signal without data
    # You need to simulate the stim_ramp if you want to estimate 'would have been perfect performance'
    # using a controller.
    # ------------------------------

    varr = {}
    varr['main_path'] = "C:\\Users\\jamilah\\Documents\\Sourceforge_analysis_PROJECTS\\Motor_classification"  # Windows
    #varr['main_path'] = "/home/jamilah/Documents/Sourceforge_analysis_PROJECTS/Motor_classification"

    NUMmark = 0   #  an arbitraily large number to denote a non-valid entry

    fs = 10 #  Original experimental sampling was at 250Hz, but data is downsampled to 10Hz
    ts = 1/fs

    mj_val = [0.1, 0.05, 0.01]


    # ------------------------------
    # Find relavant trials : trials where the joystick does not move and we can see the true 
    # experimental stimulus characteristics per axis
    exp_totsub_sig_val = []

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
            c = 18-1   # labeled (UD) - joystick movement

            # Load data experimental preprocessed data matrix
            file_name = "rotdat.pkl"
            open_file = open(file_name, "rb")
            dat = pickle.load(open_file)
            open_file.close()
            
            marg = 10

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

            # Load data experimental preprocessed data matrix
            file_name = "transdat.pkl"
            open_file = open(file_name, "rb")
            dat = pickle.load(open_file)
            open_file.close()
            
            marg = 20


        totsub_sig_val = []

        # 2) Load subjects
        subs = range(len(dat))
        subs = make_a_properlist(subs)
        for s in subs:
            num_of_tr = len(dat[s][0])

            speed_stim_sign_dd = dat[s][0]         # 0 : speed_stim_sign
            speed_stim_mag_dd = dat[s][1]          # 1 : speed_stim_mag
            speed_stim_em = dat[s][2]          # 2 : speed_stim_org
            axis_out = dat[s][3]                # 3 : axis_out
                                                # 4 : axis_org  (do not use)
            corr_axis_out = dat[s][5]           # 5 : corr_axis_out (scalar)
            corr_speed_stim_out = dat[s][6]     # 6 : corr_speed_stim_out (scalar)

            new3_ind_st = dat[s][7]             # 7 : new3_ind_st
            new3_ind_end = dat[s][8]            # 8 : new3_ind_end

            outSIGCOM = dat[s][9]               # 9 : outSIGCOM
            outSIG = dat[s][10]                 # 10 : outSIG
            outJOY = dat[s][11]                 # 11 : outJOY
            outNOISE = dat[s][12]               # 12 : outNOISE

            trialnum_org = dat[s][13]           # 13 : trialnum_org
            time = dat[s][14]                   # 14 : time_org
            SSQ = dat[s][15]                    # 15 : SSQ
            FRT_em = dat[s][16]                 # 16 : FRT

            
            
            sig_val = []

            for tr in range(num_of_tr):

                # If the joystick is not moved, we can see the true stimulus signal
                if abs(np.max(outJOY[tr])) < 0.1: # deadzone
                    
                    ax_per_tr = []
                    for ax in range(3):
                        ax_per_tr = ax_per_tr + [np.argmax(abs(outSIG[tr][:, ax]))]
                    # print('ax_per_tr : ' + str(ax_per_tr))
                    
                    
                    # Get the axis of stimulation - get the signal value at the max index for axis_out[tr]
                    index = ax_per_tr[axis_out[tr]]
                    # print('index : ' + str(index))
                    
                    sig_val = sig_val + [outSIG[tr][index, axis_out[tr]]]

            totsub_sig_val = totsub_sig_val + [sig_val]
        
        # print('length of totsub_sig_val : ' + str(len(totsub_sig_val)))
        # print('totsub_sig_val : ' + str(totsub_sig_val))
        # ------------------------------
        
        
        # ------------------------------
        # Organize the data per axis (across subs and trials)
        sig_ax0_out = []
        sig_ax1_out = []
        sig_ax2_out = []
        for s in subs:
            
            axis_out = dat[s][3]                # 3 : axis_out
            
            # print('length of totsub_sig_val[s] : ' + str(len(totsub_sig_val[s])))
            num_of_tr = len(totsub_sig_val[s])
            
            for tr in range(num_of_tr):
                # print('tr : ' + str(tr))
                if axis_out[tr] == 0:
                    sig_ax0_out = sig_ax0_out + [totsub_sig_val[s][tr]]
                elif axis_out[tr] == 1:
                    sig_ax1_out = sig_ax1_out + [totsub_sig_val[s][tr]]
                elif axis_out[tr] == 2:
                    sig_ax2_out = sig_ax2_out + [totsub_sig_val[s][tr]]
        # ------------------------------
        
        
        
        
        # ------------------------------
        # print('sig_ax0_out : ' + str(sig_ax0_out))
        ax0_max_val = np.round(np.max(sig_ax0_out))
        ax0_min_val = np.round(np.min(sig_ax0_out))

        # Condense the points by marg
        # 1) find the mode
        c = Counter(np.round(sig_ax0_out))
        number_counted = []
        for nc in c.items():
            number_counted = number_counted + [nc]
        ax0_topcout_value = number_counted[0][0]

        count_pts_not_around_topcout = []
        for i in range(len(sig_ax0_out)):
                if (sig_ax0_out[i] > (ax0_topcout_value+marg)) or (sig_ax0_out[i] < (ax0_topcout_value-marg)):
                    #outside margin so count 
                    count_pts_not_around_topcout = count_pts_not_around_topcout + [sig_ax0_out[i]]

        # 1) find the mode of the remaining pts not around top count
        count_pts_not_around_topcout = np.array(count_pts_not_around_topcout)
        if not count_pts_not_around_topcout.any():
            ax0_2nd_topcout_value = 0
        else:
            ax0_2nd_topcout_value = mode(np.round(count_pts_not_around_topcout))
        # -------------------------------------
        
        # -------------------------------------
        # print('sig_ax1_out : ' + str(sig_ax1_out))
        ax1_max_val = np.round(np.max(sig_ax1_out))
        ax1_min_val = np.round(np.min(sig_ax1_out))

        # Condense the points by marg
        # 1) find the mode
        c = Counter(np.round(sig_ax1_out))
        number_counted = []
        for nc in c.items():
            number_counted = number_counted + [nc]
        ax1_topcout_value = number_counted[0][0]

        count_pts_not_around_topcout = []
        for i in range(len(sig_ax1_out)):
                if (sig_ax1_out[i] > (ax1_topcout_value+marg)) or (sig_ax1_out[i] < (ax1_topcout_value-marg)):
                    #outside margin so count 
                    count_pts_not_around_topcout = count_pts_not_around_topcout + [sig_ax1_out[i]]

        # 1) find the mode of the remaining pts not around top count
        count_pts_not_around_topcout = np.array(count_pts_not_around_topcout)
        if not count_pts_not_around_topcout.any():
            ax1_2nd_topcout_value = 0
        else:
            ax1_2nd_topcout_value = mode(np.round(count_pts_not_around_topcout))
        # -------------------------------------
        
        # -------------------------------------
        # print('sig_ax2_out : ' + str(sig_ax2_out))
        ax2_max_val = np.round(np.max(sig_ax2_out))
        ax2_min_val = np.round(np.min(sig_ax2_out))

        # Condense the points by marg
        # 1) find the mode
        c0 = Counter(np.round(sig_ax2_out))
        number_counted = []
        for nc in c0.items():
            number_counted = number_counted + [nc]
        ax2_topcout_value = number_counted[0][0]

        count_pts_not_around_topcout = []
        for i in range(len(sig_ax2_out)):
                if (sig_ax2_out[i] > (ax2_topcout_value+marg)) or (sig_ax2_out[i] < (ax2_topcout_value-marg)):
                    #outside margin so count 
                    count_pts_not_around_topcout = count_pts_not_around_topcout + [sig_ax2_out[i]]

        # 1) find the mode of the remaining pts not around top count
        count_pts_not_around_topcout = np.array(count_pts_not_around_topcout)
        if not count_pts_not_around_topcout.any():
            ax2_2nd_topcout_value = 0
        else:
            ax2_2nd_topcout_value = mode(np.round(count_pts_not_around_topcout))
        # -------------------------------------
        
        
        # -------------------------------------
        # Do a quick figure per axis
        # plot the max and min across subjects and trials, and then a point for each 
        fig = go.Figure()
        config = dict({'scrollZoom': True, 'displayModeBar': True, 'editable': True})

        xxORG = list(range(len(sig_ax0_out)))
        fig.add_trace(go.Scatter(x=xxORG, y=sig_ax0_out, name='sig %s' % (varr['anom'][0]), mode='markers', marker=dict(color='black', size=10, symbol=5, line=dict(color='black', width=0)), showlegend=True))

        # Plotting individual values
        # Max 
        sigmax_ax0 = np.ones((len(sig_ax0_out)))*ax0_max_val
        fig.add_trace(go.Scatter(x=xxORG, y=sigmax_ax0, name='max', line = dict(color='red', width=2, dash='dash'), showlegend=True))

        # Min
        sigmin_ax0 = np.ones((len(sig_ax0_out)))*ax0_min_val
        fig.add_trace(go.Scatter(x=xxORG, y=sigmin_ax0, name='min', line = dict(color=' blue', width=2, dash='dash'), showlegend=True))

        # First most counted 
        sig1stcout_ax0 = np.ones((len(sig_ax0_out)))*ax0_topcout_value
        fig.add_trace(go.Scatter(x=xxORG, y=sig1stcout_ax0, name='most counted', line = dict(color='magenta', width=2, dash='dash'), showlegend=True))

        # Second most counted
        sig2ndcout_ax0 = np.ones((len(sig_ax0_out)))*ax0_2nd_topcout_value
        fig.add_trace(go.Scatter(x=xxORG, y=sig2ndcout_ax0, name='2nd most counted', line = dict(color=' cyan', width=2, dash='dash'), showlegend=True))

        title_str = '%s : max=%f, min=%f, 1stcout=%d, 2ndcout=%d, ' % (varr['which_exp'], ax0_max_val, ax0_min_val, ax0_topcout_value, ax0_2nd_topcout_value)
        fig.update_layout(title=title_str, xaxis_title='data points', yaxis_title='outSIG at index of max(abs(outSIG))')
        fig.show(config=config)

        filename = 'idea1'
        fig.write_image("%s_%s_%s.png" % (filename, varr['which_exp'], varr['anom'][0]))
        # ------------------------------


        # ------------------------------
        # Do a quick figure per axis
        # plot the max and min across subjects and trials, and then a point for each 
        fig = go.Figure()
        config = dict({'scrollZoom': True, 'displayModeBar': True, 'editable': True})

        xxORG = list(range(len(sig_ax1_out)))
        fig.add_trace(go.Scatter(x=xxORG, y=sig_ax1_out, name='sig %s' % (varr['anom'][1]), mode='markers', marker=dict(color='black', size=10, symbol=5, line=dict(color='black', width=0)), showlegend=True))

        # Plotting individual values
        # Max 
        sigmax_ax1 = np.ones((len(sig_ax1_out)))*ax1_max_val
        fig.add_trace(go.Scatter(x=xxORG, y=sigmax_ax1, name='max', line = dict(color='red', width=2, dash='dash'), showlegend=True))

        # Min
        sigmin_ax1 = np.ones((len(sig_ax1_out)))*ax1_min_val
        fig.add_trace(go.Scatter(x=xxORG, y=sigmin_ax1, name='min', line = dict(color=' blue', width=2, dash='dash'), showlegend=True))

        # First most counted 
        sig1stcout_ax1 = np.ones((len(sig_ax1_out)))*ax1_topcout_value
        fig.add_trace(go.Scatter(x=xxORG, y=sig1stcout_ax1, name='most counted', line = dict(color=' magenta', width=2, dash='dash'), showlegend=True))

        # Second most counted
        sig2ndcout_ax1 = np.ones((len(sig_ax1_out)))*ax1_2nd_topcout_value
        fig.add_trace(go.Scatter(x=xxORG, y=sig2ndcout_ax1, name='2nd most counted', line = dict(color=' cyan', width=2, dash='dash'), showlegend=True))

        title_str = '%s : max=%f, min=%f, 1stcout=%d, 2ndcout=%d, ' % (varr['which_exp'], ax1_max_val, ax1_min_val, ax1_topcout_value, ax1_2nd_topcout_value)
        fig.update_layout(title=title_str, xaxis_title='data points', yaxis_title='outSIG at index of max(abs(outSIG))')
        fig.show(config=config)

        filename = 'idea1'
        fig.write_image("%s_%s_%s.png" % (filename, varr['which_exp'], varr['anom'][1]))
        # ------------------------------

        # ------------------------------
        # Do a quick figure per axis
        # plot the max and min across subjects and trials, and then a point for each 
        fig = go.Figure()
        config = dict({'scrollZoom': True, 'displayModeBar': True, 'editable': True})

        xxORG = list(range(len(sig_ax2_out)))
        fig.add_trace(go.Scatter(x=xxORG, y=sig_ax2_out, name='sig %s' % (varr['anom'][2]), mode='markers', marker=dict(color='black', size=10, symbol=5, line=dict(color='black', width=0)), showlegend=True))

        # Plotting individual values
        # Max 
        sigmax_ax2 = np.ones((len(sig_ax2_out)))*ax2_max_val
        fig.add_trace(go.Scatter(x=xxORG, y=sigmax_ax2, name='max', line = dict(color='red', width=2, dash='dash'), showlegend=True))

        # Min
        sigmin_ax2 = np.ones((len(sig_ax2_out)))*ax2_min_val
        fig.add_trace(go.Scatter(x=xxORG, y=sigmin_ax2, name='min', line = dict(color=' blue', width=2, dash='dash'), showlegend=True))

        # First most counted 
        sig1stcout_ax2 = np.ones((len(sig_ax2_out)))*ax2_topcout_value
        fig.add_trace(go.Scatter(x=xxORG, y=sig1stcout_ax2, name='most counted', line = dict(color=' magenta', width=2, dash='dash'), showlegend=True))

        # Second most counted
        sig2ndcout_ax2 = np.ones((len(sig_ax2_out)))*ax2_2nd_topcout_value
        fig.add_trace(go.Scatter(x=xxORG, y=sig2ndcout_ax2, name='2nd most counted', line = dict(color=' cyan', width=2, dash='dash'), showlegend=True))

        title_str = '%s : max=%f, min=%f, 1stcout=%d, 2ndcout=%d, ' % (varr['which_exp'], ax2_max_val, ax2_min_val, ax2_topcout_value, ax2_2nd_topcout_value)
        fig.update_layout(title=title_str, xaxis_title='data points', yaxis_title='outSIG at index of max(abs(outSIG))')

        fig.show(config=config)

        filename = 'idea1'
        fig.write_image("%s_%s_%s.png" % (filename, varr['which_exp'], varr['anom'][2]))
        # ------------------------------
        

=======
import numpy as np

# Plotting
import plotly.graph_objects as go

# Data saving
import pickle

# module for counting values in a list
from collections import Counter

# Importing the statistics module
from statistics import mode, mean, median, multimode

# Personal python functions
import sys
#sys.path.insert(1, '/home/jamilah/Documents/Sourceforge_analysis_PROJECTS/Motor_classification/subfunctions')
sys.path.insert(1, 'C:\\Users\\jamilah\\Documents\\Sourceforge_analysis_PROJECTS\\Motor_classification\\subfunctions')

from subfunctions.make_a_properlist import *


# ------------------------------
# Idea 1 (pure data): find the index of the max value of abs(outSIG) (actual cabin movement) 
# per trial when abs(outJOY) was moved less than 0.1 (the deadzone), for all subjects. This 
# should be the original cabin stimulus movement, without joystick usage.  Plot per axis the 
# outSIG value at the index, we should get two clusters where one is slow movement and the 
# other is fast movement.
# ------------------------------
# Rotation:  (tau=20, from notes - need to check again)
# RO : sub=(K=4) , sup=(K=23)
# PI : sub=(K=3) , sup=(K=23)
# YA : sub=(K=2) , sup=(K=23)
# 
# Translation:  (tau=8, from notes - need to check again)
# LR : sub=(K=60) , sup=(K=100)
# FB : sub=(K=60) , sup=(K=100)
# UD : sub=(K=70 (decreases from 100 to 30)) , sup=(K=170 (increases from 100 to 170)) 
# you can to see the sub value in this method

def Try1_subsup_relationship4_speedstim_outSIGmax():
    
    # ------------------------------
    # Quick side analysis : to determine the speed_stim value for each max amplitude 

    # Working backward to recover the speed_stim AND to simulate the stim_ramp signal without data
    # You need to simulate the stim_ramp if you want to estimate 'would have been perfect performance'
    # using a controller.
    # ------------------------------

    varr = {}
    varr['main_path'] = "C:\\Users\\jamilah\\Documents\\Sourceforge_analysis_PROJECTS\\Motor_classification"  # Windows
    #varr['main_path'] = "/home/jamilah/Documents/Sourceforge_analysis_PROJECTS/Motor_classification"

    NUMmark = 0   #  an arbitraily large number to denote a non-valid entry

    fs = 10 #  Original experimental sampling was at 250Hz, but data is downsampled to 10Hz
    ts = 1/fs

    mj_val = [0.1, 0.05, 0.01]


    # ------------------------------
    # Find relavant trials : trials where the joystick does not move and we can see the true 
    # experimental stimulus characteristics per axis
    exp_totsub_sig_val = []

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
            c = 18-1   # labeled (UD) - joystick movement

            # Load data experimental preprocessed data matrix
            file_name = "rotdat.pkl"
            open_file = open(file_name, "rb")
            dat = pickle.load(open_file)
            open_file.close()
            
            marg = 10

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

            # Load data experimental preprocessed data matrix
            file_name = "transdat.pkl"
            open_file = open(file_name, "rb")
            dat = pickle.load(open_file)
            open_file.close()
            
            marg = 20


        totsub_sig_val = []

        # 2) Load subjects
        subs = range(len(dat))
        subs = make_a_properlist(subs)
        for s in subs:
            num_of_tr = len(dat[s][0])

            speed_stim_sign_dd = dat[s][0]         # 0 : speed_stim_sign
            speed_stim_mag_dd = dat[s][1]          # 1 : speed_stim_mag
            speed_stim_em = dat[s][2]          # 2 : speed_stim_org
            axis_out = dat[s][3]                # 3 : axis_out
                                                # 4 : axis_org  (do not use)
            corr_axis_out = dat[s][5]           # 5 : corr_axis_out (scalar)
            corr_speed_stim_out = dat[s][6]     # 6 : corr_speed_stim_out (scalar)

            new3_ind_st = dat[s][7]             # 7 : new3_ind_st
            new3_ind_end = dat[s][8]            # 8 : new3_ind_end

            outSIGCOM = dat[s][9]               # 9 : outSIGCOM
            outSIG = dat[s][10]                 # 10 : outSIG
            outJOY = dat[s][11]                 # 11 : outJOY
            outNOISE = dat[s][12]               # 12 : outNOISE

            trialnum_org = dat[s][13]           # 13 : trialnum_org
            time = dat[s][14]                   # 14 : time_org
            SSQ = dat[s][15]                    # 15 : SSQ
            FRT_em = dat[s][16]                 # 16 : FRT

            
            
            sig_val = []

            for tr in range(num_of_tr):

                # If the joystick is not moved, we can see the true stimulus signal
                if abs(np.max(outJOY[tr])) < 0.1: # deadzone
                    
                    ax_per_tr = []
                    for ax in range(3):
                        ax_per_tr = ax_per_tr + [np.argmax(abs(outSIG[tr][:, ax]))]
                    # print('ax_per_tr : ' + str(ax_per_tr))
                    
                    
                    # Get the axis of stimulation - get the signal value at the max index for axis_out[tr]
                    index = ax_per_tr[axis_out[tr]]
                    # print('index : ' + str(index))
                    
                    sig_val = sig_val + [outSIG[tr][index, axis_out[tr]]]

            totsub_sig_val = totsub_sig_val + [sig_val]
        
        # print('length of totsub_sig_val : ' + str(len(totsub_sig_val)))
        # print('totsub_sig_val : ' + str(totsub_sig_val))
        # ------------------------------
        
        
        # ------------------------------
        # Organize the data per axis (across subs and trials)
        sig_ax0_out = []
        sig_ax1_out = []
        sig_ax2_out = []
        for s in subs:
            
            axis_out = dat[s][3]                # 3 : axis_out
            
            # print('length of totsub_sig_val[s] : ' + str(len(totsub_sig_val[s])))
            num_of_tr = len(totsub_sig_val[s])
            
            for tr in range(num_of_tr):
                # print('tr : ' + str(tr))
                if axis_out[tr] == 0:
                    sig_ax0_out = sig_ax0_out + [totsub_sig_val[s][tr]]
                elif axis_out[tr] == 1:
                    sig_ax1_out = sig_ax1_out + [totsub_sig_val[s][tr]]
                elif axis_out[tr] == 2:
                    sig_ax2_out = sig_ax2_out + [totsub_sig_val[s][tr]]
        # ------------------------------
        
        
        
        
        # ------------------------------
        # print('sig_ax0_out : ' + str(sig_ax0_out))
        ax0_max_val = np.round(np.max(sig_ax0_out))
        ax0_min_val = np.round(np.min(sig_ax0_out))

        # Condense the points by marg
        # 1) find the mode
        c = Counter(np.round(sig_ax0_out))
        number_counted = []
        for nc in c.items():
            number_counted = number_counted + [nc]
        ax0_topcout_value = number_counted[0][0]

        count_pts_not_around_topcout = []
        for i in range(len(sig_ax0_out)):
                if (sig_ax0_out[i] > (ax0_topcout_value+marg)) or (sig_ax0_out[i] < (ax0_topcout_value-marg)):
                    #outside margin so count 
                    count_pts_not_around_topcout = count_pts_not_around_topcout + [sig_ax0_out[i]]

        # 1) find the mode of the remaining pts not around top count
        count_pts_not_around_topcout = np.array(count_pts_not_around_topcout)
        if not count_pts_not_around_topcout.any():
            ax0_2nd_topcout_value = 0
        else:
            ax0_2nd_topcout_value = mode(np.round(count_pts_not_around_topcout))
        # -------------------------------------
        
        # -------------------------------------
        # print('sig_ax1_out : ' + str(sig_ax1_out))
        ax1_max_val = np.round(np.max(sig_ax1_out))
        ax1_min_val = np.round(np.min(sig_ax1_out))

        # Condense the points by marg
        # 1) find the mode
        c = Counter(np.round(sig_ax1_out))
        number_counted = []
        for nc in c.items():
            number_counted = number_counted + [nc]
        ax1_topcout_value = number_counted[0][0]

        count_pts_not_around_topcout = []
        for i in range(len(sig_ax1_out)):
                if (sig_ax1_out[i] > (ax1_topcout_value+marg)) or (sig_ax1_out[i] < (ax1_topcout_value-marg)):
                    #outside margin so count 
                    count_pts_not_around_topcout = count_pts_not_around_topcout + [sig_ax1_out[i]]

        # 1) find the mode of the remaining pts not around top count
        count_pts_not_around_topcout = np.array(count_pts_not_around_topcout)
        if not count_pts_not_around_topcout.any():
            ax1_2nd_topcout_value = 0
        else:
            ax1_2nd_topcout_value = mode(np.round(count_pts_not_around_topcout))
        # -------------------------------------
        
        # -------------------------------------
        # print('sig_ax2_out : ' + str(sig_ax2_out))
        ax2_max_val = np.round(np.max(sig_ax2_out))
        ax2_min_val = np.round(np.min(sig_ax2_out))

        # Condense the points by marg
        # 1) find the mode
        c0 = Counter(np.round(sig_ax2_out))
        number_counted = []
        for nc in c0.items():
            number_counted = number_counted + [nc]
        ax2_topcout_value = number_counted[0][0]

        count_pts_not_around_topcout = []
        for i in range(len(sig_ax2_out)):
                if (sig_ax2_out[i] > (ax2_topcout_value+marg)) or (sig_ax2_out[i] < (ax2_topcout_value-marg)):
                    #outside margin so count 
                    count_pts_not_around_topcout = count_pts_not_around_topcout + [sig_ax2_out[i]]

        # 1) find the mode of the remaining pts not around top count
        count_pts_not_around_topcout = np.array(count_pts_not_around_topcout)
        if not count_pts_not_around_topcout.any():
            ax2_2nd_topcout_value = 0
        else:
            ax2_2nd_topcout_value = mode(np.round(count_pts_not_around_topcout))
        # -------------------------------------
        
        
        # -------------------------------------
        # Do a quick figure per axis
        # plot the max and min across subjects and trials, and then a point for each 
        fig = go.Figure()
        config = dict({'scrollZoom': True, 'displayModeBar': True, 'editable': True})

        xxORG = list(range(len(sig_ax0_out)))
        fig.add_trace(go.Scatter(x=xxORG, y=sig_ax0_out, name='sig %s' % (varr['anom'][0]), mode='markers', marker=dict(color='black', size=10, symbol=5, line=dict(color='black', width=0)), showlegend=True))

        # Plotting individual values
        # Max 
        sigmax_ax0 = np.ones((len(sig_ax0_out)))*ax0_max_val
        fig.add_trace(go.Scatter(x=xxORG, y=sigmax_ax0, name='max', line = dict(color='red', width=2, dash='dash'), showlegend=True))

        # Min
        sigmin_ax0 = np.ones((len(sig_ax0_out)))*ax0_min_val
        fig.add_trace(go.Scatter(x=xxORG, y=sigmin_ax0, name='min', line = dict(color=' blue', width=2, dash='dash'), showlegend=True))

        # First most counted 
        sig1stcout_ax0 = np.ones((len(sig_ax0_out)))*ax0_topcout_value
        fig.add_trace(go.Scatter(x=xxORG, y=sig1stcout_ax0, name='most counted', line = dict(color='magenta', width=2, dash='dash'), showlegend=True))

        # Second most counted
        sig2ndcout_ax0 = np.ones((len(sig_ax0_out)))*ax0_2nd_topcout_value
        fig.add_trace(go.Scatter(x=xxORG, y=sig2ndcout_ax0, name='2nd most counted', line = dict(color=' cyan', width=2, dash='dash'), showlegend=True))

        title_str = '%s : max=%f, min=%f, 1stcout=%d, 2ndcout=%d, ' % (varr['which_exp'], ax0_max_val, ax0_min_val, ax0_topcout_value, ax0_2nd_topcout_value)
        fig.update_layout(title=title_str, xaxis_title='data points', yaxis_title='outSIG at index of max(abs(outSIG))')
        fig.show(config=config)

        filename = 'idea1'
        fig.write_image("%s_%s_%s.png" % (filename, varr['which_exp'], varr['anom'][0]))
        # ------------------------------


        # ------------------------------
        # Do a quick figure per axis
        # plot the max and min across subjects and trials, and then a point for each 
        fig = go.Figure()
        config = dict({'scrollZoom': True, 'displayModeBar': True, 'editable': True})

        xxORG = list(range(len(sig_ax1_out)))
        fig.add_trace(go.Scatter(x=xxORG, y=sig_ax1_out, name='sig %s' % (varr['anom'][1]), mode='markers', marker=dict(color='black', size=10, symbol=5, line=dict(color='black', width=0)), showlegend=True))

        # Plotting individual values
        # Max 
        sigmax_ax1 = np.ones((len(sig_ax1_out)))*ax1_max_val
        fig.add_trace(go.Scatter(x=xxORG, y=sigmax_ax1, name='max', line = dict(color='red', width=2, dash='dash'), showlegend=True))

        # Min
        sigmin_ax1 = np.ones((len(sig_ax1_out)))*ax1_min_val
        fig.add_trace(go.Scatter(x=xxORG, y=sigmin_ax1, name='min', line = dict(color=' blue', width=2, dash='dash'), showlegend=True))

        # First most counted 
        sig1stcout_ax1 = np.ones((len(sig_ax1_out)))*ax1_topcout_value
        fig.add_trace(go.Scatter(x=xxORG, y=sig1stcout_ax1, name='most counted', line = dict(color=' magenta', width=2, dash='dash'), showlegend=True))

        # Second most counted
        sig2ndcout_ax1 = np.ones((len(sig_ax1_out)))*ax1_2nd_topcout_value
        fig.add_trace(go.Scatter(x=xxORG, y=sig2ndcout_ax1, name='2nd most counted', line = dict(color=' cyan', width=2, dash='dash'), showlegend=True))

        title_str = '%s : max=%f, min=%f, 1stcout=%d, 2ndcout=%d, ' % (varr['which_exp'], ax1_max_val, ax1_min_val, ax1_topcout_value, ax1_2nd_topcout_value)
        fig.update_layout(title=title_str, xaxis_title='data points', yaxis_title='outSIG at index of max(abs(outSIG))')
        fig.show(config=config)

        filename = 'idea1'
        fig.write_image("%s_%s_%s.png" % (filename, varr['which_exp'], varr['anom'][1]))
        # ------------------------------

        # ------------------------------
        # Do a quick figure per axis
        # plot the max and min across subjects and trials, and then a point for each 
        fig = go.Figure()
        config = dict({'scrollZoom': True, 'displayModeBar': True, 'editable': True})

        xxORG = list(range(len(sig_ax2_out)))
        fig.add_trace(go.Scatter(x=xxORG, y=sig_ax2_out, name='sig %s' % (varr['anom'][2]), mode='markers', marker=dict(color='black', size=10, symbol=5, line=dict(color='black', width=0)), showlegend=True))

        # Plotting individual values
        # Max 
        sigmax_ax2 = np.ones((len(sig_ax2_out)))*ax2_max_val
        fig.add_trace(go.Scatter(x=xxORG, y=sigmax_ax2, name='max', line = dict(color='red', width=2, dash='dash'), showlegend=True))

        # Min
        sigmin_ax2 = np.ones((len(sig_ax2_out)))*ax2_min_val
        fig.add_trace(go.Scatter(x=xxORG, y=sigmin_ax2, name='min', line = dict(color=' blue', width=2, dash='dash'), showlegend=True))

        # First most counted 
        sig1stcout_ax2 = np.ones((len(sig_ax2_out)))*ax2_topcout_value
        fig.add_trace(go.Scatter(x=xxORG, y=sig1stcout_ax2, name='most counted', line = dict(color=' magenta', width=2, dash='dash'), showlegend=True))

        # Second most counted
        sig2ndcout_ax2 = np.ones((len(sig_ax2_out)))*ax2_2nd_topcout_value
        fig.add_trace(go.Scatter(x=xxORG, y=sig2ndcout_ax2, name='2nd most counted', line = dict(color=' cyan', width=2, dash='dash'), showlegend=True))

        title_str = '%s : max=%f, min=%f, 1stcout=%d, 2ndcout=%d, ' % (varr['which_exp'], ax2_max_val, ax2_min_val, ax2_topcout_value, ax2_2nd_topcout_value)
        fig.update_layout(title=title_str, xaxis_title='data points', yaxis_title='outSIG at index of max(abs(outSIG))')

        fig.show(config=config)

        filename = 'idea1'
        fig.write_image("%s_%s_%s.png" % (filename, varr['which_exp'], varr['anom'][2]))
        # ------------------------------
        

>>>>>>> 94b06cd4776edc5e6880e69ca0d1eefbe92d257c
    return