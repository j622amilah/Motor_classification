import numpy as np
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

from itertools import zip_longest

from textwrap import wrap

import sys
sys.path.insert(1, 'C:\\Users\\jamilah\\Documents\\Sourceforge_analysis_PROJECTS\\Motor_classification')

from subfunctions.make_a_properlist import *
from subfunctions.confidence_interval import *
from subfunctions.two_sample_stats import *
from subfunctions.semi_automated_gen import *
from subfunctions.compare_condi import compare_across_condi, compare_within_condi




def plot_count2subplot2(po, df_scalarmetics_exp, cou, ax, plt, exp, exp_name, anom, estimator_type, eval_axis_dir):

    # Redoing the count bargraph because I can not go back to it and make changes fast; it is too complex
    final_temp_withincondi = pd.DataFrame()

    final_temp_acrosscondi = pd.DataFrame()

    df_long_tot = pd.DataFrame()

    outer3_name = ['rot', 'trans']

    bonfero_thresh = 0.0167
    across_marg = 4

    df_sig_cats = pd.DataFrame()

    num_of_tests = 3

    df = df_scalarmetics_exp[outer3_name[exp]]

    outer_name_list = ['sub', 'sup']
    inner_name_list = ['IC', 'EC', 'NC', 'NR']
    
    
    ax_all_vals_exp = []
    for i in range(3):  # 0=RO/LR, 1=PI/FB, 2=YA/UD
        
        ax_all_vals = []
        for j in range(1,3):  # 1=sub, 2=sup
            num_of_sub = len(df.subject.value_counts().to_numpy())
            print('num_of_sub: ', num_of_sub)

            # 1a) I need the counts per subject to get the population count for the error bars
            IC_vals = list(df.subject[(df.res_type == 1) & (df.ax == i) & (np.abs(df.ss) == j)].value_counts().to_numpy())
            

            if eval_axis_dir == 'all_ax':
                # ------------------------------------
                # Combined axis direction evaluation 
                # ------------------------------------
                # More than one or category requires that you sum the entries
                temp0_0 = list(df.subject[(df.res_type == 2) & (df.ax == i) & (np.abs(df.ss) == j)].value_counts().to_numpy())
                temp0_1 = list(df.subject[(df.res_type == 4) & (df.ax == i) & (np.abs(df.ss) == j)].value_counts().to_numpy())
                temp0_2 = list(df.subject[(df.res_type == 5) & (df.ax == i) & (np.abs(df.ss) == j)].value_counts().to_numpy())
                add1st = [x + y for x, y in zip_longest(temp0_0, temp0_1, fillvalue=0)]
                EC_vals = [x + y for x, y in zip_longest(add1st, temp0_2, fillvalue=0)]

                # More than one or category requires that you sum the entries
                temp1_0 = list(df.subject[(df.res_type == 3) & (df.ax == i) & (np.abs(df.ss) == j)].value_counts().to_numpy())
                temp1_1 = list(df.subject[(df.res_type == 6) & (df.ax == i) & (np.abs(df.ss) == j)].value_counts().to_numpy())
                temp1_2 = list(df.subject[(df.res_type == 7) & (df.ax == i) & (np.abs(df.ss) == j)].value_counts().to_numpy())
                add1st = [x + y for x, y in zip_longest(temp1_0, temp1_1, fillvalue=0)]
                NC_vals = [x + y for x, y in zip_longest(add1st, temp1_2, fillvalue=0)]

                NR_vals = df.subject[(df.res_type == 9) & (df.ax == i) & (np.abs(df.ss) == j)].value_counts().to_numpy()
                # ------------------------------------
            elif eval_axis_dir == 'pos_ax':
                # ------------------------------------
                # POSITIVE axis direction evaluation 
                # ------------------------------------
                # More than one or category requires that you sum the entries
                temp0_0 = list(df.subject[(df.res_type == 2) & (df.ax == i) & (df.ss == j)].value_counts().to_numpy())
                temp0_1 = list(df.subject[(df.res_type == 4) & (df.ax == i) & (df.ss == j)].value_counts().to_numpy())
                temp0_2 = list(df.subject[(df.res_type == 5) & (df.ax == i) & (df.ss == j)].value_counts().to_numpy())
                add1st = [x + y for x, y in zip_longest(temp0_0, temp0_1, fillvalue=0)]
                EC_vals = [x + y for x, y in zip_longest(add1st, temp0_2, fillvalue=0)]

                # More than one or category requires that you sum the entries
                temp1_0 = list(df.subject[(df.res_type == 3) & (df.ax == i) & (df.ss == j)].value_counts().to_numpy())
                temp1_1 = list(df.subject[(df.res_type == 6) & (df.ax == i) & (df.ss == j)].value_counts().to_numpy())
                temp1_2 = list(df.subject[(df.res_type == 7) & (df.ax == i) & (df.ss == j)].value_counts().to_numpy())
                add1st = [x + y for x, y in zip_longest(temp1_0, temp1_1, fillvalue=0)]
                NC_vals = [x + y for x, y in zip_longest(add1st, temp1_2, fillvalue=0)]

                NR_vals = df.subject[(df.res_type == 9) & (df.ax == i) & (df.ss == j)].value_counts().to_numpy()
                # ------------------------------------
            elif eval_axis_dir == 'neg_ax':
                # ------------------------------------
                # NEGATIVE axis direction evaluation 
                # ------------------------------------
                # More than one or category requires that you sum the entries
                temp0_0 = list(df.subject[(df.res_type == 2) & (df.ax == i) & (df.ss == -j)].value_counts().to_numpy())
                temp0_1 = list(df.subject[(df.res_type == 4) & (df.ax == i) & (df.ss == -j)].value_counts().to_numpy())
                temp0_2 = list(df.subject[(df.res_type == 5) & (df.ax == i) & (df.ss == -j)].value_counts().to_numpy())
                add1st = [x + y for x, y in zip_longest(temp0_0, temp0_1, fillvalue=0)]
                EC_vals = [x + y for x, y in zip_longest(add1st, temp0_2, fillvalue=0)]

                # More than one or category requires that you sum the entries
                temp1_0 = list(df.subject[(df.res_type == 3) & (df.ax == i) & (df.ss == -j)].value_counts().to_numpy())
                temp1_1 = list(df.subject[(df.res_type == 6) & (df.ax == i) & (df.ss == -j)].value_counts().to_numpy())
                temp1_2 = list(df.subject[(df.res_type == 7) & (df.ax == i) & (df.ss == -j)].value_counts().to_numpy())
                add1st = [x + y for x, y in zip_longest(temp1_0, temp1_1, fillvalue=0)]
                NC_vals = [x + y for x, y in zip_longest(add1st, temp1_2, fillvalue=0)]

                NR_vals = df.subject[(df.res_type == 9) & (df.ax == i) & (df.ss == -j)].value_counts().to_numpy()
                # ------------------------------------
            
            # print('IC_vals : ', IC_vals)
            # print('EC_vals : ', EC_vals)
            # print('NC_vals : ', NC_vals)
            # print('NR_vals : ', NR_vals)
            
            # Check for correctness : the sum of IC+EC+NC+NR == IC_vals+EC_vals+NC_vals+NR_vals
            sumofvals = np.sum(IC_vals) + np.sum(EC_vals) + np.sum(NC_vals) + np.sum(NR_vals)
            # print('sumofvals : ', sumofvals)

            # ----------------

            # 3) Normalize/scale the counts to values that it would be at if NO TRIALS were removed 

            # Each subject should have 42 trials : 
            # 3axis*2sub/sup*2direction (practice) +  3axis*2sub/sup*2direction (2times) + 6 sham = 12 + 24 + 6
            # 12+24=36/6 plotting categories(axis subORsup) = 6
            # so each axis subORsup should have 6 trials, not counting the 6 sham
            suspose2be_counts = num_of_sub*6 
            # print('suspose2be_counts : ', suspose2be_counts)

            multfactor = suspose2be_counts/sumofvals

            nor_IC_vals = [multfactor*i for i in IC_vals]
            nor_EC_vals = [multfactor*i for i in EC_vals]
            nor_NC_vals = [multfactor*i for i in NC_vals]
            nor_NR_vals = [multfactor*i for i in NR_vals]
            
            print('nor_IC_vals : ', nor_IC_vals)
            print('nor_EC_vals : ', nor_EC_vals)
            print('nor_NC_vals : ', nor_NC_vals)
            print('nor_NR_vals : ', nor_NR_vals)

            # ----------------

            # Make a new dataFrame with all the vals in one column and the label in the other put vals in a nested array
            all_vals = [nor_IC_vals, nor_EC_vals, nor_NC_vals, nor_NR_vals]
            longcol_num = []
            longcol_text = []
            for n1 in range(len(all_vals)):
                for n2 in range(len(all_vals[n1])):
                    longcol_num.append(all_vals[n1][n2])
                    longcol_text.append(inner_name_list[n1])

            col0 = pd.Series(np.ravel(longcol_text))
            col1 = pd.Series(np.ravel(longcol_num))
            temp = pd.concat([col0, col1], axis=1)
            df_long = temp.rename({0: 'str', 1: 'vals'}, axis=1)
            
            
            # Make an appended df_long across all conditions for statistical processing
            df_long_copy = temp.rename({0: 'str_%s_%s_%s' % (outer3_name[exp], anom[i], outer_name_list[j-1]), 1: 'vals_%s_%s_%s' % (outer3_name[exp], anom[i], outer_name_list[j-1])}, axis=1)
            df_long_tot = pd.concat([df_long_tot, df_long_copy], axis=1)
            # ----------------
            
            # Plot each subORsup per axis (for now)
            # sns.set(font_scale = 1.7, style="white", palette=None) 
            # OR
            sns.set(font_scale = 2) # default is without style and palette
            
            sns.color_palette("light:#90a4ae", as_cmap=True)  # Greys_d, light:#5A9
            
            
            if estimator_type == 'mean':
                # Plot the mean trial count
                if i == 0:
                    sns.barplot(x="str", y="vals", data=df_long, ax=ax[po,cou], ci="sd", capsize=.2, estimator=np.mean, palette="light:#90a4ae", errcolor="#3E26A8", linewidth=3, edgecolor="#3E26A8")
                elif i == 1:
                    sns.barplot(x="str", y="vals", data=df_long, ax=ax[po,cou], ci="sd", capsize=.2, estimator=np.mean, palette="light:#90a4ae", errcolor="#02BAC3", linewidth=3, edgecolor="#02BAC3")
                elif i == 2:
                    sns.barplot(x="str", y="vals", data=df_long, ax=ax[po,cou], ci="sd", capsize=.2, estimator=np.mean, palette="light:#90a4ae", errcolor="#F6EF1F", linewidth=3, edgecolor="#F6EF1F")
                ax[po,cou].set(ylim=(0, 20))
                ax[po,0].set_ylabel("\n".join(wrap('Normalized mean trial count (%s)' % (exp_name), 20)))
                plt.tight_layout()
                
                if j == 1:
                    ax[po,cou].set_xlabel('%s sub' % (anom[i]), fontsize=22)
                elif j == 2:
                    ax[po,cou].set_xlabel('%s sup' % (anom[i]), fontsize=22)
                    
            elif estimator_type == 'sum':
                # Plot the sum trial count
                if i == 0:
                    sns.barplot(x="str", y="vals", data=df_long, ax=ax[po,cou], ci="sd", capsize=.2, estimator=np.sum, palette="light:#90a4ae", errcolor="#3E26A8", linewidth=3, edgecolor="#3E26A8")
                elif i == 1:
                    sns.barplot(x="str", y="vals", data=df_long, ax=ax[po,cou], ci="sd", capsize=.2, estimator=np.sum, palette="light:#90a4ae", errcolor="#02BAC3", linewidth=3, edgecolor="#02BAC3")
                elif i == 2:
                    sns.barplot(x="str", y="vals", data=df_long, ax=ax[po,cou], ci="sd", capsize=.2, estimator=np.sum, palette="light:#90a4ae", errcolor="#F6EF1F", linewidth=3, edgecolor="#F6EF1F")
                ax[po,cou].set(ylim=(0, 110))
                ax[po,0].set_ylabel("\n".join(wrap('Normalized trial count (%s)' % (exp_name), 20)))
                ax[po,cou].set_xlabel(' ', fontsize=22)
            
            if cou > 0:
                ax[po,cou].set_ylabel(' ')
                ax[po,cou].set_yticks([])
            
            
            ax_all_vals.append(all_vals)
            
            
            # ----------------
            # Plot 95%CI
            # ----------------
            if cou == 1 or cou == 3 or cou == 5:
                ax_all_vals = np.array(ax_all_vals)
                print('length of ax_all_vals : ', ax_all_vals.shape)
                vec = make_a_properlist(np.concatenate((ax_all_vals[0], ax_all_vals[1]), axis=0))
                mean_dat, lower_tail, upper_tail = confidence_interval(vec, desired_CI=0.95)
                ax[po,cou-1].axhline(lower_tail, ls='--', linewidth=2, color='r')
                ax[po,cou].axhline(lower_tail, ls='--', linewidth=2, color='r')
                
            
                # Save which categories that are greater than the 95% lower CI for time response plotting
                
                # do not include NR: does not make sense to show response time for people who never 
                # responded (NR should all be around 15-16 seconds)
                for q in range(len(inner_name_list)-1):
                    for rr in range(2):
                        if np.sum(ax_all_vals[rr][q]) > lower_tail:
                            col4 = pd.Series(1) # number
                        else:
                            col4 = pd.Series(0) # number
                        col0 = pd.Series(outer3_name[exp])  # string
                        col1 = pd.Series(anom[i])  # string
                        col2 = pd.Series(outer_name_list[rr]) # string
                        col3 = pd.Series(inner_name_list[q])  # string
                        temp = pd.concat([col0, col1, col2, col3, col4], axis=1)
                        df_sig_cats = pd.concat([temp, df_sig_cats], axis=0)
            # ----------------
            
            cou = cou + 1
            plt.xticks(fontsize=22)
            
            
    # ----------------
    # Statistics
    # ----------------
    # Trying a different way : because across conditions need all the data
    # 1) put needed data in a DataFrame, 2) read from DataFrame and do stats at the end:
    if exp == 0:
        # Within axes : differences with axis across same condition (Visually looked for any combinations) 
        which_anom = 'RO'
        incon = 'IC'
        print(exp, which_anom, incon)
        vec0 = df_long_tot.vals_rot_RO_sub[(df_long_tot.str_rot_RO_sub == incon)].to_numpy()
        print('vec0 : ', vec0)
        vec1 = df_long_tot.vals_rot_RO_sup[(df_long_tot.str_rot_RO_sup == incon)].to_numpy()
        print('vec1 : ', vec1)

        final_temp_withincondi = compare_within_condi(df_long_tot, incon, num_of_tests, final_temp_withincondi, bonfero_thresh, inner_name_list, across_marg, outer_name_list, anom, ax, po, exp, which_anom, estimator_type)
        incon = 'EC'
        print(exp, which_anom, incon)
        final_temp_withincondi = compare_within_condi(df_long_tot, incon, num_of_tests, final_temp_withincondi, bonfero_thresh, inner_name_list, across_marg, outer_name_list, anom, ax, po, exp, which_anom, estimator_type)
        incon = 'NC'
        print(exp, which_anom, incon)
        final_temp_withincondi = compare_within_condi(df_long_tot, incon, num_of_tests, final_temp_withincondi, bonfero_thresh, inner_name_list, across_marg, outer_name_list, anom, ax, po, exp, which_anom, estimator_type)

        which_anom = 'PI'
        incon = 'IC'
        print(exp, which_anom, incon)
        final_temp_withincondi = compare_within_condi(df_long_tot, incon, num_of_tests, final_temp_withincondi, bonfero_thresh, inner_name_list, across_marg, outer_name_list, anom, ax, po, exp, which_anom, estimator_type)
        incon = 'EC'
        print(exp, which_anom, incon)
        final_temp_withincondi = compare_within_condi(df_long_tot, incon, num_of_tests, final_temp_withincondi, bonfero_thresh, inner_name_list, across_marg, outer_name_list, anom, ax, po, exp, which_anom, estimator_type)
        incon = 'NC'
        print(exp, which_anom, incon)
        final_temp_withincondi = compare_within_condi(df_long_tot, incon, num_of_tests, final_temp_withincondi, bonfero_thresh, inner_name_list, across_marg, outer_name_list, anom, ax, po, exp, which_anom, estimator_type)

        which_anom = 'YA'
        incon = 'IC'
        print(exp, which_anom, incon)
        final_temp_withincondi = compare_within_condi(df_long_tot, incon, num_of_tests, final_temp_withincondi, bonfero_thresh, inner_name_list, across_marg, outer_name_list, anom, ax, po, exp, which_anom, estimator_type)
        incon = 'EC'
        print(exp, which_anom, incon)
        final_temp_withincondi = compare_within_condi(df_long_tot, incon, num_of_tests, final_temp_withincondi, bonfero_thresh, inner_name_list, across_marg, outer_name_list, anom, ax, po, exp, which_anom, estimator_type)
        incon = 'NC'
        print(exp, which_anom, incon)
        final_temp_withincondi = compare_within_condi(df_long_tot, incon, num_of_tests, final_temp_withincondi, bonfero_thresh, inner_name_list, across_marg, outer_name_list, anom, ax, po, exp, which_anom, estimator_type)

        # ---------

        # Across axes : differences between axis but same condition (Visually looked for any combinations)
        incon = 'IC'
        ss = 'sub'
        print(exp, ss, incon)
        final_temp_acrosscondi = compare_across_condi(df_long_tot, incon, num_of_tests, final_temp_acrosscondi, bonfero_thresh, inner_name_list, across_marg, outer_name_list, anom, ax, po, ss, exp, estimator_type)

        incon = 'EC'
        ss = 'sub'
        print(exp, ss, incon)
        final_temp_acrosscondi = compare_across_condi(df_long_tot, incon, num_of_tests, final_temp_acrosscondi, bonfero_thresh, inner_name_list, across_marg, outer_name_list, anom, ax, po, ss, exp, estimator_type)

        incon = 'NC'
        ss = 'sub'
        print(exp, ss, incon)
        final_temp_acrosscondi = compare_across_condi(df_long_tot, incon, num_of_tests, final_temp_acrosscondi, bonfero_thresh, inner_name_list, across_marg, outer_name_list, anom, ax, po, ss, exp, estimator_type)

        # ---------

        incon = 'IC'
        ss = 'sup'
        print(exp, ss, incon)
        final_temp_acrosscondi = compare_across_condi(df_long_tot, incon, num_of_tests, final_temp_acrosscondi, bonfero_thresh, inner_name_list, across_marg, outer_name_list, anom, ax, po, ss, exp, estimator_type)

        incon = 'EC'
        ss = 'sup'
        print(exp, ss, incon)
        final_temp_acrosscondi = compare_across_condi(df_long_tot, incon, num_of_tests, final_temp_acrosscondi, bonfero_thresh, inner_name_list, across_marg, outer_name_list, anom, ax, po, ss, exp, estimator_type)

        incon = 'NC'
        ss = 'sup'
        print(exp, ss, incon)
        final_temp_acrosscondi = compare_across_condi(df_long_tot, incon, num_of_tests, final_temp_acrosscondi, bonfero_thresh, inner_name_list, across_marg, outer_name_list, anom, ax, po, ss, exp, estimator_type)

    elif exp == 1:
        # Within axes : differences with axis across same condition (Visually looked for any combinations) 
        which_anom = 'LR'
        incon = 'IC'
        print(exp, which_anom, incon)
        final_temp_withincondi = compare_within_condi(df_long_tot, incon, num_of_tests, final_temp_withincondi, bonfero_thresh, inner_name_list, across_marg, outer_name_list, anom, ax, po, exp, which_anom, estimator_type)
        incon = 'EC'
        print(exp, which_anom, incon)
        final_temp_withincondi = compare_within_condi(df_long_tot, incon, num_of_tests, final_temp_withincondi, bonfero_thresh, inner_name_list, across_marg, outer_name_list, anom, ax, po, exp, which_anom, estimator_type)
        incon = 'NC'
        print(exp, which_anom, incon)
        final_temp_withincondi = compare_within_condi(df_long_tot, incon, num_of_tests, final_temp_withincondi, bonfero_thresh, inner_name_list, across_marg, outer_name_list, anom, ax, po, exp, which_anom, estimator_type)

        which_anom = 'FB'
        incon = 'IC'
        print(exp, which_anom, incon)
        final_temp_withincondi = compare_within_condi(df_long_tot, incon, num_of_tests, final_temp_withincondi, bonfero_thresh, inner_name_list, across_marg, outer_name_list, anom, ax, po, exp, which_anom, estimator_type)
        incon = 'EC'
        print(exp, which_anom, incon)
        final_temp_withincondi = compare_within_condi(df_long_tot, incon, num_of_tests, final_temp_withincondi, bonfero_thresh, inner_name_list, across_marg, outer_name_list, anom, ax, po, exp, which_anom, estimator_type)
        incon = 'NC'
        print(exp, which_anom, incon)
        final_temp_withincondi = compare_within_condi(df_long_tot, incon, num_of_tests, final_temp_withincondi, bonfero_thresh, inner_name_list, across_marg, outer_name_list, anom, ax, po, exp, which_anom, estimator_type)

        which_anom = 'UD'
        incon = 'IC'
        print(exp, which_anom, incon)
        final_temp_withincondi = compare_within_condi(df_long_tot, incon, num_of_tests, final_temp_withincondi, bonfero_thresh, inner_name_list, across_marg, outer_name_list, anom, ax, po, exp, which_anom, estimator_type)
        incon = 'EC'
        print(exp, which_anom, incon)
        final_temp_withincondi = compare_within_condi(df_long_tot, incon, num_of_tests, final_temp_withincondi, bonfero_thresh, inner_name_list, across_marg, outer_name_list, anom, ax, po, exp, which_anom, estimator_type)
        incon = 'NC'
        print(exp, which_anom, incon)
        final_temp_withincondi = compare_within_condi(df_long_tot, incon, num_of_tests, final_temp_withincondi, bonfero_thresh, inner_name_list, across_marg, outer_name_list, anom, ax, po, exp, which_anom, estimator_type)

        # ---------

        # Across axes : differences between axis but same condition (Visually looked for any combinations)
        incon = 'IC'
        ss = 'sub'
        print(exp, ss, incon)
        final_temp_acrosscondi = compare_across_condi(df_long_tot, incon, num_of_tests, final_temp_acrosscondi, bonfero_thresh, inner_name_list, across_marg, outer_name_list, anom, ax, po, ss, exp, estimator_type)

        incon = 'EC'
        ss = 'sub'
        print(exp, ss, incon)
        final_temp_acrosscondi = compare_across_condi(df_long_tot, incon, num_of_tests, final_temp_acrosscondi, bonfero_thresh, inner_name_list, across_marg, outer_name_list, anom, ax, po, ss, exp, estimator_type)

        incon = 'NC'
        ss = 'sub'
        print(exp, ss, incon)
        final_temp_acrosscondi = compare_across_condi(df_long_tot, incon, num_of_tests, final_temp_acrosscondi, bonfero_thresh, inner_name_list, across_marg, outer_name_list, anom, ax, po, ss, exp, estimator_type)

        # ---------

        incon = 'IC'
        ss = 'sup'
        print(exp, ss, incon)
        final_temp_acrosscondi = compare_across_condi(df_long_tot, incon, num_of_tests, final_temp_acrosscondi, bonfero_thresh, inner_name_list, across_marg, outer_name_list, anom, ax, po, ss, exp, estimator_type)

        incon = 'EC'
        ss = 'sup'
        print(exp, ss, incon)
        final_temp_acrosscondi = compare_across_condi(df_long_tot, incon, num_of_tests, final_temp_acrosscondi, bonfero_thresh, inner_name_list, across_marg, outer_name_list, anom, ax, po, ss, exp, estimator_type)

        incon = 'NC'
        ss = 'sup'
        print(exp, ss, incon)
        final_temp_acrosscondi = compare_across_condi(df_long_tot, incon, num_of_tests, final_temp_acrosscondi, bonfero_thresh, inner_name_list, across_marg, outer_name_list, anom, ax, po, ss, exp, estimator_type)

        plt.xticks(fontsize=22)

    return cou, final_temp_withincondi, final_temp_acrosscondi, df_long_tot