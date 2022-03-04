import numpy as np

# Plotting
import plotly.graph_objects as go

# Data saving
import pickle

# module for counting values in a list
from collections import Counter

# Importing the statistics module
from statistics import mode, mean, median, multimode

from sklearn.cluster import KMeans


# Personal python functions
from subfunctions.make_a_properlist import *
from subfunctions.detect_sig_change_wrt_baseline import *
from subfunctions.findall import *

from b_data_preprocessing.kmeans_minmax_boundary import *
from b_data_preprocessing.speed_stim_from_initslope import *


# PURPOSE : Calculates data-driven speed stimulus (speed_stim_dd).



def s3_calc_datadriven_speedstim(varr):

    fs = 10 #  Original experimental sampling was at 250Hz, but data is downsampled to 10Hz
    ts = 1/fs
    
    # ------------------------------
    # Find relavant trials : trials where the joystick does not move and we can see the true 
    # experimental stimulus characteristics per axis
    
    speed_stim_dd = []
    slope_per_exp = []
    
    # 1) Load exp : put the experiment that you wish to run.
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
            file_dir_name = "%s\\%s" % (varr['main_path2'], file_name)
            open_file = open(file_dir_name, "rb")
            dat = pickle.load(open_file)
            open_file.close()

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
            file_dir_name = "%s\\%s" % (varr['main_path2'], file_name)
            open_file = open(file_dir_name, "rb")
            dat = pickle.load(open_file)
            open_file.close()


        
        # ------------------------------
        totsub_slope_ORG = []
        
        # 2) Load subjects
        subs = range(len(dat))
        subs = make_a_properlist(subs)

        for s in subs:
            num_of_tr = len(dat[s][0])

            speed_stim_sign_dd_OLD = dat[s][0]         # 0 : speed_stim_sign
            speed_stim_mag_dd_OLD = dat[s][1]          # 1 : speed_stim_mag
            speed_stim_em = dat[s][2]           # 2 : speed_stim_org
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
            
            # ------------------------------
            
            slope_val = []
            for tr in range(num_of_tr):
                
                t = time[tr]
                tr_JOY = outJOY[tr][:, axis_out[tr]]
                tr_SIG = outSIG[tr][:, axis_out[tr]]
                
                tr_len = len(tr_SIG)  # check if it gives the rows, not the columns
                
                # If the joystick is not moved, we can see the true stimulus signal
                if abs(np.max(tr_JOY)) < 0.1: # deadzone
                    
                    num_of_init_pts = int(tr_len/5)
                else:
                    # When the joystick was moved
                    baseline = 0
                    marg =  0.1
                    dpOFsig_in_zone, indexOFsig_in_zone, dp_sign_not_in_zone, indexOFsig_not_in_zone = detect_sig_change_wrt_baseline(tr_JOY, baseline, marg)
                    
                    # Find when the joystick was moved - this is the stop pt to take the slope
                    num_of_init_pts = indexOFsig_not_in_zone[0]
                    
                    # Corrections
                    if not num_of_init_pts.any():
                        num_of_init_pts = 2   # if the joystick is moved initially, just use first two points
                
                
                vec = tr_SIG[0:num_of_init_pts]
                xx = list(range(len(vec)))
                P = np.polyfit(xx, vec, 1)# approximates coefficients for a linear function y = a1*x + a2 so first coefficient is the slope
                w_MP = P[0]		# a1 (slope), linear parameter
                b_MP = P[1]		# a2 (y-intercept), linear parameter
                
                # The initial slope across trials for each subject
                slope_val = slope_val + [w_MP]
            
            slope_val = make_a_properlist(slope_val)
            totsub_slope_ORG = totsub_slope_ORG + [slope_val]
        # ------------------------------
        
        # ------------------------------
        # Append all the data across subjects and trials
        totsub_sig_val = make_a_properlist(totsub_slope_ORG)
        
        # Calculate mean and min-max boundaries for grouped data
        max_clu_0, min_clu_0, max_clu_1, min_clu_1 = kmeans_minmax_boundary(totsub_sig_val, fs)
        
        # Calculate speed stim categories from initial slope data, using the max and min boundary thresholds.
        speed_stim_per_exp = speed_stim_from_initslope(max_clu_0, min_clu_0, max_clu_1, min_clu_1, totsub_slope_ORG)
        # ------------------------------
        
        # ------------------------------
        
        #speed_stim_sign_dd_OLD
        
        # Calculate the same speed stim categories using the OLD speed stim mag
        
        # ------------------------------
        
        speed_stim_dd = speed_stim_dd + [speed_stim_per_exp]  # per experiment
        slope_per_exp = slope_per_exp + [totsub_slope_ORG]   # initial slope per experiment, across subject and across trials

    return speed_stim_dd, slope_per_exp