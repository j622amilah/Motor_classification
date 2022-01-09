<<<<<<< HEAD
# Created by Jamilah Foucher, Aout 25, 2021 

# Purpose:  To stablize an unstable transfer function.  Only works for continuous systems at the moment.


# Input VARIABLES:
# (1) tf
# (2) sys_type

# Output VARIABLES:
# (1) den_pp
# 

import numpy as np

import plotly.graph_objects as go

from scipy.signal import tf2ss

from numpy.polynomial import polynomial as P

# Discrete time lti
from scipy import signal

import sys
sys.path.insert(1, 'C:\\Users\\jamilah\\Documents\\Sourceforge_analysis_PROJECTS\\Motor_classification')

from subfunctions.make_a_properlist import *
from subfunctions.findall import *



def pole_placement(tf, sys_type):

    # [1] Applying some control theory ideas : are the roots stable? Meaning that are the roots lie in the unit circle?
    # Meaning that for a discrete time invarient system the poles give dynamics where the output will
    # result in bounded values
    
    (num, den) = tf
    
    roots_out = np.roots(den)
    # print('roots_out: ' + str(roots_out))
    
    den_pp = []   # initialization
    
    if sys_type == 'disc':
        # ---------------------
        # For discrete system
        # ---------------------
        # Test the roots of the system to see if they are inside the unit circle
        flag = 0
        for i in roots_out:
            # print('abs(i.real) : ' + str(abs(i.real)))
            if np.round(abs(i.real), 1) > 1:
                flag = 1
                break

        # print('flag : ' + str(flag))
        
        if flag == 1:
            
            # Choose the new stable poles
            newp = []
            for i in roots_out:
                if abs(i.real) > 1:
                    # Reassign pole such that it is inside the unit circle, preserve the sign
                    newp = newp + [i/10]
                else:
                    newp = newp + [i]
            newp = make_a_properlist(newp)
            newp = np.array(newp)
            
            # Find a new stable system
            
            
            # Get new coeficients for denomenator
            

    elif sys_type == 'cont':
        # ---------------------
        # For continuous system
        # ---------------------
        # Test the roots of the system to see if they are on the right hand
        flag = 0
        for i in roots_out:
            if i >= 0:
                flag = 1
                break

        # print('flag : ' + str(flag))
        
        
        if flag == 1:  # roots are 0 or positive, pole placement is NEEDED
            
            # Do pole placement for a continuous system
            A, B, C, D = tf2ss(num, den)
            
            # ---------------------
            
            # Look for all roots that are negative, put them in a vector
            newvec, ind_newvec = findall(roots_out, '<', 0)
            
            # print('newvec : ' + str(newvec))
            # print('ind_newvec : ' + str(ind_newvec))
            newvec = np.array(newvec)
            
            # If there are NO negative roots, create at least one negative root below
            
            if not newvec.any():    # Means that all the poles are zero or positive, 
                # Temporarily correct the poles (because they will be corrected below) and make all roots_out negative
                temp_roots_out = -np.array(roots_out)
                newvec, ind_newvec = findall(temp_roots_out, '<', 0)
                # Randomly pick one of the roots that are negative
                rlist = np.random.permutation(len(ind_newvec))
                # print('rlist : ' + str(rlist))
                
                stable_pole = temp_roots_out[ind_newvec[rlist[0]]]
                # print('stable_pole : ' + str(stable_pole))
                
                
            # ---------------------
            # At this point, we have at least one negative root, but the others could be zero or positive
            
            # Choose the new stable poles
            newp = []
            cout = 0
            for i in roots_out:
                if i >= 0:
                    if i == 0:
                        # If the root is zero, make it a multiple of existing negative poles
                        mult_neg  = 2*stable_pole
                        newp = newp + [mult_neg]
                    else:
                        # If the root is positive, reassign pole to negative side

                        # Check to ensure the new reassigned pole is not an existing negative pole
                        longvec = roots_out
                        shortvec = longvec[cout]
                        # Returns the unique values in 1st array NOT in 2nd array
                        roots_out_except_cur_root = np.setdiff1d(longvec, shortvec)
                        
                        for q in roots_out_except_cur_root:
                            if np.round(q, 2) == np.round(-i, 2):
                                # assign the positive root to a multiple
                                # or should it be a matching complex conjugate pair?
                                newp = newp + [-3*i]  # could try 0.5
                            else:
                                newp = newp + [-i]
                else:
                    # Root is negative, do nothing
                    newp = newp + [i]
                    
                cout = cout + 1
            newp = make_a_properlist(newp)
            newp = np.array(newp)

            # Find a new stable system
            fsf = signal.place_poles(A, B, newp)  # uses YT method
            roots_out = fsf.computed_poles   # resave over roots_out
            # print('CORRECTED poles : ' + str(roots_out))

            # Get new coeficients for denomenator
            den_pp = P.polyfromroots((roots_out))
        
        elif flag == 0:  # roots are negative, pole placement is NOT NEEDED for stability
            den_pp = den
    
    
    # Figure of old poles and zeros with respect to the new poles and zeros
    
    
    
=======
# Created by Jamilah Foucher, Aout 25, 2021 

# Purpose:  To stablize an unstable transfer function.  Only works for continuous systems at the moment.


# Input VARIABLES:
# (1) tf
# (2) sys_type

# Output VARIABLES:
# (1) den_pp
# 

import numpy as np

import plotly.graph_objects as go

from scipy.signal import tf2ss

from numpy.polynomial import polynomial as P

# Discrete time lti
from scipy import signal

import sys
sys.path.insert(1, 'C:\\Users\\jamilah\\Documents\\Sourceforge_analysis_PROJECTS\\Motor_classification')

from subfunctions.make_a_properlist import *
from subfunctions.findall import *



def pole_placement(tf, sys_type):

    # [1] Applying some control theory ideas : are the roots stable? Meaning that are the roots lie in the unit circle?
    # Meaning that for a discrete time invarient system the poles give dynamics where the output will
    # result in bounded values
    
    (num, den) = tf
    
    roots_out = np.roots(den)
    # print('roots_out: ' + str(roots_out))
    
    den_pp = []   # initialization
    
    if sys_type == 'disc':
        # ---------------------
        # For discrete system
        # ---------------------
        # Test the roots of the system to see if they are inside the unit circle
        flag = 0
        for i in roots_out:
            # print('abs(i.real) : ' + str(abs(i.real)))
            if np.round(abs(i.real), 1) > 1:
                flag = 1
                break

        # print('flag : ' + str(flag))
        
        if flag == 1:
            
            # Choose the new stable poles
            newp = []
            for i in roots_out:
                if abs(i.real) > 1:
                    # Reassign pole such that it is inside the unit circle, preserve the sign
                    newp = newp + [i/10]
                else:
                    newp = newp + [i]
            newp = make_a_properlist(newp)
            newp = np.array(newp)
            
            # Find a new stable system
            
            
            # Get new coeficients for denomenator
            

    elif sys_type == 'cont':
        # ---------------------
        # For continuous system
        # ---------------------
        # Test the roots of the system to see if they are on the right hand
        flag = 0
        for i in roots_out:
            if i >= 0:
                flag = 1
                break

        # print('flag : ' + str(flag))
        
        
        if flag == 1:  # roots are 0 or positive, pole placement is NEEDED
            
            # Do pole placement for a continuous system
            A, B, C, D = tf2ss(num, den)
            
            # ---------------------
            
            # Look for all roots that are negative, put them in a vector
            newvec, ind_newvec = findall(roots_out, '<', 0)
            
            # print('newvec : ' + str(newvec))
            # print('ind_newvec : ' + str(ind_newvec))
            newvec = np.array(newvec)
            
            # If there are NO negative roots, create at least one negative root below
            
            if not newvec.any():    # Means that all the poles are zero or positive, 
                # Temporarily correct the poles (because they will be corrected below) and make all roots_out negative
                temp_roots_out = -np.array(roots_out)
                newvec, ind_newvec = findall(temp_roots_out, '<', 0)
                # Randomly pick one of the roots that are negative
                rlist = np.random.permutation(len(ind_newvec))
                # print('rlist : ' + str(rlist))
                
                stable_pole = temp_roots_out[ind_newvec[rlist[0]]]
                # print('stable_pole : ' + str(stable_pole))
                
                
            # ---------------------
            # At this point, we have at least one negative root, but the others could be zero or positive
            
            # Choose the new stable poles
            newp = []
            cout = 0
            for i in roots_out:
                if i >= 0:
                    if i == 0:
                        # If the root is zero, make it a multiple of existing negative poles
                        mult_neg  = 2*stable_pole
                        newp = newp + [mult_neg]
                    else:
                        # If the root is positive, reassign pole to negative side

                        # Check to ensure the new reassigned pole is not an existing negative pole
                        longvec = roots_out
                        shortvec = longvec[cout]
                        # Returns the unique values in 1st array NOT in 2nd array
                        roots_out_except_cur_root = np.setdiff1d(longvec, shortvec)
                        
                        for q in roots_out_except_cur_root:
                            if np.round(q, 2) == np.round(-i, 2):
                                # assign the positive root to a multiple
                                # or should it be a matching complex conjugate pair?
                                newp = newp + [-3*i]  # could try 0.5
                            else:
                                newp = newp + [-i]
                else:
                    # Root is negative, do nothing
                    newp = newp + [i]
                    
                cout = cout + 1
            newp = make_a_properlist(newp)
            newp = np.array(newp)

            # Find a new stable system
            fsf = signal.place_poles(A, B, newp)  # uses YT method
            roots_out = fsf.computed_poles   # resave over roots_out
            # print('CORRECTED poles : ' + str(roots_out))

            # Get new coeficients for denomenator
            den_pp = P.polyfromroots((roots_out))
        
        elif flag == 0:  # roots are negative, pole placement is NOT NEEDED for stability
            den_pp = den
    
    
    # Figure of old poles and zeros with respect to the new poles and zeros
    
    
    
>>>>>>> 94b06cd4776edc5e6880e69ca0d1eefbe92d257c
    return den_pp