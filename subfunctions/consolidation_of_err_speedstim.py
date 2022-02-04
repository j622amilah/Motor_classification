import numpy as np

# Plotting
from plotly.subplots import make_subplots
import plotly.graph_objects as go
	



	
def consolidation_of_err_speedstim(MSE_win_size_tr,  RMSE_win_size_tr, varr, speed_stim):
    num_of_tr = len(MSE_win_size_tr)
    num_of_ws = len(MSE_win_size_tr[0])


    if varr['which_exp'] == 'rot':
        subval = 0.5
        supval = 1.25
    elif varr['which_exp'] == 'trans':
        subval = 3.75
        supval = 17.5



    # ------------------------------
    # Average bins per win_size, per trial
    tot_mean_MSE_ws_tr_sub = []
    tot_mean_RMSE_ws_tr_sub = []
    tot_mean_MSE_ws_tr_sup = []
    tot_mean_RMSE_ws_tr_sup = []
    for tr in range(num_of_tr):
        tot_mean_MSE_win_size_sub = []
        tot_mean_RMSE_win_size_sub = []
        tot_mean_MSE_win_size_sup = []
        tot_mean_RMSE_win_size_sup = []
        for win_size in range(num_of_ws):
            # Get mean across bins
            if np.abs(speed_stim[tr]) == subval:
                tot_mean_MSE_win_size_sub = tot_mean_MSE_win_size_sub + [np.mean(MSE_win_size_tr[tr][win_size], axis=0, keepdims=False)]
                tot_mean_RMSE_win_size_sub = tot_mean_RMSE_win_size_sub + [np.mean(RMSE_win_size_tr[tr][win_size], axis=0, keepdims=False)]
            elif np.abs(speed_stim[tr]) == supval:
                tot_mean_MSE_win_size_sup = tot_mean_MSE_win_size_sup + [np.mean(MSE_win_size_tr[tr][win_size], axis=0, keepdims=False)]
                tot_mean_RMSE_win_size_sup = tot_mean_RMSE_win_size_sup + [np.mean(RMSE_win_size_tr[tr][win_size], axis=0, keepdims=False)]


    tot_mean_MSE_ws_tr_sub = tot_mean_MSE_ws_tr_sub + [tot_mean_MSE_win_size_sub]
    tot_mean_RMSE_ws_tr_sub = tot_mean_RMSE_ws_tr_sub + [tot_mean_RMSE_win_size_sub]
    tot_mean_MSE_ws_tr_sup = tot_mean_MSE_ws_tr_sup + [tot_mean_MSE_win_size_sup]
    tot_mean_RMSE_ws_tr_sup = tot_mean_RMSE_ws_tr_sup + [tot_mean_RMSE_win_size_sup]
    # ------------------------------

    # ------------------------------
    # Average trials per win_size condition 
    tot_meanMSE_ws_fin_sub = []
    tot_meanRMSE_ws_fin_sub = []
    tot_meanMSE_ws_fin_sup = []
    tot_meanRMSE_ws_fin_sup = []
    for win_size in range(num_of_ws):
        tot_mean_MSE_ws_acrosstr_sub = []
        tot_mean_RMSE_ws_acrosstr_sub = []
        tot_mean_MSE_ws_acrosstr_sup = []
        tot_mean_RMSE_ws_acrosstr_sup = []
        for tr in range(num_of_tr):
            if np.abs(speed_stim[tr]) == subval:
                tot_mean_MSE_ws_acrosstr_sub = tot_mean_MSE_ws_acrosstr_sub + [tot_mean_MSE_ws_tr_sub[tr][win_size]]
                tot_mean_RMSE_ws_acrosstr_sub = tot_mean_RMSE_ws_acrosstr_sub + [tot_mean_RMSE_ws_tr_sub[tr][win_size]]
            elif np.abs(speed_stim[tr]) == supval:
                tot_mean_MSE_ws_acrosstr_sup = tot_mean_MSE_ws_acrosstr_sup + [tot_mean_MSE_ws_tr_sup[tr][win_size]]
                tot_mean_RMSE_ws_acrosstr_sup = tot_mean_RMSE_ws_acrosstr_sup + [tot_mean_RMSE_ws_tr_sup[tr][win_size]]

    tot_meanMSE_ws_fin_sub = tot_meanMSE_ws_fin_sub + [tot_mean_MSE_ws_acrosstr_sub]
    tot_meanRMSE_ws_fin_sub = tot_meanRMSE_ws_fin_sub + [tot_mean_RMSE_ws_acrosstr_sub]
    tot_meanMSE_ws_fin_sup = tot_meanMSE_ws_fin_sup + [tot_mean_MSE_ws_acrosstr_sup]
    tot_meanRMSE_ws_fin_sup = tot_meanRMSE_ws_fin_sup + [tot_mean_RMSE_ws_acrosstr_sup]

    # sub
    meanMSE_perWS_sub = np.mean(tot_meanMSE_ws_fin_sub, axis=1, keepdims=False)
    print('meanMSE_perWS_sub : ' + str(meanMSE_perWS_sub))
    print('length of meanMSE_perWS_sub : ' + str(len(meanMSE_perWS_sub)))

    meanRMSE_perWS_sub = np.mean(tot_meanRMSE_ws_fin_sub, axis=1, keepdims=False)
    print('meanRMSE_perWS_sub : ' + str(meanRMSE_perWS_sub))
    print('length of meanRMSE_perWS_sub : ' + str(len(meanRMSE_perWS_sub)))

    aMSE_sub = np.transpose(meanMSE_perWS_sub)
    # print('aMSE_sub : ' + str(aMSE_sub))
    # print('aMSE_sub[0][0] : ' + str(aMSE_sub[0][0]))

    aRMSE_sub = np.transpose(meanRMSE_perWS_sub)
    # print('aRMSE_sub : ' + str(aRMSE_sub))
    # print('aRMSE_sub[0][0] : ' + str(aRMSE_sub[0][0]))

    # sup
    meanMSE_perWS_sup = np.mean(tot_meanMSE_ws_fin_sup, axis=1, keepdims=False)
    print('meanMSE_perWS_sup : ' + str(meanMSE_perWS_sup))
    print('length of meanMSE_perWS_sup : ' + str(len(meanMSE_perWS_sup)))

    meanRMSE_perWS_sup = np.mean(tot_meanRMSE_ws_fin_sup, axis=1, keepdims=False)
    print('meanRMSE_perWS_sup : ' + str(meanRMSE_perWS_sup))
    print('length of meanRMSE_perWS_sup : ' + str(len(meanRMSE_perWS_sup)))

    aMSE_sup = np.transpose(meanMSE_perWS_sup)
    # print('aMSE_sup : ' + str(aMSE_sup))
    # print('aMSE_sup[0][0] : ' + str(aMSE_sup[0][0]))

    aRMSE_sup = np.transpose(meanRMSE_perWS_sup)
    # print('aRMSE_sup : ' + str(aRMSE_sup))
    # print('aRMSE_sup[0][0] : ' + str(aRMSE_sup[0][0]))
    # ------------------------------


    # ------------------------------
    # sub
    plotORnot = 0
    if plotORnot == 1:
        # ------------------------------
        fig = go.Figure()
        config = dict({'scrollZoom': True, 'displayModeBar': True, 'editable': True})

        xxORG = list(range(len(aMSE_sub[0][0])))
        
        fig.add_trace(go.Scatter(x=xxORG, y=aMSE_sub[0][0], name='axis0', line = dict(color='red', width=2, dash='dash'), showlegend=True))
        fig.add_trace(go.Scatter(x=xxORG, y=aMSE_sub[0][1], name='axis1', line = dict(color='green', width=2, dash='dash'), showlegend=True))
        fig.add_trace(go.Scatter(x=xxORG, y=aMSE_sub[0][2], name='axis2', line = dict(color='blue', width=2, dash='dash'), showlegend=True))
        
        fig.update_layout(title='Absolute and Relative error : MSE sub', xaxis_title='window size', yaxis_title='mean MSE sub across bins and trials')
        fig.show(config=config)
        fig.write_image("MSEsub%d_sub.png" % (s))
        # ------------------------------
        
        # ------------------------------
        fig = go.Figure()
        config = dict({'scrollZoom': True, 'displayModeBar': True, 'editable': True})

        xxORG = list(range(len(aRMSE_sub[0][0])))
        
        fig.add_trace(go.Scatter(x=xxORG, y=aRMSE_sub[0][0], name='axis0', line = dict(color='red', width=2, dash='dash'), showlegend=True))
        fig.add_trace(go.Scatter(x=xxORG, y=aRMSE_sub[0][1], name='axis1', line = dict(color='green', width=2, dash='dash'), showlegend=True))
        fig.add_trace(go.Scatter(x=xxORG, y=aRMSE_sub[0][2], name='axis2', line = dict(color='blue', width=2, dash='dash'), showlegend=True))
        
        fig.update_layout(title='Absolute and Relative error : RMSE sub', xaxis_title='window size', yaxis_title='mean RMSE sub across bins and trials')
        fig.show(config=config)
        fig.write_image("RMSEsub%d_sub.png" % (s))
        # ------------------------------

    # ------------------------------
    # sup
    plotORnot = 0
    if plotORnot == 1:
        # ------------------------------
        fig = go.Figure()
        config = dict({'scrollZoom': True, 'displayModeBar': True, 'editable': True})

        xxORG = list(range(len(aMSE_sup[0][0])))
        
        fig.add_trace(go.Scatter(x=xxORG, y=aMSE_sup[0][0], name='axis0', line = dict(color='red', width=2, dash='dash'), showlegend=True))
        fig.add_trace(go.Scatter(x=xxORG, y=aMSE_sup[0][1], name='axis1', line = dict(color='green', width=2, dash='dash'), showlegend=True))
        fig.add_trace(go.Scatter(x=xxORG, y=aMSE_sup[0][2], name='axis2', line = dict(color='blue', width=2, dash='dash'), showlegend=True))
        
        fig.update_layout(title='Absolute and Relative error : MSE sup', xaxis_title='window size', yaxis_title='mean MSE sup across bins and trials')
        fig.show(config=config)
        fig.write_image("MSEsub%d_sup.png" % (s))
        # ------------------------------
        
        # ------------------------------
        fig = go.Figure()
        config = dict({'scrollZoom': True, 'displayModeBar': True, 'editable': True})

        xxORG = list(range(len(aRMSE_sup[0][0])))
        
        fig.add_trace(go.Scatter(x=xxORG, y=aRMSE_sup[0][0], name='axis0', line = dict(color='red', width=2, dash='dash'), showlegend=True))
        fig.add_trace(go.Scatter(x=xxORG, y=aRMSE_sup[0][1], name='axis1', line = dict(color='green', width=2, dash='dash'), showlegend=True))
        fig.add_trace(go.Scatter(x=xxORG, y=aRMSE_sup[0][2], name='axis2', line = dict(color='blue', width=2, dash='dash'), showlegend=True))
        
        fig.update_layout(title='Absolute and Relative error : RMSE sup', xaxis_title='window size', yaxis_title='mean RMSE sup across bins and trials')
        fig.show(config=config)
        fig.write_image("RMSEsub%d_sup.png" % (s))
        # ------------------------------


    return aMSE_sub, aMSE_sup, aRMSE_sub, aRMSE_sup
