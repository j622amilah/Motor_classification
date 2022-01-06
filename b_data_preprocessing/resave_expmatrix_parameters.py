import numpy as np

# Data saving
import pickle


def resave_expmatrix_parameters(speed_stim_DD_out):
    # Resave all the data in an updated matrix

    varr = {}
    varr['main_path'] = "C:\\Users\\jamilah\\Documents\\Sourceforge_analysis_PROJECTS\\Motor_classification"  # Windows
    # varr['main_path'] = "/home/jamilah/Documents/Sourceforge_analysis_PROJECTS/Motor_classification"
    
    
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
            file_name = "rotdat.pkl"
            open_file = open(file_name, "rb")
            dat = pickle.load(open_file)
            open_file.close()
            
            rotdat2 = []

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

            transdat2 = []


        # 2) Load subjects
        subs = list(range(len(varr['subjects'])))
        
        subdat = []
        
        for s in subs:

            # ------------------------------
            # (2) Load pre-preocessed data
            axis_out = dat[s][3]                # 3 : axis_out (DD)
            
            new3_ind_st = dat[s][7]             # 7 : new3_ind_st (DD)
            new3_ind_end = dat[s][8]            # 8 : new3_ind_end (DD)
            
            outSIGCOM = dat[s][9]               # 9 : outSIGCOM
            outSIG = dat[s][10]                 # 10 : outSIG
            outJOY = dat[s][11]                 # 11 : outJOY
            outNOISE = dat[s][12]               # 12 : outNOISE
            
            trialnum_org = dat[s][13]           # 13 : trialnum_org
            time = dat[s][14]                   # 14 : time_org
            SSQ = dat[s][15]                    # 15 : SSQ
            FRT_em = dat[s][16]                 # 16 : FRT
            # ------------------------------


            # ------------------------------
            # Pack up corrections into the matrix
            # ------------------------------
            # experimental matrix events
            e0 = np.array(speed_stim_DD_out[exp][s], dtype=object)            # (DD)
            
            e1 = np.array(axis_out)                 # (DD)
            
            e2 = np.array(new3_ind_st)
            e3 = np.array(new3_ind_end)
            
            e4 = np.array(outSIGCOM, dtype=object)
            e5 = np.array(outSIG, dtype=object)
            e6 = np.array(outJOY, dtype=object)
            e7 = np.array(outNOISE, dtype=object)
            
            e8 = np.array(trialnum_org)
            e9 = np.array(time, dtype=object)
            e10 = np.array(SSQ)
            e11 = np.array(FRT_em)
            
            subdat = e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11
            
            # Append the matrix of each subject 
            if exp == 0:
                rotdat2 = rotdat2 + [subdat]
            elif exp == 1:
                transdat2 = transdat2 + [subdat]


        # ------------------------------
        # Save data matrices to file per experiment
        file_name = "%sdat2.pkl" % (varr['which_exp'])
        open_file = open(file_name, "wb")
        if varr['which_exp'] == 'rot':
            pickle.dump(rotdat2, open_file)
            del rotdat2
        elif varr['which_exp'] == 'trans':
            pickle.dump(transdat2, open_file)
            del transdat2
        open_file.close()
        # ------------------------------


    return 