<<<<<<< HEAD
# ------------------------------
# Idea 3 (control diagram): directly calculate the stim_ramp from the outSIG and outJOY. 
# - stim_ramp = F(s)speed_stim
# - at junction 1: outSIG + stim_ramp = cab
# - at junction 2: cab + joy_gain*outJOY = u
# - outSIGCOM = H(s)*u
# 
# Problem : Found the correct block diagram.  But then realized that it was formulated in terms of
# human-in-the-loop, where the human performance is a transfer function block.  Need to estimate the 
# transfer function from the outJOY (output of block) and outSIG (input of block). Tried many formulations
# (arx, frequency response, estimating an ode from the signal, n4sid) to get a descent estimation of 
# the human-in-the-loop block.  n4sid was the best, as it returns the output (outJOY) for the input (outSIG).

# It gives a very small ramp for frequency response discrete (human-in-the-loop block fit is poor, regardless could try to categorize this for sub and sup), 

# For n4sid continuous, it gives the exact shape as the input.  

# For n4sid discrete,


# ------------------------------

import numpy as np

# Plotting
import plotly.graph_objects as go

# Data saving
import pickle

# Import math Library
import math 

# fft
from scipy.fft import fft, ifft

# importing "cmath" for complex number operations
import cmath

# Continuous time lti
from scipy.signal import lsim

# Filtering, Discrete time lti
from scipy import signal

# Least squares 
from sklearn.linear_model import LinearRegression

from sklearn.metrics import r2_score

# Personal python functions
import sys

# sys.path.insert(1, '/home/jamilah/Documents/Sourceforge_analysis_PROJECTS/Motor_classification')
sys.path.insert(1, 'C:\\Users\\jamilah\\Documents\\Sourceforge_analysis_PROJECTS\\Motor_classification')

from subfunctions.numderiv import *
from subfunctions.make_a_properlist import *
from subfunctions.detect_sig_change_wrt_baseline import *

from subfunctions.ode_fit_of_a_signal import *
from subfunctions.freqresp_functions import *

from subfunctions.optimize_n4sid_settings import *




def Try4_get_stim_speed2():

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
            
            
            
            for tr in range(num_of_tr):
                stim_ramp0 = []
                stim_ramp1 = []
                stim_ramp2 = []
                speed_stim = []
                
                # ------------------------------
                # Closed loop : 
                # u = stim_ramp*time
                # outSIG(s)/U(s) = 1/[1 - R(s)H(s)]
                
                # U(s)/outSIG(s) = 1 - R(s)H(s)
                
                # h_t = outJOY[tr][axis_out[tr]]/outSIG[tr][axis_out[tr]]
                # ------------------------------
                
                
                
                # Get H(s) : Estimate the ordinary differenial equation for output/input=H(s) 
                
                # ------------------------------
                # Way 1: find the slope of 1st and 2nd derivatives of the input and output
                # Only works on simple (periodic) signals
                # print('length of outJOY[tr][:,axis_out[tr]]: ' + str(len(outJOY[tr][:,axis_out[tr]])))
                # print('length of time[tr]: ' + str(len(time[tr])))
                # ode_Hnum = ode_fit_of_a_signal(outJOY[tr][:,axis_out[tr]], time[tr])   # 2nd order system
                # ode_Hden = ode_fit_of_a_signal(outSIG[tr][:,axis_out[tr]], time[tr])   # 2nd order system
                # ------------------------------
                
                
                # ------------------------------
                
                inputs = outSIG[tr][:,axis_out[tr]]
                outputs = outJOY[tr][:,axis_out[tr]]
                t = time[tr]
                zero_thresh = 0.1 # deadzone of joystick - so person does not move
                
                
                
                human_model_choice = 3   # 0=ode_fit_of_a_signal, 1=ARX, 2=Frequency Response, 3=N4SID
                
                if abs(np.sum(outputs)) > zero_thresh:
                
                    if human_model_choice == 0:
                        model_type = 'homemade'
                        # ------------------------------
                        # Way 0: slope fit of input derivatives 
                        
                        ode_coef_num = ode_fit_of_a_signal(outputs, t)
                        ode_coef_den = ode_fit_of_a_signal(inputs, t)
                        
                        # Reflections
                        # NOTE : I am just transforming the input and output signal into odes.  They have not been # tunned such that they make sense in terms of a system or filter.
                        
                        # I was hoping that by putting the ode equations together in input/output format it would work 
                        
                        
                        # transform to continous time
                        
                        
                        # Check the roots of the "denomenator"
                        roots_out = np.roots(ode_coef_den)
                        print('Original poles : ' + str(roots_out))
                        
                        # Need to modify the roots such that the "composite transfer fuction/filter" is bounded
                        
                        
                        
                        # For discrete system
                        # Test the roots of the system to see if they are inside the unit circle
                        flag = 0
                        for i in roots_out:
                            print('abs(i.real) : ' + str(abs(i.real)))
                            if np.round(abs(i.real), 1) > 1:
                                flag = 1
                                break
                        
                        if flag == 1:
                            # Do pole placement 
                            A, B, C, D = tf2ss(ode_coef_num, ode_coef_den)

                            # Choose the new stable poles
                            newp = []
                            for i in roots_out:
                                if abs(i.real) > 1:
                                    newp = newp + [i/10]
                                else:
                                    newp = newp + [i]
                            newp = make_a_properlist(newp)
                            newp = np.array(newp)

                            # Find a new stable system
                            fsf = signal.place_poles(A, B, newp)  # uses YT method
                            roots_out = fsf.computed_poles   # resave over roots_out
                            print('CORRECTED poles : ' + str(roots_out))

                            # Get new coeficients for denomenator
                            ode_coef_den = P.polyfromroots((roots_out))
                        
                        # The system roots are stable, but the response is unbounded...why?
                        # could be the system sampling
                        
                        # Discrete time model:
                        tf = (ode_coef_num, ode_coef_den, ts)
                        print('Final H(z) tf using homemade : ' + str(tf))
                        
                        a1 = ode_coef_num[2]
                        b1 = ode_coef_num[1]
                        c1 = ode_coef_num[0]
                        
                        a2 = ode_coef_den[2]
                        b2 = ode_coef_den[1]
                        c2 = ode_coef_den[0]
                
                    if human_model_choice == 1:
                        model_type = 'arx'
                        # ------------------------------
                        # Way 1: arx
                        train_input = outputs  # train on the output means that we tune the poles and zero gain (K) with respect to the output, because we want the model output to look like the output and NOT the input
                        
                        # Create the input matrix in order to solve for the coefficients
                        # Train the model using the training sets
                        dinputs = numderiv(inputs, t)
                        ddinputs = numderiv(dinputs, t)
                        # print('length of dinputs : ' + str(len(dinputs)))
                        # print('length of ddinputs : ' + str(len(ddinputs)))

                        first_col = np.ones((len(inputs)))
                        first_col = make_a_properlist(first_col)
                        derivative_mat_of_inputs = np.transpose([first_col, dinputs, ddinputs])

                        # Create linear regression object
                        regr = LinearRegression()
                        regr.fit(derivative_mat_of_inputs, outputs)

                        # This give the coefficients for the ratio of the : beta = B/A
                        beta = regr.coef_
                        print('beta : ' + str(beta))

                        # Need to normalize the beta coefficients before assigning B and A
                        beta_norm = beta/np.max(abs(beta))
                        print('beta_norm : ' + str(beta_norm))
                        
                        
                        # Transform the beta coefficients into A and B transfer function coefficients
                        # Lets choose stable discrete poles for A and then solve for B using the 
                        # beta = B/A relationship
                        
                        # Q : How do you manipulate beta such that you get good B/A polynomials??
                        
                        tunePOLESorNOT = 0
                        if tunePOLESorNOT == 1:
                            # ----------------------------------------------------
                            # Tune poles closest to unit circle - great if using system alone
                            # but, if you are multiplying it by another system it could cause unstability
                            trys = 1000  # Try pole placement this many times to adjust one pole such that the amplitude better matches the output signal
                            
                            err_diff = np.zeros((trys))
                            err_diff[0] = 100  # set a big number
                            err_tol = 0.1 #0.001
                            
                            # Error minimizing loop to tune a poles
                            for n in range(1,trys):
                                print('n : ' + str(n) + ', error diff[n-1] : ' + str(err_diff[n-1]))
                                a0 = 1
                                a1 = beta_norm[1]
                                a2 = a1/n

                                # To tell if the system is stable based on changing the coefficients
                                roots = np.roots([a0, a1, a2])
                                print('roots : ' + str(roots))
                                
                                # ------------
                                # Remove the imaginary components of the roots
                                real_roots = roots.real

                                # Recalculate the coefficients using the real_roots
                                den = P.polyfromroots((real_roots))
                                # den = [a0, a1, a2]
                                # ------------

                                num = beta_norm*den
                                # print('num : ' + str(num))
                                num_invert = num[::-1]
                                # print('num_invert : ' + str(num_invert))

                                # Discrete time model:
                                dt = ts
                                tf = (num_invert, den, dt)
                                # print('tf : ' + str(tf))
                                
                                pred_t, pred_output  = signal.dlsim(tf, train_input, t=t)
                                pred_output = make_a_properlist(pred_output)
                                pred_t = make_a_properlist(pred_t)

                                # Calculate error: using RMSE to evaluate the predition error
                                err_diff[n] = 1/len(pred_output) * np.sqrt(np.sum(np.square(np.array(train_input[0:len(pred_output)]) - np.array(pred_output)), axis=0, keepdims=True))
                                
                                if (err_diff[n-1] - err_diff[n]) < err_tol:
                                    break
                            # ----------------------------------------------------
                        elif tunePOLESorNOT == 0:
                            # ----------------------------------------------------
                            # Do NOT tune poles
                            a0 = 1
                            a1 = beta_norm[1]
                            a2 = a1/2
                            
                            # To tell if the system is stable based on changing the coefficients
                            roots = np.roots([a0, a1, a2])
                            print('roots : ' + str(roots))
                            
                            # ------------
                            # Remove the imaginary components of the roots
                            real_roots = roots.real

                            # Recalculate the coefficients using the real_roots
                            den = P.polyfromroots((real_roots))
                            # den = [a0, a1, a2]
                            # ------------
                            
                            num = beta_norm*den
                            # print('num : ' + str(num))
                            num_invert = num[::-1]
                            # print('num_invert : ' + str(num_invert))

                            # Discrete time model:
                            dt = ts
                            tf = (num_invert, den, dt)
                            # print('tf : ' + str(tf))
                            
                            pred_t, pred_output  = signal.dlsim(tf, train_input, t=t)
                            pred_output = make_a_properlist(pred_output)
                            pred_t = make_a_properlist(pred_t)
                            # ----------------------------------------------------
                        
                        # Then multiply a gain (K) with the denominator to get a better fit
                        max_ind = np.argmax(train_input)
                        K = inputs[max_ind]/pred_output[max_ind]

                        num = K*num_invert
                        den = den
                        
                        # Discrete time model:
                        dt = ts
                        tf = (num, den, dt)
                        print('Final H(z) tf using ARX : ' + str(tf))
                        
                        a1 = num[2]
                        b1 = num[1]
                        c1 = num[0]
                        
                        a2 = den[2]
                        b2 = den[1]
                        c2 = den[0]
                        
                        # ----------------
                        
                        # H(z) is the final transfer function, the human input-output system, because
                        # ARX fits coefficients for the input and output values accordingly.
                        # It is not perfect at recreating the output with respect to the input, because
                        # it does not project the input vector space onto the output space.  But, we 
                        # tune the coefficients to best fit the output, hoping that it will be a 
                        # decent model.
                        
                        # We give the transfer function the input and we hope to get something that looks like the output
                        # pred_t, pred_output  = signal.dlsim(tf, inputs, t=t)
                        # pred_output = make_a_properlist(pred_output)
                        # pred_t = make_a_properlist(pred_t)
                        # ------------------------------
                    
                    if human_model_choice == 2:
                        model_type = 'freq_resp'
                        # ------------------------------
                        # Way 3) frequency response
                        # ------------------------------
                        Xn_mag_in, Xn_phase_in, omeg_in, Xn_mag_half_db_in, Xn_phase_half_in, omg_half_in = get_freqresp_mag_phase(inputs, t, ts)
                        
                        Xn_mag_out, Xn_phase_out, omeg_out, Xn_mag_half_db_out, Xn_phase_half_out, omg_half_out = get_freqresp_mag_phase(outputs, t, ts)

                        which_way = 0
                        if which_way == 0:
                            # Way 0 : select fc for input and output separately, then combine Y(jw)/U(jw).
                            # Here we combine two filters for different 'natural frequencies' - each need to be 1st order
                            
                            # Input : single signal
                            choose_fc = 1  # choose_fc=0 : fc is 0.3 db drop, choose_fc=1 : Nyquist freq, choose_fc=2 : fc is where two magnitudes cross
                            single_sig = 0  #0=input, 1=output
                            fc = select_fc(fs, choose_fc, single_sig, Xn_mag_half_db_in, Xn_phase_half_in, omg_half_in, Xn_mag_half_db_out, Xn_phase_half_out, omg_half_out)
                            n = 1  # filter order
                            tf = select_filter(n, fc, fs)
                            num = tf[0]
                            den = tf[1]
                            ts_fc_in = tf[2]
                            aa2 = num[1]
                            aa3 = num[0]
                            bb2 = den[1]
                            bb3 = den[0]
                            
                            # Output : single signal
                            choose_fc = 1  # choose_fc=0 : fc is 0.3 db drop, choose_fc=1 : Nyquist freq, choose_fc=2 : fc is where two magnitudes cross
                            single_sig = 1  #0=input, 1=output
                            fc = select_fc(fs, choose_fc, single_sig, Xn_mag_half_db_out, Xn_phase_half_out, omg_half_out, Xn_mag_half_db_out, Xn_phase_half_out, omg_half_out)
                            n = 1  # filter order
                            tf = select_filter(n, fc, fs)
                            num = tf[0]
                            den = tf[1]
                            ts_fc_out = tf[2]
                            aa5 = num[1]
                            aa6 = num[0]
                            bb5 = den[1]
                            bb6 = den[0]
                            
                            # 1st order filter for Y(z) and U(z)
                            # H(z) = Y(z)/U(z) and the human input-output system becomes 4th order 
                            Hnum = [aa2*bb5, (aa2*bb6 + aa3*bb5), aa3*bb6]
                            Hden = [bb2*aa5, (bb2*aa6 + bb3*aa5), bb3*aa6]
                            
                            a1 = Hnum[2]
                            b1 = Hnum[1]
                            c1 = Hnum[0]
                            
                            a2 = Hden[2]
                            b2 = Hden[1]
                            c2 = Hden[0]
                            
                            ts_fc = min([ts_fc_in, ts_fc_out])
                        
                        elif which_way == 1:
                            # Way 1 : select fc for input and output together, there is one transfer function/filter -do 2nd order
                            choose_fc = 2  #See when the two magnitudes cross
                            single_sig = 0  #0=input, 1=output, only relavant when choose_fc = 0 or 1
                            fc = select_fc(fs, choose_fc, single_sig, Xn_mag_half_db_in, Xn_phase_half_in, omg_half_in, Xn_mag_half_db_out, Xn_phase_half_out, omg_half_out)
                            
                            n = 2  # filter order
                            tf = select_filter(n, fc, fs)
                            num = tf[0]
                            den = tf[1]
                            ts_fc = tf[2]
                            
                            a1 = num[2]
                            b1 = num[1]
                            c1 = num[0]
                            
                            a2 = den[2]
                            b2 = den[1]
                            c2 = den[0]
                        
                        # Discrete time model:
                        tf = ([a1, b1, c1], [a2, b2, c2], ts_fc)
                        print('Final H(z) tf using Frequency Response (1st order filter for Y and U) : ' + str(tf))
                        # ----------------
                        
                    if human_model_choice == 3:
                        model_type = 'n4sid'
                        # ------------------------------
                        # Way 4) n4sid
                        # ------------------------------
                        # Solve for H(s) or H(z)
                        pred_output, tf, r_squared, sysmeth, discon, which_setting = optimize_n4sid_settings(inputs, outputs, t, ts)
                        
                        plot_best_coefmeth(t, inputs, outputs, pred_output, sysmeth, r_squared, 1)
                        
                        # --------------------
                        # The output model could be discrete or continuous
                        
                        if discon == 0:   # Discrete
                            pred_output_dis_best = pred_output
                        elif discon == 1:   # Continuous
                            pred_output_con_best = pred_output
                        # --------------------
                        
                        # Discrete time model:
                        num = tf[0]
                        den = tf[1]
                        print('Final H(z) tf using n4sid : ' + str(tf))
                        
                        a1 = num[2]
                        b1 = num[1]
                        c1 = num[0]
                        
                        a2 = den[2]
                        b2 = den[1]
                        c2 = den[0]
                        
                        print('Roots of H(z) : ' + str(np.roots(den)))
                        # ------------------------------
                        # End of searching or H(z)
                    
                    
                    # --------------------
                    # --------------------
                    # Plot Human system (H(z)) response BEFORE it is multiply by Robot system (R(z))
                    # --------------------
                    # --------------------
                    print('Lets test the Final tf on the input: ')
                    pred_t, pred_output  = signal.dlsim(tf, inputs, t=t)
                    pred_output = make_a_properlist(pred_output)
                    pred_t = make_a_properlist(pred_t)

                    fig = go.Figure()
                    config = dict({'scrollZoom': True, 'displayModeBar': True, 'editable': True})

                    fig.add_trace(go.Scatter(x=t, y=inputs, name='inputs : outSIG', line = dict(color='red', width=2, dash='dash'), showlegend=True))
                    fig.add_trace(go.Scatter(x=t, y=outputs, name='outputs : outJOY', line = dict(color='blue', width=2, dash='dash'), showlegend=True))
                    fig.add_trace(go.Scatter(x=pred_t, y=pred_output, name='H(z) : predicted output', line = dict(color='black', width=2, dash='dash'), showlegend=True))
                    
                    N = np.min([len(outputs), len(pred_output)])
                    y_true = np.array(outputs[0:N])
                    y_pred = np.array(pred_output[0:N])
                    err_R2 = r2_score(y_true, y_pred)
                    fig.update_layout(title='Human model %s : R^2=%2.5f' % (model_type, err_R2), xaxis_title='time', yaxis_title='signal')
                    fig.show(config=config)
                    # --------------------
                    # ------------------------------
                    
                    
                    # --------------------
                    # Write out robot system : R(z) = 1/[z^-2 + bz^-1 + c]
                    
                    # 1st attempt to write the correct 2nd order robot system
                    # TT = 4
                    # b = (3.6*math.pi)/TT  # 1st order denomenator
                    # c = math.pi/(TT*0.9)  # 0th order denomenator
                    
                    # 2nd attempt to write the correct 2nd order robot system
                    # b = 4*0.8*math.pi
                    # c = math.pi/0.8
                    
                    # 3rd attempt to write the correct 2nd order robot system
                    zeta = 0.8
                    T = 4 # 4
                    wn = 1/(T*zeta)
                    # num = [1]  # classical formulation numerator is [wn*wn], but we used [1]
                    # den = [1, 2*zeta*wn, wn*wn]
                    b = 2*zeta*wn
                    c = wn*wn
                    # --------------------
                    
                    # --------------------
                    # Multiply robot system with human system : R(z)*H(z)
                    num = [a1, b1, c1]
                    den = [a2, b2+b*a2, c2+b*b2+c*a2, b*c2+c*b2, c*c2]
                    print('num : ' + str(num))
                    print('den : ' + str(den))
                    print('Roots of R(z)*H(z) : ' + str(np.roots(den)))
                    # --------------------
                    
                    # --------------------
                    # Solve for u using the closedloop expression of outSIG wrt u=stim_ramp*t
                    # outSIG/u = 1/[1 - R(z)*H(z)]
                    
                    
                    
                    # We invert the transfer function, because we want to solve for u
                    # u/outSIG = [1 - R(z)*H(z)]
                    num_cl = [a2, b2+b*a2, c2+b*b2+c*a2-a1, b*c2+c*b2-b1, c*c2-c1]
                    den_cl = [a2, b2+b*a2, c2+b*b2+c*a2, b*c2+c*b2, c*c2]
                    
                    # print('num : ' + str(num_cl))
                    # print('den : ' + str(den_cl))
                    # cl_sysroots = np.roots(den_cl)
                    # print('Roots of inverted closedloop to solve for u) : ' + str(cl_sysroots))
                    # --------------------
                    
                    # --------------------
                    # Check if discrete closedloop expression is stable
                    
                    roots_out = np.roots(den_cl)
                    print('u/outSIG = [1 - R(z)*H(z)] roots_out: ' + str(roots_out))
                    # --------------------
                    
                else:
                    # When outJOY/outSIG are zero, we can not solve for H(z) system
                    # going backward if outJOY and outSIG are zero.
                    # The Person needs to move the joystick in order for us to solve using ARX/frequency response.
                    
                    # Good point!
                    # When the person does not move, H(z) = 1 meaning outSIG=outJOY, according to the diagram (it seems counter intuitive thinking about it) 
                    
                    # --------------------
                    # Write out robot system : R(z) = 1/[z^-2 + bz^-1 + c]
                    
                    # 1st attempt to write the correct 2nd order robot system
                    # TT = 4
                    # b = (3.6*math.pi)/TT  # 1st order denomenator
                    # c = math.pi/(TT*0.9)  # 0th order denomenator
                    
                    # 2nd attempt to write the correct 2nd order robot system
                    # b = 4*0.8*math.pi
                    # c = math.pi/0.8
                    
                    # 3rd attempt to write the correct 2nd order robot system
                    zeta = 0.8
                    T = 4 # 4
                    wn = 1/(T*zeta)
                    # num = [1]  # classical formulation numerator is [wn*wn], but we used [1]
                    # den = [1, 2*zeta*wn, wn*wn]
                    b = 2*zeta*wn
                    c = wn*wn
                    # --------------------
                    
                    # --------------------
                    # Solve for u using the closedloop expression of outSIG wrt u=stim_ramp*t
                    # outSIG/u = 1/[1 - R(z)*H(z)]
                    # outSIG/u = 1/[1 - R(z)]
                    
                    # We invert the transfer function, because we want to solve for u
                    # u/outSIG = [1 - R(z)]
                    num_cl = [1, b, c-1]
                    den_cl = [1, b, c]
                    print('num : ' + str(num_cl))
                    print('den : ' + str(den_cl))
                    print('Roots of inverted closedloop to solve for u) : ' + str(np.roots(den_cl)))
                    # --------------------
                    
                    
                    # u = np.zeros((len(inputs)))
                    # u_t = t
                
                
               # --------------------
               
               
                # Solve for u
                # Continuous time: 
                # u_t, u, xout = lsim((num, den), U=outSIG[tr][:,axis_out[tr]], T=time[tr])
                
                # Discrete time:
                u_t, u  = signal.dlsim((num_cl, den_cl, ts), inputs, t=t)
                u = make_a_properlist(u)
                u_t = make_a_properlist(u_t)
                
                # --------------------
                
                # Finally, we want to solve for stim_ramp using : u = stim_ramp * time
                # stim_ramp = u/time
                
                print('length of u : ' + str(len(u)))
                print('length of time[tr] : ' + str(len(time[tr])))
                
                N = np.min([len(u), len(time[tr])])
                sr = np.array(u[0:N])/time[tr][0:N]
                # ------------------------------
               
                    
                # --------------------
                fig = go.Figure()
                config = dict({'scrollZoom': True, 'displayModeBar': True, 'editable': True})
                
                
                # Plotting the stimulus ramp, joystick input, and cabin movement
                
                fig.add_trace(go.Scatter(x=time[tr][0:N], y=u[0:N], name='u : %s' % (varr['which_exp']), line = dict(color='cyan', width=2, dash='dash'), showlegend=True))
                
                fig.add_trace(go.Scatter(x=time[tr][0:N], y=sr[0:N], name='sr : %s' % (varr['which_exp']), line = dict(color='red', width=2, dash='dash'), showlegend=True))
                
                # Plotting joystick
                fig.add_trace(go.Scatter(x=time[tr], y=outJOY[tr][:,axis_out[tr]], name='outJOY axstim : %s' % (varr['which_exp']), line = dict(color='blue', width=2, dash='dash'), showlegend=True))
                
                # Plotting actual cabin position
                fig.add_trace(go.Scatter(x=time[tr], y=outSIG[tr][:,axis_out[tr]], name='outSIG axstim : %s' % (varr['which_exp']), line = dict(color='black', width=2, dash='dash'), showlegend=True))
                
                fig.update_layout(title='stim_ramp : s : %d, tr : %d, stim_axis : %d' % (s, tr, axis_out[tr]), xaxis_title='data points', yaxis_title='stim ramp')
                fig.show(config=config)
                # --------------------
                
=======
# ------------------------------
# Idea 3 (control diagram): directly calculate the stim_ramp from the outSIG and outJOY. 
# - stim_ramp = F(s)speed_stim
# - at junction 1: outSIG + stim_ramp = cab
# - at junction 2: cab + joy_gain*outJOY = u
# - outSIGCOM = H(s)*u
# 
# Problem : Found the correct block diagram.  But then realized that it was formulated in terms of
# human-in-the-loop, where the human performance is a transfer function block.  Need to estimate the 
# transfer function from the outJOY (output of block) and outSIG (input of block). Tried many formulations
# (arx, frequency response, estimating an ode from the signal, n4sid) to get a descent estimation of 
# the human-in-the-loop block.  n4sid was the best, as it returns the output (outJOY) for the input (outSIG).

# It gives a very small ramp for frequency response discrete (human-in-the-loop block fit is poor, regardless could try to categorize this for sub and sup), 

# For n4sid continuous, it gives the exact shape as the input.  

# For n4sid discrete,


# ------------------------------

import numpy as np

# Plotting
import plotly.graph_objects as go

# Data saving
import pickle

# Import math Library
import math 

# fft
from scipy.fft import fft, ifft

# importing "cmath" for complex number operations
import cmath

# Continuous time lti
from scipy.signal import lsim

# Filtering, Discrete time lti
from scipy import signal

# Least squares 
from sklearn.linear_model import LinearRegression

from sklearn.metrics import r2_score

# Personal python functions
import sys

# sys.path.insert(1, '/home/jamilah/Documents/Sourceforge_analysis_PROJECTS/Motor_classification')
sys.path.insert(1, 'C:\\Users\\jamilah\\Documents\\Sourceforge_analysis_PROJECTS\\Motor_classification')

from subfunctions.numderiv import *
from subfunctions.make_a_properlist import *
from subfunctions.detect_sig_change_wrt_baseline import *

from subfunctions.ode_fit_of_a_signal import *
from subfunctions.freqresp_functions import *

from subfunctions.optimize_n4sid_settings import *




def Try4_get_stim_speed2():

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
            
            
            
            for tr in range(num_of_tr):
                stim_ramp0 = []
                stim_ramp1 = []
                stim_ramp2 = []
                speed_stim = []
                
                # ------------------------------
                # Closed loop : 
                # u = stim_ramp*time
                # outSIG(s)/U(s) = 1/[1 - R(s)H(s)]
                
                # U(s)/outSIG(s) = 1 - R(s)H(s)
                
                # h_t = outJOY[tr][axis_out[tr]]/outSIG[tr][axis_out[tr]]
                # ------------------------------
                
                
                
                # Get H(s) : Estimate the ordinary differenial equation for output/input=H(s) 
                
                # ------------------------------
                # Way 1: find the slope of 1st and 2nd derivatives of the input and output
                # Only works on simple (periodic) signals
                # print('length of outJOY[tr][:,axis_out[tr]]: ' + str(len(outJOY[tr][:,axis_out[tr]])))
                # print('length of time[tr]: ' + str(len(time[tr])))
                # ode_Hnum = ode_fit_of_a_signal(outJOY[tr][:,axis_out[tr]], time[tr])   # 2nd order system
                # ode_Hden = ode_fit_of_a_signal(outSIG[tr][:,axis_out[tr]], time[tr])   # 2nd order system
                # ------------------------------
                
                
                # ------------------------------
                
                inputs = outSIG[tr][:,axis_out[tr]]
                outputs = outJOY[tr][:,axis_out[tr]]
                t = time[tr]
                zero_thresh = 0.1 # deadzone of joystick - so person does not move
                
                
                
                human_model_choice = 3   # 0=ode_fit_of_a_signal, 1=ARX, 2=Frequency Response, 3=N4SID
                
                if abs(np.sum(outputs)) > zero_thresh:
                
                    if human_model_choice == 0:
                        model_type = 'homemade'
                        # ------------------------------
                        # Way 0: slope fit of input derivatives 
                        
                        ode_coef_num = ode_fit_of_a_signal(outputs, t)
                        ode_coef_den = ode_fit_of_a_signal(inputs, t)
                        
                        # Reflections
                        # NOTE : I am just transforming the input and output signal into odes.  They have not been # tunned such that they make sense in terms of a system or filter.
                        
                        # I was hoping that by putting the ode equations together in input/output format it would work 
                        
                        
                        # transform to continous time
                        
                        
                        # Check the roots of the "denomenator"
                        roots_out = np.roots(ode_coef_den)
                        print('Original poles : ' + str(roots_out))
                        
                        # Need to modify the roots such that the "composite transfer fuction/filter" is bounded
                        
                        
                        
                        # For discrete system
                        # Test the roots of the system to see if they are inside the unit circle
                        flag = 0
                        for i in roots_out:
                            print('abs(i.real) : ' + str(abs(i.real)))
                            if np.round(abs(i.real), 1) > 1:
                                flag = 1
                                break
                        
                        if flag == 1:
                            # Do pole placement 
                            A, B, C, D = tf2ss(ode_coef_num, ode_coef_den)

                            # Choose the new stable poles
                            newp = []
                            for i in roots_out:
                                if abs(i.real) > 1:
                                    newp = newp + [i/10]
                                else:
                                    newp = newp + [i]
                            newp = make_a_properlist(newp)
                            newp = np.array(newp)

                            # Find a new stable system
                            fsf = signal.place_poles(A, B, newp)  # uses YT method
                            roots_out = fsf.computed_poles   # resave over roots_out
                            print('CORRECTED poles : ' + str(roots_out))

                            # Get new coeficients for denomenator
                            ode_coef_den = P.polyfromroots((roots_out))
                        
                        # The system roots are stable, but the response is unbounded...why?
                        # could be the system sampling
                        
                        # Discrete time model:
                        tf = (ode_coef_num, ode_coef_den, ts)
                        print('Final H(z) tf using homemade : ' + str(tf))
                        
                        a1 = ode_coef_num[2]
                        b1 = ode_coef_num[1]
                        c1 = ode_coef_num[0]
                        
                        a2 = ode_coef_den[2]
                        b2 = ode_coef_den[1]
                        c2 = ode_coef_den[0]
                
                    if human_model_choice == 1:
                        model_type = 'arx'
                        # ------------------------------
                        # Way 1: arx
                        train_input = outputs  # train on the output means that we tune the poles and zero gain (K) with respect to the output, because we want the model output to look like the output and NOT the input
                        
                        # Create the input matrix in order to solve for the coefficients
                        # Train the model using the training sets
                        dinputs = numderiv(inputs, t)
                        ddinputs = numderiv(dinputs, t)
                        # print('length of dinputs : ' + str(len(dinputs)))
                        # print('length of ddinputs : ' + str(len(ddinputs)))

                        first_col = np.ones((len(inputs)))
                        first_col = make_a_properlist(first_col)
                        derivative_mat_of_inputs = np.transpose([first_col, dinputs, ddinputs])

                        # Create linear regression object
                        regr = LinearRegression()
                        regr.fit(derivative_mat_of_inputs, outputs)

                        # This give the coefficients for the ratio of the : beta = B/A
                        beta = regr.coef_
                        print('beta : ' + str(beta))

                        # Need to normalize the beta coefficients before assigning B and A
                        beta_norm = beta/np.max(abs(beta))
                        print('beta_norm : ' + str(beta_norm))
                        
                        
                        # Transform the beta coefficients into A and B transfer function coefficients
                        # Lets choose stable discrete poles for A and then solve for B using the 
                        # beta = B/A relationship
                        
                        # Q : How do you manipulate beta such that you get good B/A polynomials??
                        
                        tunePOLESorNOT = 0
                        if tunePOLESorNOT == 1:
                            # ----------------------------------------------------
                            # Tune poles closest to unit circle - great if using system alone
                            # but, if you are multiplying it by another system it could cause unstability
                            trys = 1000  # Try pole placement this many times to adjust one pole such that the amplitude better matches the output signal
                            
                            err_diff = np.zeros((trys))
                            err_diff[0] = 100  # set a big number
                            err_tol = 0.1 #0.001
                            
                            # Error minimizing loop to tune a poles
                            for n in range(1,trys):
                                print('n : ' + str(n) + ', error diff[n-1] : ' + str(err_diff[n-1]))
                                a0 = 1
                                a1 = beta_norm[1]
                                a2 = a1/n

                                # To tell if the system is stable based on changing the coefficients
                                roots = np.roots([a0, a1, a2])
                                print('roots : ' + str(roots))
                                
                                # ------------
                                # Remove the imaginary components of the roots
                                real_roots = roots.real

                                # Recalculate the coefficients using the real_roots
                                den = P.polyfromroots((real_roots))
                                # den = [a0, a1, a2]
                                # ------------

                                num = beta_norm*den
                                # print('num : ' + str(num))
                                num_invert = num[::-1]
                                # print('num_invert : ' + str(num_invert))

                                # Discrete time model:
                                dt = ts
                                tf = (num_invert, den, dt)
                                # print('tf : ' + str(tf))
                                
                                pred_t, pred_output  = signal.dlsim(tf, train_input, t=t)
                                pred_output = make_a_properlist(pred_output)
                                pred_t = make_a_properlist(pred_t)

                                # Calculate error: using RMSE to evaluate the predition error
                                err_diff[n] = 1/len(pred_output) * np.sqrt(np.sum(np.square(np.array(train_input[0:len(pred_output)]) - np.array(pred_output)), axis=0, keepdims=True))
                                
                                if (err_diff[n-1] - err_diff[n]) < err_tol:
                                    break
                            # ----------------------------------------------------
                        elif tunePOLESorNOT == 0:
                            # ----------------------------------------------------
                            # Do NOT tune poles
                            a0 = 1
                            a1 = beta_norm[1]
                            a2 = a1/2
                            
                            # To tell if the system is stable based on changing the coefficients
                            roots = np.roots([a0, a1, a2])
                            print('roots : ' + str(roots))
                            
                            # ------------
                            # Remove the imaginary components of the roots
                            real_roots = roots.real

                            # Recalculate the coefficients using the real_roots
                            den = P.polyfromroots((real_roots))
                            # den = [a0, a1, a2]
                            # ------------
                            
                            num = beta_norm*den
                            # print('num : ' + str(num))
                            num_invert = num[::-1]
                            # print('num_invert : ' + str(num_invert))

                            # Discrete time model:
                            dt = ts
                            tf = (num_invert, den, dt)
                            # print('tf : ' + str(tf))
                            
                            pred_t, pred_output  = signal.dlsim(tf, train_input, t=t)
                            pred_output = make_a_properlist(pred_output)
                            pred_t = make_a_properlist(pred_t)
                            # ----------------------------------------------------
                        
                        # Then multiply a gain (K) with the denominator to get a better fit
                        max_ind = np.argmax(train_input)
                        K = inputs[max_ind]/pred_output[max_ind]

                        num = K*num_invert
                        den = den
                        
                        # Discrete time model:
                        dt = ts
                        tf = (num, den, dt)
                        print('Final H(z) tf using ARX : ' + str(tf))
                        
                        a1 = num[2]
                        b1 = num[1]
                        c1 = num[0]
                        
                        a2 = den[2]
                        b2 = den[1]
                        c2 = den[0]
                        
                        # ----------------
                        
                        # H(z) is the final transfer function, the human input-output system, because
                        # ARX fits coefficients for the input and output values accordingly.
                        # It is not perfect at recreating the output with respect to the input, because
                        # it does not project the input vector space onto the output space.  But, we 
                        # tune the coefficients to best fit the output, hoping that it will be a 
                        # decent model.
                        
                        # We give the transfer function the input and we hope to get something that looks like the output
                        # pred_t, pred_output  = signal.dlsim(tf, inputs, t=t)
                        # pred_output = make_a_properlist(pred_output)
                        # pred_t = make_a_properlist(pred_t)
                        # ------------------------------
                    
                    if human_model_choice == 2:
                        model_type = 'freq_resp'
                        # ------------------------------
                        # Way 3) frequency response
                        # ------------------------------
                        Xn_mag_in, Xn_phase_in, omeg_in, Xn_mag_half_db_in, Xn_phase_half_in, omg_half_in = get_freqresp_mag_phase(inputs, t, ts)
                        
                        Xn_mag_out, Xn_phase_out, omeg_out, Xn_mag_half_db_out, Xn_phase_half_out, omg_half_out = get_freqresp_mag_phase(outputs, t, ts)

                        which_way = 0
                        if which_way == 0:
                            # Way 0 : select fc for input and output separately, then combine Y(jw)/U(jw).
                            # Here we combine two filters for different 'natural frequencies' - each need to be 1st order
                            
                            # Input : single signal
                            choose_fc = 1  # choose_fc=0 : fc is 0.3 db drop, choose_fc=1 : Nyquist freq, choose_fc=2 : fc is where two magnitudes cross
                            single_sig = 0  #0=input, 1=output
                            fc = select_fc(fs, choose_fc, single_sig, Xn_mag_half_db_in, Xn_phase_half_in, omg_half_in, Xn_mag_half_db_out, Xn_phase_half_out, omg_half_out)
                            n = 1  # filter order
                            tf = select_filter(n, fc, fs)
                            num = tf[0]
                            den = tf[1]
                            ts_fc_in = tf[2]
                            aa2 = num[1]
                            aa3 = num[0]
                            bb2 = den[1]
                            bb3 = den[0]
                            
                            # Output : single signal
                            choose_fc = 1  # choose_fc=0 : fc is 0.3 db drop, choose_fc=1 : Nyquist freq, choose_fc=2 : fc is where two magnitudes cross
                            single_sig = 1  #0=input, 1=output
                            fc = select_fc(fs, choose_fc, single_sig, Xn_mag_half_db_out, Xn_phase_half_out, omg_half_out, Xn_mag_half_db_out, Xn_phase_half_out, omg_half_out)
                            n = 1  # filter order
                            tf = select_filter(n, fc, fs)
                            num = tf[0]
                            den = tf[1]
                            ts_fc_out = tf[2]
                            aa5 = num[1]
                            aa6 = num[0]
                            bb5 = den[1]
                            bb6 = den[0]
                            
                            # 1st order filter for Y(z) and U(z)
                            # H(z) = Y(z)/U(z) and the human input-output system becomes 4th order 
                            Hnum = [aa2*bb5, (aa2*bb6 + aa3*bb5), aa3*bb6]
                            Hden = [bb2*aa5, (bb2*aa6 + bb3*aa5), bb3*aa6]
                            
                            a1 = Hnum[2]
                            b1 = Hnum[1]
                            c1 = Hnum[0]
                            
                            a2 = Hden[2]
                            b2 = Hden[1]
                            c2 = Hden[0]
                            
                            ts_fc = min([ts_fc_in, ts_fc_out])
                        
                        elif which_way == 1:
                            # Way 1 : select fc for input and output together, there is one transfer function/filter -do 2nd order
                            choose_fc = 2  #See when the two magnitudes cross
                            single_sig = 0  #0=input, 1=output, only relavant when choose_fc = 0 or 1
                            fc = select_fc(fs, choose_fc, single_sig, Xn_mag_half_db_in, Xn_phase_half_in, omg_half_in, Xn_mag_half_db_out, Xn_phase_half_out, omg_half_out)
                            
                            n = 2  # filter order
                            tf = select_filter(n, fc, fs)
                            num = tf[0]
                            den = tf[1]
                            ts_fc = tf[2]
                            
                            a1 = num[2]
                            b1 = num[1]
                            c1 = num[0]
                            
                            a2 = den[2]
                            b2 = den[1]
                            c2 = den[0]
                        
                        # Discrete time model:
                        tf = ([a1, b1, c1], [a2, b2, c2], ts_fc)
                        print('Final H(z) tf using Frequency Response (1st order filter for Y and U) : ' + str(tf))
                        # ----------------
                        
                    if human_model_choice == 3:
                        model_type = 'n4sid'
                        # ------------------------------
                        # Way 4) n4sid
                        # ------------------------------
                        # Solve for H(s) or H(z)
                        pred_output, tf, r_squared, sysmeth, discon, which_setting = optimize_n4sid_settings(inputs, outputs, t, ts)
                        
                        plot_best_coefmeth(t, inputs, outputs, pred_output, sysmeth, r_squared, 1)
                        
                        # --------------------
                        # The output model could be discrete or continuous
                        
                        if discon == 0:   # Discrete
                            pred_output_dis_best = pred_output
                        elif discon == 1:   # Continuous
                            pred_output_con_best = pred_output
                        # --------------------
                        
                        # Discrete time model:
                        num = tf[0]
                        den = tf[1]
                        print('Final H(z) tf using n4sid : ' + str(tf))
                        
                        a1 = num[2]
                        b1 = num[1]
                        c1 = num[0]
                        
                        a2 = den[2]
                        b2 = den[1]
                        c2 = den[0]
                        
                        print('Roots of H(z) : ' + str(np.roots(den)))
                        # ------------------------------
                        # End of searching or H(z)
                    
                    
                    # --------------------
                    # --------------------
                    # Plot Human system (H(z)) response BEFORE it is multiply by Robot system (R(z))
                    # --------------------
                    # --------------------
                    print('Lets test the Final tf on the input: ')
                    pred_t, pred_output  = signal.dlsim(tf, inputs, t=t)
                    pred_output = make_a_properlist(pred_output)
                    pred_t = make_a_properlist(pred_t)

                    fig = go.Figure()
                    config = dict({'scrollZoom': True, 'displayModeBar': True, 'editable': True})

                    fig.add_trace(go.Scatter(x=t, y=inputs, name='inputs : outSIG', line = dict(color='red', width=2, dash='dash'), showlegend=True))
                    fig.add_trace(go.Scatter(x=t, y=outputs, name='outputs : outJOY', line = dict(color='blue', width=2, dash='dash'), showlegend=True))
                    fig.add_trace(go.Scatter(x=pred_t, y=pred_output, name='H(z) : predicted output', line = dict(color='black', width=2, dash='dash'), showlegend=True))
                    
                    N = np.min([len(outputs), len(pred_output)])
                    y_true = np.array(outputs[0:N])
                    y_pred = np.array(pred_output[0:N])
                    err_R2 = r2_score(y_true, y_pred)
                    fig.update_layout(title='Human model %s : R^2=%2.5f' % (model_type, err_R2), xaxis_title='time', yaxis_title='signal')
                    fig.show(config=config)
                    # --------------------
                    # ------------------------------
                    
                    
                    # --------------------
                    # Write out robot system : R(z) = 1/[z^-2 + bz^-1 + c]
                    
                    # 1st attempt to write the correct 2nd order robot system
                    # TT = 4
                    # b = (3.6*math.pi)/TT  # 1st order denomenator
                    # c = math.pi/(TT*0.9)  # 0th order denomenator
                    
                    # 2nd attempt to write the correct 2nd order robot system
                    # b = 4*0.8*math.pi
                    # c = math.pi/0.8
                    
                    # 3rd attempt to write the correct 2nd order robot system
                    zeta = 0.8
                    T = 4 # 4
                    wn = 1/(T*zeta)
                    # num = [1]  # classical formulation numerator is [wn*wn], but we used [1]
                    # den = [1, 2*zeta*wn, wn*wn]
                    b = 2*zeta*wn
                    c = wn*wn
                    # --------------------
                    
                    # --------------------
                    # Multiply robot system with human system : R(z)*H(z)
                    num = [a1, b1, c1]
                    den = [a2, b2+b*a2, c2+b*b2+c*a2, b*c2+c*b2, c*c2]
                    print('num : ' + str(num))
                    print('den : ' + str(den))
                    print('Roots of R(z)*H(z) : ' + str(np.roots(den)))
                    # --------------------
                    
                    # --------------------
                    # Solve for u using the closedloop expression of outSIG wrt u=stim_ramp*t
                    # outSIG/u = 1/[1 - R(z)*H(z)]
                    
                    
                    
                    # We invert the transfer function, because we want to solve for u
                    # u/outSIG = [1 - R(z)*H(z)]
                    num_cl = [a2, b2+b*a2, c2+b*b2+c*a2-a1, b*c2+c*b2-b1, c*c2-c1]
                    den_cl = [a2, b2+b*a2, c2+b*b2+c*a2, b*c2+c*b2, c*c2]
                    
                    # print('num : ' + str(num_cl))
                    # print('den : ' + str(den_cl))
                    # cl_sysroots = np.roots(den_cl)
                    # print('Roots of inverted closedloop to solve for u) : ' + str(cl_sysroots))
                    # --------------------
                    
                    # --------------------
                    # Check if discrete closedloop expression is stable
                    
                    roots_out = np.roots(den_cl)
                    print('u/outSIG = [1 - R(z)*H(z)] roots_out: ' + str(roots_out))
                    # --------------------
                    
                else:
                    # When outJOY/outSIG are zero, we can not solve for H(z) system
                    # going backward if outJOY and outSIG are zero.
                    # The Person needs to move the joystick in order for us to solve using ARX/frequency response.
                    
                    # Good point!
                    # When the person does not move, H(z) = 1 meaning outSIG=outJOY, according to the diagram (it seems counter intuitive thinking about it) 
                    
                    # --------------------
                    # Write out robot system : R(z) = 1/[z^-2 + bz^-1 + c]
                    
                    # 1st attempt to write the correct 2nd order robot system
                    # TT = 4
                    # b = (3.6*math.pi)/TT  # 1st order denomenator
                    # c = math.pi/(TT*0.9)  # 0th order denomenator
                    
                    # 2nd attempt to write the correct 2nd order robot system
                    # b = 4*0.8*math.pi
                    # c = math.pi/0.8
                    
                    # 3rd attempt to write the correct 2nd order robot system
                    zeta = 0.8
                    T = 4 # 4
                    wn = 1/(T*zeta)
                    # num = [1]  # classical formulation numerator is [wn*wn], but we used [1]
                    # den = [1, 2*zeta*wn, wn*wn]
                    b = 2*zeta*wn
                    c = wn*wn
                    # --------------------
                    
                    # --------------------
                    # Solve for u using the closedloop expression of outSIG wrt u=stim_ramp*t
                    # outSIG/u = 1/[1 - R(z)*H(z)]
                    # outSIG/u = 1/[1 - R(z)]
                    
                    # We invert the transfer function, because we want to solve for u
                    # u/outSIG = [1 - R(z)]
                    num_cl = [1, b, c-1]
                    den_cl = [1, b, c]
                    print('num : ' + str(num_cl))
                    print('den : ' + str(den_cl))
                    print('Roots of inverted closedloop to solve for u) : ' + str(np.roots(den_cl)))
                    # --------------------
                    
                    
                    # u = np.zeros((len(inputs)))
                    # u_t = t
                
                
               # --------------------
               
               
                # Solve for u
                # Continuous time: 
                # u_t, u, xout = lsim((num, den), U=outSIG[tr][:,axis_out[tr]], T=time[tr])
                
                # Discrete time:
                u_t, u  = signal.dlsim((num_cl, den_cl, ts), inputs, t=t)
                u = make_a_properlist(u)
                u_t = make_a_properlist(u_t)
                
                # --------------------
                
                # Finally, we want to solve for stim_ramp using : u = stim_ramp * time
                # stim_ramp = u/time
                
                print('length of u : ' + str(len(u)))
                print('length of time[tr] : ' + str(len(time[tr])))
                
                N = np.min([len(u), len(time[tr])])
                sr = np.array(u[0:N])/time[tr][0:N]
                # ------------------------------
               
                    
                # --------------------
                fig = go.Figure()
                config = dict({'scrollZoom': True, 'displayModeBar': True, 'editable': True})
                
                
                # Plotting the stimulus ramp, joystick input, and cabin movement
                
                fig.add_trace(go.Scatter(x=time[tr][0:N], y=u[0:N], name='u : %s' % (varr['which_exp']), line = dict(color='cyan', width=2, dash='dash'), showlegend=True))
                
                fig.add_trace(go.Scatter(x=time[tr][0:N], y=sr[0:N], name='sr : %s' % (varr['which_exp']), line = dict(color='red', width=2, dash='dash'), showlegend=True))
                
                # Plotting joystick
                fig.add_trace(go.Scatter(x=time[tr], y=outJOY[tr][:,axis_out[tr]], name='outJOY axstim : %s' % (varr['which_exp']), line = dict(color='blue', width=2, dash='dash'), showlegend=True))
                
                # Plotting actual cabin position
                fig.add_trace(go.Scatter(x=time[tr], y=outSIG[tr][:,axis_out[tr]], name='outSIG axstim : %s' % (varr['which_exp']), line = dict(color='black', width=2, dash='dash'), showlegend=True))
                
                fig.update_layout(title='stim_ramp : s : %d, tr : %d, stim_axis : %d' % (s, tr, axis_out[tr]), xaxis_title='data points', yaxis_title='stim ramp')
                fig.show(config=config)
                # --------------------
                
>>>>>>> 94b06cd4776edc5e6880e69ca0d1eefbe92d257c
    return