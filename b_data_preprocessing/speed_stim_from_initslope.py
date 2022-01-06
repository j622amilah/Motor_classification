import numpy as np

# Personal python functions
import sys
#sys.path.insert(1, '/home/jamilah/Documents/Sourceforge_analysis_PROJECTS/Motor_classification/b_data_preprocessing')
sys.path.insert(1, 'C:\\Users\\jamilah\\Documents\\Sourceforge_analysis_PROJECTS\\Motor_classification\\b_data_preprocessing')

from subfunctions.make_a_properlist import *


# PURPOSE : calculates speed stim categories from initial slope data, using the max and min boundary thresholds.

def speed_stim_from_initslope(max_clu_0, min_clu_0, max_clu_1, min_clu_1, totsub_slope_ORG):

    # sup trial = trials with initial slope points between min_clu_1_OR_0.1 and max_clu_1
    # sub trial = trials with initial slope points between min_clu_0_OR_0.1 and max_clu_0

    sub_range = [min_clu_0, max_clu_0]
    sup_range = [min_clu_1, max_clu_1]

    max_val = sup_range[1]
    mid_val = (sup_range[0] + sub_range[1])/2
    min_val = sub_range[0]

    # ------------------------------
    # Divide the data into sub and sup based on the margin boundaries : 
    # ------------------------------
    outlier_val = 0
    sup_val = 2
    sub_val = 1

    speed_stim_per_exp = []

    # print('len(totsub_slope_ORG) : ' + str(len(totsub_slope_ORG)))

    for s in range(len(totsub_slope_ORG)):  # loop over the number of subjects and label each trial sup=1,  sub=0, or outlier
        
        num_of_tr = len(totsub_slope_ORG[s])
        
        stim_speed_pertr = []
        
        for tr in range(num_of_tr):
            if np.abs(totsub_slope_ORG[s][tr]) < 0.001:  # zero stim is considered an outlier
                sstim = outlier_val   # outlier
            else:
                if (np.abs(totsub_slope_ORG[s][tr]) > mid_val) and (np.abs(totsub_slope_ORG[s][tr]) < max_val):
                    sstim = sup_val   # sup
                elif (np.abs(totsub_slope_ORG[s][tr]) < mid_val) and (np.abs(totsub_slope_ORG[s][tr]) > min_val):
                    # print('sub detected : ' + str(np.abs(totsub_slope_ORG[s][tr])))
                    sstim = sub_val   # sub
                else:
                    sstim = outlier_val   # outlier: vaules above the max_clu_1 line and below the min_clu_0 line
            
            stim_speed_pertr = stim_speed_pertr + [sstim]
            
        stim_speed_pertr = make_a_properlist(stim_speed_pertr)
        speed_stim_per_exp = speed_stim_per_exp + [stim_speed_pertr]  # per subject
        # print('s : ' + str(s) + ', ' + 'speed_stim_per_exp : ' + str(speed_stim_per_exp))
    # ------------------------------


    return speed_stim_per_exp