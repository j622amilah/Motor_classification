<<<<<<< HEAD
import numpy as np


def interpretation_of_kstest(statistic, pvalue):
     # or np.isclose(pvalue, 1, atol=0.1)
    if np.isclose(statistic, 0, atol=0.01):    # default atol=1e-08
        out = 1 # result is parametric/normal
    else:
        out = 0  # result is non-parametric/non-normal
=======
import numpy as np


def interpretation_of_kstest(statistic, pvalue):
     # or np.isclose(pvalue, 1, atol=0.1)
    if np.isclose(statistic, 0, atol=0.01):    # default atol=1e-08
        out = 1 # result is parametric/normal
    else:
        out = 0  # result is non-parametric/non-normal
>>>>>>> 94b06cd4776edc5e6880e69ca0d1eefbe92d257c
    return out