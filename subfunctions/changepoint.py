import numpy as np

# Personal python functions
import sys
sys.path.insert(1, 'C:\\Users\\jamilah\\Documents\\Sourceforge_analysis_PROJECTS\\Motor_classification')
from subfunctions.make_a_properlist import *


def CP(x, count):
    x_avg, S, S_min, S_max, S_diff = CUMSUM_J(x)
    Con_level, m_CUMSUM, m_MSE = procedure(x, S, S_max, S_diff, count)
    avgm_MSE = np.mean(m_MSE)
    avgCon_level, change = sigcheck(Con_level, avgm_MSE)
    
    return avgCon_level, change, avgm_MSE
	
# -------------------------------------------------

def CUMSUM_J(x):
    x_avg = np.mean(x)

    # 2: Start the cumulative sum at zero by setting S_{0} = 0
    S = []
    S.append(0)

    # 3: Calculate the other cumulative sums by adding the difference between
    # current value and the average to the previous sum, i.e.,S_{i}=S_{i-1} + (x_{i}-x_avg) for i = 1, 2,...,24
    for i in range(1, len(x)):
        S.append(S[i-1] + (x[i-1] - x_avg))
        
    # 4: Calculate an estimator of the magnitude of the change
    S_min = np.min(S)
    S_max = np.max(S)
    S_diff = S_max - S_min
    
    return x_avg, S, S_min, S_max, S_diff

# -------------------------------------------------

def procedure(x, S, S_max, S_diff, count):

    Con_level = []
    m_CUMSUM = []
    m_MSE = []
    
    # Repeat this bootstraping analysis 10 times to see if it is consistent
    for j in range(10):
        # 5: Bootstrap analysis
        N = 1000  # N = the number of bootstrap samples performed
        
        x_boot = {}
        x_avg_boot = []
        S_boot = []
        S_min_boot = []
        S_max_boot = []
        S_diff_boot = []
        
        for i in range(N):
            x_boot_order = np.random.permutation(len(x))
            
            tmp = []
            for k in range(len(x)):
                tmp.append(x[x_boot_order[k]])
            x_boot[i] = tmp
            
            x_avg_boot_tmp, S_boot_tmp, S_min_boot_tmp, S_max_boot_tmp, S_diff_boot_tmp = CUMSUM_J(x_boot[i])
            S_diff_boot.append(S_diff_boot_tmp)

        # A bootstrap analysis consists of performing a large number of bootstraps and counting the number of bootstraps for which S_diff_boot < S_diff.
        # Let N be the number of bootstrap samples performed and let X be the number of bootstraps for which S_diff_boot < S_diff.  
        X = 0
        for i in range(N):
            if S_diff_boot[i] < S_diff:
                X = X + 1  # X = the number of bootstraps for which S_diff# < S_diff

        Con_level.append(100*(X/N))  # Confidence level that a change occurred as a percentage
        
        S_diff_all = S_diff, S_diff_boot
        S_diff_all = make_a_properlist(S_diff_all)
        
        # Sm = the point furthest from zeros in the CUMSUM chart
        Sm = S_max

        for i in range(len(S)):
            if S[i] == S_max:
                m = i  # m = the last point before the change occurred, the point m+1 estimates the first point after the change
        m_CUMSUM.append(m)

        # 7: Second estimator of when the change occurred is the mean square error
        # (MSE) estimator.  The value of m that minimizes MSE(m) is the best
        # estimator of the last point before the change.
        MSE_m = []
        for m in range(len(x)):
            x_avg1 = np.sum(x[0:m-1])/m

            x_avg2 = np.sum(x[m:len(x)])/(len(x) - m)

            MSE_m.append(np.sum((x[0:m-1] - x_avg1)**2) + np.sum((x[m:len(x)] - x_avg2)**2) )
        
        print('MSE_m:', MSE_m)
        
        for i in range(len(x)):
            if MSE_m[i] == np.min(MSE_m):
                m_MSE.append(i)  # The value of m minimizing MSE(m)
    
    return Con_level, m_CUMSUM, m_MSE

# -------------------------------------------------

def sigcheck(Con_level, m_MSE):

    avgCon_level = np.mean(Con_level)
    if avgCon_level > 90:
        # print('Change detected: datapoint = ', m_MSE)
        change = 1
    else:
        # print('No change detected')
        change = 0
    
    return avgCon_level, change

# -------------------------------------------------

def changepoint(x):
    
    trig = 'loop'
    count = 0
    
    xdict = {}
    xdict[count] = x
    
    nc = 0
    levels = 0
    
    avgCon_level = []
    change = []
    avgm_MSE = []
    
    while trig == 'loop':
        avgCon_level_cur, change_cur, avgm_MSE_cur = CP(xdict[count], count)
        avgCon_level.append(avgCon_level_cur)
        change.append(change_cur)
        avgm_MSE.append(avgm_MSE_cur)
        
        if change_cur == 1:  # if a change was detected
            # Split data in half: start with left side
            # print('avgm_MSE[count] : ', avgm_MSE[count])
            xdict[int(count+1)] = xdict[count][0:int(avgm_MSE[count]-1)]
            
            levels = 0
            for u in range(len(change)):
                if change[u] == 1:
                    levels = levels + 1
        else:
            if (levels - nc) == 0:
                trig = 'brloop'
            else:
                print('avgm_MSE: ', avgm_MSE)
                print('levels', levels)
                print('nc', nc)
                print('avgm_MSE[int(levels-nc)] : ', avgm_MSE[int(levels-nc)])
                if len(change) == 4:
                    temp = [1, 0, 1, 0]
                    out = [True if temp[i] == change[i] else False for i in change]
                    
                    if all(out) == True:
                        xdict[int(count+1)] = xdict[int(count-1)][int(avgm_MSE[int(count-1)])::]
                    else:
                        xdict[int(count+1)] = xdict[int(levels-nc)][int(avgm_MSE[int(levels-nc)])::]
                else:
                    xdict[int(count+1)] = xdict[int(levels-nc)][int(avgm_MSE[int(levels-nc)])::]
            
            nc = nc + 1
        count = count + 1

    return avgCon_level, change, avgm_MSE