import numpy as np

def make_a_properlist(vec):
    
    out = []
    for i in range(len(vec)):
    	out = out + [np.ravel(vec[i])]
    vecout = np.concatenate(out).ravel().tolist()
    
    # OR
    
    # np.ravel()
    
    # OR
    
    
    # These only work if array is nested one time 

    # vec = np.array(vec)
    # vecout = vec.flatten()
    
    # OR
    
    # functools_reduce
    # import functools
    # import operator
    # functools.reduce(operator.iconcat, a, [])

    # # OR

    # out = []
    # for sublist in a:
    # out.extend(sublist)
    
    
    return vecout
