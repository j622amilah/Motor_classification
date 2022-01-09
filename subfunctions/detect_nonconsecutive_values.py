import numpy as np

def detect_nonconsecutive_values(vec):
    
    non_consec_vec = [vec[0]]
    non_consec_ind = [0]
    
    for i in range(len(vec)-1):
        if vec[i] != vec[i+1]:
            # not consecutive data point
            non_consec_vec = non_consec_vec + [vec[i+1]]
            non_consec_ind = non_consec_ind + [i+1]
    
    non_consec_vec = np.ravel(non_consec_vec)
    non_consec_ind = np.ravel(non_consec_ind)
    
    return non_consec_vec, non_consec_ind
