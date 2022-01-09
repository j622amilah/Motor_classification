import numpy as np

# Plotting
from plotly.subplots import make_subplots
import plotly.graph_objects as go
	



	
def consolidation_of_err_wo_speedstim(MSE_win_size_tr):
    num_of_tr = len(MSE_win_size_tr)
    num_of_ws = len(MSE_win_size_tr[0])

    # ------------------------------
    # Average bins per win_size, per trial
    tot_mean_MSE_ws_tr = []
    tot_mean_RMSE_ws_tr = []
    for tr in range(num_of_tr):
        tot_mean_MSE_win_size = []
        tot_mean_RMSE_win_size = []
        for win_size in range(num_of_ws):
            # Get mean across bins
            tot_mean_MSE_win_size = tot_mean_MSE_win_size + [np.mean(MSE_win_size_tr[tr][win_size], axis=0, keepdims=False)]
            tot_mean_RMSE_win_size = tot_mean_RMSE_win_size + [np.mean(RMSE_win_size_tr[tr][win_size], axis=0, keepdims=False)]


    tot_mean_MSE_ws_tr = tot_mean_MSE_ws_tr + [tot_mean_MSE_win_size]
    tot_mean_RMSE_ws_tr = tot_mean_RMSE_ws_tr + [tot_mean_RMSE_win_size]
    # ------------------------------

    # ------------------------------
    # Average trials per win_size condition 
    tot_meanMSE_ws_fin = []
    tot_meanRMSE_ws_fin = []
    for win_size in range(num_of_ws):
        tot_mean_MSE_ws_acrosstr = []
        tot_mean_RMSE_ws_acrosstr = []
        for tr in range(num_of_tr):
            tot_mean_MSE_ws_acrosstr = tot_mean_MSE_ws_acrosstr + [tot_mean_MSE_ws_tr[tr][win_size]]
            tot_mean_RMSE_ws_acrosstr = tot_mean_RMSE_ws_acrosstr + [tot_mean_RMSE_ws_tr[tr][win_size]]

    tot_meanMSE_ws_fin = tot_meanMSE_ws_fin + [tot_mean_MSE_ws_acrosstr]
    tot_meanRMSE_ws_fin = tot_meanRMSE_ws_fin + [tot_mean_RMSE_ws_acrosstr]

    meanMSE_perWS = np.mean(tot_meanMSE_ws_fin, axis=1, keepdims=False)
    print('meanMSE_perWS : ' + str(meanMSE_perWS))
    print('length of meanMSE_perWS : ' + str(len(meanMSE_perWS)))

    meanRMSE_perWS = np.mean(tot_meanRMSE_ws_fin, axis=1, keepdims=False)
    print('meanRMSE_perWS : ' + str(meanRMSE_perWS))
    print('length of meanRMSE_perWS : ' + str(len(meanRMSE_perWS)))

    aMSE = np.transpose(meanMSE_perWS)
    # print('aMSE : ' + str(aMSE))
    # print('aMSE[0][0] : ' + str(aMSE[0][0]))

    aRMSE = np.transpose(meanRMSE_perWS)
    # print('aRMSE : ' + str(aRMSE))
    # print('aRMSE[0][0] : ' + str(aRMSE[0][0]))
    # ------------------------------

    # ------------------------------
    fig = go.Figure()
    config = dict({'scrollZoom': True, 'displayModeBar': True, 'editable': True})

    xxORG = list(range(len(aMSE[0][0])))

    fig.add_trace(go.Scatter(x=xxORG, y=aMSE[0][0], name='axis0', line = dict(color='red', width=2, dash='dash'), showlegend=True))
    fig.add_trace(go.Scatter(x=xxORG, y=aMSE[0][1], name='axis1', line = dict(color='green', width=2, dash='dash'), showlegend=True))
    fig.add_trace(go.Scatter(x=xxORG, y=aMSE[0][2], name='axis2', line = dict(color='blue', width=2, dash='dash'), showlegend=True))

    fig.update_layout(title='Absolute and Relative error : MSE', xaxis_title='window size', yaxis_title='mean MSE across bins and trials')
    fig.show(config=config)
    fig.write_image("MSEsub%d.png" % (s))
    # ------------------------------

    # ------------------------------
    fig = go.Figure()
    config = dict({'scrollZoom': True, 'displayModeBar': True, 'editable': True})

    xxORG = list(range(len(aRMSE[0][0])))

    fig.add_trace(go.Scatter(x=xxORG, y=aRMSE[0][0], name='axis0', line = dict(color='red', width=2, dash='dash'), showlegend=True))
    fig.add_trace(go.Scatter(x=xxORG, y=aRMSE[0][1], name='axis1', line = dict(color='green', width=2, dash='dash'), showlegend=True))
    fig.add_trace(go.Scatter(x=xxORG, y=aRMSE[0][2], name='axis2', line = dict(color='blue', width=2, dash='dash'), showlegend=True))

    fig.update_layout(title='Absolute and Relative error : RMSE', xaxis_title='window size', yaxis_title='mean RMSE across bins and trials')
    fig.show(config=config)
    fig.write_image("RMSEsub%d.png" % (s))
    # ------------------------------


    return aMSE, aRMSE
