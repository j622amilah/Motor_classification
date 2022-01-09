<<<<<<< HEAD
import numpy as np

# Plotting
import plotly.graph_objects as go
import plotly.express as px

# Data saving
import pickle

# module for counting values in a list
from collections import Counter

# Importing the statistics module
from statistics import mode, mean, median, multimode

from sklearn.cluster import KMeans


# Personal python functions
import sys
#sys.path.insert(1, '/home/jamilah/Documents/Sourceforge_analysis_PROJECTS/Motor_classification/subfunctions')
sys.path.insert(1, 'C:\\Users\\jamilah\\Documents\\Sourceforge_analysis_PROJECTS\\Motor_classification\\subfunctions')

from subfunctions.make_a_properlist import *
from subfunctions.detect_sig_change_wrt_baseline import *
from subfunctions.findall import *

from subfunctions.calc_slope_persub_tr import *



# RESULT : The initial slope and kmeans appears reasonable (there is a fairly even distribution of 
# sup and sub trials per subject - bar graph) for calculating speed_stim.   

# To be sure that the result is reasonable, we compare it with the experimental matrix values.

# We compare with the original experimental matrix calculatation (mode of all axes) and it gives a poor correlation 
# for rotation and some translation participants.  

# We could use data-driven speed stim, but why was the experimental matrix wrong.  The experimental matrix is like 
# GOD, it should NOT be wrong.  To reassure ourselves we try to get a reasonable correlation between the 
# data-driven measure and the experimental matrix values.

# Realized that experimental matrix values could be computed better.  Use target angular speed and the selected 
# stimulus axis.

# NEXT step : now that it is working, recode the functions in a modular fashion - so we can quickly change stuff if
# we need to change it or access specific calculated values.



def Try5_estimate_initial_slope():
    
    varr = {}
    varr['main_path'] = "C:\\Users\\jamilah\\Documents\\Sourceforge_analysis_PROJECTS\\Motor_classification"  # Windows
    # varr['main_path'] = "/home/jamilah/Documents/Sourceforge_analysis_PROJECTS/Motor_classification"

    NUMmark = 0   #  an arbitraily large number to denote a non-valid entry

    fs = 10 #  Original experimental sampling was at 250Hz, but data is downsampled to 10Hz
    ts = 1/fs

    mj_val = [0.1, 0.05, 0.01]


    # ------------------------------
    # Find relavant trials : trials where the joystick does not move and we can see the true 
    # experimental stimulus characteristics per axis
    
    speed_stim_dd = []
    
    speed_stim_em = []
    
    slope_per_exp = []

    # 1) Load exp : put the experiment that you wish to run
    for exp in range(2):  # 0=rotation, 1=translation
        
        if exp == 0:
            # Rotational data - 18 participants
            varr['which_exp'] = 'rot'
            varr['subjects'] = 'GV-123','AW-123','CDV-456','LB-000','PJ-123','PN-509','DL-777','SS-531','MD-565','CB-161','PI-112','FD-112','JMF-123','LB-195','LM-123','MBC-777','PB-123','SA-643'
            varr['sub_nom_rot'] = 'GV','AW','CDV','LB','PJ','PN','DL','SS','MD','CB','PI','FD','JMF','LB','LM','MBC','PB','SA'
            varr['anom'] = 'RO', 'PI', 'YA'
            varr['joyanom'] = '1', '2', '3'  # Numbers for standarization, because we switch axes.  For pre-processing we set an axis like in anom.
            varr['vals'] = 0.5, 1.25, 0
            varr['data_path'] = '%s\\DATA_10Hz_rot' % (varr['main_path'])  # Windows
            # varr['data_path'] = '%s/DATA_10Hz_rot' % (varr['main_path'])

            # 1) Orientation of joystick axes (Proven by standardization test)
            a = 17-1  # labeled (PI) - joystick movement
            b = 16-1   # labeled (RO) - joystick movement
            c = 18-1   # labeled (UD) - joystick movement

            # Load data experimental preprocessed data matrix
            file_name = "rotdat.pkl"
            open_file = open(file_name, "rb")
            dat = pickle.load(open_file)
            open_file.close()
            
            marg = 10

        elif exp == 1:
            # Translational data - 14 participants
            varr['which_exp'] = 'trans'
            varr['subjects'] = '20170411-TB-463','20172206-NB-777','20170413-GP-007','20172806-SM-308','20170404-AV-280','20170308-MK-160','20172008-AS-007','20170824-GL-380','p9_16102017-RW-115','p10_12102017-SG-123','p11_17102017-LG-123','p12_10102017-HS-000','p13_13102017-GB-666','p14_20171014-SL-132'
            varr['sub_nom_rot'] = 'TB','NB','GP','SM','AV','MK','AS','GL','RW','SG','LG','HS','GB','SL'        
            varr['anom'] = 'LR', 'FB', 'UD'
            varr['joyanom'] = '1', '2', '3'
            varr['vals'] = 3.75, 15, 0
            varr['data_path'] = '%s\\DATA_10Hz_trans' % (varr['main_path'])  # Windows
            # varr['data_path'] = '%s/DATA_10Hz_trans' % (varr['main_path'])

            # 1) Orientation of joystick axes (Proven by standardization test)
            a = 16-1  # labeled (LR) - joystick movement
            b = 17-1   # labeled (FB) - joystick movement
            c = 18-1   # labeled (UD) - joystick movement

            # Load data experimental preprocessed data matrix
            file_name = "transdat.pkl"
            open_file = open(file_name, "rb")
            dat = pickle.load(open_file)
            open_file.close()
            
            marg = 20


        
        # ------------------------------
        totsub_sig_val_ORG, totsub_speed_stim_em = calc_slope_persub_tr(dat)
        
        # Append all the slope data into one list
        totsub_sig_val = make_a_properlist(totsub_sig_val_ORG)
        # ------------------------------
        
        
        # ------------------------------
        # Make all the points positive, to include both negative and positive stimulation
        totsub_sig_val = np.array(totsub_sig_val)
        totsub_sig_val_abs = abs(totsub_sig_val)
        
        # remove outliers
        avg_totsub_sig_val_abs = np.mean(totsub_sig_val_abs)
        
        thresh = 4*np.std(totsub_sig_val_abs)
        
        newvec, ind_newvec =  findall(totsub_sig_val_abs, '<', thresh)
        pos_totsub_sig_val = []
        for i in ind_newvec:
            pos_totsub_sig_val.append(totsub_sig_val_abs[i])
        # ------------------------------
        
        
        # ------------------------------
        # Plot all the data per experiment
        fig = go.Figure()
        config = dict({'scrollZoom': True, 'displayModeBar': True, 'editable': True})

        xxORG = list(range(len(totsub_sig_val)))
        fig.add_trace(go.Scatter(x=xxORG, y=totsub_sig_val, name='slope', mode='markers', marker=dict(color='black', size=10, symbol=5, line=dict(color='black', width=0)), showlegend=True))
        
        xxORG2 = list(range(len(pos_totsub_sig_val)))
        fig.add_trace(go.Scatter(x=xxORG2, y=pos_totsub_sig_val, name='slope', mode='markers', marker=dict(color='red', size=10, symbol=5, line=dict(color='red', width=0)), showlegend=True))
        
        thresh_vec = thresh*np.ones((len(xxORG2),1))
        thresh_vec = make_a_properlist(thresh_vec)
        fig.add_trace(go.Scatter(x=xxORG2, y=thresh_vec, name='thresh_vec', line = dict(color='blue', width=1, dash='dash'), showlegend=True))
        
        title_str = 'All data : exp %d' % (exp)
        fig.update_layout(title=title_str, xaxis_title='data points', yaxis_title='outSIG at index of max(abs(outSIG))')
        fig.show(config=config)
        # ------------------------------
        
        
        # ------------------------------
        pos_totsub_sig_val = make_a_properlist(pos_totsub_sig_val)
        pos_totsub_sig_val = np.array(pos_totsub_sig_val)
        
        # Reshape into a column
        pos_totsub_sig_val = np.reshape(pos_totsub_sig_val, (len(pos_totsub_sig_val), 1))
        # OR
        # pos_totsub_sig_val.reshape(-1,1)
        
        # ------------------------------
        # Need to find two 1-dimensional lines that are positve and then the same two lines that are negative
        # ------------------------------
        # kmeans = KMeans(n_clusters=2)
        # clusters_out = kmeans.fit_predict(pos_totsub_sig_val)   # this is how you get labels/features from the data
        
        # OR 
        
        kmeans = KMeans(n_clusters=2).fit(pos_totsub_sig_val)
        clusters_out = kmeans.predict(pos_totsub_sig_val)
        # print('clusters_out : ' + str(clusters_out))
        # ------------------------------
        
        # ------------------------------
        # Centroid values : this is the 
        centroids = kmeans.cluster_centers_
        # print('centroids org : ' + str(centroids))
        mean_clu_0 = centroids[0]
        mean_clu_1 = centroids[1]
        
        # Note to self : confirming that the centroids are the mean of each category
        newvec, ind_newvec =  findall(clusters_out, '==', 0)
        clu_0 = []
        for i in ind_newvec:
            clu_0.append(pos_totsub_sig_val[i])
        # mean_clu_0 = np.mean(clu_0)
        # print('mean_clu_0 : ' + str(mean_clu_0))
        
        newvec, ind_newvec =  findall(clusters_out, '==', 1)
        clu_1 = []
        for i in ind_newvec:
            clu_1.append(pos_totsub_sig_val[i])
        # mean_clu_1 = np.mean(clu_1)
        # print('mean_clu_1 : ' + str(mean_clu_1))
        # ------------------------------
        
        # ------------------------------
        # Label the clusters correctly : 0=min cluster, 1=max cluster
        
        if mean_clu_0 > mean_clu_1:
            # reassign cluster 0 (lowest cluster) with mean_clu_1
            temp = mean_clu_0
            mean_clu_0 = mean_clu_1
            mean_clu_1 = temp
            temp = clu_0
            clu_0 = clu_1
            clu_1 = temp
        # print('centroids min-max: ' + str(mean_clu_0) + ', ' + str(mean_clu_1))
        
        # Find the margin boundary that separates the two clusters
        
        # want min_clu_1 >= max_clu_0 by adjusting numm
        start_val = 1
        stop_val = 2
        ts = 0.01
        f = 1/ts  # sampling frequency
        N = int(f*stop_val)
        out = np.multiply(range(start_val, N), ts) 
        std_list = out[::-1]  # Invert list
        
        flag = 0
        for numm in std_list:
            max_clu_0 = numm*np.std(clu_0) + mean_clu_0
            min_clu_0 = mean_clu_0 - numm*np.std(clu_0)
            max_clu_1 = numm*np.std(clu_1) + mean_clu_1
            min_clu_1 = mean_clu_1 - numm*np.std(clu_1)
            
            if min_clu_1 >= max_clu_0 and flag == 0:
                flag = 1
                break
        # print('numm : ' + str(numm))
        # ------------------------------
        
        # ------------------------------
        fig = go.Figure()
        config = dict({'scrollZoom': True, 'displayModeBar': True, 'editable': True})
        
        pos_totsub_sig_val = make_a_properlist(pos_totsub_sig_val)
        xxORG = list(range(len(pos_totsub_sig_val)))
        fig.add_trace(go.Scatter(x=xxORG, y=pos_totsub_sig_val, name='slope', mode='markers', marker=dict(color='black', size=10, symbol=3, line=dict(color='black', width=0)), showlegend=True))
        
        # ------------------------------
        mean_clu_0_vec = mean_clu_0*np.ones((len(xxORG),1))
        mean_clu_0_vec = make_a_properlist(mean_clu_0_vec)
        fig.add_trace(go.Scatter(x=xxORG, y=mean_clu_0_vec, name='mean_clu_0', line = dict(color='red', width=2, dash='dash'), showlegend=True))
        
        max_clu_0_vec = max_clu_0*np.ones((len(xxORG),1))
        max_clu_0_vec = make_a_properlist(max_clu_0_vec)
        fig.add_trace(go.Scatter(x=xxORG, y=max_clu_0_vec, name='max_clu_0', line = dict(color='red', width=1, dash='dash'), showlegend=True))
        
        min_clu_0_vec = min_clu_0*np.ones((len(xxORG),1))
        min_clu_0_vec = make_a_properlist(min_clu_0_vec)
        fig.add_trace(go.Scatter(x=xxORG, y=min_clu_0_vec, name='min_clu_0', line = dict(color='red', width=1, dash='dash'), showlegend=True))
        # ------------------------------
        
        # ------------------------------
        mean_clu_1_vec = mean_clu_1*np.ones((len(xxORG),1))
        mean_clu_1_vec = make_a_properlist(mean_clu_1_vec)
        fig.add_trace(go.Scatter(x=xxORG, y=mean_clu_1_vec, name='mean_clu_1', line = dict(color='blue', width=2, dash='dash'), showlegend=True))
        
        max_clu_1_vec = max_clu_1*np.ones((len(xxORG),1))
        max_clu_1_vec = make_a_properlist(max_clu_1_vec)
        fig.add_trace(go.Scatter(x=xxORG, y=max_clu_1_vec, name='max_clu_1', line = dict(color='blue', width=1, dash='dash'), showlegend=True))
        
        min_clu_1_vec = min_clu_1*np.ones((len(xxORG),1))
        min_clu_1_vec = make_a_properlist(min_clu_1_vec)
        fig.add_trace(go.Scatter(x=xxORG, y=min_clu_1_vec, name='min_clu_1', line = dict(color='blue', width=1, dash='dash'), showlegend=True))
        # ------------------------------
        
        title_str = 'All data : exp %d' % (exp)
        fig.update_layout(title=title_str, xaxis_title='data points', yaxis_title='outSIG at index of max(abs(outSIG))')
        fig.show(config=config)
        # ------------------------------
        
        
        
        # sup trial = trials with initial slope points between min_clu_1_OR_0.1 and max_clu_1
        # sub trial = trials with initial slope points between min_clu_0_OR_0.1 and max_clu_0
        
        sub_range = [min_clu_0, max_clu_0]
        sup_range = [min_clu_1, max_clu_1]
        
        print('sub_range : ' + str(sub_range))
        print('sup_range : ' + str(sup_range))
        
        # ------------------------------
        # speed_stim_per_exp, slope_per_exp = calc_speedstim_from_range(dat, sub_range, sup_range)
        
        max_val = sup_range[1]
        mid_val = (sup_range[0] + sub_range[1])/2
        min_val = sub_range[0]
        
        print('max_val : ' + str(max_val))
        print('mid_val : ' + str(mid_val))
        print('min_val : ' + str(min_val))
        
        print('totsub_sig_val_ORG : ' + str(totsub_sig_val_ORG))
        
        num_of_s = len(totsub_sig_val_ORG)
        print('num_of_s : ' + str(num_of_s))

        speed_stim_per_exp = []

        for s in range(num_of_s):
            
            num_of_tr = len(totsub_sig_val_ORG[s])
            
            stim_speed_pertr = []
            
            for tr in range(num_of_tr):
                if np.abs(totsub_sig_val_ORG[s][tr]) < 0.01:  # zero stim is considered an outlier
                    sstim = 100   # outlier
                else:
                    if (np.abs(totsub_sig_val_ORG[s][tr]) > mid_val) and (np.abs(totsub_sig_val_ORG[s][tr]) < max_val):
                        sstim = 1   # sup
                    elif (np.abs(totsub_sig_val_ORG[s][tr]) < mid_val) and (np.abs(totsub_sig_val_ORG[s][tr]) > min_val):
                        print('sub detected : ' + str(np.abs(totsub_sig_val_ORG[s][tr])))
                        sstim = 0   # sub
                    else:
                        sstim = 100   # outlier: vaules above the max_clu_1 line and below the min_clu_0 line
                
                stim_speed_pertr = stim_speed_pertr + [sstim]
                
            stim_speed_pertr = make_a_properlist(stim_speed_pertr)
            speed_stim_per_exp = speed_stim_per_exp + [stim_speed_pertr]
        # ------------------------------
        
        
        # ------------------------------
        
        speed_stim_dd = speed_stim_dd + [speed_stim_per_exp]
        
        
        speed_stim_em = speed_stim_em + [totsub_speed_stim_em]

    
    print('speed_stim_dd : ' + str(speed_stim_dd))
    
    # ------------------------------
    # Need to test the calculated speed_stim_dd with the experimental matrix data
    # ------------------------------
    corr_ss_exp = []
    for ex in range(len(speed_stim_dd)):
        corr_ss_out = []
        for s in range(len(speed_stim_dd[ex])):
            # Confirmation check of axis : to see how similar data-driven axis_out is to the experimental matrix axis_org
            # Pearson correlation coefficient : corr (x,y) = cov (x,y) / (std (x) * std (y))
            corr_ss = np.corrcoef(speed_stim_dd[ex][s], speed_stim_em[ex][s]) # outputs a correlation matrix
            corr_ss = corr_ss[0,1]
            corr_ss_out = corr_ss_out + [corr_ss]
        
        corr_ss_exp = corr_ss_exp + [corr_ss_out]
    # print('corr_ss_exp : ' + str(corr_ss_exp))

    varr = {}
    for exp in range(2):  # 0=rotation, 1=translation
        
        if exp == 0:
            # Rotational data - 18 participants
            varr['which_exp'] = 'rot'
        elif exp == 1:
            # Translational data - 14 participants
            varr['which_exp'] = 'trans'
            
        fig = go.Figure()
        config = dict({'scrollZoom': True, 'displayModeBar': True, 'editable': True})
        xxORG = list(range(len(corr_ss_exp[exp])))
        fig.add_trace(go.Scatter(x=xxORG, y=corr_ss_exp[exp], name='corr_axis_out_exp', line = dict(color='red', width=2, dash='dash'), showlegend=True))
        fig.update_layout(title='Correlation of speed stim (across trials) per subject - %s' % (varr['which_exp']), xaxis_title='subjects', yaxis_title='correlation (%s): axis' % (varr['which_exp']))
        fig.show(config=config)
        fig.write_image("corr_ss_out_exp_%s.png" % (varr['which_exp']))
        
        # ------------------------------
        # Problem : 
        # Rotation has strong negative correlation, meaning that sub is infact sup and vice-versa
        # Translational seems ok
        # ------------------------------
        
        # ------------------------------
        
        # Bar chart of individual categories - for calculated 
        subname = []
        data = []
        for i in range(len(speed_stim_dd[exp])):
            # print('speed_stim_dd[0][i] : ' + str(speed_stim_dd[exp][i]))
            c = Counter(speed_stim_dd[exp][i])
            
            sub_count = np.array(c[0])
            sup_count = np.array(c[1])
            out_count = np.array(c[100])
            
            subdata = sub_count.reshape(-1,1), sup_count.reshape(-1,1), out_count.reshape(-1,1)
            subdata = make_a_properlist(subdata)
            
            data = data + [subdata]
            
            subname = subname + ['s%d' % (i)]
            
        data = np.array(data)
        sub_col = data[:,0]
        sup_col = data[:,1]
        out_col = data[:,2]
        subname = make_a_properlist(subname)
        # print('subname : ' + str(subname))
        
        fig = go.Figure(data=[go.Bar(name='sub', x=subname, y=sub_col), go.Bar(name='sup', x=subname, y=sup_col),
                        go.Bar(name='outliers', x=subname, y=out_col)])
        fig.update_layout(title_text="Calculated")
        fig.show()
        # name_str = "bar_graph_calcul_%s.png" % (varr['which_exp'])
        # fig.write_image(name_str)
        
        # ------------------------------
        
        # Bar chart of individual categories - for experimental matrix 
        subname = []
        data = []
        for i in range(len(speed_stim_em[exp])):
            # print('speed_stim_em[0][i] : ' + str(speed_stim_em[exp][i]))
            c = Counter(speed_stim_em[exp][i])
            
            sub_count = np.array(c[0])
            sup_count = np.array(c[1])
            out_count = np.array(c[100])
            
            subdata = sub_count.reshape(-1,1), sup_count.reshape(-1,1), out_count.reshape(-1,1)
            subdata = make_a_properlist(subdata)
            
            data = data + [subdata]
            
            subname = subname + ['s%d' % (i)]
            
        data = np.array(data)
        sub_col = data[:,0]
        sup_col = data[:,1]
        out_col = data[:,2]
        subname = make_a_properlist(subname)
        # print('subname : ' + str(subname))
        fig = go.Figure(data=[go.Bar(name='sub', x=subname, y=sub_col), go.Bar(name='sup', x=subname, y=sup_col),
                        go.Bar(name='outliers', x=subname, y=out_col)])
        fig.update_layout(title_text="Experimental matrix")
        fig.show()
    
    
        slope_per_exp = slope_per_exp + [totsub_sig_val_ORG]
    

=======
import numpy as np

# Plotting
import plotly.graph_objects as go
import plotly.express as px

# Data saving
import pickle

# module for counting values in a list
from collections import Counter

# Importing the statistics module
from statistics import mode, mean, median, multimode

from sklearn.cluster import KMeans


# Personal python functions
import sys
#sys.path.insert(1, '/home/jamilah/Documents/Sourceforge_analysis_PROJECTS/Motor_classification/subfunctions')
sys.path.insert(1, 'C:\\Users\\jamilah\\Documents\\Sourceforge_analysis_PROJECTS\\Motor_classification\\subfunctions')

from subfunctions.make_a_properlist import *
from subfunctions.detect_sig_change_wrt_baseline import *
from subfunctions.findall import *

from subfunctions.calc_slope_persub_tr import *



# RESULT : The initial slope and kmeans appears reasonable (there is a fairly even distribution of 
# sup and sub trials per subject - bar graph) for calculating speed_stim.   

# To be sure that the result is reasonable, we compare it with the experimental matrix values.

# We compare with the original experimental matrix calculatation (mode of all axes) and it gives a poor correlation 
# for rotation and some translation participants.  

# We could use data-driven speed stim, but why was the experimental matrix wrong.  The experimental matrix is like 
# GOD, it should NOT be wrong.  To reassure ourselves we try to get a reasonable correlation between the 
# data-driven measure and the experimental matrix values.

# Realized that experimental matrix values could be computed better.  Use target angular speed and the selected 
# stimulus axis.

# NEXT step : now that it is working, recode the functions in a modular fashion - so we can quickly change stuff if
# we need to change it or access specific calculated values.



def Try5_estimate_initial_slope():
    
    varr = {}
    varr['main_path'] = "C:\\Users\\jamilah\\Documents\\Sourceforge_analysis_PROJECTS\\Motor_classification"  # Windows
    # varr['main_path'] = "/home/jamilah/Documents/Sourceforge_analysis_PROJECTS/Motor_classification"

    NUMmark = 0   #  an arbitraily large number to denote a non-valid entry

    fs = 10 #  Original experimental sampling was at 250Hz, but data is downsampled to 10Hz
    ts = 1/fs

    mj_val = [0.1, 0.05, 0.01]


    # ------------------------------
    # Find relavant trials : trials where the joystick does not move and we can see the true 
    # experimental stimulus characteristics per axis
    
    speed_stim_dd = []
    
    speed_stim_em = []
    
    slope_per_exp = []

    # 1) Load exp : put the experiment that you wish to run
    for exp in range(2):  # 0=rotation, 1=translation
        
        if exp == 0:
            # Rotational data - 18 participants
            varr['which_exp'] = 'rot'
            varr['subjects'] = 'GV-123','AW-123','CDV-456','LB-000','PJ-123','PN-509','DL-777','SS-531','MD-565','CB-161','PI-112','FD-112','JMF-123','LB-195','LM-123','MBC-777','PB-123','SA-643'
            varr['sub_nom_rot'] = 'GV','AW','CDV','LB','PJ','PN','DL','SS','MD','CB','PI','FD','JMF','LB','LM','MBC','PB','SA'
            varr['anom'] = 'RO', 'PI', 'YA'
            varr['joyanom'] = '1', '2', '3'  # Numbers for standarization, because we switch axes.  For pre-processing we set an axis like in anom.
            varr['vals'] = 0.5, 1.25, 0
            varr['data_path'] = '%s\\DATA_10Hz_rot' % (varr['main_path'])  # Windows
            # varr['data_path'] = '%s/DATA_10Hz_rot' % (varr['main_path'])

            # 1) Orientation of joystick axes (Proven by standardization test)
            a = 17-1  # labeled (PI) - joystick movement
            b = 16-1   # labeled (RO) - joystick movement
            c = 18-1   # labeled (UD) - joystick movement

            # Load data experimental preprocessed data matrix
            file_name = "rotdat.pkl"
            open_file = open(file_name, "rb")
            dat = pickle.load(open_file)
            open_file.close()
            
            marg = 10

        elif exp == 1:
            # Translational data - 14 participants
            varr['which_exp'] = 'trans'
            varr['subjects'] = '20170411-TB-463','20172206-NB-777','20170413-GP-007','20172806-SM-308','20170404-AV-280','20170308-MK-160','20172008-AS-007','20170824-GL-380','p9_16102017-RW-115','p10_12102017-SG-123','p11_17102017-LG-123','p12_10102017-HS-000','p13_13102017-GB-666','p14_20171014-SL-132'
            varr['sub_nom_rot'] = 'TB','NB','GP','SM','AV','MK','AS','GL','RW','SG','LG','HS','GB','SL'        
            varr['anom'] = 'LR', 'FB', 'UD'
            varr['joyanom'] = '1', '2', '3'
            varr['vals'] = 3.75, 15, 0
            varr['data_path'] = '%s\\DATA_10Hz_trans' % (varr['main_path'])  # Windows
            # varr['data_path'] = '%s/DATA_10Hz_trans' % (varr['main_path'])

            # 1) Orientation of joystick axes (Proven by standardization test)
            a = 16-1  # labeled (LR) - joystick movement
            b = 17-1   # labeled (FB) - joystick movement
            c = 18-1   # labeled (UD) - joystick movement

            # Load data experimental preprocessed data matrix
            file_name = "transdat.pkl"
            open_file = open(file_name, "rb")
            dat = pickle.load(open_file)
            open_file.close()
            
            marg = 20


        
        # ------------------------------
        totsub_sig_val_ORG, totsub_speed_stim_em = calc_slope_persub_tr(dat)
        
        # Append all the slope data into one list
        totsub_sig_val = make_a_properlist(totsub_sig_val_ORG)
        # ------------------------------
        
        
        # ------------------------------
        # Make all the points positive, to include both negative and positive stimulation
        totsub_sig_val = np.array(totsub_sig_val)
        totsub_sig_val_abs = abs(totsub_sig_val)
        
        # remove outliers
        avg_totsub_sig_val_abs = np.mean(totsub_sig_val_abs)
        
        thresh = 4*np.std(totsub_sig_val_abs)
        
        newvec, ind_newvec =  findall(totsub_sig_val_abs, '<', thresh)
        pos_totsub_sig_val = []
        for i in ind_newvec:
            pos_totsub_sig_val.append(totsub_sig_val_abs[i])
        # ------------------------------
        
        
        # ------------------------------
        # Plot all the data per experiment
        fig = go.Figure()
        config = dict({'scrollZoom': True, 'displayModeBar': True, 'editable': True})

        xxORG = list(range(len(totsub_sig_val)))
        fig.add_trace(go.Scatter(x=xxORG, y=totsub_sig_val, name='slope', mode='markers', marker=dict(color='black', size=10, symbol=5, line=dict(color='black', width=0)), showlegend=True))
        
        xxORG2 = list(range(len(pos_totsub_sig_val)))
        fig.add_trace(go.Scatter(x=xxORG2, y=pos_totsub_sig_val, name='slope', mode='markers', marker=dict(color='red', size=10, symbol=5, line=dict(color='red', width=0)), showlegend=True))
        
        thresh_vec = thresh*np.ones((len(xxORG2),1))
        thresh_vec = make_a_properlist(thresh_vec)
        fig.add_trace(go.Scatter(x=xxORG2, y=thresh_vec, name='thresh_vec', line = dict(color='blue', width=1, dash='dash'), showlegend=True))
        
        title_str = 'All data : exp %d' % (exp)
        fig.update_layout(title=title_str, xaxis_title='data points', yaxis_title='outSIG at index of max(abs(outSIG))')
        fig.show(config=config)
        # ------------------------------
        
        
        # ------------------------------
        pos_totsub_sig_val = make_a_properlist(pos_totsub_sig_val)
        pos_totsub_sig_val = np.array(pos_totsub_sig_val)
        
        # Reshape into a column
        pos_totsub_sig_val = np.reshape(pos_totsub_sig_val, (len(pos_totsub_sig_val), 1))
        # OR
        # pos_totsub_sig_val.reshape(-1,1)
        
        # ------------------------------
        # Need to find two 1-dimensional lines that are positve and then the same two lines that are negative
        # ------------------------------
        # kmeans = KMeans(n_clusters=2)
        # clusters_out = kmeans.fit_predict(pos_totsub_sig_val)   # this is how you get labels/features from the data
        
        # OR 
        
        kmeans = KMeans(n_clusters=2).fit(pos_totsub_sig_val)
        clusters_out = kmeans.predict(pos_totsub_sig_val)
        # print('clusters_out : ' + str(clusters_out))
        # ------------------------------
        
        # ------------------------------
        # Centroid values : this is the 
        centroids = kmeans.cluster_centers_
        # print('centroids org : ' + str(centroids))
        mean_clu_0 = centroids[0]
        mean_clu_1 = centroids[1]
        
        # Note to self : confirming that the centroids are the mean of each category
        newvec, ind_newvec =  findall(clusters_out, '==', 0)
        clu_0 = []
        for i in ind_newvec:
            clu_0.append(pos_totsub_sig_val[i])
        # mean_clu_0 = np.mean(clu_0)
        # print('mean_clu_0 : ' + str(mean_clu_0))
        
        newvec, ind_newvec =  findall(clusters_out, '==', 1)
        clu_1 = []
        for i in ind_newvec:
            clu_1.append(pos_totsub_sig_val[i])
        # mean_clu_1 = np.mean(clu_1)
        # print('mean_clu_1 : ' + str(mean_clu_1))
        # ------------------------------
        
        # ------------------------------
        # Label the clusters correctly : 0=min cluster, 1=max cluster
        
        if mean_clu_0 > mean_clu_1:
            # reassign cluster 0 (lowest cluster) with mean_clu_1
            temp = mean_clu_0
            mean_clu_0 = mean_clu_1
            mean_clu_1 = temp
            temp = clu_0
            clu_0 = clu_1
            clu_1 = temp
        # print('centroids min-max: ' + str(mean_clu_0) + ', ' + str(mean_clu_1))
        
        # Find the margin boundary that separates the two clusters
        
        # want min_clu_1 >= max_clu_0 by adjusting numm
        start_val = 1
        stop_val = 2
        ts = 0.01
        f = 1/ts  # sampling frequency
        N = int(f*stop_val)
        out = np.multiply(range(start_val, N), ts) 
        std_list = out[::-1]  # Invert list
        
        flag = 0
        for numm in std_list:
            max_clu_0 = numm*np.std(clu_0) + mean_clu_0
            min_clu_0 = mean_clu_0 - numm*np.std(clu_0)
            max_clu_1 = numm*np.std(clu_1) + mean_clu_1
            min_clu_1 = mean_clu_1 - numm*np.std(clu_1)
            
            if min_clu_1 >= max_clu_0 and flag == 0:
                flag = 1
                break
        # print('numm : ' + str(numm))
        # ------------------------------
        
        # ------------------------------
        fig = go.Figure()
        config = dict({'scrollZoom': True, 'displayModeBar': True, 'editable': True})
        
        pos_totsub_sig_val = make_a_properlist(pos_totsub_sig_val)
        xxORG = list(range(len(pos_totsub_sig_val)))
        fig.add_trace(go.Scatter(x=xxORG, y=pos_totsub_sig_val, name='slope', mode='markers', marker=dict(color='black', size=10, symbol=3, line=dict(color='black', width=0)), showlegend=True))
        
        # ------------------------------
        mean_clu_0_vec = mean_clu_0*np.ones((len(xxORG),1))
        mean_clu_0_vec = make_a_properlist(mean_clu_0_vec)
        fig.add_trace(go.Scatter(x=xxORG, y=mean_clu_0_vec, name='mean_clu_0', line = dict(color='red', width=2, dash='dash'), showlegend=True))
        
        max_clu_0_vec = max_clu_0*np.ones((len(xxORG),1))
        max_clu_0_vec = make_a_properlist(max_clu_0_vec)
        fig.add_trace(go.Scatter(x=xxORG, y=max_clu_0_vec, name='max_clu_0', line = dict(color='red', width=1, dash='dash'), showlegend=True))
        
        min_clu_0_vec = min_clu_0*np.ones((len(xxORG),1))
        min_clu_0_vec = make_a_properlist(min_clu_0_vec)
        fig.add_trace(go.Scatter(x=xxORG, y=min_clu_0_vec, name='min_clu_0', line = dict(color='red', width=1, dash='dash'), showlegend=True))
        # ------------------------------
        
        # ------------------------------
        mean_clu_1_vec = mean_clu_1*np.ones((len(xxORG),1))
        mean_clu_1_vec = make_a_properlist(mean_clu_1_vec)
        fig.add_trace(go.Scatter(x=xxORG, y=mean_clu_1_vec, name='mean_clu_1', line = dict(color='blue', width=2, dash='dash'), showlegend=True))
        
        max_clu_1_vec = max_clu_1*np.ones((len(xxORG),1))
        max_clu_1_vec = make_a_properlist(max_clu_1_vec)
        fig.add_trace(go.Scatter(x=xxORG, y=max_clu_1_vec, name='max_clu_1', line = dict(color='blue', width=1, dash='dash'), showlegend=True))
        
        min_clu_1_vec = min_clu_1*np.ones((len(xxORG),1))
        min_clu_1_vec = make_a_properlist(min_clu_1_vec)
        fig.add_trace(go.Scatter(x=xxORG, y=min_clu_1_vec, name='min_clu_1', line = dict(color='blue', width=1, dash='dash'), showlegend=True))
        # ------------------------------
        
        title_str = 'All data : exp %d' % (exp)
        fig.update_layout(title=title_str, xaxis_title='data points', yaxis_title='outSIG at index of max(abs(outSIG))')
        fig.show(config=config)
        # ------------------------------
        
        
        
        # sup trial = trials with initial slope points between min_clu_1_OR_0.1 and max_clu_1
        # sub trial = trials with initial slope points between min_clu_0_OR_0.1 and max_clu_0
        
        sub_range = [min_clu_0, max_clu_0]
        sup_range = [min_clu_1, max_clu_1]
        
        print('sub_range : ' + str(sub_range))
        print('sup_range : ' + str(sup_range))
        
        # ------------------------------
        # speed_stim_per_exp, slope_per_exp = calc_speedstim_from_range(dat, sub_range, sup_range)
        
        max_val = sup_range[1]
        mid_val = (sup_range[0] + sub_range[1])/2
        min_val = sub_range[0]
        
        print('max_val : ' + str(max_val))
        print('mid_val : ' + str(mid_val))
        print('min_val : ' + str(min_val))
        
        print('totsub_sig_val_ORG : ' + str(totsub_sig_val_ORG))
        
        num_of_s = len(totsub_sig_val_ORG)
        print('num_of_s : ' + str(num_of_s))

        speed_stim_per_exp = []

        for s in range(num_of_s):
            
            num_of_tr = len(totsub_sig_val_ORG[s])
            
            stim_speed_pertr = []
            
            for tr in range(num_of_tr):
                if np.abs(totsub_sig_val_ORG[s][tr]) < 0.01:  # zero stim is considered an outlier
                    sstim = 100   # outlier
                else:
                    if (np.abs(totsub_sig_val_ORG[s][tr]) > mid_val) and (np.abs(totsub_sig_val_ORG[s][tr]) < max_val):
                        sstim = 1   # sup
                    elif (np.abs(totsub_sig_val_ORG[s][tr]) < mid_val) and (np.abs(totsub_sig_val_ORG[s][tr]) > min_val):
                        print('sub detected : ' + str(np.abs(totsub_sig_val_ORG[s][tr])))
                        sstim = 0   # sub
                    else:
                        sstim = 100   # outlier: vaules above the max_clu_1 line and below the min_clu_0 line
                
                stim_speed_pertr = stim_speed_pertr + [sstim]
                
            stim_speed_pertr = make_a_properlist(stim_speed_pertr)
            speed_stim_per_exp = speed_stim_per_exp + [stim_speed_pertr]
        # ------------------------------
        
        
        # ------------------------------
        
        speed_stim_dd = speed_stim_dd + [speed_stim_per_exp]
        
        
        speed_stim_em = speed_stim_em + [totsub_speed_stim_em]

    
    print('speed_stim_dd : ' + str(speed_stim_dd))
    
    # ------------------------------
    # Need to test the calculated speed_stim_dd with the experimental matrix data
    # ------------------------------
    corr_ss_exp = []
    for ex in range(len(speed_stim_dd)):
        corr_ss_out = []
        for s in range(len(speed_stim_dd[ex])):
            # Confirmation check of axis : to see how similar data-driven axis_out is to the experimental matrix axis_org
            # Pearson correlation coefficient : corr (x,y) = cov (x,y) / (std (x) * std (y))
            corr_ss = np.corrcoef(speed_stim_dd[ex][s], speed_stim_em[ex][s]) # outputs a correlation matrix
            corr_ss = corr_ss[0,1]
            corr_ss_out = corr_ss_out + [corr_ss]
        
        corr_ss_exp = corr_ss_exp + [corr_ss_out]
    # print('corr_ss_exp : ' + str(corr_ss_exp))

    varr = {}
    for exp in range(2):  # 0=rotation, 1=translation
        
        if exp == 0:
            # Rotational data - 18 participants
            varr['which_exp'] = 'rot'
        elif exp == 1:
            # Translational data - 14 participants
            varr['which_exp'] = 'trans'
            
        fig = go.Figure()
        config = dict({'scrollZoom': True, 'displayModeBar': True, 'editable': True})
        xxORG = list(range(len(corr_ss_exp[exp])))
        fig.add_trace(go.Scatter(x=xxORG, y=corr_ss_exp[exp], name='corr_axis_out_exp', line = dict(color='red', width=2, dash='dash'), showlegend=True))
        fig.update_layout(title='Correlation of speed stim (across trials) per subject - %s' % (varr['which_exp']), xaxis_title='subjects', yaxis_title='correlation (%s): axis' % (varr['which_exp']))
        fig.show(config=config)
        fig.write_image("corr_ss_out_exp_%s.png" % (varr['which_exp']))
        
        # ------------------------------
        # Problem : 
        # Rotation has strong negative correlation, meaning that sub is infact sup and vice-versa
        # Translational seems ok
        # ------------------------------
        
        # ------------------------------
        
        # Bar chart of individual categories - for calculated 
        subname = []
        data = []
        for i in range(len(speed_stim_dd[exp])):
            # print('speed_stim_dd[0][i] : ' + str(speed_stim_dd[exp][i]))
            c = Counter(speed_stim_dd[exp][i])
            
            sub_count = np.array(c[0])
            sup_count = np.array(c[1])
            out_count = np.array(c[100])
            
            subdata = sub_count.reshape(-1,1), sup_count.reshape(-1,1), out_count.reshape(-1,1)
            subdata = make_a_properlist(subdata)
            
            data = data + [subdata]
            
            subname = subname + ['s%d' % (i)]
            
        data = np.array(data)
        sub_col = data[:,0]
        sup_col = data[:,1]
        out_col = data[:,2]
        subname = make_a_properlist(subname)
        # print('subname : ' + str(subname))
        
        fig = go.Figure(data=[go.Bar(name='sub', x=subname, y=sub_col), go.Bar(name='sup', x=subname, y=sup_col),
                        go.Bar(name='outliers', x=subname, y=out_col)])
        fig.update_layout(title_text="Calculated")
        fig.show()
        # name_str = "bar_graph_calcul_%s.png" % (varr['which_exp'])
        # fig.write_image(name_str)
        
        # ------------------------------
        
        # Bar chart of individual categories - for experimental matrix 
        subname = []
        data = []
        for i in range(len(speed_stim_em[exp])):
            # print('speed_stim_em[0][i] : ' + str(speed_stim_em[exp][i]))
            c = Counter(speed_stim_em[exp][i])
            
            sub_count = np.array(c[0])
            sup_count = np.array(c[1])
            out_count = np.array(c[100])
            
            subdata = sub_count.reshape(-1,1), sup_count.reshape(-1,1), out_count.reshape(-1,1)
            subdata = make_a_properlist(subdata)
            
            data = data + [subdata]
            
            subname = subname + ['s%d' % (i)]
            
        data = np.array(data)
        sub_col = data[:,0]
        sup_col = data[:,1]
        out_col = data[:,2]
        subname = make_a_properlist(subname)
        # print('subname : ' + str(subname))
        fig = go.Figure(data=[go.Bar(name='sub', x=subname, y=sub_col), go.Bar(name='sup', x=subname, y=sup_col),
                        go.Bar(name='outliers', x=subname, y=out_col)])
        fig.update_layout(title_text="Experimental matrix")
        fig.show()
    
    
        slope_per_exp = slope_per_exp + [totsub_sig_val_ORG]
    

>>>>>>> 94b06cd4776edc5e6880e69ca0d1eefbe92d257c
    return speed_stim_em, speed_stim_dd, slope_per_exp, sub_range, sup_range