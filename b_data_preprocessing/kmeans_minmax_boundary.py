import numpy as np

from sklearn.cluster import KMeans

# Plotting
import plotly.graph_objects as go

# Personal python functions
import sys
#sys.path.insert(1, '/home/jamilah/Documents/Sourceforge_analysis_PROJECTS/Motor_classification/b_data_preprocessing')
sys.path.insert(1, 'C:\\Users\\jamilah\\Documents\\Sourceforge_analysis_PROJECTS\\Motor_classification\\b_data_preprocessing')

from subfunctions.make_a_properlist import *
from subfunctions.findall import*


# PURPOSE : to calculate two distict groups with a dataset using kmeans, it returns the max and min boundarys around the mean.


def kmeans_minmax_boundary(alldata, fs):
    
    ts = 1/fs
    
    # ------------------------------
    # Make all the points positive, to include both negative and positive stimulation
    alldata = np.array(alldata)
    alldata_abs = np.abs(alldata)

    # remove outliers before performing kmeans, so that the sup and sub estimate is more exact
    avg_alldata_abs = np.mean(alldata_abs)

    thresh = 4*np.std(alldata_abs)  # outliers are 4 standard deviations from the mean

    newvec, ind_newvec =  findall(alldata_abs, '<', thresh)
    pos_alldata = []
    for i in ind_newvec:
        pos_alldata.append(alldata_abs[i])
    # ------------------------------


    # ------------------------------
    pos_alldata = make_a_properlist(pos_alldata)
    pos_alldata = np.array(pos_alldata)

    # Reshape into a column
    pos_alldata = np.reshape(pos_alldata, (len(pos_alldata), 1))
    # OR
    # pos_alldata.reshape(-1,1)

    # ------------------------------
    # Need to find two 1-dimensional lines that are positve and then the same two lines that are negative
    # ------------------------------
    # kmeans = KMeans(n_clusters=2)
    # clusters_out = kmeans.fit_predict(pos_alldata)   # this is how you get labels/features from the data

    # OR 

    kmeans = KMeans(n_clusters=2).fit(pos_alldata)
    clusters_out = kmeans.predict(pos_alldata)
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
        clu_0.append(pos_alldata[i])
    # mean_clu_0 = np.mean(clu_0)
    # print('mean_clu_0 : ' + str(mean_clu_0))

    newvec, ind_newvec =  findall(clusters_out, '==', 1)
    clu_1 = []
    for i in ind_newvec:
        clu_1.append(pos_alldata[i])
    # mean_clu_1 = np.mean(clu_1)
    # print('mean_clu_1 : ' + str(mean_clu_1))
    # ------------------------------

    # ------------------------------
    # Label the clusters correctly : from min to max; 0=min cluster, 1=max cluster.  the function kmeans returns the clusters in random order, 
    # sometimes max first and min, or vice versa.
    # ------------------------------

    if mean_clu_0 > mean_clu_1:
        # reassign cluster 0 (lowest cluster) with mean_clu_1
        temp = mean_clu_0
        mean_clu_0 = mean_clu_1
        mean_clu_1 = temp
        temp = clu_0
        clu_0 = clu_1
        clu_1 = temp
    # print('centroids min-max: ' + str(mean_clu_0) + ', ' + str(mean_clu_1))

    # ------------------------------
    # Find the margin boundary that separates the two clusters
    # ------------------------------
    # want min_clu_1 >= max_clu_0 by adjusting numm
    start_val = 1
    stop_val = 2
    N = int(fs*stop_val)
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
    # Plot all data and the min max boundaries for sub-sup labeling
    plotORnot = 0
    
    if plotORnot == 1:
        fig = go.Figure()
        config = dict({'scrollZoom': True, 'displayModeBar': True, 'editable': True})
        
        # All initial slope estimates
        xxORG = list(range(len(alldata)))
        fig.add_trace(go.Scatter(x=xxORG, y=alldata, name='slope', mode='markers', marker=dict(color='yellow', size=10, symbol=5, line=dict(color='black', width=0)), showlegend=True))
        
        # 4 standard deviations from mean of all initial slope estimates
        thresh_vec = thresh*np.ones((len(xxORG),1))
        thresh_vec = make_a_properlist(thresh_vec)
        fig.add_trace(go.Scatter(x=xxORG, y=thresh_vec, name='thresh_vec', line = dict(color='green', width=1, dash='dash'), showlegend=True))
        
        # All initial slope estimates made positive 
        pos_alldata = make_a_properlist(pos_alldata)
        fig.add_trace(go.Scatter(x=xxORG, y=pos_alldata, name='slope', mode='markers', marker=dict(color='black', size=10, symbol=3, line=dict(color='black', width=0)), showlegend=True))
        
        # Plotting first cluster : min range
        mean_clu_0_vec = mean_clu_0*np.ones((len(xxORG),1))
        mean_clu_0_vec = make_a_properlist(mean_clu_0_vec)
        fig.add_trace(go.Scatter(x=xxORG, y=mean_clu_0_vec, name='mean_clu_0', line = dict(color='red', width=2, dash='dash'), showlegend=True))
        
        max_clu_0_vec = max_clu_0*np.ones((len(xxORG),1))
        max_clu_0_vec = make_a_properlist(max_clu_0_vec)
        fig.add_trace(go.Scatter(x=xxORG, y=max_clu_0_vec, name='max_clu_0', line = dict(color='red', width=1, dash='dash'), showlegend=True))
        
        min_clu_0_vec = min_clu_0*np.ones((len(xxORG),1))
        min_clu_0_vec = make_a_properlist(min_clu_0_vec)
        fig.add_trace(go.Scatter(x=xxORG, y=min_clu_0_vec, name='min_clu_0', line = dict(color='red', width=1, dash='dash'), showlegend=True))
        
        # Plotting second cluster : max range
        mean_clu_1_vec = mean_clu_1*np.ones((len(xxORG),1))
        mean_clu_1_vec = make_a_properlist(mean_clu_1_vec)
        fig.add_trace(go.Scatter(x=xxORG, y=mean_clu_1_vec, name='mean_clu_1', line = dict(color='blue', width=2, dash='dash'), showlegend=True))
        
        max_clu_1_vec = max_clu_1*np.ones((len(xxORG),1))
        max_clu_1_vec = make_a_properlist(max_clu_1_vec)
        fig.add_trace(go.Scatter(x=xxORG, y=max_clu_1_vec, name='max_clu_1', line = dict(color='blue', width=1, dash='dash'), showlegend=True))
        
        min_clu_1_vec = min_clu_1*np.ones((len(xxORG),1))
        min_clu_1_vec = make_a_properlist(min_clu_1_vec)
        fig.add_trace(go.Scatter(x=xxORG, y=min_clu_1_vec, name='min_clu_1', line = dict(color='blue', width=1, dash='dash'), showlegend=True))
        
        title_str = 'All data : exp %d' % (exp)
        fig.update_layout(title=title_str, xaxis_title='data points', yaxis_title='outSIG at index of max(abs(outSIG))')
        fig.show(config=config)
    # ------------------------------
    
    
    
    return max_clu_0, min_clu_0, max_clu_1, min_clu_1