import numpy as np

# Plotting
from plotly.subplots import make_subplots
import plotly.graph_objects as go





def plottingANDstats_MSE_RMSE(plot_stim_speed, ax0_MSE, ax1_MSE, ax2_MSE, ax0_RMSE, ax1_RMSE, ax2_RMSE, ax0_MSE_sub, ax1_MSE_sub, ax2_MSE_sub, ax0_RMSE_sub, ax1_RMSE_sub, ax2_RMSE_sub, ax0_MSE_sup, ax1_MSE_sup, ax2_MSE_sup, ax0_RMSE_sup, ax1_RMSE_sup, ax2_RMSE_sup):


    if plot_stim_speed == 0:
        # Take the mean across all the participants
        ax0_MSE_all = np.mean(ax0_MSE, axis=0, keepdims=True)
        ax1_MSE_all = np.mean(ax1_MSE, axis=0, keepdims=True)
        ax2_MSE_all = np.mean(ax2_MSE, axis=0, keepdims=True)
        print('ax0_MSE_all : ' + str(ax0_MSE_all))
        print('length of ax0_MSE_all[0] : ' + str(len(ax0_MSE_all[0])))
        print('ax0_MSE_all[0] : ' + str(ax0_MSE_all[0]))
        
        # Take the mean across all the participants
        ax0_RMSE_all = np.mean(ax0_RMSE, axis=0, keepdims=True)
        ax1_RMSE_all = np.mean(ax1_RMSE, axis=0, keepdims=True)
        ax2_RMSE_all = np.mean(ax2_RMSE, axis=0, keepdims=True)
        print('ax0_RMSE_all : ' + str(ax0_RMSE_all))
        print('length of ax0_RMSE_all[0] : ' + str(len(ax0_RMSE_all[0])))
        print('ax0_RMSE_all[0] : ' + str(ax0_RMSE_all[0]))


        # ------------------------------
        # MSE : Plotting the average of all participants  
        # ------------------------------  
        fig = go.Figure()
        config = dict({'scrollZoom': True, 'displayModeBar': True, 'editable': True})
        xxORG = list(range(len(ax0_MSE_all[0])))

        fig.add_trace(go.Scatter(x=xxORG, y=ax0_MSE_all[0], name='axis0: Roll/LR', line = dict(color='red', width=2, dash='dash'), showlegend=True))
        fig.add_trace(go.Scatter(x=xxORG, y=ax1_MSE_all[0], name='axis1: Pitch/FB', line = dict(color='green', width=2, dash='dash'), showlegend=True))
        fig.add_trace(go.Scatter(x=xxORG, y=ax2_MSE_all[0], name='axis2: Yaw/UD', line = dict(color='blue', width=2, dash='dash'), showlegend=True))

        fig.update_layout(title='Absolute and Relative error : MSE', xaxis_title='window size', yaxis_title='mean MSE across bins and trials')
        fig.show(config=config)
        fig.write_image("MSE_allsub.png")
        # ------------------------------
        
        
        # ------------------------------
        # RMSE : Plotting the average of all participants
        # ------------------------------
        fig = go.Figure()
        config = dict({'scrollZoom': True, 'displayModeBar': True, 'editable': True})
        xxORG = list(range(len(ax0_RMSE_all[0])))

        fig.add_trace(go.Scatter(x=xxORG, y=ax0_RMSE_all[0], name='axis0: Roll/LR', line = dict(color='red', width=2, dash='dash'), showlegend=True))
        fig.add_trace(go.Scatter(x=xxORG, y=ax1_RMSE_all[0], name='axis1: Pitch/FB', line = dict(color='green', width=2, dash='dash'), showlegend=True))
        fig.add_trace(go.Scatter(x=xxORG, y=ax2_RMSE_all[0], name='axis2: Yaw/UD', line = dict(color='blue', width=2, dash='dash'), showlegend=True))

        fig.update_layout(title='Absolute and Relative error : RMSE', xaxis_title='window size', yaxis_title='mean RMSE across bins and trials')
        fig.show(config=config)
        fig.write_image("RMSE_allsub.png")
        # ------------------------------
        
        
    elif plot_stim_speed == 1:

        # Take the mean across all the participants
        ax0_MSE_all_sub = np.mean(ax0_MSE_sub, axis=0, keepdims=True)
        ax1_MSE_all_sub = np.mean(ax1_MSE_sub, axis=0, keepdims=True)
        ax2_MSE_all_sub = np.mean(ax2_MSE_sub, axis=0, keepdims=True)
        
        ax0_MSE_all_sup = np.mean(ax0_MSE_sup, axis=0, keepdims=True)
        ax1_MSE_all_sup = np.mean(ax1_MSE_sup, axis=0, keepdims=True)
        ax2_MSE_all_sup = np.mean(ax2_MSE_sup, axis=0, keepdims=True)
        
        print('ax0_MSE_all_sup : ' + str(ax0_MSE_all_sup))
        print('length of ax0_MSE_all_sup[0] : ' + str(len(ax0_MSE_all_sup[0])))
        print('ax0_MSE_all_sup[0] : ' + str(ax0_MSE_all_sup[0]))
        
        # Take the mean across all the participants
        ax0_RMSE_all_sub = np.mean(ax0_RMSE_sub, axis=0, keepdims=True)
        ax1_RMSE_all_sub = np.mean(ax1_RMSE_sub, axis=0, keepdims=True)
        ax2_RMSE_all_sub = np.mean(ax2_RMSE_sub, axis=0, keepdims=True)
        
        ax0_RMSE_all_sup = np.mean(ax0_RMSE_sup, axis=0, keepdims=True)
        ax1_RMSE_all_sup = np.mean(ax1_RMSE_sup, axis=0, keepdims=True)
        ax2_RMSE_all_sup = np.mean(ax2_RMSE_sup, axis=0, keepdims=True)
        
        print('ax0_RMSE_all_sup : ' + str(ax0_RMSE_all_sup))
        print('length of ax0_RMSE_all_sup[0] : ' + str(len(ax0_RMSE_all_sup[0])))
        print('ax0_RMSE_all_sup[0] : ' + str(ax0_RMSE_all_sup[0]))

        
        # ------------------------------
        # MSE : Plotting the average of all participants  
        # ------------------------------  
        ax0_MSE_all = np.mean(ax0_MSE, axis=0, keepdims=True)
        print('ax0_MSE_all : ' + str(ax0_MSE_all))

        ax1_MSE_all = np.mean(ax1_MSE, axis=0, keepdims=True)
        ax2_MSE_all = np.mean(ax2_MSE, axis=0, keepdims=True)

        print('length of ax0_MSE_all[0] : ' + str(len(ax0_MSE_all[0])))
        print('ax0_MSE_all[0] : ' + str(ax0_MSE_all[0]))

        fig = go.Figure()
        config = dict({'scrollZoom': True, 'displayModeBar': True, 'editable': True})
        xxORG = list(range(len(ax0_MSE_all[0])))

        fig.add_trace(go.Scatter(x=xxORG, y=ax0_MSE_all[0], name='axis0: Roll/LR', line = dict(color='red', width=2, dash='dash'), showlegend=True))
        fig.add_trace(go.Scatter(x=xxORG, y=ax1_MSE_all[0], name='axis1: Pitch/FB', line = dict(color='green', width=2, dash='dash'), showlegend=True))
        fig.add_trace(go.Scatter(x=xxORG, y=ax2_MSE_all[0], name='axis2: Yaw/UD', line = dict(color='blue', width=2, dash='dash'), showlegend=True))

        fig.update_layout(title='Absolute and Relative error : MSE', xaxis_title='window size', yaxis_title='mean MSE across bins and trials')
        fig.show(config=config)
        fig.write_image("MSE_allsub.png")
        # ------------------------------
        
        
        # ------------------------------
        # RMSE (sub and sup) : Plotting the average of all participants
        # ------------------------------
        ax0_RMSE_all = np.mean(ax0_RMSE, axis=0, keepdims=True)
        print('ax0_RMSE_all : ' + str(ax0_RMSE_all))

        ax1_RMSE_all = np.mean(ax1_RMSE, axis=0, keepdims=True)
        ax2_RMSE_all = np.mean(ax2_RMSE, axis=0, keepdims=True)

        print('length of ax0_RMSE_all[0] : ' + str(len(ax0_RMSE_all[0])))
        print('ax0_RMSE_all[0] : ' + str(ax0_RMSE_all[0]))

        fig = go.Figure()
        config = dict({'scrollZoom': True, 'displayModeBar': True, 'editable': True})
        xxORG = list(range(len(ax0_RMSE_all[0])))

        fig.add_trace(go.Scatter(x=xxORG, y=ax0_RMSE_all[0], name='axis0: Roll/LR', line = dict(color='red', width=2, dash='dash'), showlegend=True))
        fig.add_trace(go.Scatter(x=xxORG, y=ax1_RMSE_all[0], name='axis1: Pitch/FB', line = dict(color='green', width=2, dash='dash'), showlegend=True))
        fig.add_trace(go.Scatter(x=xxORG, y=ax2_RMSE_all[0], name='axis2: Yaw/UD', line = dict(color='blue', width=2, dash='dash'), showlegend=True))

        fig.update_layout(title='Absolute and Relative error : RMSE', xaxis_title='window size', yaxis_title='mean RMSE across bins and trials')
        fig.show(config=config)
        fig.write_image("RMSE_allsub.png")
        # ------------------------------
        
        
        
        # ------------------------------
        # Control Response figure : error vs sub/sup per win_size category for rot and trans
        # ------------------------------
        
        # winval_list = np.floor([siglen,siglen/2, siglen/4, siglen/6, siglen/8, siglen/10, siglen/12, siglen/14, siglen/16, siglen/18, siglen/20, siglen/22, siglen/24, siglen/26, siglen/28, siglen/30])
        
        # Choose top five min errors and put in win_size_cat with absolute=1
        aa = 'RMSE'  # 'MSE', 'RMSE'
        
        if aa == 'MSE':
            ax0_metric_all_sub = ax0_MSE_all_sub
            ax1_metric_all_sub = ax1_MSE_all_sub
            ax2_metric_all_sub = ax2_MSE_all_sub
            ax0_metric_all_sup = ax0_MSE_all_sup
            ax1_metric_all_sup = ax1_MSE_all_sup
            ax2_metric_all_sup = ax2_MSE_all_sup
        elif aa == 'RMSE':
            ax0_metric_all_sub = ax0_RMSE_all_sub
            ax1_metric_all_sub = ax1_RMSE_all_sub
            ax2_metric_all_sub = ax2_RMSE_all_sub
            ax0_metric_all_sup = ax0_RMSE_all_sup
            ax1_metric_all_sup = ax1_RMSE_all_sup
            ax2_metric_all_sup = ax2_RMSE_all_sup
         
        
        min_ind_ax0_sub = np.argmin(ax0_metric_all_sub[0][1:-1])  # we do not want to search across first point (which is absolute)
        min_ind_ax1_sub = np.argmin(ax1_metric_all_sub[0][1:-1])
        min_ind_ax2_sub = np.argmin(ax2_metric_all_sub[0][1:-1])
        
        c = Counter([min_ind_ax0_sub, min_ind_ax1_sub, min_ind_ax2_sub])
        top_ind_across_ax_sub = c.most_common
        print('top_ind_across_ax_sub : ' + str(top_ind_across_ax_sub))
        win_size_cat_sub = make_a_properlist([0, top_ind_across_ax_sub[0:4]])
        
        
        min_ind_ax0_sup = np.argmin(ax0_metric_all_sup[0][1:-1])
        min_ind_ax1_sup = np.argmin(ax1_metric_all_sup[0][1:-1])
        min_ind_ax2_sup = np.argmin(ax2_metric_all_sup[0][1:-1])
        
        c = Counter([min_ind_ax0_sup, min_ind_ax1_sup, min_ind_ax2_sup])
        top_ind_across_ax_sup = c.most_common
        print('top_ind_across_ax_sup : ' + str(top_ind_across_ax_sup))
        win_size_cat_sup = make_a_properlist([0, top_ind_across_ax_sup[0:4]])
        
        # ------------------------------
        # Grouped Bar Chart
        # ------------------------------
        xtitle = 'sub'
        ax_category_name = [varr['anom']]
        
        if xtitle == 'sub':
            ax0_win_des_sub = ax0_metric_all_sub[win_size_cat_sub]   # each column is a win_size err for axis0
            ax1_win_des_sub = ax1_metric_all_sub[win_size_cat_sub] 
            ax2_win_des_sub = ax2_metric_all_sub[win_size_cat_sub]
        elif xtitle == 'sup':
            ax0_win_des_subORsup = ax0_metric_all_sup[win_size_cat_sup] 
            ax1_win_des_subORsup = ax1_metric_all_sup[win_size_cat_sup] 
            ax2_win_des_subORsup = ax2_metric_all_sup[win_size_cat_sup] 
        
        fig = go.Figure(data=[
            go.Bar(name='Abs err: 1', x=ax_category_name, y=[ax0_win_des_subORsup[0], ax1_win_des_subORsup[0], ax2_win_des_subORsup[0]]), 
            go.Bar(name='Rel err: n1', x=ax_category_name, y=[ax0_win_des_subORsup[1], ax1_win_des_subORsup[1], ax2_win_des_subORsup[1]]), 
            go.Bar(name='Rel err: n2', x=ax_category_name, y=[ax0_win_des_subORsup[2], ax1_win_des_subORsup[2], ax2_win_des_subORsup[2]]), 
            go.Bar(name='Rel err: n3', x=ax_category_name, y=[ax0_win_des_subORsup[3], ax1_win_des_subORsup[3], ax2_win_des_subORsup[3]]), 
            go.Bar(name='Rel err: n4', x=ax_category_name, y=[ax0_win_des_subORsup[4], ax1_win_des_subORsup[4], ax2_win_des_subORsup[4]]), 
            go.Bar(name='Rel err: n5', x=ax_category_name, y=[ax0_win_des_subORsup[5], ax1_win_des_subORsup[5], ax2_win_des_subORsup[5]])])

        titlestr = ''
        fig.update_layout(title=titlestr, xaxis_title=xtitle, yaxis_title='Average subject trial error', barmode='group')
        fig.show()
        
        figure_name1 = 'grouped_bar_chart_%s_%s' % (varr['which_exp'], xtitle)
        fig.write_image("%s.png" % (figure_name1))
        # ------------------------------
        
        
        # ------------------------------
        # Clustered Grouped Bar Chart
        # ------------------------------
        # https://towardsdatascience.com/clustered-overlapped-bar-charts-with-plotly-express-c752d2925cf1
        # ax_category_name = [varr['anom'], '', varr['anom']]
        # fig = go.Figure()
        
        # fig.add_trace(go.Bar(x = df_clust['Year'], y = df_clust['North America'], width = anchos, name='Abs err: 1', text = df_clust['North America']))
                     
        # titlestr = ''
        # fig.update_layout(title=titlestr, xaxis_title=xtitle, yaxis_title='Average subject trial error', barmode='group')
        # fig.show()
        
        # figure_name1 = 'grouped_bar_chart_%s_%s' % (varr['which_exp'], xtitle)
        # fig.write_image("%s.png" % (figure_name1))
        # ------------------------------
        
    return