<<<<<<< HEAD
import numpy as np

from scipy.signal import lsim

# Plotting
import plotly.graph_objects as go

# Data saving
import pickle

# Import math Library
import math 

# Filtering
from scipy import signal

# Personal python functions
import sys
# sys.path.insert(1, '/home/jamilah/Documents/Sourceforge_analysis_PROJECTS/Motor_classification/subfunctions')
sys.path.insert(1, 'C:\\Users\\jamilah\\Documents\\Sourceforge_analysis_PROJECTS\\Motor_classification\\subfunctions')

from subfunctions.numderiv import *
from subfunctions.make_a_properlist import *
from subfunctions.detect_sig_change_wrt_baseline import *


# ------------------------------
# Idea 3 (control diagram): directly calculate the stim_ramp from the outSIG and outJOY. 
# - stim_ramp = F(s)speed_stim
# - at junction 1: outSIG + stim_ramp = cab
# - at junction 2: cab + joy_gain*outJOY = u
# - outSIGCOM = H(s)*u
# 
# Problem : Not correct, stim_ramp contains joystick motion.  
# Need to recover the almost the exact block diagram of the system 
# ------------------------------


def Try3_get_stim_speed():

    varr = {}
    varr['main_path'] = "C:\\Users\\jamilah\\Documents\\Sourceforge_analysis_PROJECTS\\Motor_classification"  # Windows
    #varr['main_path'] = "/home/jamilah/Documents/Sourceforge_analysis_PROJECTS/Motor_classification"

    NUMmark = 0   #  an arbitraily large number to denote a non-valid entry

    fs = 10 #  Original experimental sampling was at 250Hz, but data is downsampled to 10Hz
    ts = 1/fs

    mj_val = [0.1, 0.05, 0.01]






    for exp in range(1):  # 0=rotation, 1=translation
        if exp == 0:
            # Rotational data - 18 participants
            varr['which_exp'] = 'rot'
            varr['vals'] = 0.5, 1.25, 0

            # Load data experimental preprocessed data matrix
            file_name = "rotdat.pkl"
            open_file = open(file_name, "rb")
            dat = pickle.load(open_file)
            open_file.close()
            
            joy_gain = 10  # rotation
                
        elif exp == 1:
            # Translational data - 14 participants
            varr['which_exp'] = 'trans'
            varr['vals'] = 3.75, 15, 0
            
            # Load data experimental preprocessed data matrix
            file_name = "transdat.pkl"
            open_file = open(file_name, "rb")
            dat = pickle.load(open_file)
            open_file.close()
            
            joy_gain = 30  # what I confirmed before, but look again
        
        
        sign_slope_tr_subs = []
        speed_stim_tr_subs = []
        
        
        # 2) Load subjects
        subs = range(1)
        # subs = range(len(dat))
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
            
            
            sign_slope_tr = []
            speed_stim_tr = []
            
            
            for tr in range(num_of_tr):
                stim_ramp0 = []
                stim_ramp1 = []
                stim_ramp2 = []
                speed_stim = []
                
                
                for ax in range(3):
                    # Robotic movement system 2nd order transfer function
                    T = 4
                    a = 1   # 2nd order denomenator
                    b = (3.6*math.pi)/T  # 1st order denomenator
                    c = math.pi/(T*0.9)  # 0th order denomenator
                    d = 1  # numerator
                    
                    # Way 1 : Include the entire system to solve for stim_ramp 

                    # Writing out the system equations
                    # stim_ramp = F(s)speed_stim

                    # y(t) = outSIGCOM(t)
                    # u(t) = [stim_ramp(t) + outSIG(t)] + outJOY(t)

                    # And, the robotic movement tf in time domain is: a*y_ddot(t) + b*y_dot(t) + c*y(t) = d*u(t)
                    # Rewriting, let X = a*y_ddot(t) + b*y_dot(t) + c*y(t).  
                    # So, X = d*u(t). Then plug in u(t), such that X = d*[stim_ramp(t) + outSIG(t)] + d*outJOY(t)

                    # ------------------------------
                    # Way 1 : wrong
                    # [1] We want to solve for stim_ramp
                    # (X - d*outJOY(t)) - d*outSIG(t) = d*stim_ramp(t)
                    # ss(t) = ((1/d)*X - joy_gain*outJOY(t)) - cab_gain*outSIG(t)
                    
                    sig = outSIGCOM[tr][:,ax]
                    t = time[tr]
                    
                    x1 = a*np.array(numderiv(numderiv(sig, t), t))
                    x2 = b*np.array(numderiv(sig, t))
                    x3 = c*sig
                    X = x1 + x2 + x3
                    stim_ramp0 = stim_ramp0 + [((1/d)*X - joy_gain*outJOY[tr][:,ax]) - outSIG[tr][:,ax]]
                    # ------------------------------
                    
                    
                    # ------------------------------
                    # Way 2 : mathematically better - solving for sr in time domain - open loop
                    q = np.ones((len(outSIG[tr][:,ax])))
                    sr = a + b + c - d*outSIG[tr][:,ax]*(1/q) + outSIG[tr][:,ax] - joy_gain*outJOY[tr][:,ax]
                    
                    
                    # ------------------------------
                    
                    # great point 
                    
                    # I may likely NOT have the correct system even if I write the correct robot
                    # transfer function, because of delays and filtering.  I may be more successful
                    # if I do a 'grid search' across parameters and calculate sr2
                    # a = 1   should likely not change the dynamics
                    # b and c will change the response dynamics
                    
                    # sr_bc = []
                    # bc_label = []
                    # for b in range(1, 3):
                    #    for c in range(1, 3):
                    #         bc_lab = [b, c]
                    #         # ------------------------------
                    #         # Way 3 : closed loop - assuming Human_system=1
                    #         print('b : ' + str(b))
                    #         num = [a, b, c-2*d]
                    #         den = [a, b, c]
                    #           u = joy_gain*outJOY[tr][:,ax]
                    # 
                    #         stim_ramp_t, sr2, xout = lsim((num, den), U=u, T=time[tr])
                    #         sr_bc = sr_bc + [sr2]
                    #         
                    #         bc_label = bc_label + [bc_lab]
                            
                            
                    sr_bc = []
                    bc_label = []
                    jg_vals = [10]
                    for jg in jg_vals:
                        bc_lab = jg
                        # ------------------------------
                        # Way 3 : closed loop - assuming Human_system=1
                        num = [a, b, c-2*d]
                        den = [a, b, c]
                        
                        u = jg*outJOY[tr][:,ax]
                        
                        # Discrete time: (model was unstable)
                        # dt = 1/10  # originally collected at 1/252, but downsampled to 1/10
                        # tf = (num, den, dt)
                        # stim_ramp_t, sr2 = signal.dlsim((num, den, dt), u, t=time[tr])
                        
                        # Continuous time: 
                        stim_ramp_t, sr2, xout = lsim((num, den), U=u, T=time[tr])
                        
                        # sr2 = make_a_properlist(sr2)
                        # print('sr2' + str(sr2))
                        
                        
                        sr_bc = sr_bc + [sr2]
                        
                        # Determining speed_stim by the initial rate of change of "estimated stim_ramp"
                        if ax == axis_out[tr]:
                            
                            # Baseline shift sr2 to zero
                            sr2 = sr2 - sr2[0]
                            
                            # Filter
                            n = 4   # filter order
                            fs = 250 # data sampling frequency (Hz)
                            fc = 10  # Cut-off frequency of the filter
                            w = fc / (fs / 2) # Normalize the frequency
                            b, a = signal.butter(n, w, 'low')  # 3rd order
                            sr2 = signal.filtfilt(b, a, sr2)
                            
                            if varr['which_exp'] == 'rot':
                                tau = 20  # it should have been 20 second rise time
                                sup = 1.25  # angle/sec
                                sub = 0.5  # angle/sec
                                
                                marg_val = sub # make it the sub boundary
                                dpOFsig_in_zone, indexOFsig_in_zone, dp_sign_not_in_zone, indexOFsig_not_in_zone = detect_sig_change_wrt_baseline(sr2, 0, marg_val)

                                # So, if sub boundary is found, we count the number of data pts it took from zero
                                # to reach the sub boundary.  The more data pts counted it is sub because the rate
                                # of motion is slower than in sup.  
                                if not indexOFsig_not_in_zone.any():
                                    # could be empty if there is no motion
                                    initial_move_ind = 0
                                    inital_st_of_move_ind = 0
                                    dpts_2_do_subrate = 0
                                    initial_slope_stim_ramp = 0
                                    sign_slope = 0
                                    diff_sub = 0
                                else:
                                    initial_move_ind = indexOFsig_not_in_zone[0]
                                
                                    marg_val = 0.07 # make it really close to zero, but a bit bigger
                                    dpOFsig_in_zone, indexOFsig_in_zone, dp_sign_not_in_zone, indexOFsig_not_in_zone = detect_sig_change_wrt_baseline(sr2, 0, marg_val)
                                    inital_st_of_move_ind = indexOFsig_not_in_zone[0]
                                    # the initial start point before motion may not be at 0,
                                    # there could be a long period of time at zero before movement

                                    dpts_2_do_subrate = initial_move_ind - inital_st_of_move_ind

                                    # -------------------------------------------
                                    st = inital_st_of_move_ind
                                    stp = initial_move_ind
                                    print('st : ' + str(st))
                                    print('stp : ' + str(stp))
                                    
                                    if st == stp:
                                        # Redo the initial start point
                                        marg_val = 0.001 # make it really close to zero, but a bit bigger
                                        dpOFsig_in_zone, indexOFsig_in_zone, dp_sign_not_in_zone, indexOFsig_not_in_zone = detect_sig_change_wrt_baseline(sr2, 0, marg_val)
                                        inital_st_of_move_ind = indexOFsig_not_in_zone[0]
                                        # the initial start point before motion may not be at 0,
                                        # there could be a long period of time at zero before movement

                                        dpts_2_do_subrate = initial_move_ind - inital_st_of_move_ind

                                    # -------------------------------------------
                                    st = inital_st_of_move_ind
                                    stp = initial_move_ind
                                    slope = np.polyfit(time[tr][st:stp], sr2[st:stp], 1)
                                    # print('slope : ' + str(slope))

                                    initial_slope_stim_ramp = slope[1]
                                    sign_slope = np.sign(initial_slope_stim_ramp)  # Check with speed_stim_sign
                                    # print('initial_slope_stim_ramp : ' + str(initial_slope_stim_ramp))
                                    # -------------------------------------------
                                
                                    # Is iniital_slope closer to sub
                                    diff_sub = abs(initial_slope_stim_ramp - sub)
                                    print('diff_sub : ' + str(diff_sub))
                                    diff_sup = abs(initial_slope_stim_ramp - sup)
                                    print('diff_sup : ' + str(diff_sup))
                                
                            elif varr['which_exp'] == 'trans':
                                tau = 8  # it should have been 8 second rise time
                                trans_sup = 15  # cm/sec
                                trans_sub = 3.75  # cm/sec
                                # is iniital_slope closer to trans_sub
                                diff_sub = abs(initial_slope_stim_ramp-trans_sub)
                                diff_sup = abs(initial_slope_stim_ramp-trans_sup)
                            
                            
                            if diff_sub == 0:
                                ss = 'no_move'
                            elif diff_sub < diff_sup:
                                ss = 'sub'
                            elif diff_sub > diff_sup:
                                ss = 'sup'
                        

                        bc_label = bc_label + [bc_lab]
                    
                    
                        # den =  [K/tau]
                        # num = [1, 1/tau]
                        # stim_ramp_t, ss, xout = lsim((num, den), U=sr2, T=time[tr])
                        # ss_bc = ss_bc + [ss]
                        
                    stim_ramp1 = stim_ramp1 + [sr]
                    stim_ramp2 = stim_ramp2 + [sr_bc]
                    # ------------------------------
                
                sign_slope_tr = sign_slope_tr + [sign_slope]
                speed_stim_tr = speed_stim_tr + [ss]
                
                bc_label = make_a_properlist(bc_label)
                print('bc_label : ' + str(bc_label))
                
                # --------------------
                fig = go.Figure()
                config = dict({'scrollZoom': True, 'displayModeBar': True, 'editable': True})

                xxORG = list(range(len(outJOY[tr][:,0])))
                
                # Plotting joystick
                fig.add_trace(go.Scatter(x=xxORG, y=outJOY[tr][:,axis_out[tr]], name='outJOY axstim : %s' % (varr['which_exp']), line = dict(color='red', width=2, dash='dash'), showlegend=True))
                # fig.add_trace(go.Scatter(x=xxORG, y=outJOY[tr][:,1], name='outJOY ax1 : %s' % (varr['which_exp']), line = dict(color='green', width=2, dash='dash'), showlegend=True))
                # fig.add_trace(go.Scatter(x=xxORG, y=outJOY[tr][:,2], name='outJOY ax2 : %s' % (varr['which_exp']), line = dict(color='blue', width=2, dash='dash'), showlegend=True))
                
                # Plotting actual cabin position
                fig.add_trace(go.Scatter(x=xxORG, y=outSIG[tr][:,axis_out[tr]], name='outSIG axstim : %s' % (varr['which_exp']), line = dict(color='black', width=2, dash='dash'), showlegend=True))
                
                # Open loop
                fig.add_trace(go.Scatter(x=xxORG, y=stim_ramp1[axis_out[tr]], name='openloop : %s' % (varr['which_exp']), line = dict(color='blue', width=2, dash='dash'), showlegend=True))
                # fig.add_trace(go.Scatter(x=xxORG, y=stim_ramp1[0], name='openloop : %s' % (varr['which_exp']), line = dict(color='red', width=2, dash='dash'), showlegend=True))
                # fig.add_trace(go.Scatter(x=xxORG, y=stim_ramp1[1], name='openloop : %s' % (varr['which_exp']), line = dict(color='green', width=2, dash='dash'), showlegend=True))
                # fig.add_trace(go.Scatter(x=xxORG, y=stim_ramp1[2], name='openloop : %s' % (varr['which_exp']), line = dict(color='blue', width=2, dash='dash'), showlegend=True))
                
                # Closed loop
                # for bc in range(len(bc_label)):
                #     fig.add_trace(go.Scatter(x=xxORG, y=stim_ramp2[0][bc], name='closedloop : %s, b=%2.1f, c=%2.1f' % (varr['which_exp'], bc_label[0][bc], bc_label[1][bc]), line = dict(color='red', width=2, dash='solid'), showlegend=True))
                #     fig.add_trace(go.Scatter(x=xxORG, y=stim_ramp2[1][bc], name='closedloop : %s, b=%2.1f, c=%2.1f' % (varr['which_exp'], bc_label[0][bc], bc_label[1][bc]), line = dict(color='green', width=2, dash='solid'), showlegend=True))
                #     fig.add_trace(go.Scatter(x=xxORG, y=stim_ramp2[2][bc], name='closedloop : %s, b=%2.1f, c=%2.1f' % (varr['which_exp'], bc_label[0][bc], bc_label[1][bc]), line = dict(color='blue', width=2, dash='solid'), showlegend=True))
                
                for bc in range(len(bc_label)):
                    fig.add_trace(go.Scatter(x=xxORG, y=stim_ramp2[axis_out[tr]][bc], name='closedloop : %s, jg=%2.1f' % (varr['which_exp'], bc_label[bc]), showlegend=True))
                    
                    dpt1 = inital_st_of_move_ind*np.ones((2))
                    dpt1 = [int(x) for x in dpt1] # convert to integer
                    fig.add_trace(go.Scatter(x=dpt1, y=stim_ramp2[axis_out[tr]][bc][dpt1], name='inital_st_of_move_ind', mode='markers', marker=dict(color='blue', size=10, symbol=5, line=dict(color='blue', width=0)), showlegend=True))
                    
                    dpt2 = initial_move_ind*np.ones((2))
                    dpt2 = [int(x) for x in dpt2] # convert to integer
                    fig.add_trace(go.Scatter(x=dpt2, y=stim_ramp2[axis_out[tr]][bc][dpt2], name='initial_move_ind', mode='markers', marker=dict(color='red', size=10, symbol=5, line=dict(color='red', width=0)), showlegend=True))
                    
                    # fig.add_trace(go.Scatter(x=xxORG, y=stim_ramp2[0][bc], name='way2 : %s, jg=%2.1f' % (varr['which_exp'], bc_label[bc]), showlegend=True))
                    # fig.add_trace(go.Scatter(x=xxORG, y=stim_ramp2[1][bc], name='way2 : %s, jg=%2.1f' % (varr['which_exp'], bc_label[bc]), showlegend=True))
                    # fig.add_trace(go.Scatter(x=xxORG, y=stim_ramp2[2][bc], name='way2 : %s, jg=%2.1f' % (varr['which_exp'], bc_label[bc]), showlegend=True))
                
                    # fig.add_trace(go.Scatter(x=xxORG, y=speed_stim[axis_out[tr]][bc], name='way2 : %s, jg=%2.1f' % (varr['which_exp'], bc_label[bc]), showlegend=True))
                
                fig.update_layout(title='stim_ramp : s : %d, tr : %d, stim_axis : %d, stim : %s, dpts : %d, slope : %2.1f' % (s, tr, axis_out[tr], ss, dpts_2_do_subrate, initial_slope_stim_ramp), xaxis_title='data points', yaxis_title='stim ramp')
                fig.show(config=config)
                # --------------------
        
        sign_slope_tr = make_a_properlist(sign_slope_tr)
        sign_slope_tr_subs = sign_slope_tr_subs + [sign_slope_tr]
        
        speed_stim_tr = make_a_properlist(speed_stim_tr)
        speed_stim_tr_subs = speed_stim_tr_subs + [speed_stim_tr]
            
        
        
=======
import numpy as np

from scipy.signal import lsim

# Plotting
import plotly.graph_objects as go

# Data saving
import pickle

# Import math Library
import math 

# Filtering
from scipy import signal

# Personal python functions
import sys
# sys.path.insert(1, '/home/jamilah/Documents/Sourceforge_analysis_PROJECTS/Motor_classification/subfunctions')
sys.path.insert(1, 'C:\\Users\\jamilah\\Documents\\Sourceforge_analysis_PROJECTS\\Motor_classification\\subfunctions')

from subfunctions.numderiv import *
from subfunctions.make_a_properlist import *
from subfunctions.detect_sig_change_wrt_baseline import *


# ------------------------------
# Idea 3 (control diagram): directly calculate the stim_ramp from the outSIG and outJOY. 
# - stim_ramp = F(s)speed_stim
# - at junction 1: outSIG + stim_ramp = cab
# - at junction 2: cab + joy_gain*outJOY = u
# - outSIGCOM = H(s)*u
# 
# Problem : Not correct, stim_ramp contains joystick motion.  
# Need to recover the almost the exact block diagram of the system 
# ------------------------------


def Try3_get_stim_speed():

    varr = {}
    varr['main_path'] = "C:\\Users\\jamilah\\Documents\\Sourceforge_analysis_PROJECTS\\Motor_classification"  # Windows
    #varr['main_path'] = "/home/jamilah/Documents/Sourceforge_analysis_PROJECTS/Motor_classification"

    NUMmark = 0   #  an arbitraily large number to denote a non-valid entry

    fs = 10 #  Original experimental sampling was at 250Hz, but data is downsampled to 10Hz
    ts = 1/fs

    mj_val = [0.1, 0.05, 0.01]






    for exp in range(1):  # 0=rotation, 1=translation
        if exp == 0:
            # Rotational data - 18 participants
            varr['which_exp'] = 'rot'
            varr['vals'] = 0.5, 1.25, 0

            # Load data experimental preprocessed data matrix
            file_name = "rotdat.pkl"
            open_file = open(file_name, "rb")
            dat = pickle.load(open_file)
            open_file.close()
            
            joy_gain = 10  # rotation
                
        elif exp == 1:
            # Translational data - 14 participants
            varr['which_exp'] = 'trans'
            varr['vals'] = 3.75, 15, 0
            
            # Load data experimental preprocessed data matrix
            file_name = "transdat.pkl"
            open_file = open(file_name, "rb")
            dat = pickle.load(open_file)
            open_file.close()
            
            joy_gain = 30  # what I confirmed before, but look again
        
        
        sign_slope_tr_subs = []
        speed_stim_tr_subs = []
        
        
        # 2) Load subjects
        subs = range(1)
        # subs = range(len(dat))
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
            
            
            sign_slope_tr = []
            speed_stim_tr = []
            
            
            for tr in range(num_of_tr):
                stim_ramp0 = []
                stim_ramp1 = []
                stim_ramp2 = []
                speed_stim = []
                
                
                for ax in range(3):
                    # Robotic movement system 2nd order transfer function
                    T = 4
                    a = 1   # 2nd order denomenator
                    b = (3.6*math.pi)/T  # 1st order denomenator
                    c = math.pi/(T*0.9)  # 0th order denomenator
                    d = 1  # numerator
                    
                    # Way 1 : Include the entire system to solve for stim_ramp 

                    # Writing out the system equations
                    # stim_ramp = F(s)speed_stim

                    # y(t) = outSIGCOM(t)
                    # u(t) = [stim_ramp(t) + outSIG(t)] + outJOY(t)

                    # And, the robotic movement tf in time domain is: a*y_ddot(t) + b*y_dot(t) + c*y(t) = d*u(t)
                    # Rewriting, let X = a*y_ddot(t) + b*y_dot(t) + c*y(t).  
                    # So, X = d*u(t). Then plug in u(t), such that X = d*[stim_ramp(t) + outSIG(t)] + d*outJOY(t)

                    # ------------------------------
                    # Way 1 : wrong
                    # [1] We want to solve for stim_ramp
                    # (X - d*outJOY(t)) - d*outSIG(t) = d*stim_ramp(t)
                    # ss(t) = ((1/d)*X - joy_gain*outJOY(t)) - cab_gain*outSIG(t)
                    
                    sig = outSIGCOM[tr][:,ax]
                    t = time[tr]
                    
                    x1 = a*np.array(numderiv(numderiv(sig, t), t))
                    x2 = b*np.array(numderiv(sig, t))
                    x3 = c*sig
                    X = x1 + x2 + x3
                    stim_ramp0 = stim_ramp0 + [((1/d)*X - joy_gain*outJOY[tr][:,ax]) - outSIG[tr][:,ax]]
                    # ------------------------------
                    
                    
                    # ------------------------------
                    # Way 2 : mathematically better - solving for sr in time domain - open loop
                    q = np.ones((len(outSIG[tr][:,ax])))
                    sr = a + b + c - d*outSIG[tr][:,ax]*(1/q) + outSIG[tr][:,ax] - joy_gain*outJOY[tr][:,ax]
                    
                    
                    # ------------------------------
                    
                    # great point 
                    
                    # I may likely NOT have the correct system even if I write the correct robot
                    # transfer function, because of delays and filtering.  I may be more successful
                    # if I do a 'grid search' across parameters and calculate sr2
                    # a = 1   should likely not change the dynamics
                    # b and c will change the response dynamics
                    
                    # sr_bc = []
                    # bc_label = []
                    # for b in range(1, 3):
                    #    for c in range(1, 3):
                    #         bc_lab = [b, c]
                    #         # ------------------------------
                    #         # Way 3 : closed loop - assuming Human_system=1
                    #         print('b : ' + str(b))
                    #         num = [a, b, c-2*d]
                    #         den = [a, b, c]
                    #           u = joy_gain*outJOY[tr][:,ax]
                    # 
                    #         stim_ramp_t, sr2, xout = lsim((num, den), U=u, T=time[tr])
                    #         sr_bc = sr_bc + [sr2]
                    #         
                    #         bc_label = bc_label + [bc_lab]
                            
                            
                    sr_bc = []
                    bc_label = []
                    jg_vals = [10]
                    for jg in jg_vals:
                        bc_lab = jg
                        # ------------------------------
                        # Way 3 : closed loop - assuming Human_system=1
                        num = [a, b, c-2*d]
                        den = [a, b, c]
                        
                        u = jg*outJOY[tr][:,ax]
                        
                        # Discrete time: (model was unstable)
                        # dt = 1/10  # originally collected at 1/252, but downsampled to 1/10
                        # tf = (num, den, dt)
                        # stim_ramp_t, sr2 = signal.dlsim((num, den, dt), u, t=time[tr])
                        
                        # Continuous time: 
                        stim_ramp_t, sr2, xout = lsim((num, den), U=u, T=time[tr])
                        
                        # sr2 = make_a_properlist(sr2)
                        # print('sr2' + str(sr2))
                        
                        
                        sr_bc = sr_bc + [sr2]
                        
                        # Determining speed_stim by the initial rate of change of "estimated stim_ramp"
                        if ax == axis_out[tr]:
                            
                            # Baseline shift sr2 to zero
                            sr2 = sr2 - sr2[0]
                            
                            # Filter
                            n = 4   # filter order
                            fs = 250 # data sampling frequency (Hz)
                            fc = 10  # Cut-off frequency of the filter
                            w = fc / (fs / 2) # Normalize the frequency
                            b, a = signal.butter(n, w, 'low')  # 3rd order
                            sr2 = signal.filtfilt(b, a, sr2)
                            
                            if varr['which_exp'] == 'rot':
                                tau = 20  # it should have been 20 second rise time
                                sup = 1.25  # angle/sec
                                sub = 0.5  # angle/sec
                                
                                marg_val = sub # make it the sub boundary
                                dpOFsig_in_zone, indexOFsig_in_zone, dp_sign_not_in_zone, indexOFsig_not_in_zone = detect_sig_change_wrt_baseline(sr2, 0, marg_val)

                                # So, if sub boundary is found, we count the number of data pts it took from zero
                                # to reach the sub boundary.  The more data pts counted it is sub because the rate
                                # of motion is slower than in sup.  
                                if not indexOFsig_not_in_zone.any():
                                    # could be empty if there is no motion
                                    initial_move_ind = 0
                                    inital_st_of_move_ind = 0
                                    dpts_2_do_subrate = 0
                                    initial_slope_stim_ramp = 0
                                    sign_slope = 0
                                    diff_sub = 0
                                else:
                                    initial_move_ind = indexOFsig_not_in_zone[0]
                                
                                    marg_val = 0.07 # make it really close to zero, but a bit bigger
                                    dpOFsig_in_zone, indexOFsig_in_zone, dp_sign_not_in_zone, indexOFsig_not_in_zone = detect_sig_change_wrt_baseline(sr2, 0, marg_val)
                                    inital_st_of_move_ind = indexOFsig_not_in_zone[0]
                                    # the initial start point before motion may not be at 0,
                                    # there could be a long period of time at zero before movement

                                    dpts_2_do_subrate = initial_move_ind - inital_st_of_move_ind

                                    # -------------------------------------------
                                    st = inital_st_of_move_ind
                                    stp = initial_move_ind
                                    print('st : ' + str(st))
                                    print('stp : ' + str(stp))
                                    
                                    if st == stp:
                                        # Redo the initial start point
                                        marg_val = 0.001 # make it really close to zero, but a bit bigger
                                        dpOFsig_in_zone, indexOFsig_in_zone, dp_sign_not_in_zone, indexOFsig_not_in_zone = detect_sig_change_wrt_baseline(sr2, 0, marg_val)
                                        inital_st_of_move_ind = indexOFsig_not_in_zone[0]
                                        # the initial start point before motion may not be at 0,
                                        # there could be a long period of time at zero before movement

                                        dpts_2_do_subrate = initial_move_ind - inital_st_of_move_ind

                                    # -------------------------------------------
                                    st = inital_st_of_move_ind
                                    stp = initial_move_ind
                                    slope = np.polyfit(time[tr][st:stp], sr2[st:stp], 1)
                                    # print('slope : ' + str(slope))

                                    initial_slope_stim_ramp = slope[1]
                                    sign_slope = np.sign(initial_slope_stim_ramp)  # Check with speed_stim_sign
                                    # print('initial_slope_stim_ramp : ' + str(initial_slope_stim_ramp))
                                    # -------------------------------------------
                                
                                    # Is iniital_slope closer to sub
                                    diff_sub = abs(initial_slope_stim_ramp - sub)
                                    print('diff_sub : ' + str(diff_sub))
                                    diff_sup = abs(initial_slope_stim_ramp - sup)
                                    print('diff_sup : ' + str(diff_sup))
                                
                            elif varr['which_exp'] == 'trans':
                                tau = 8  # it should have been 8 second rise time
                                trans_sup = 15  # cm/sec
                                trans_sub = 3.75  # cm/sec
                                # is iniital_slope closer to trans_sub
                                diff_sub = abs(initial_slope_stim_ramp-trans_sub)
                                diff_sup = abs(initial_slope_stim_ramp-trans_sup)
                            
                            
                            if diff_sub == 0:
                                ss = 'no_move'
                            elif diff_sub < diff_sup:
                                ss = 'sub'
                            elif diff_sub > diff_sup:
                                ss = 'sup'
                        

                        bc_label = bc_label + [bc_lab]
                    
                    
                        # den =  [K/tau]
                        # num = [1, 1/tau]
                        # stim_ramp_t, ss, xout = lsim((num, den), U=sr2, T=time[tr])
                        # ss_bc = ss_bc + [ss]
                        
                    stim_ramp1 = stim_ramp1 + [sr]
                    stim_ramp2 = stim_ramp2 + [sr_bc]
                    # ------------------------------
                
                sign_slope_tr = sign_slope_tr + [sign_slope]
                speed_stim_tr = speed_stim_tr + [ss]
                
                bc_label = make_a_properlist(bc_label)
                print('bc_label : ' + str(bc_label))
                
                # --------------------
                fig = go.Figure()
                config = dict({'scrollZoom': True, 'displayModeBar': True, 'editable': True})

                xxORG = list(range(len(outJOY[tr][:,0])))
                
                # Plotting joystick
                fig.add_trace(go.Scatter(x=xxORG, y=outJOY[tr][:,axis_out[tr]], name='outJOY axstim : %s' % (varr['which_exp']), line = dict(color='red', width=2, dash='dash'), showlegend=True))
                # fig.add_trace(go.Scatter(x=xxORG, y=outJOY[tr][:,1], name='outJOY ax1 : %s' % (varr['which_exp']), line = dict(color='green', width=2, dash='dash'), showlegend=True))
                # fig.add_trace(go.Scatter(x=xxORG, y=outJOY[tr][:,2], name='outJOY ax2 : %s' % (varr['which_exp']), line = dict(color='blue', width=2, dash='dash'), showlegend=True))
                
                # Plotting actual cabin position
                fig.add_trace(go.Scatter(x=xxORG, y=outSIG[tr][:,axis_out[tr]], name='outSIG axstim : %s' % (varr['which_exp']), line = dict(color='black', width=2, dash='dash'), showlegend=True))
                
                # Open loop
                fig.add_trace(go.Scatter(x=xxORG, y=stim_ramp1[axis_out[tr]], name='openloop : %s' % (varr['which_exp']), line = dict(color='blue', width=2, dash='dash'), showlegend=True))
                # fig.add_trace(go.Scatter(x=xxORG, y=stim_ramp1[0], name='openloop : %s' % (varr['which_exp']), line = dict(color='red', width=2, dash='dash'), showlegend=True))
                # fig.add_trace(go.Scatter(x=xxORG, y=stim_ramp1[1], name='openloop : %s' % (varr['which_exp']), line = dict(color='green', width=2, dash='dash'), showlegend=True))
                # fig.add_trace(go.Scatter(x=xxORG, y=stim_ramp1[2], name='openloop : %s' % (varr['which_exp']), line = dict(color='blue', width=2, dash='dash'), showlegend=True))
                
                # Closed loop
                # for bc in range(len(bc_label)):
                #     fig.add_trace(go.Scatter(x=xxORG, y=stim_ramp2[0][bc], name='closedloop : %s, b=%2.1f, c=%2.1f' % (varr['which_exp'], bc_label[0][bc], bc_label[1][bc]), line = dict(color='red', width=2, dash='solid'), showlegend=True))
                #     fig.add_trace(go.Scatter(x=xxORG, y=stim_ramp2[1][bc], name='closedloop : %s, b=%2.1f, c=%2.1f' % (varr['which_exp'], bc_label[0][bc], bc_label[1][bc]), line = dict(color='green', width=2, dash='solid'), showlegend=True))
                #     fig.add_trace(go.Scatter(x=xxORG, y=stim_ramp2[2][bc], name='closedloop : %s, b=%2.1f, c=%2.1f' % (varr['which_exp'], bc_label[0][bc], bc_label[1][bc]), line = dict(color='blue', width=2, dash='solid'), showlegend=True))
                
                for bc in range(len(bc_label)):
                    fig.add_trace(go.Scatter(x=xxORG, y=stim_ramp2[axis_out[tr]][bc], name='closedloop : %s, jg=%2.1f' % (varr['which_exp'], bc_label[bc]), showlegend=True))
                    
                    dpt1 = inital_st_of_move_ind*np.ones((2))
                    dpt1 = [int(x) for x in dpt1] # convert to integer
                    fig.add_trace(go.Scatter(x=dpt1, y=stim_ramp2[axis_out[tr]][bc][dpt1], name='inital_st_of_move_ind', mode='markers', marker=dict(color='blue', size=10, symbol=5, line=dict(color='blue', width=0)), showlegend=True))
                    
                    dpt2 = initial_move_ind*np.ones((2))
                    dpt2 = [int(x) for x in dpt2] # convert to integer
                    fig.add_trace(go.Scatter(x=dpt2, y=stim_ramp2[axis_out[tr]][bc][dpt2], name='initial_move_ind', mode='markers', marker=dict(color='red', size=10, symbol=5, line=dict(color='red', width=0)), showlegend=True))
                    
                    # fig.add_trace(go.Scatter(x=xxORG, y=stim_ramp2[0][bc], name='way2 : %s, jg=%2.1f' % (varr['which_exp'], bc_label[bc]), showlegend=True))
                    # fig.add_trace(go.Scatter(x=xxORG, y=stim_ramp2[1][bc], name='way2 : %s, jg=%2.1f' % (varr['which_exp'], bc_label[bc]), showlegend=True))
                    # fig.add_trace(go.Scatter(x=xxORG, y=stim_ramp2[2][bc], name='way2 : %s, jg=%2.1f' % (varr['which_exp'], bc_label[bc]), showlegend=True))
                
                    # fig.add_trace(go.Scatter(x=xxORG, y=speed_stim[axis_out[tr]][bc], name='way2 : %s, jg=%2.1f' % (varr['which_exp'], bc_label[bc]), showlegend=True))
                
                fig.update_layout(title='stim_ramp : s : %d, tr : %d, stim_axis : %d, stim : %s, dpts : %d, slope : %2.1f' % (s, tr, axis_out[tr], ss, dpts_2_do_subrate, initial_slope_stim_ramp), xaxis_title='data points', yaxis_title='stim ramp')
                fig.show(config=config)
                # --------------------
        
        sign_slope_tr = make_a_properlist(sign_slope_tr)
        sign_slope_tr_subs = sign_slope_tr_subs + [sign_slope_tr]
        
        speed_stim_tr = make_a_properlist(speed_stim_tr)
        speed_stim_tr_subs = speed_stim_tr_subs + [speed_stim_tr]
            
        
        
>>>>>>> 94b06cd4776edc5e6880e69ca0d1eefbe92d257c
    return