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



#def rot_main_preprocessing_steps(varr, temp, A, s, NUMmark):
def rot_main_preprocessing_steps(varr, A, a, b, c, s, NUMmark):
    
    
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
    print('Axis detection')
    
    # Way 1: Experimental collected data axis detection
    trialnum0 = np.zeros((tr_num))
    axis0 = np.zeros((tr_num))
    speed_stim0 = np.zeros((tr_num))
    for q in range(tr_num):
        st = int(new3_ind_st[q])
        stp = int(new3_ind_end[q])
        trialnum0[q] = mode(A[st:stp, 1])   # trial number
        axis0[q:q+1] = mode(A[st:stp, 14])  # (1:roll, 2:pitch, 3:yaw)
        speed_stim0[q:q+1] = mode(A[st:stp, 19])   # ([1.2500; 0.5000; 0; -0.5000; -1.2500]

	
    # :::::::::::::::::::
    # Confirmation check
    # :::::::::::::::::::
    # Way 2: Data-driven axis detection

    for tr in range(len(new3_ind_st)):
        # Same method for FB, LR
        # a) sum the first 1/4 of each cabin movement signal for each axis : justification is that the first part of the signal is likely pure stimulus without participant influence
		
        # Calculate the sum of the two signals at the beginning and determine which is larger.
        tr_ind = np.multiply(range(int(new3_ind_st[tr]), int(new3_ind_end[tr])), 1)
        portion = new2_ind_st[tr] + len(tr_ind)/4
		
        starter = int(new3_ind_end[tr])
        ender = int(np.round(portion) - new2_ind_st[tr])
        
        for ax in range(3):
            axis_verify1[tr, ax] = max(abs( outSIG[tr][starter:ender, ax] ))
            axis_verify2[tr, ax] = abs(sum( outSIG[tr][starter:ender, ax] ))
	

    val1 = max(axis_verify1)
	[val2, ax_dd2] = max(axis_verify2)
	
    # :::::::::::::::::::
    # Confirmation check to see how similar data-driven axis_out is to the experimental matrix axis0
    # corr (x,y) = cov (x,y) / (std (x) * std (y))
    # Pearson correlation coefficient
	corr_out1 = np.corrcoef(axis0, ax_dd1);
	corr_out2 = np.corrcoef(axis0, ax_dd2);
	
    # ------------------------------
	plotORnot = 0;  # 1 = show figures, 0 = do not show figures
	
	if plotORnot == 1
	    # Only save a figure if it does not exist in main_path
		if exist(sprintf('corr_rot_sub%d.png', s)) ~= 2
			figure('Visible', 'on')
			plot(ax_dd1, 'b')
			hold on
			plot(ax_dd2, 'g')
			plot(axis0, 'r')
			legend({'data max', 'data sum', 'exp matrix'}, "location", "northeastoutside")
			title(sprintf('sub %d, axis labeling (data-driven vs exp label): max corr=%f, sum corr=%f', s, corr_out1, corr_out2), 'FontSize', 17)
			set(gcf, 'units', 'normalized', 'outerposition', [0 0 1 1])
			set(gcf,'PaperPositionMode','auto')
			set(gcf,'PaperPosition', [1 1 28 19]);    # change the paper position instead of the position
			cd(varr.main_path)
			print(gcf, '-dpng', sprintf('corr_rot_sub%d', s))
			close all
		end
	end
    # ------------------------------
	
	cd([varr.main_path, 'a1_1_subfunctions'])
	
    # ------------------------------
    # Check if axes are assigned correctly to trials: Plotting
    # ------------------------------
	plotORnot = 0;  % 1 = show figures, 0 = do not show figures
	
	if plotORnot == 1
		cd([varr.main_path, 'a1_1_subfunctions'])
		check_axes_assignmentPLOT(s, trialnum0, new3_ind_st, new3_ind_end, temp, axis0, varr);
	end % end of if plotORnot == 1
    # ------------------------------
	

    # ------------------------------
    # (3) Detect bad trials (robot stopped, erroneous movement)
    # ------------------------------
    # fprintf('a1_1_rot_errordetect_trialselection : Check which trials are bad trials\n')
	
	g_rej_vec = zeros(length(axis0), 1);    # global reject vector
	
	generic_ind_st = new3_ind_st;
	generic_ind_end = new3_ind_end;
	
    # :::::::::::::::::::
    # fprintf('a1_1_rot_errordetect_trialselection : Detect when robot stopped\n')
	
    # NOTE : The data was saved for the trial ONLY (No reinitialization) for rotation
    # So there will be jumps to zero from the last data point in each trial.
    # So no need to detect jumps in data due to robot stop - if the robot stopped we would have a trial that is 
    # too short than average and remove it during horizontally short trial removal
	
    # :::::::::::::::::::
	
	
    # :::::::::::::::::::
    # Remove zero stimulation trials (vertically short data)
    # :::::::::::::::::::
    # fprintf('a1_1_rot_errordetect_trialselection : Detect vertically short RO, PI, YA\n')
	
	cut_trial_ver_short = [];
	height_cutoff = 0.5;    # a value close to zero 
	d = 1;
	for i = 1:length(generic_ind_st)
		if max(abs(temp.(sprintf('cpos%s', varr.anom{axis0(i,1)}))(generic_ind_st(i,1):generic_ind_end(i,1)) )) < height_cutoff
			cut_trial_ver_short(d,1) = i;
			d = d + 1;
		end
	end
	g_rej_vec(cut_trial_ver_short,1) = 30;
	
    # cut_trial_ver_short
    # :::::::::::::::::::
	
    # :::::::::::::::::::
    # Remove short trials (horizontally short data)
    # Justification: In rotation, the data consists of detection (20secs) and control (15secs) so the maximum length of a trial is 35 seconds.  The data is sampled at 10Hz, so that is 350 data points per trial maximum.  If detection time is almost 0 seconds (fast detection), then the shortest a trial should be is 15 seconds.  We try to be lenient and account for delays and set the data cut off at 12 seconds.
    # :::::::::::::::::::
    # fprintf('a1_1_rot_errordetect_trialselection : Detect horizontally short trials\n')
	
    # ONLY true for ROTATION because there is no reinitialization:
    # First refine STOP point with respect to the time vector - The stop point should be at the maximum time height_cutoff
	for i = 1:length(generic_ind_end)
		[t, inx] = max( A(generic_ind_st(i,1):generic_ind_end(i,1), 2) );
		pt_diff = length(A(generic_ind_st(i,1):generic_ind_end(i,1), 2)) - inx;
		generic_ind_end_temp(i,1) = generic_ind_end(i,1) - pt_diff;
	end
    # Reassign generic_ind_end
	clear generic_ind_end t inx pt_diff
	generic_ind_end = generic_ind_end_temp;
	clear generic_ind_end_temp
	
    # Now, check the time length of each trial
	width_cutoff = 12;    # cut data with time greater than 12 seconds
	c = 1;
	cut_trial_hor_short = [];
	for i = 1:length(generic_ind_st)
		tr_t_diff(i,1) =  A(generic_ind_end(i,1), 2) - A(generic_ind_st(i,1), 2);
		dp_diff(i,1) = generic_ind_end(i,1) - generic_ind_st(i,1);
		
		if tr_t_diff(i,1) < width_cutoff
			cut_trial_hor_short(c,1) = i;
			c = c + 1;
		
	
	g_rej_vec(cut_trial_hor_short,1) = 40;
	
	clear tr_t_diff dp_diff
	
    # cut_trial_hor_short
    # :::::::::::::::::::
    # ------------------------------
	
	
    # ------------------------------
    # (4) Remove the bad trials from trials
    # ------------------------------
    # fprintf('a1_1_rot_errordetect_trialselection : Remove the bad trials from trials\n')
	out1 = sort([cut_trial_ver_short; cut_trial_hor_short]);
	[out2, I, J] = unique(out1);
	
    # Remove the bad trials 
	longvec = (1:length(new3_ind_st))';
	shortvec = out2;
	cd([varr.sumf_path, 'get_missing_vector_entries'])
	[tr_from_short_not_in_long, tr_from_long_not_in_short] = get_missing_vector(shortvec, longvec);
	cd(varr.main_path)
	good_tr = tr_from_long_not_in_short;
	
    # Keep vectors the same original number of trials, put NUMmark for trials that we cut
	cd([varr.sumf_path, 'make_new_vec_w_index_vec'])
	way = 2;  % 1 is a slower way (for loop and if statement), 2 is faster (find function)
	new4_ind_st = make_new_vec_w_index_vec(new3_ind_st, good_tr, NUMmark, way);
	new4_ind_end = make_new_vec_w_index_vec(new3_ind_end, good_tr, NUMmark, way);
	axis1 = make_new_vec_w_index_vec(axis0, good_tr, NUMmark, way);
	speed_stim_org = make_new_vec_w_index_vec(speed_stim0, good_tr, NUMmark, way);
	trialnum1 = make_new_vec_w_index_vec(trialnum0, good_tr, NUMmark, way);
	cd(varr.main_path)
	
    # ------------------------------
	
	
    # ------------------------------
	plotORnot = 0;  % 1 = show figures, 0 = do not show figures
	
	if plotORnot == 1
		for i = 1:length(good_tr)
			tr = good_tr(i,1);
			xxORG = new4_ind_st(tr,1):new4_ind_end(tr,1);
			figure
			plot(xxORG, temp.cposRO(xxORG), '-b', 'LineWidth', 2)
			hold on
			plot(xxORG, temp.cposPI(xxORG), '-r', 'LineWidth', 2)
			plot(xxORG, temp.cposYA(xxORG), '-k', 'LineWidth', 2)
			
			a_str = varr.anom{axis1(tr,1),1};
			
			title(sprintf('sub=%d, tr=%d, axis:%s, stim:%f', s, tr, a_str, speed_stim_org(tr,1)), 'FontSize', 20)
			ylabel('Movement')
			legend({"cab RO", "cab PI", "cab YA"}, "location", "northeastoutside")
			
			pause();
		end
	end
    # ------------------------------
	
	

    # ------------------------------
    # (5) Refine start-stop index for only stimulus period
    # ------------------------------
    # fprintf('a1_1_rot_errordetect_trialselection : Refine start-stop index for only stimulus period\n')
	
	Len = length(axis1);
	speed_stim_sign = zeros(Len, 1);
	speed_stim_mag = zeros(Len, 1);
	starttrial_index = zeros(Len, 1);
	stoptrial_index = zeros(Len, 1);
	
    # Put cabin data into cell arrays based on the given start-stop index
	ind_st = new4_ind_st;
	ind_end = new4_ind_end;
	cd([varr.main_path, 'a1_1_subfunctions'])
	[outJOY, outSIG, outSIGCOM] = full_sig_2_cell(temp, ind_st, ind_end, varr);
	
	
	plotORnot = 0;  # 1 = show figures, 0 = do not show figures
	plotORnot_derv = 0;  # 1 = show figures, 0 = do not show figures
	marg = 5;  # margin around signal baseline for zonemax area
	axis_val = axis1
	cd([varr.main_path, 'a1_1_subfunctions'])
	[starttrial_index, stoptrial_index, speed_stim_sign, speed_stim_mag] = process_index_for_trials(s, good_tr, outSIG, marg, varr, starttrial_index, stoptrial_index, speed_stim_sign, speed_stim_mag, plotORnot, plotORnot_derv, axis_val);
	
    # ------------------------------
