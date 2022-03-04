<<<<<<< HEAD
import numpy as np

# Data saving
import pickle

# Plotting
import plotly.graph_objects as go
import plotly.express as px

# module for counting values in a list
from collections import Counter

# Personal python functions
import sys
#sys.path.insert(1, '/home/jamilah/Documents/Sourceforge_analysis_PROJECTS/Motor_classification/b_data_preprocessing')
sys.path.insert(1, 'C:\\Users\\jamilah\\Documents\\Sourceforge_analysis_PROJECTS\\Motor_classification\\b_data_preprocessing')

from subfunctions.make_a_properlist import *



# PURPOSE : Compare data-driven and experiment matrix speed-stim : correlation and bar chart.

def s3_compare_dd_em_speed_stim():
    
    varr = {}
    varr['main_path'] = "C:\\Users\\jamilah\\Documents\\Sourceforge_analysis_PROJECTS\\Motor_classification"  # Windows
    # varr['main_path'] = "/home/jamilah/Documents/Sourceforge_analysis_PROJECTS/Motor_classification"
    
    outlier_val = 0
    sup_val = 2
    sub_val = 1
    
    
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
            c = 18-1   # labeled (YA) - joystick movement
            
            # Load data experimental preprocessed data matrix
            file_name = "rotdat_correction1.pkl"
            open_file = open(file_name, "rb")
            dat = pickle.load(open_file)
            open_file.close()

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
            file_name = "transdat_correction1.pkl"
            open_file = open(file_name, "rb")
            dat = pickle.load(open_file)
            open_file.close()
            


        # 2) Load subjects
        subs = range(len(varr['subjects']))
        subs = make_a_properlist(subs)


        corr_val_1 = []
        corr_val_2 = []
        corr_val_3 = []
        corr_val_4 = []
        corr_val_5 = []
        corr_val_6 = []
        
        speed_stim_co_ALL = []
        speed_stim_ro_ALL = []
        
        for s in subs:
            print('s : ' + str(s))

            # ------------------------------
            # (2) Load pre-preocessed data
            num_of_tr = len(dat[s][0])      
            
            speed_stim_sign_OLD = dat[s][0]         # speed_stim_sign_OLD (DD)
            speed_stim_mag_OLD = dat[s][1]          # speed_stim_mag_OLD (DD)
            
            speed_stim_org_co = dat[s][2]       # speed_stim_org_co (DD)
            speed_stim_org_ro = dat[s][3]       # speed_stim_org_ro (DD)
            
            speed_stim_dd = dat[s][4]           # speed_stim_dd (DD)
            
            axis_out = dat[s][5]                # axis_out (DD)
            axis_org = dat[s][6]                # axis_org (EM : do not use)
            corr_axis_out = dat[s][7]           # corr_axis_out (scalar)
            corr_speed_stim_out = dat[s][8]     # corr_speed_stim_out ([corr_ssdir_dd_co, corr_ssdir_dd_ro, corr_ssmag_dd_co, corr_ssmag_dd_ro, corr_ss_DD_EM_co, corr_ss_DD_EM_ro])
            
            new3_ind_st = dat[s][9]             # new3_ind_st (DD)
            new3_ind_end = dat[s][10]           # new3_ind_end (DD)
            
            outSIGCOM = dat[s][11]              # outSIGCOM
            outSIG = dat[s][12]                 # outSIG
            outJOY = dat[s][13]                 # outJOY
            outNOISE = dat[s][14]               # outNOISE
            
            trialnum_org = dat[s][15]           # trialnum_org
            time = dat[s][16]                   # time_org
            SSQ = dat[s][17]                    # SSQ
            FRT_em = dat[s][18]                 # FRT
            
            # ------------------------------
            
            # Restack the data to be for each of the 6-categories have a value per subject
            corr_val_1 = corr_val_1 + [corr_speed_stim_out[0]]
            corr_val_2 = corr_val_2 + [corr_speed_stim_out[1]]
            corr_val_3 = corr_val_3 + [corr_speed_stim_out[2]]
            corr_val_4 = corr_val_4 + [corr_speed_stim_out[3]]
            corr_val_5 = corr_val_5 + [corr_speed_stim_out[4]]
            corr_val_6 = corr_val_6 + [corr_speed_stim_out[5]]
            
            speed_stim_co_ALL = speed_stim_co_ALL + [speed_stim_org_co]
            speed_stim_ro_ALL = speed_stim_ro_ALL + [speed_stim_org_ro]
            
            #  end of for loop s
            
         
        # ------------------------------
        # Need to plot the correlation values across subjects
        # to determine the order of of target angle speed for rotation, 
        # and to determine if combining mag and direction is accurate
        
        # If combining mag and direction is not accurate, is magnitude or direction for speed stim wrong.
        # ------------------------------
        num_of_corrval = 6
        num_of_s = len(corr_val_1)
        
        fig = go.Figure()
        config = dict({'scrollZoom': True, 'displayModeBar': True, 'editable': True})
        xxORG = list(range(num_of_s))
        
        fig.add_trace(go.Scatter(x=xxORG, y=corr_val_1, name='Dir corr: dd, co', line = dict(width=2, dash='dash'), showlegend=True))
        fig.add_trace(go.Scatter(x=xxORG, y=corr_val_2, name='Dir corr: dd, ro', line = dict(width=3, dash='dash'), showlegend=True))
        fig.add_trace(go.Scatter(x=xxORG, y=corr_val_3, name='Mag corr: dd, co', line = dict(width=4, dash='dash'), showlegend=True))
        fig.add_trace(go.Scatter(x=xxORG, y=corr_val_4, name='Mag corr: dd, ro', line = dict(width=5, dash='dash'), showlegend=True))
        fig.add_trace(go.Scatter(x=xxORG, y=corr_val_5, name='DirandMag corr: dd, co', line = dict(width=6, dash='dash'), showlegend=True))
        fig.add_trace(go.Scatter(x=xxORG, y=corr_val_6, name='DirandMag corr: dd, ro', line = dict(width=7, dash='dash'), showlegend=True))
        
        fig.update_layout(title='Correlation of speed stim (across trials) per subject - %s' % (varr['which_exp']), xaxis_title='subjects', yaxis_title='correlation (%s): speed stim' % (varr['which_exp']))
        fig.show(config=config)
        fig.write_image("corr_speed_stim_out_%s.png" % (varr['which_exp']))
        
        
        # Q : do you use speed_stim_dd (mag only) or speed_stim_DD (dir and mag only)
        # ------------------------------
        # Bar chart of individual categories - for calculated 
        subname = []
        data = []
        for i in range(len(speed_stim_dd[exp])):
            # print('speed_stim_dd[0][i] : ' + str(speed_stim_dd[exp][i]))
            c = Counter(speed_stim_dd[exp][i])
            
            sub_count = np.array(c[sub_val])
            sup_count = np.array(c[sup_val])
            out_count = np.array(c[outlier_val])
            
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
        fig.update_layout(title_text='%s: (Data driven) mag speed stim' % (varr['which_exp']))
        fig.show()
        # name_str = "bar_graph_calcul_%s.png" % (varr['which_exp'])
        # fig.write_image(name_str)
        # ------------------------------
        
        
        # ------------------------------
        # Bar chart of individual categories - for experimental matrix 
        subname = []
        data = []
        for i in range(len(speed_stim_co_ALL)):
            # print('speed_stim_co_ALL[i] : ' + str(speed_stim_co_ALL[i]))
            c = Counter(speed_stim_co_ALL[i])
            
            sub_count = np.array(c[sub_val])
            sup_count = np.array(c[sup_val])
            out_count = np.array(c[outlier_val])
            
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
        fig.update_layout(title_text='%s: (Experimental matrix) mag speed stim : correct order' % (varr['which_exp']))
        fig.show()
        # ------------------------------
        
        
=======
import numpy as np

# Data saving
import pickle

# Plotting
import plotly.graph_objects as go
import plotly.express as px

# module for counting values in a list
from collections import Counter

# Personal python functions
import sys
#sys.path.insert(1, '/home/jamilah/Documents/Sourceforge_analysis_PROJECTS/Motor_classification/b_data_preprocessing')
sys.path.insert(1, 'C:\\Users\\jamilah\\Documents\\Sourceforge_analysis_PROJECTS\\Motor_classification\\b_data_preprocessing')

from subfunctions.make_a_properlist import *



# PURPOSE : Compare data-driven and experiment matrix speed-stim : correlation and bar chart.

def s3_compare_dd_em_speed_stim():
    
    varr = {}
    varr['main_path'] = "C:\\Users\\jamilah\\Documents\\Sourceforge_analysis_PROJECTS\\Motor_classification"  # Windows
    # varr['main_path'] = "/home/jamilah/Documents/Sourceforge_analysis_PROJECTS/Motor_classification"
    
    outlier_val = 0
    sup_val = 2
    sub_val = 1
    
    
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
            c = 18-1   # labeled (YA) - joystick movement
            
            # Load data experimental preprocessed data matrix
            file_name = "rotdat_correction1.pkl"
            open_file = open(file_name, "rb")
            dat = pickle.load(open_file)
            open_file.close()

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
            file_name = "transdat_correction1.pkl"
            open_file = open(file_name, "rb")
            dat = pickle.load(open_file)
            open_file.close()
            


        # 2) Load subjects
        subs = range(len(varr['subjects']))
        subs = make_a_properlist(subs)


        corr_val_1 = []
        corr_val_2 = []
        corr_val_3 = []
        corr_val_4 = []
        corr_val_5 = []
        corr_val_6 = []
        
        speed_stim_co_ALL = []
        speed_stim_ro_ALL = []
        
        for s in subs:
            print('s : ' + str(s))

            # ------------------------------
            # (2) Load pre-preocessed data
            num_of_tr = len(dat[s][0])      
            
            speed_stim_sign_OLD = dat[s][0]         # speed_stim_sign_OLD (DD)
            speed_stim_mag_OLD = dat[s][1]          # speed_stim_mag_OLD (DD)
            
            speed_stim_org_co = dat[s][2]       # speed_stim_org_co (DD)
            speed_stim_org_ro = dat[s][3]       # speed_stim_org_ro (DD)
            
            speed_stim_dd = dat[s][4]           # speed_stim_dd (DD)
            
            axis_out = dat[s][5]                # axis_out (DD)
            axis_org = dat[s][6]                # axis_org (EM : do not use)
            corr_axis_out = dat[s][7]           # corr_axis_out (scalar)
            corr_speed_stim_out = dat[s][8]     # corr_speed_stim_out ([corr_ssdir_dd_co, corr_ssdir_dd_ro, corr_ssmag_dd_co, corr_ssmag_dd_ro, corr_ss_DD_EM_co, corr_ss_DD_EM_ro])
            
            new3_ind_st = dat[s][9]             # new3_ind_st (DD)
            new3_ind_end = dat[s][10]           # new3_ind_end (DD)
            
            outSIGCOM = dat[s][11]              # outSIGCOM
            outSIG = dat[s][12]                 # outSIG
            outJOY = dat[s][13]                 # outJOY
            outNOISE = dat[s][14]               # outNOISE
            
            trialnum_org = dat[s][15]           # trialnum_org
            time = dat[s][16]                   # time_org
            SSQ = dat[s][17]                    # SSQ
            FRT_em = dat[s][18]                 # FRT
            
            # ------------------------------
            
            # Restack the data to be for each of the 6-categories have a value per subject
            corr_val_1 = corr_val_1 + [corr_speed_stim_out[0]]
            corr_val_2 = corr_val_2 + [corr_speed_stim_out[1]]
            corr_val_3 = corr_val_3 + [corr_speed_stim_out[2]]
            corr_val_4 = corr_val_4 + [corr_speed_stim_out[3]]
            corr_val_5 = corr_val_5 + [corr_speed_stim_out[4]]
            corr_val_6 = corr_val_6 + [corr_speed_stim_out[5]]
            
            speed_stim_co_ALL = speed_stim_co_ALL + [speed_stim_org_co]
            speed_stim_ro_ALL = speed_stim_ro_ALL + [speed_stim_org_ro]
            
            #  end of for loop s
            
         
        # ------------------------------
        # Need to plot the correlation values across subjects
        # to determine the order of of target angle speed for rotation, 
        # and to determine if combining mag and direction is accurate
        
        # If combining mag and direction is not accurate, is magnitude or direction for speed stim wrong.
        # ------------------------------
        num_of_corrval = 6
        num_of_s = len(corr_val_1)
        
        fig = go.Figure()
        config = dict({'scrollZoom': True, 'displayModeBar': True, 'editable': True})
        xxORG = list(range(num_of_s))
        
        fig.add_trace(go.Scatter(x=xxORG, y=corr_val_1, name='Dir corr: dd, co', line = dict(width=2, dash='dash'), showlegend=True))
        fig.add_trace(go.Scatter(x=xxORG, y=corr_val_2, name='Dir corr: dd, ro', line = dict(width=3, dash='dash'), showlegend=True))
        fig.add_trace(go.Scatter(x=xxORG, y=corr_val_3, name='Mag corr: dd, co', line = dict(width=4, dash='dash'), showlegend=True))
        fig.add_trace(go.Scatter(x=xxORG, y=corr_val_4, name='Mag corr: dd, ro', line = dict(width=5, dash='dash'), showlegend=True))
        fig.add_trace(go.Scatter(x=xxORG, y=corr_val_5, name='DirandMag corr: dd, co', line = dict(width=6, dash='dash'), showlegend=True))
        fig.add_trace(go.Scatter(x=xxORG, y=corr_val_6, name='DirandMag corr: dd, ro', line = dict(width=7, dash='dash'), showlegend=True))
        
        fig.update_layout(title='Correlation of speed stim (across trials) per subject - %s' % (varr['which_exp']), xaxis_title='subjects', yaxis_title='correlation (%s): speed stim' % (varr['which_exp']))
        fig.show(config=config)
        fig.write_image("corr_speed_stim_out_%s.png" % (varr['which_exp']))
        
        
        # Q : do you use speed_stim_dd (mag only) or speed_stim_DD (dir and mag only)
        # ------------------------------
        # Bar chart of individual categories - for calculated 
        subname = []
        data = []
        for i in range(len(speed_stim_dd[exp])):
            # print('speed_stim_dd[0][i] : ' + str(speed_stim_dd[exp][i]))
            c = Counter(speed_stim_dd[exp][i])
            
            sub_count = np.array(c[sub_val])
            sup_count = np.array(c[sup_val])
            out_count = np.array(c[outlier_val])
            
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
        fig.update_layout(title_text='%s: (Data driven) mag speed stim' % (varr['which_exp']))
        fig.show()
        # name_str = "bar_graph_calcul_%s.png" % (varr['which_exp'])
        # fig.write_image(name_str)
        # ------------------------------
        
        
        # ------------------------------
        # Bar chart of individual categories - for experimental matrix 
        subname = []
        data = []
        for i in range(len(speed_stim_co_ALL)):
            # print('speed_stim_co_ALL[i] : ' + str(speed_stim_co_ALL[i]))
            c = Counter(speed_stim_co_ALL[i])
            
            sub_count = np.array(c[sub_val])
            sup_count = np.array(c[sup_val])
            out_count = np.array(c[outlier_val])
            
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
        fig.update_layout(title_text='%s: (Experimental matrix) mag speed stim : correct order' % (varr['which_exp']))
        fig.show()
        # ------------------------------
        
        
>>>>>>> 94b06cd4776edc5e6880e69ca0d1eefbe92d257c
    return