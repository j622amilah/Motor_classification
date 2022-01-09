import numpy as np

# Data saving
import pickle

# Importing the statistics module
from statistics import mode, mean, median, multimode

# Personal python functions
import sys
#sys.path.insert(1, '/home/jamilah/Documents/Sourceforge_analysis_PROJECTS/Motor_classification/b_data_preprocessing')
sys.path.insert(1, 'C:\\Users\\jamilah\\Documents\\Sourceforge_analysis_PROJECTS\\Motor_classification\\b_data_preprocessing')

from subfunctions.make_a_properlist import *
from subfunctions.cut_initial_trials import *
from subfunctions.full_sig_2_cell import *


# PURPOSE : To recalculate the experimental matrix speed stim, using the target angular speed per stimulus axis.  (Before, we calculated the mode of either grad_stim or mode across all axes : NOT CORRECT).

# And, resave rotdat.pkl and transdat.pkl



def s3_recalculate_speed_stim_org(speed_stim_dd, slope_per_exp):

    varr = {}
    varr['main_path'] = "C:\\Users\\jamilah\\Documents\\Sourceforge_analysis_PROJECTS\\Motor_classification"  # Windows
    # varr['main_path'] = "/home/jamilah/Documents/Sourceforge_analysis_PROJECTS/Motor_classification"

    fs = 10 #  Original experimental sampling was at 250Hz, but data is downsampled to 10Hz
    ts = 1/fs

    
    corr_ssdir_dd_co_out = []
    corr_ssmag_dd_co_out = []
    tas_out = []
    ss_org_co_out = []


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
            
            # Load data experimental preprocessed data matrix
            file_name = "rotdat.pkl"
            open_file = open(file_name, "rb")
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
            open_file = open(file_name, "rb")
            dat = pickle.load(open_file)
            open_file.close()
        
        corr_ssdir_dd_co_exp = []
        corr_ssmag_dd_co_exp = []
        tas_exp = []
        ss_org_co_exp = []
        
        
        # 2) Load subjects
        subs = range(len(varr['subjects']))
        subs = make_a_properlist(subs)
        
        
        for s in subs:
            # print('s : ' + str(s))
            
            # ------------------------------
            # (1) Load orignal data
            A = np.loadtxt("%s\\%s.txt" % (varr['data_path'], varr['subjects'][s]))  # Windows

            # ------------------------------
            # (2) Load pre-preocessed data
            num_of_tr = len(dat[s][0])      
            
            speed_stim_sign_dd_OLD = dat[s][0]         # 0 : speed_stim_sign (DD)
            speed_stim_mag_dd_OLD = dat[s][1]          # 1 : speed_stim_mag (DD)
            
            axis_out = dat[s][3]                # 3 : axis_out (DD)
            axis_org = dat[s][4]                # 4 : axis_org (EM : do not use)
            corr_axis_out = dat[s][5]           # 5 : corr_axis_out (scalar)
            corr_speed_stim_sign_out = dat[s][6]     # 6 : corr_speed_stim_out (scalar)
            
            new3_ind_st = dat[s][7]             # 7 : new3_ind_st (DD)
            new3_ind_end = dat[s][8]            # 8 : new3_ind_end (DD)
            
            outSIGCOM = dat[s][9]               # 9 : outSIGCOM
            outSIG = dat[s][10]                 # 10 : outSIG
            outJOY = dat[s][11]                 # 11 : outJOY
            outNOISE = dat[s][12]               # 12 : outNOISE
            
            trialnum_org = dat[s][13]           # 13 : trialnum_org
            time = dat[s][14]                   # 14 : time_org
            SSQ = dat[s][15]                    # 15 : SSQ
            FRT_em = dat[s][16]                 # 16 : FRT
            
            # ------------------------------
            
            
            # ------------------------------
            # (3) Speed stimulus experimental matrix : accounting for the confusion in roll and pitch axis.
            # ------------------------------
            outlier_val = 0
            sup_val = 2
            sub_val = 1

            Len_tr = len(new3_ind_st)
            
            # Way 1: Experimental collected speed stim
            speed_stim_org_co = np.zeros((Len_tr))
            tar_ang_speed_val_co = np.zeros((Len_tr))

            # print('new3_ind_st : ' + str(new3_ind_st))
            # print('new3_ind_end : ' + str(new3_ind_end))

            for tr in range(Len_tr):
                st = int(new3_ind_st[tr])
                stp = int(new3_ind_end[tr])

                # Using target angular speed with respect to axis
                if varr['which_exp'] == 'rot':
                    # Calculate both roll and pitch reversed and correct order : to test which is correct with data-driven
                    # Correct order :
                    val = axis_out[tr]  # 0=RO, 1=PI, 2=YA
                    if val == 0: 
                        tar_ang_speed_val_co[tr] = mode(A[st:stp, 10-1])
                    elif val == 1:
                        tar_ang_speed_val_co[tr] = mode(A[st:stp, 11-1])
                    elif val == 2:
                        tar_ang_speed_val_co[tr] = mode(A[st:stp, 12-1])
                    
                    # Turn target angular speed values into 0, 1, or outlier_val
                    if abs(tar_ang_speed_val_co[tr]) == 1.25 or abs(tar_ang_speed_val_co[tr]) == 1.5:
                        speed_stim_org_co[tr] = sup_val   # sup
                    elif abs(tar_ang_speed_val_co[tr]) == 0.5:
                        speed_stim_org_co[tr] = sub_val   # sub
                    else:
                        speed_stim_org_co[tr] = outlier_val    # outlier
                    

                elif varr['which_exp'] == 'trans':
                    # Correct order :
                    val = axis_out[tr]  # 0=LR, 1=FB, 2=UD
                    if val == 0: 
                        tar_ang_speed_val_co[tr] = mode(A[st:stp, 10-1])
                    elif val == 1:
                        tar_ang_speed_val_co[tr] = mode(A[st:stp, 11-1])
                    elif val == 2:
                        tar_ang_speed_val_co[tr] = mode(A[st:stp, 12-1])
                    
                    # Turn target angular speed values into 0, 1, or outlier_val
                    if abs(tar_ang_speed_val_co[tr]) == 15 or abs(tar_ang_speed_val_co[tr]) == 17.5:
                        speed_stim_org_co[tr] = sup_val   # sup
                    elif abs(tar_ang_speed_val_co[tr]) == 3.75:
                        speed_stim_org_co[tr] = sub_val   # sub
                    else:
                        speed_stim_org_co[tr] = outlier_val    # outlier
            # ------------------------------
            
            
            # ------------------------------
            # Calculate correlation for DD (direction=sign(slope_per_exp) and EM (direction=sign(speed_stim_org_co)
            # Pearson correlation coefficient : corr (x,y) = cov (x,y) / (std (x) * std (y))
            corr_ssdir_dd_co = np.corrcoef(speed_stim_dd[exp][s], speed_stim_org_co) # outputs a correlation matrix
            corr_ssdir_dd_co = corr_ssdir_dd_co[0,1]
            
            # Calculate correlation for DD (magnitude=speed_stim_dd and EM (magnitude=speed_stim_org_co)
            corr_ssmag_dd_co = np.corrcoef(speed_stim_dd[exp][s], speed_stim_org_co) # outputs a correlation matrix
            corr_ssmag_dd_co = corr_ssmag_dd_co[0,1]
            
            
            # ------------------------------
            # finished for loop with s 
            
            corr_ssdir_dd_co_exp = corr_ssdir_dd_co_exp + [corr_ssdir_dd_co]  # scalar
            corr_ssmag_dd_co_exp = corr_ssmag_dd_co_exp + [corr_ssmag_dd_co]  # scalar
            
            tas_exp = tas_exp + [tar_ang_speed_val_co]
            ss_org_co_exp = ss_org_co_exp + [speed_stim_org_co]
        
        
        corr_ssdir_dd_co_out = corr_ssdir_dd_co_out + [corr_ssdir_dd_co_exp]
        corr_ssmag_dd_co_out = corr_ssmag_dd_co_out + [corr_ssmag_dd_co_exp]
        
        tas_out = tas_out + [tas_exp]
        ss_org_co_out = ss_org_co_out + [ss_org_co_exp]
        
        
    return tas_out, ss_org_co_out, corr_ssdir_dd_co_out, corr_ssmag_dd_co_out