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
from subfunctions.make_a_properlist import *


# Creating folders for image or data saving
import os



def s2_comparison_expparameters_vs_data(varr, PCtype):

	if PCtype == 'Windows':
    	filemarker = '\\'
    elif PCtype == 'Linux':
    	filemarker = '/'

    # ------------------------------
    # There were differences between the robotic/participant data and the experimental matrix parameters (axis, speed_stim).
    
    # The experimental matrix parameters were loaded from one PC, and the robot data was loaded from UDP from 
    # another PC.  If the system is in real-time there could have been delays between the PCs, and thus in writing
    # the correct.  Also, in real-time software, the software give precedence to changing variables over fixed
    # variables (the system was on automatic handling and/or precidence to robotic movement to prevent the system from loosing increments and stopping).  So, there could be a recording delays for the fixed experimental matrix parameters in comparison to the constantly changing robot/joystick data.
    
    # We recalculate the experimental matrix parameters (axis, speed_stim) from the robotic/participant data, called data-driven experimental parameters, to confirm the accuracy of the experimental matrix parameters
    
    # axis : the magnitude of the first 1/5 of actual cabin movement was calculated for each axis.  The axis with the largest initial magnitude is the stimulus axis.  Participants could not respond quickly, so the initial cabin movement is the true experimental stimulus.

    # speed_stim sign :  the direction of the magnitude of the first 1/5 of actual cabin movement.
    
    # Figure of experimental matrix and data-driven axis and speed_stim correlation per subject.
    # ------------------------------

    NUMmark = 0   #  an arbitrarily large number to denote a non-valid entry

    fs = 10 #  Original experimental sampling was at 250Hz, but data is downsampled to 10Hz
    ts = 1/fs

    mj_val = [0.1, 0.05, 0.01]


    # 1) Load exp : put the experiment that you wish to run
    for exp in range(2):  # 0=rotation, 1=translation
        
        Xexp = []
        
        if exp == 0:
            # Rotational data - 18 participants
            varr['which_exp'] = 'rot'
            varr['subjects'] = 'GV-123','AW-123','CDV-456','LB-000','PJ-123','PN-509','DL-777','SS-531','MD-565','CB-161','PI-112','FD-112','JMF-123','LB-195','LM-123','MBC-777','PB-123','SA-643'
            varr['sub_nom_rot'] = 'GV','AW','CDV','LB','PJ','PN','DL','SS','MD','CB','PI','FD','JMF','LB','LM','MBC','PB','SA'
            varr['anom'] = 'RO', 'PI', 'YA'
            varr['joyanom'] = '1', '2', '3'  # Numbers for standarization, because we switch axes.  For pre-processing we set an axis like in anom.
            varr['vals'] = 0.5, 1.25, 0
            
            varr['data_path'] = '%s%sDATA_10Hz_rot' % (varr['main_path'], filemarker)

            # 1) Orientation of joystick axes (Proven by standardization test)
            a = 17-1  # labeled (PI) - joystick movement
            b = 16-1   # labeled (RO) - joystick movement
            c = 18-1   # labeled (UD) - joystick movement

            # Load data experimental preprocessed data matrix
            file_name = "rotdat.pkl"
            
        elif exp == 1:
            # Translational data - 14 participants
            varr['which_exp'] = 'trans'
            varr['subjects'] = '20170411-TB-463','20172206-NB-777','20170413-GP-007','20172806-SM-308','20170404-AV-280','20170308-MK-160','20172008-AS-007','20170824-GL-380','p9_16102017-RW-115','p10_12102017-SG-123','p11_17102017-LG-123','p12_10102017-HS-000','p13_13102017-GB-666','p14_20171014-SL-132'
            varr['sub_nom_rot'] = 'TB','NB','GP','SM','AV','MK','AS','GL','RW','SG','LG','HS','GB','SL'        
            varr['anom'] = 'LR', 'FB', 'UD'
            varr['joyanom'] = '1', '2', '3'
            varr['vals'] = 3.75, 15, 0
            
            varr['data_path'] = '%s%sDATA_10Hz_trans' % (varr['main_path'], filemarker)

            # 1) Orientation of joystick axes (Proven by standardization test)
            a = 16-1  # labeled (LR) - joystick movement
            b = 17-1   # labeled (FB) - joystick movement
            c = 18-1   # labeled (UD) - joystick movement

            # Load data experimental preprocessed data matrix
            file_name = "transdat.pkl"
            
            
            
        file_dir_name = "%s%s%s" % (varr['main_path2'], filemarker, file_name)
        open_file = open(file_dir_name, "rb")
        dat = pickle.load(open_file)
        open_file.close()
		
        corr_axis_out_exp = []
        corr_speed_stim_out_exp = []

        # 2) Load subjects
        #subs = range(len(dat))
        subs = 0
        subs = make_a_properlist(subs)
        for s in subs:
            
            num_of_tr = len(dat[s][0])      
            
            speed_stim_sign_dd = dat[s][0]         # 0 : speed_stim_sign
            speed_stim_mag_dd = dat[s][1]          # 1 : speed_stim_mag
            speed_stim_em = dat[s][2]          # 2 : speed_stim_org
            axis_out = dat[s][3]                # 3 : axis_out
                                                # 4 : axis_org  (do not use)
            corr_axis_out = dat[s][5]           # 5 : corr_axis_out (scalar)
            corr_axis_out_exp = corr_axis_out_exp + [corr_axis_out]
            
            corr_speed_stim_out = dat[s][6]     # 6 : corr_speed_stim_out (scalar)
            corr_speed_stim_out_exp = corr_speed_stim_out_exp + [corr_speed_stim_out]
            
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
        
        
        # ------------------------------
        
        if plotORnot == 1:
		    fig = go.Figure()
		    config = dict({'scrollZoom': True, 'displayModeBar': True, 'editable': True})
		    xxORG = list(range(len(corr_axis_out_exp)))
		    fig.add_trace(go.Scatter(x=xxORG, y=corr_axis_out_exp, name='corr_axis_out_exp', line = dict(color='red', width=2, dash='dash'), showlegend=True))
		    fig.update_layout(title='Correlation of axis experimental matrix and axis data-driven (across trials) per subject', xaxis_title='subjects', yaxis_title='correlation (%s): axis' % (varr['which_exp']))
		    fig.show(config=config)
		    fig.write_image("%s%scorr_axis_out_exp_%s.png" % (varr['main_path2'], filemarker, varr['which_exp']))
		    
		    fig = go.Figure()
		    config = dict({'scrollZoom': True, 'displayModeBar': True, 'editable': True})
		    xxORG = list(range(len(corr_speed_stim_out_exp)))
		    fig.add_trace(go.Scatter(x=xxORG, y=corr_speed_stim_out_exp, name='corr_speed_stim_out_exp', line = dict(color='red', width=2, dash='dash'), showlegend=True))
		    fig.update_layout(title='Correlation of speed_stim experimental matrix and axis data-driven (across trials) per subject', xaxis_title='subjects', yaxis_title='correlation (%s): speed_stim' % (varr['which_exp']))
		    fig.show(config=config)
		    fig.write_image("%s%scorr_speed_stim_out_exp_%s.png" % (varr['main_path2'], filemarker, varr['which_exp']))
        
    return
