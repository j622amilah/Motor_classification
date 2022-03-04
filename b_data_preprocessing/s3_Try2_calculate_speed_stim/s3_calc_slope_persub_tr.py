<<<<<<< HEAD
import numpy as np

# Personal python functions
import sys
#sys.path.insert(1, '/home/jamilah/Documents/Sourceforge_analysis_PROJECTS/Motor_classification/subfunctions')
sys.path.insert(1, 'C:\\Users\\jamilah\\Documents\\Sourceforge_analysis_PROJECTS\\Motor_classification\\subfunctions')

from subfunctions.make_a_properlist import *
from subfunctions.detect_sig_change_wrt_baseline import *




def calc_slope_persub_tr(dat):

    totsub_slope_val = []
    totsub_speed_stim_em = []
    
    # 2) Load subjects
    subs = range(len(dat))
    subs = make_a_properlist(subs)

    for s in subs:
        num_of_tr = len(dat[s][0])

        speed_stim_sign_dd = dat[s][0]         # 0 : speed_stim_sign
        speed_stim_mag_dd = dat[s][1]          # 1 : speed_stim_mag
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
        speed_stim_em_bin = []
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
            
            # Convert experimental stimulus values to 0 or 1
            if abs(np.round(speed_stim_em[tr],2)) == 1.25 or abs(np.round(speed_stim_em[tr],2)) >= 15.0:
                speed_stim_em_bin = speed_stim_em_bin + [1]
            elif abs(np.round(speed_stim_em[tr],2)) == 0.5 or abs(np.round(speed_stim_em[tr],2)) == 3.75:
                speed_stim_em_bin = speed_stim_em_bin + [0]
            else:  # zero stim is considered an outlier
                speed_stim_em_bin = speed_stim_em_bin + [100]  
            speed_stim_em_bin = make_a_properlist(speed_stim_em_bin)

        # ------------------------------
        
        slope_val = make_a_properlist(slope_val)
        
        # Per subject
        totsub_slope_val = totsub_slope_val + [slope_val]
        
        totsub_speed_stim_em = totsub_speed_stim_em + [speed_stim_em_bin]
        
        
=======
import numpy as np

# Personal python functions
import sys
#sys.path.insert(1, '/home/jamilah/Documents/Sourceforge_analysis_PROJECTS/Motor_classification/subfunctions')
sys.path.insert(1, 'C:\\Users\\jamilah\\Documents\\Sourceforge_analysis_PROJECTS\\Motor_classification\\subfunctions')

from subfunctions.make_a_properlist import *
from subfunctions.detect_sig_change_wrt_baseline import *




def calc_slope_persub_tr(dat):

    totsub_slope_val = []
    totsub_speed_stim_em = []
    
    # 2) Load subjects
    subs = range(len(dat))
    subs = make_a_properlist(subs)

    for s in subs:
        num_of_tr = len(dat[s][0])

        speed_stim_sign_dd = dat[s][0]         # 0 : speed_stim_sign
        speed_stim_mag_dd = dat[s][1]          # 1 : speed_stim_mag
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
        speed_stim_em_bin = []
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
            
            # Convert experimental stimulus values to 0 or 1
            if abs(np.round(speed_stim_em[tr],2)) == 1.25 or abs(np.round(speed_stim_em[tr],2)) >= 15.0:
                speed_stim_em_bin = speed_stim_em_bin + [1]
            elif abs(np.round(speed_stim_em[tr],2)) == 0.5 or abs(np.round(speed_stim_em[tr],2)) == 3.75:
                speed_stim_em_bin = speed_stim_em_bin + [0]
            else:  # zero stim is considered an outlier
                speed_stim_em_bin = speed_stim_em_bin + [100]  
            speed_stim_em_bin = make_a_properlist(speed_stim_em_bin)

        # ------------------------------
        
        slope_val = make_a_properlist(slope_val)
        
        # Per subject
        totsub_slope_val = totsub_slope_val + [slope_val]
        
        totsub_speed_stim_em = totsub_speed_stim_em + [speed_stim_em_bin]
        
        
>>>>>>> 94b06cd4776edc5e6880e69ca0d1eefbe92d257c
    return totsub_slope_val, totsub_speed_stim_em