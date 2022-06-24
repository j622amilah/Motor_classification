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
from subfunctions.check_axes_assignmentPLOT import *
from subfunctions.cut_initial_trials import *
from subfunctions.findall import *
from subfunctions.main_preprocessing_steps import *
from subfunctions.make_a_properlist import *
from subfunctions.size import *
from subfunctions.standarization_notebadtrials import *
from subfunctions.saveSSQ import *
from subfunctions.check_axes_assignmentPLOT_final import *
from subfunctions.s3_calc_datadriven_speedstim_4pipeline import *

# Creating folders for image or data saving
import os



def s1_removeBADtrials_savedata(varr, plot_sub_trials, PCtype, plotORnot_ALL, plot_sub_trials_FINAL):

	if PCtype == 'Windows':
		filemarker = "\\"
	elif PCtype == 'Linux':
		filemarker = '/'
	
    # ------------------------------

	# Selecting a method of removing bad trials from the data
	# Saving the data per participant per experiment

	NUMmark = 0   #  an arbitrarily large number to denote a non-valid entry

	fs = 10 #  Original experimental sampling was at 250Hz, but data is downsampled to 10Hz
	ts = 1/fs

	mj_val = [0.1, 0.05, 0.01]

	tr_type_sub_exp = []

	corr_ssdir_dd_co_out = []
	corr_ssmag_dd_co_out = []
	tas_out = []
	ss_org_co_out = []

	# ------------------------------

	# 1) Load exp : put the experiment that you wish to run
	for exp in range(1):  # 0=rotation, 1=translation

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
			c = 18-1   # labeled (YA) - joystick movement
			
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
			
		
		
		datout_temp = []
		
		# ------------------------------
		
		# 2) Directional control orientation :
		# Convention 1 : (cab = cab_com - joystick), thus (cab = -joy)
		# (Proven by standardization test)
		dirC = 0
		
		# ------------------------------
		
		# 3) Deadzone margin : 0.1 (Proven by standardization test)
		marg_joy = 0.1

		# ------------------------------

		# 4) Load subjects
		subs = np.arange(len(varr['subjects']))
		
		exp_reject_cat_vec = []
		exp_acc_tr_per = []
		
		tr_type_sub = []
		
		for s in subs:
			print('s : ' + str(s))

			# ------------------------------
			# (1) Load data
			A = np.loadtxt("%s%s%s.txt" % (varr['data_path'], filemarker, varr['subjects'][s]))

			# print('Size of A matrix : ' + str(size(A)))     # result(row00=9445, col00=22)
			# ------------------------------
			
			
			# ------------------------------
			# There was confusion if yaw joystick direction was reversed
			yr = 0  # 0=keep the sign of yaw/UD joystick, 1=reverse the sign of yaw/UD joystick
			# ------------------------------
			
			
			# ------------------------------
			# a) Pre-process the data using the selected orax, dirC, and mj_val 
			starttrial_index, stoptrial_index, speed_stim_sign, speed_stim_org_sign, speed_stim_mag, speed_stim_org, tar_ang_speed_val_co, speed_stim_tas_sign, axis_out, axis_org, new3_ind_st, new3_ind_end, g_rej_vec, outJOY, outSIG, outSIGCOM, outNOISE, corr_axis_out, trialnum_org, time_org, FRT, good_tr = main_preprocessing_steps(varr, A, a, b, c, s, NUMmark, yr, plotORnot_ALL, filemarker)
			# ------------------------------


			# ------------------------------
			# Check if axes are assigned correctly to trials: PLOTTING
			# ------------------------------
			if plot_sub_trials == 1:
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
			# Check if axes are assigned correctly to trials: PLOTTING
			# All trials, it says the type of rejection on the plot.
			# ------------------------------
			if plot_sub_trials_FINAL == 1:
			    filename = 'images_cutfinal_%s' % (varr['which_exp'])
			    check_axes_assignmentPLOT_final(s, outJOY, outSIG, axis_out, varr, filename, time_org, g_rej_vec)
			# ------------------------------
			
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
			
			# Experimental matrix events
			e0 = speed_stim_mag[good_tr_fin]  # data-driven measured stimulus magnitude : take max of outSIG
			
			speed_stim_sign = np.array(speed_stim_sign)
			e1 = speed_stim_sign[good_tr_fin] # data-driven measured stimulus direction : take sign of slope of initial outSIG
			
			speed_stim_org_sign = np.array(speed_stim_org_sign)
			e2 = speed_stim_org_sign[good_tr_fin] # experimental matrix direction
			
			speed_stim_tas_sign = np.array(speed_stim_tas_sign)
			e3 = speed_stim_tas_sign[good_tr_fin] # experimental matrix direction
			
			speed_stim_org = np.array(speed_stim_org)
			e4 = speed_stim_org[good_tr_fin]  # experimental matrix stimulus magnitude and direction
			
			tar_ang_speed_val_co = np.array(tar_ang_speed_val_co)
			e5 = tar_ang_speed_val_co[good_tr_fin] # experimental matrix stimulus magnitude and direction
			
			axis_out = np.array(axis_out)
			e6 = axis_out[good_tr_fin]  # data-driven measured axis
			
			axis_org = np.array(axis_org)
			e7 = axis_org[good_tr_fin] # experimental matrix axis

			# correlation between axis value in experimental matrix in comparison to axis measured from data via start-stop index
			e8 = corr_axis_out

			# start-stop trial cut index
			new3_ind_st = np.array(new3_ind_st)
			e9 = new3_ind_st[good_tr_fin]
			
			new3_ind_end = np.array(new3_ind_end)
			e10 = new3_ind_end[good_tr_fin]

			# Parameters with 3 axis
			e11 = []
			e12 = []
			e13 = []
			e14 = []
			e15 = []
			for tr in good_tr_fin:
			    e11 = e11 + [outSIGCOM[tr]]  # a list (num of dp, 3) per trial
			    e12 = e12 + [outSIG[tr]]  # a list (num of dp, 3) per trial
			    e13 = e13 + [outJOY[tr]]  # a list (num of dp, 3) per trial
			    e14 = e14 + [outNOISE[tr]]  # a list (num of dp, 3) per trial
			    e15 = e15 + [time_org[tr]]  # a list (num of dp, 1) per trial
			
			trialnum_org = np.array(trialnum_org)
			e16 = trialnum_org[good_tr_fin]
			
			# Each [] is a 4x1 vector=[nausee, oculo_moteur, disorientation, sickness]
			e17 = saveSSQ(s, varr['which_exp']) # SSQ [[before], [after], [diff=before-after]]
			
			e18 = FRT[good_tr_fin]
			
			subdat = e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18
			
			datout_temp.append(subdat)
			
		# end of s
		
		dothis = 0
		if dothis == 1:
			# ------------------------------
			# Correlation study to determine which speed stim measure is most reliable
			# We correlate directional and magnitude speed measures with each other, the measures that are
			# most similar to each other are likely the correct speed stimuli eventhough there were recording delays 
			# for this measure.
			
			# Speed stim was the most unreliably saved measure to file, the output value to the .txt file was delayed with
			# respect to the cabin and joystick values for certain participants, due to the real-time functioning of 
			# the simulator system. The correlation analysis is a way to numerically determine the speed stim for all 
			# participant data files, despite the simulator delays.
			# ------------------------------
			# e2, e4 # Way 0 : speed_stim_org : experimental matrix stimulus magnitude and direction
			
			# e5, e3 # Way 1 : tar_ang_speed_val_co : experimental matrix stimulus magnitude and direction
			
			# Way 2 : Global : to calculate speed stim magnitude and direction : Plot all data and perform kmeans 1D for two groups (sub, sup) 
			speed_stim_dd, slope_per_exp = s3_calc_datadriven_speedstim_4pipeline(datout_temp)   # data-driven stimulus magnitude and direction 
			
			# e0, e1, Way 3 : Per trial : data-driven using the initial slope of each trial to get the direction. Magnitude was designated by a 
			# threshold value per trial with respect to group min and max values.
			
			allsubmag = []
			allsubdir = []
			for s in subs:
				# Both magnitude & direction
				speed_stim_org = e4[s]
				tar_ang_speed_val_co = e5[s]
				
				# Magnitude
				speed_stim_mag = e0[s]   # data-driven measured stimulus magnitude : slope per trial
				speed_stim_dd_mag = transform_ss2int_persub(varr, speed_stim_dd)    # data-driven measured stimulus magnitude : kmeans (BEST)
				speed_stim_org_mag = transform_ss2int_persub(varr, speed_stim_org) 
				speed_stim_tas_mag = transform_ss2int_persub(varr, tar_ang_speed_val_co)
				
				# Direction
				speed_stim_sign = e1[s]  # data-driven measured stimulus magnitude : slope per trial
				speed_stim_dd_sign = np.sign(slope_per_exp[s]) # data-driven measured stimulus magnitude : kmeans (BEST)
				speed_stim_org_sign = e2[s] 
				speed_stim_tas_sign = e3[s]
				
				q = [speed_stim_mag, speed_stim_dd_mag, speed_stim_org_mag, speed_stim_tas_mag]
				qdir = [speed_stim_sign, speed_stim_dd_sign, speed_stim_org_sign, speed_stim_tas_sign]
				mat = np.zeros((len(q),len(q)))
				matdir = np.zeros((len(q),len(q)))
				for ind1, vec1 in enumerate(q):
					for ind2, vec2 in enumerate(q):
						corrvals = np.corrcoef(vec1, vec2) # outputs a correlation matrix
						mat[ind1:ind1+1,ind2:ind2+1] = corrvals[0,1]
						corrvals_dir = np.corrcoef(qdir[ind1], qdir[ind2]) # outputs a correlation matrix
						matdir[ind1:ind1+1,ind2:ind2+1] = corrvals_dir[0,1]
				out = np.triu(mat,1)
				out = out.flatten() # ss/ssdd, ss/ssorg, ss/sstas, ssdd/ssorg, ssdd/sstas, ssorg/sstas
				out_mag = [i for i in out if i != 0]# ne prends pas des valeurs 0
				out = np.triu(matdir,1)
				out = out.flatten() # ss/ssdd, ss/ssorg, ss/sstas, ssdd/ssorg, ssdd/sstas, ssorg/sstas
				out_dir = [i for i in out if i != 0]# ne prends pas des valeurs 0
				
				allsubmag.append(out_mag)
				allsubdir.append(out_dir)
			
			# ------------------------------
			# Plot results for selection of prefered speed stim
			# ------------------------------
			# df_tmpmag = pd.DataFrame(allsubmag).T
			# df_tmpdir = pd.DataFrame(allsubdir).T # want columns to be category
			
			
			slope_per_exp[s]
			# ------------------------------
			# Refold all the data into a new condensed dataout matrix : including data-driven global
			# ------------------------------
			dataout = []
			for s in subs:
			
				e0 = datout_temp[s][0]   # speed_stim_mag : maximum cabin value (ambiguous value : max value could be due to joystick movement)
				e1 = datout_temp[s][1]   # speed_stim_sign : sign of initial cabin slope value
				
				# We calculate kmeans of the initial cabin slope values and make two groups (sub, sup)
				speed_stim_DD = np.sign(slope_per_exp[s])*speed_stim_dd[s]    # 1=sub, 2=sup
				e2 = [np.round(int(x), 0) for x in speed_stim_DD]
				
				e3 = datout_temp[s][4]   # speed_stim_org
				e4 = datout_temp[s][5]   # tar_ang_speed_val_co
				
				e5 = datout_temp[s][6]  # axis_out
				e6 = datout_temp[s][7]  # axis_org
				e7 = datout_temp[s][8]  # corr_axis_out
				e8 = datout_temp[s][9]  # new3_ind_st
				e9 = datout_temp[s][10]  # new3_ind_end
				e10 = datout_temp[s][11]  # outSIGCOM   
				e11 = datout_temp[s][12]  # outSIG
				e12 = datout_temp[s][13]  # outJOY
				e13 = datout_temp[s][14]  # outNOISE
				e14 = datout_temp[s][15]  # time_org
				e15 = datout_temp[s][16]  # trialnum_org
				e16 = datout_temp[s][17]  # SSQ
				e17 = datout_temp[s][18]  # FRT
				
				subdat = e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17

				dataout.append(subdat)
			# ------------------------------
			
			
			# ------------------------------
			# Save data matrices to file per experiment
			# ------------------------------
			file_name = "%s%s%sdat.pkl" % (varr['main_path2'], filemarker, varr['which_exp'])
			open_file = open(file_name, "wb")
			pickle.dump(datout, open_file)
			del datout, datout_temp
			open_file.close()
			# ------------------------------
		        
            
		    
		    
	return datout_temp


	
# ------------------------------	
	
def transform_ss2int_persub(varr, ss_persub):

	outlier_val = 0
	sup_val = 2
	sub_val = 1

	ss_int_persub

	for tr in range(len(ss_persub)):
		
		# Turn target angular speed values into 0, 1, or outlier_val
		if varr['which_exp'] == 'rot':
			if abs(ss_persub[tr]) == 1.25 or abs(ss_persub[tr]) == 1.5:
				ss_int_persub[tr] = sup_val   # sup
			elif abs(ss_persub[tr]) == 0.5:
				ss_int_persub[tr] = sub_val   # sub
			else:
				ss_int_persub[tr] = outlier_val    # outlier
				
		elif varr['which_exp'] == 'trans':
			if abs(ss_persub[tr]) == 15 or abs(ss_persub[tr]) == 17.5:
				ss_int_persub[tr] = sup_val   # sup
			elif abs(ss_persub[tr]) == 3.75:
				ss_int_persub[tr] = sub_val   # sub
			else:
				ss_int_persub[tr] = outlier_val    # outlier
		

	return ss_int_persub
	
# ------------------------------
	
def plot_axis_correlation(plotORnot, corr_axis_out_exp):

	# Ploting axis and speed correlation of experimental matrix and data-driven
	# Across subjects
	if plotORnot == 1:
		fig = go.Figure()
		config = dict({'scrollZoom': True, 'displayModeBar': True, 'editable': True})
		xxORG = list(range(len(corr_axis_out_exp)))
		fig.add_trace(go.Scatter(x=xxORG, y=corr_axis_out_exp, name='corr_axis_out_exp', 
		                         line = dict(color='red', width=2, dash='dash'), showlegend=True))
		fig.update_layout(title='Correlation of axis experimental matrix and axis data-driven (across trials) per subject', xaxis_title='subjects', yaxis_title='correlation (%s): axis' % (varr['which_exp']))
		fig.show(config=config)
		fig.write_image("%s%scorr_axis_out_exp_%s.png" % (varr['main_path2'], filemarker, varr['which_exp']))
		
	return


