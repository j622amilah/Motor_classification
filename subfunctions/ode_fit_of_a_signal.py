<<<<<<< HEAD
# Created by Jamilah Foucher, Aout 25, 2021 

# Purpose: To estimate an ordinary differential equation from a time series.

# Input VARIABLES:
# (1) sig is the time series/signal
# (2) t is the corresponding time


# Output VARIABLES:
# (1) ode_coef are the coeffcients of the ordinary differential equation


# Example: 
# ts = 0.1
# start_val = 0
# stop_val = 10
# f = 1/ts  # sampling frequency
# N = int(f*stop_val)
# t = np.multiply(range(start_val, N), ts)

# angle = t/max(t)*(4*math.pi)
# # print('angle : ' + str(angle))

# sig = 2*np.sin(angle)
# sig = make_a_properlist(sig)

# ode_coef = ode_fit_of_a_signal(sig, t)


import numpy as np

# Plotting
import plotly.graph_objects as go

# Filtering
from scipy import signal

from scipy.signal import tf2ss

from numpy.polynomial import polynomial as P

# Personal python functions
import sys
sys.path.insert(1, 'C:\\Users\\jamilah\\Documents\\Sourceforge_analysis_PROJECTS\\Motor_classification')
from subfunctions.numderiv import *
from subfunctions.make_a_properlist import *


def ode_fit_of_a_signal(sig, t):

    # Filter
    n = 4   # filter order
    fs = 10 # 250 # data sampling frequency (Hz)
    fc = fs/2 - 0.0001 # 10  # Cut-off frequency of the filter
    w = fc / (fs / 2) # Normalize the frequency
    b, a = signal.butter(n, w, 'low')  # 3rd order
    sigfilt = signal.filtfilt(b, a, sig)
    
    p = np.polyfit(t, sigfilt, 1)
    w0 = p[0]
    print('w0 : ' + str(w0))
    
    #Take derivative of signal
    sig_dot = numderiv(sigfilt,t)
    p = np.polyfit(t[0:len(sig_dot)], sig_dot, 1)
    w1 = p[0]
    print('w1 : ' + str(w1))
    
    #Take derivative of derivative
    sig_ddot = numderiv(sig_dot, t[0:len(sig_dot)])
    p = np.polyfit(t[0:len(sig_ddot)], sig_ddot, 1)
    w2 = p[0]
    print('w2 : ' + str(w2))
    
    # ------------------------------
    # [0] Initial output
    ode_coef = [w2, w1, w0]
    
    # Determine sign of coeficients
    y_ode1 = np.multiply(ode_coef[2], sig_ddot) + np.multiply(ode_coef[1], sig_dot) + np.multiply(ode_coef[0], sigfilt)
    err_diff1 = 1/len(y_ode1) * np.sqrt(np.sum(np.square(sigfilt - y_ode1), axis=0, keepdims=True)) 
    
    y_ode2 = np.multiply(-ode_coef[2], sig_ddot) + np.multiply(-ode_coef[1], sig_dot) + np.multiply(-ode_coef[0], sigfilt)
    err_diff2 = 1/len(y_ode2) * np.sqrt(np.sum(np.square(sigfilt - y_ode2), axis=0, keepdims=True))
    if err_diff1 > err_diff2:
        ode_coef = -ode_coef
    
    
    y_ode = np.multiply(ode_coef[2], sig_ddot) + np.multiply(ode_coef[1], sig_dot) + np.multiply(ode_coef[0], sigfilt)
    
    # [1] Applying some control theory ideas : are the roots stable? Meaning that are the roots lie in the unit circle?
    # Meaning that for a discrete time invarient system the poles give dynamics where the output will
    # result in bounded values
    roots_out = np.roots(ode_coef)
    print('Original poles ' + str(roots_out))
    
    # For continuous system : want stable roots to be negative, and unstable roots to be positive
    # sign_roots_out = np.sign(roots_out)
    
    # For discrete system
    sign_roots_out = []
    for rts in roots_out:
        if abs(rts) > 1:
            sign_roots_out = sign_roots_out + [1]  # Unstable, so make a positive number 
        else:
            sign_roots_out = sign_roots_out + [-1]   # Stable, so make a negative number
    
    print('sign_roots_out : ' + str(sign_roots_out))
    
    
    if np.sum(sign_roots_out) + len(sign_roots_out) != 0:
        print('Not all the poles are negative!!')
        
        # Do pole placement 
        num = 1
        den = ode_coef
        A, B, C, D = tf2ss(num, den)
        
        # For continuous system : Set desired poles
        newp = []
        for nofp in range(len(sign_roots_out)):
            if nofp < 0:
                newp = newp + [roots_out[nofp]]
            else:
                newp = newp + [-roots_out[nofp]]
        
        # Find a new stable system
        fsf = signal.place_poles(A, B, newp)  # uses YT method
        roots_out = fsf.computed_poles   # resave over roots_out
        print('CORRECTED poles : ' + str(roots_out))
        
        # Get new coeficients for ode
        ode_coef = P.polyfromroots((roots_out))
        y_ode = np.multiply(ode_coef[2], sig_ddot) + np.multiply(ode_coef[1], sig_dot) + np.multiply(ode_coef[0], sigfilt)
    
    # ------------------------------
    
    # ------------------------------
    # [2] Incrementally push the largest pole to the right-hand-side (make more negative) to
    # increase the amplitude of the response, such that the error between y_ode and original signal
    # are minimal
    # print('max y_ode : ' + str(np.max(y_ode)))
    # print('max sigfilt : ' + str(np.max(sigfilt)))
    
    trys = 1000  # Try pole placement this many times to adjust one pole such that the amplitude better matches the output signal 
    err_tol = 0.01
    
    for n in range(2,trys): 
        # Only change one pole so that the phase does not change : we only want the amplitude of ode to change
        
        # Using RMSE to evaluate the predition error
        err_diff = 1/len(y_ode) * np.sqrt(np.sum(np.square(sigfilt - y_ode), axis=0, keepdims=True)) 
        
        
        # Find the pole closest to zero, and slowly move it towards the unit circle
        # root2change = np.min(roots_out)*n
        root2change = roots_out[-1]*n
        
        print('n : ' + str(n) + ', error diff : ' + str(err_diff) + ', root2change : ' + str(root2change))
        
        if err_diff > err_tol and abs(root2change) < 1:
            # Do pole placement 
            num = 1
            den = ode_coef
            A, B, C, D = tf2ss(num, den)
            
            # Set desired poles : closer to the unit circle gives a larger amplitude
            newp = [roots_out[0:(len(roots_out)-1)], root2change]
            newp = make_a_properlist(newp)
            
            fsf = signal.place_poles(A, B, newp)  # uses YT method
            poles_out = fsf.computed_poles
            print('CORRECTED poles : ' + str(poles_out))
        
            # Get new coeficients for ode
            ode_coef = P.polyfromroots((poles_out))
            
            # Determine sign of coeficients
            y_ode1 = np.multiply(ode_coef[2], sig_ddot) + np.multiply(ode_coef[1], sig_dot) + np.multiply(ode_coef[0], sigfilt)
            err_diff1 = 1/len(y_ode1) * np.sqrt(np.sum(np.square(sigfilt - y_ode1), axis=0, keepdims=True)) 
            
            y_ode2 = np.multiply(-ode_coef[2], sig_ddot) + np.multiply(-ode_coef[1], sig_dot) + np.multiply(-ode_coef[0], sigfilt)
            err_diff2 = 1/len(y_ode2) * np.sqrt(np.sum(np.square(sigfilt - y_ode2), axis=0, keepdims=True))
            if err_diff1 > err_diff2:
                ode_coef = -ode_coef
            
        else:
            break  # break the for loop
        
        
    # ------------------------------

    # ------------------------------
    # Plotting check
    fig = go.Figure()
    config = dict({'scrollZoom': True, 'displayModeBar': True, 'editable': True})
    xxORG = list(range(len(sigfilt)))

    fig.add_trace(go.Scatter(x=xxORG, y=sigfilt, name='x', line = dict(color='red', width=2, dash='dash'), showlegend=True))
    
    fig.add_trace(go.Scatter(x=xxORG, y=y_ode, name='y_ode', line = dict(color='blue', width=2, dash='dash'), showlegend=True))
    
    # fig.add_trace(go.Scatter(x=xxORG, y=y_ode_corr, name='y_ode_corr', line = dict(color='magenta', width=2, dash='dash'), showlegend=True))

    fig.update_layout(title='signal with estimated ode', xaxis_title='data points', yaxis_title='amplitude')
    fig.show(config=config)
    # ------------------------------
    
=======
# Created by Jamilah Foucher, Aout 25, 2021 

# Purpose: To estimate an ordinary differential equation from a time series.

# Input VARIABLES:
# (1) sig is the time series/signal
# (2) t is the corresponding time


# Output VARIABLES:
# (1) ode_coef are the coeffcients of the ordinary differential equation


# Example: 
# ts = 0.1
# start_val = 0
# stop_val = 10
# f = 1/ts  # sampling frequency
# N = int(f*stop_val)
# t = np.multiply(range(start_val, N), ts)

# angle = t/max(t)*(4*math.pi)
# # print('angle : ' + str(angle))

# sig = 2*np.sin(angle)
# sig = make_a_properlist(sig)

# ode_coef = ode_fit_of_a_signal(sig, t)


import numpy as np

# Plotting
import plotly.graph_objects as go

# Filtering
from scipy import signal

from scipy.signal import tf2ss

from numpy.polynomial import polynomial as P

# Personal python functions
import sys
sys.path.insert(1, 'C:\\Users\\jamilah\\Documents\\Sourceforge_analysis_PROJECTS\\Motor_classification')
from subfunctions.numderiv import *
from subfunctions.make_a_properlist import *


def ode_fit_of_a_signal(sig, t):

    # Filter
    n = 4   # filter order
    fs = 10 # 250 # data sampling frequency (Hz)
    fc = fs/2 - 0.0001 # 10  # Cut-off frequency of the filter
    w = fc / (fs / 2) # Normalize the frequency
    b, a = signal.butter(n, w, 'low')  # 3rd order
    sigfilt = signal.filtfilt(b, a, sig)
    
    p = np.polyfit(t, sigfilt, 1)
    w0 = p[0]
    print('w0 : ' + str(w0))
    
    #Take derivative of signal
    sig_dot = numderiv(sigfilt,t)
    p = np.polyfit(t[0:len(sig_dot)], sig_dot, 1)
    w1 = p[0]
    print('w1 : ' + str(w1))
    
    #Take derivative of derivative
    sig_ddot = numderiv(sig_dot, t[0:len(sig_dot)])
    p = np.polyfit(t[0:len(sig_ddot)], sig_ddot, 1)
    w2 = p[0]
    print('w2 : ' + str(w2))
    
    # ------------------------------
    # [0] Initial output
    ode_coef = [w2, w1, w0]
    
    # Determine sign of coeficients
    y_ode1 = np.multiply(ode_coef[2], sig_ddot) + np.multiply(ode_coef[1], sig_dot) + np.multiply(ode_coef[0], sigfilt)
    err_diff1 = 1/len(y_ode1) * np.sqrt(np.sum(np.square(sigfilt - y_ode1), axis=0, keepdims=True)) 
    
    y_ode2 = np.multiply(-ode_coef[2], sig_ddot) + np.multiply(-ode_coef[1], sig_dot) + np.multiply(-ode_coef[0], sigfilt)
    err_diff2 = 1/len(y_ode2) * np.sqrt(np.sum(np.square(sigfilt - y_ode2), axis=0, keepdims=True))
    if err_diff1 > err_diff2:
        ode_coef = -ode_coef
    
    
    y_ode = np.multiply(ode_coef[2], sig_ddot) + np.multiply(ode_coef[1], sig_dot) + np.multiply(ode_coef[0], sigfilt)
    
    # [1] Applying some control theory ideas : are the roots stable? Meaning that are the roots lie in the unit circle?
    # Meaning that for a discrete time invarient system the poles give dynamics where the output will
    # result in bounded values
    roots_out = np.roots(ode_coef)
    print('Original poles ' + str(roots_out))
    
    # For continuous system : want stable roots to be negative, and unstable roots to be positive
    # sign_roots_out = np.sign(roots_out)
    
    # For discrete system
    sign_roots_out = []
    for rts in roots_out:
        if abs(rts) > 1:
            sign_roots_out = sign_roots_out + [1]  # Unstable, so make a positive number 
        else:
            sign_roots_out = sign_roots_out + [-1]   # Stable, so make a negative number
    
    print('sign_roots_out : ' + str(sign_roots_out))
    
    
    if np.sum(sign_roots_out) + len(sign_roots_out) != 0:
        print('Not all the poles are negative!!')
        
        # Do pole placement 
        num = 1
        den = ode_coef
        A, B, C, D = tf2ss(num, den)
        
        # For continuous system : Set desired poles
        newp = []
        for nofp in range(len(sign_roots_out)):
            if nofp < 0:
                newp = newp + [roots_out[nofp]]
            else:
                newp = newp + [-roots_out[nofp]]
        
        # Find a new stable system
        fsf = signal.place_poles(A, B, newp)  # uses YT method
        roots_out = fsf.computed_poles   # resave over roots_out
        print('CORRECTED poles : ' + str(roots_out))
        
        # Get new coeficients for ode
        ode_coef = P.polyfromroots((roots_out))
        y_ode = np.multiply(ode_coef[2], sig_ddot) + np.multiply(ode_coef[1], sig_dot) + np.multiply(ode_coef[0], sigfilt)
    
    # ------------------------------
    
    # ------------------------------
    # [2] Incrementally push the largest pole to the right-hand-side (make more negative) to
    # increase the amplitude of the response, such that the error between y_ode and original signal
    # are minimal
    # print('max y_ode : ' + str(np.max(y_ode)))
    # print('max sigfilt : ' + str(np.max(sigfilt)))
    
    trys = 1000  # Try pole placement this many times to adjust one pole such that the amplitude better matches the output signal 
    err_tol = 0.01
    
    for n in range(2,trys): 
        # Only change one pole so that the phase does not change : we only want the amplitude of ode to change
        
        # Using RMSE to evaluate the predition error
        err_diff = 1/len(y_ode) * np.sqrt(np.sum(np.square(sigfilt - y_ode), axis=0, keepdims=True)) 
        
        
        # Find the pole closest to zero, and slowly move it towards the unit circle
        # root2change = np.min(roots_out)*n
        root2change = roots_out[-1]*n
        
        print('n : ' + str(n) + ', error diff : ' + str(err_diff) + ', root2change : ' + str(root2change))
        
        if err_diff > err_tol and abs(root2change) < 1:
            # Do pole placement 
            num = 1
            den = ode_coef
            A, B, C, D = tf2ss(num, den)
            
            # Set desired poles : closer to the unit circle gives a larger amplitude
            newp = [roots_out[0:(len(roots_out)-1)], root2change]
            newp = make_a_properlist(newp)
            
            fsf = signal.place_poles(A, B, newp)  # uses YT method
            poles_out = fsf.computed_poles
            print('CORRECTED poles : ' + str(poles_out))
        
            # Get new coeficients for ode
            ode_coef = P.polyfromroots((poles_out))
            
            # Determine sign of coeficients
            y_ode1 = np.multiply(ode_coef[2], sig_ddot) + np.multiply(ode_coef[1], sig_dot) + np.multiply(ode_coef[0], sigfilt)
            err_diff1 = 1/len(y_ode1) * np.sqrt(np.sum(np.square(sigfilt - y_ode1), axis=0, keepdims=True)) 
            
            y_ode2 = np.multiply(-ode_coef[2], sig_ddot) + np.multiply(-ode_coef[1], sig_dot) + np.multiply(-ode_coef[0], sigfilt)
            err_diff2 = 1/len(y_ode2) * np.sqrt(np.sum(np.square(sigfilt - y_ode2), axis=0, keepdims=True))
            if err_diff1 > err_diff2:
                ode_coef = -ode_coef
            
        else:
            break  # break the for loop
        
        
    # ------------------------------

    # ------------------------------
    # Plotting check
    fig = go.Figure()
    config = dict({'scrollZoom': True, 'displayModeBar': True, 'editable': True})
    xxORG = list(range(len(sigfilt)))

    fig.add_trace(go.Scatter(x=xxORG, y=sigfilt, name='x', line = dict(color='red', width=2, dash='dash'), showlegend=True))
    
    fig.add_trace(go.Scatter(x=xxORG, y=y_ode, name='y_ode', line = dict(color='blue', width=2, dash='dash'), showlegend=True))
    
    # fig.add_trace(go.Scatter(x=xxORG, y=y_ode_corr, name='y_ode_corr', line = dict(color='magenta', width=2, dash='dash'), showlegend=True))

    fig.update_layout(title='signal with estimated ode', xaxis_title='data points', yaxis_title='amplitude')
    fig.show(config=config)
    # ------------------------------
    
>>>>>>> 94b06cd4776edc5e6880e69ca0d1eefbe92d257c
    return ode_coef