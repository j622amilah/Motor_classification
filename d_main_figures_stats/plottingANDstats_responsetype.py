import numpy as np

# Plotting
from plotly.subplots import make_subplots
import plotly.graph_objects as go

from collections import Counter

# Data saving
import pickle

def plottingANDstats_responsetype():
    
	# ------------------------------
    # Reloading the metric matrix, to analysis detection response
    # ------------------------------

    varr = {}
    varr['main_path'] = "C:\\Users\\jamilah\\Documents\\Sourceforge_analysis_PROJECTS\\Motor_classification"  # Windows
    #varr['main_path'] = "/home/jamilah/Documents/Sourceforge_analysis_PROJECTS/Motor_classification"

    NUMmark = 0   #  an arbitraily large number to denote a non-valid entry

    fs = 10 #  Original experimental sampling was at 250Hz, but data is downsampled to 10Hz
    ts = 1/fs

    mj_val = [0.1, 0.05, 0.01]


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
            file_name = "rot_Xexp.pkl"
            
            xtitle = 'Rotation'
            ax_category_name = ['RO', 'PI', 'YA']
            

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
            
            # Load data experimental preprocessed data matrix
            file_name = "trans_Xexp.pkl"
            
            xtitle = 'Translation'
            ax_category_name = ['LR', 'FB', 'UD']
    
    
    
        open_file = open(file_name, "rb")
        X = pickle.load(open_file)
        open_file.close()



        # Average across subjects and trials per axis
        num_of_subs = len(X)
        print('num_of_subs : ' + str(num_of_subs))
        ax0 = []
        ax1 = []
        ax2 = []
        for s in range(num_of_subs):
            # print('s : ' + str(s))
            
            num_of_tr = len(X[s])
            
            # subX = np.transpose(X[s])
            
            axis_out = X[s][:,3]
            # axis_out = subX[3,:]
            
            ax0_sub = []
            ax1_sub = []
            ax2_sub = []
            for tr in range(num_of_tr):
                if int(axis_out[tr]) == 0: # RO/LR
                    # ax0_sub = ax0_sub + [1+subX[4,tr]]
                    ax0_sub = ax0_sub + [X[s][tr,4]]
                elif int(axis_out[tr]) == 1: # PI/FB
                    # ax1_sub = ax1_sub + [1+subX[4,tr]]
                    ax1_sub = ax1_sub + [X[s][tr,4]]
                elif int(axis_out[tr]) == 2: # YA/UD  
                    # ax2_sub = ax2_sub + [1+subX[4,tr]]
                    ax2_sub = ax2_sub + [X[s][tr,4]]
                # print('ax0_sub : ' + str(ax0_sub))
            
            ax0_sub = [int(x) for x in ax0_sub]
            c0 = Counter(ax0_sub)
            rt_ax0 = [c0[1], c0[2], c0[3], c0[4], c0[5], c0[6], c0[7], c0[8], c0[9], c0[10]]

            ax1_sub = [int(x) for x in ax1_sub]
            c1 = Counter(ax1_sub)
            rt_ax1 = [c1[1], c1[2], c1[3], c1[4], c1[5], c1[6], c1[7], c1[8], c1[9], c1[10]]
            
            ax2_sub = [int(x) for x in ax2_sub]
            c2 = Counter(ax2_sub)
            rt_ax2 = [c2[1], c2[2], c2[3], c2[4], c2[5], c2[6], c2[7], c2[8], c2[9], c2[10]]

            # ax0 = ax0 + [ax0_sub]
            # ax1 = ax1 + [ax1_sub]
            # ax2 = ax2 + [ax2_sub]
            
            ax0 = ax0 + [rt_ax0]
            ax1 = ax1 + [rt_ax1]
            ax2 = ax2 + [rt_ax2]


        print('ax0 : ' + str(ax0))
        print('ax1 : ' + str(ax1))
        print('ax2 : ' + str(ax2))

        tot_cou_per_ax = 14*num_of_subs # the number trials per axis originally adminstered * number of participants

        ax0_a_s = np.sum(ax0, axis=0)
        print('ax0_a_s : ' + str(ax0_a_s))
        ax0_tot_cou = np.sum(ax0_a_s)
        print('ax0_tot_cou : ' + str(ax0_tot_cou))

        # Normalize the count to a value from 0 to 1, then rescale to a meaningful integer value.
        # A meaningful integer value is in the context of the experiment, the original 
        # experimental trial counts that were administered
        ax0_a_s_nor = np.floor(tot_cou_per_ax*(ax0_a_s/ax0_tot_cou))
        print('ax0_a_s_nor : ' + str(ax0_a_s_nor))

        ax1_a_s = np.sum(ax1, axis=0)
        print('ax1_a_s : ' + str(ax1_a_s))
        ax1_tot_cou = np.sum(ax1_a_s)
        print('ax1_tot_cou : ' + str(ax1_tot_cou))
        ax1_a_s_nor = np.floor(tot_cou_per_ax*(ax1_a_s/ax1_tot_cou))
        print('ax1_a_s_nor : ' + str(ax1_a_s_nor))

        ax2_a_s = np.sum(ax2, axis=0)
        print('ax2_a_s : ' + str(ax2_a_s))
        ax2_tot_cou = np.sum(ax2_a_s)
        print('ax2_tot_cou : ' + str(ax2_tot_cou))
        ax2_a_s_nor = np.floor(tot_cou_per_ax*(ax2_a_s/ax2_tot_cou))
        print('ax2_a_s_nor : ' + str(ax2_a_s_nor))

        # True, the count across axes are not the same because we cut data during the 
        # standarization step so you can not compare them,
        # need to normalize the count per axis wrt the max


        # Remove sham from the plot, we are not interested in analysising sham trials but
        # we needed to include them in the total count for the correct total distribution.


        # ------------------------------
        # Grouped Bar Chart per axis
        # ------------------------------
        res_type = ['1:ax=ic,dir=ic', '2:ax=ic,dir=ec', '3:ax=ic,dir=nc', '4:ax=ec,dir=ic', '5:ax=ec,dir=ec', '6:ax=ec,dir=nc', '7:ax=nc', '8:sham:ax=ic', '9:subnomoveax=nc', '10:sham:ax=nc']

        fig = go.Figure(data=[
            go.Bar(name=res_type[0], x=ax_category_name, y=[ax0_a_s_nor[0],ax1_a_s_nor[0],ax2_a_s_nor[0]]),
            go.Bar(name=res_type[1], x=ax_category_name, y=[ax0_a_s_nor[1],ax1_a_s_nor[1],ax2_a_s_nor[1]]),
            go.Bar(name=res_type[2], x=ax_category_name, y=[ax0_a_s_nor[2],ax1_a_s_nor[2],ax2_a_s_nor[2]]),
            go.Bar(name=res_type[3], x=ax_category_name, y=[ax0_a_s_nor[3],ax1_a_s_nor[3],ax2_a_s_nor[3]]),
            go.Bar(name=res_type[4], x=ax_category_name, y=[ax0_a_s_nor[4],ax1_a_s_nor[4],ax2_a_s_nor[4]]),
            go.Bar(name=res_type[5], x=ax_category_name, y=[ax0_a_s_nor[5],ax1_a_s_nor[5],ax2_a_s_nor[5]]),
            go.Bar(name=res_type[6], x=ax_category_name, y=[ax0_a_s_nor[6],ax1_a_s_nor[6],ax2_a_s_nor[6]]),
            go.Bar(name=res_type[8], x=ax_category_name, y=[ax0_a_s_nor[8],ax1_a_s_nor[8],ax2_a_s_nor[8]])
                  ])

        fig.update_layout(title='%s: normalized count per axis (ic=initially correct, ec=eventually correct, nc=never correct)' % (xtitle), xaxis_title=xtitle, yaxis_title='Trial count (per response type category)', barmode='group')
        fig.show()

        figure_name1 = 'grouped_bar_chart_resptype_%s' % (varr['which_exp'])
        fig.write_image("%s.png" % (figure_name1))
        # ------------------------------
        
        
        
        # ------------------------------
        # Grouped Bar Chart per axis per speed_stim : paper figure
        # ------------------------------
        
        
        
        # ------------------------------
        # Statistics for Grouped Bar Chart per axis per speed_stim : paper figure
        # ------------------------------
        
    
    return