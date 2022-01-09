import numpy as np

def convert_rowlist_2_columnlist(vec):
    
    # for visual printing of lists

    vec_c = np.zeros((len(vec),1))

    for i in range(len(vec)):
        vec_c[i] = vec[i] 
    vec_c = np.concatenate(vec_c).ravel().tolist()
    
    return vec_c
