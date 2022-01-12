function infralim_random_values2

% PURPOSE: This code creates the randomized trial matrix for both
% rotational and translational experiment, called Rand_trials.  Evaluates
% the values to be used for the infraliminary experiment (i.e. perception of infraliminary motion with iMose).


%The user has to define the main ranges of :
%angular speed
%rot_axis (n rows and 3 columns)
%number of trial per condition (2 in order to limit the time of a single
%experiment

% ----------------- To CHANGE -----------------
subname = 'random';%'17102017-GL-123'; %'20172008-AS-007';%'20170308-MK-160'; % '20170406-AD-777';
dir_to_save = 'C:\Imose\BEC\Euromov\Motion_Patterns\EXP_Infra_trans';

ang_speed = [-300 -75 75 300];       % Rotational [-25 -10 10 25]
rot_axis= eye(3);
trial_number_per_cond=2;    
ang_speed_fam= [-350 -300 300 350];         % Rotational [-30 -25 25 30]
% ----------------------------------

%Trials=length(ang_speed)*length(rot_axis)*3;

Trial_matrix= [];  %initialization of this matrix to empty
fam_matrix=[];

for i = 1:length(ang_speed)
    for k = 1: trial_number_per_cond
            for j = 1:length(rot_axis)-1
                [a, b]=unique(rot_axis(j,:));
                Trial_matrix=[Trial_matrix;[ang_speed(i)*rot_axis(j,:) b(2) 0]];
            end
    end
 end


n=length(Trial_matrix);


 random_values= randperm(n);
 Rand_trials=[];
 
 for i=1:n
     Rand_trials=[Rand_trials; Trial_matrix(random_values(i),:)];
 end
 
 %for zero cases and yaw cases
 Trial_matrix_yz=[];
 for i = 1:length(ang_speed)
     for k = 1: trial_number_per_cond
         %[a, b]=unique(rot_axis(j,:));
         Trial_matrix_yz=[Trial_matrix_yz;[ang_speed(i)*rot_axis(3,:) 3 0]];
     end
 end
 
 
 for k = 1: trial_number_per_cond
     for j = 1:length(rot_axis)
         [a, b]=unique(rot_axis(j,:));
         Trial_matrix_yz=[Trial_matrix_yz;[0*rot_axis(j,:) b(2) 0]];
     end
 end
 
 n1=length(Trial_matrix_yz);

 
 random_values= randperm(n1);
 Rand_trials_yz=[];
 
 for i=1:n1
     Rand_trials_yz=[Rand_trials_yz; Trial_matrix_yz(random_values(i),:)];
 end

 Random_trials_all=[];
%assembly of Rand_trials and Rand_trials_yz
index= (length(Rand_trials_yz)+length(Rand_trials))/2-1;
for i=1:index
    Random_trials_all=[Random_trials_all; [Rand_trials(i,:); Rand_trials_yz(i,:)]];
end
Random_trials_all=[Random_trials_all; Rand_trials(index+1:length(Rand_trials),:)];


%familiarization trials =======================
for i = 1:length(ang_speed_fam)
    for j = 1:length(rot_axis)
        [a b]=unique(rot_axis(j,:));
        fam_matrix=[fam_matrix;[ang_speed_fam(i)*rot_axis(j,:) b(2) 1]];
    end
end

random_values= randperm(length(fam_matrix));
rand_fam_matrix=[];

for i=1:length(fam_matrix)
    rand_fam_matrix=[rand_fam_matrix; fam_matrix(random_values(i),:)];
end
%==============================================

Rand_trials=[rand_fam_matrix;Random_trials_all];
%each trial is executed twice. We divide the experiment in 2 blocks: one familiarization phase (12trials)
%1 block of 30 trials. A pause should occur at trial numbers 13.


clear i j k n

save(sprintf('%s.mat', subname), 'Rand_trials')
