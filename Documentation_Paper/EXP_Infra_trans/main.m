
%%

% d24m04y18: plotting stimulation and command to iMose from the equations, this actually already exists in the data
% - Esscentually recreating gradual stim (column 19), and commanded (columns 3,4,5)
close all
clear all
clc

main_path = 'C:\Imose\BEC\Euromov\Motion_Patterns\EXPERIMENTS\EXP_Infra_trans\';
cd(main_path); 

Allaxis = {'xaxis','yaxis','zaxis'};

for a = 1:3
    for c = 1:2
        whichaxis = Allaxis{a};
        
        whichgain_type = c; % 1: gain=1, 2: gain=exp change   % first do 1, then change to 2

        filesave_dir = [main_path, whichaxis];
        mkdir(filesave_dir);
        cd(filesave_dir);

        tar_ang_speed = [-75, -300, -350, 75, 300, 350]; % Target angular speed

        for i = 1:length(tar_ang_speed)

            % ----------------------------------
            % Modeling the stimulation creation:
            % ----------------------------------
            % Stim_xyz is created using a 2nd order transfer function/filter
            T = 4;
            num = 1;
            den = [1 (3.6*pi)/T pi/(T*0.9)];
            sysout_stim = tf(num, den);

            tfinal = 15;  % roughly 15 seconds per trial
            t = 0:0.004:tfinal;   % time from 0 to 20 seconds


            u =  (tar_ang_speed(i)*0.05).*ones(length(t), 1); % stim_rpy(cm/s) 

            orange = [255 156 55]./255;

            [Stim_xyz, tout, x] = lsim(sysout_stim, u, t);  % filtered stim_rpy (cm/s)

            % Purpose of gain: to decrease the stim_xyz to zero when the cabin is at a certain boundary
            % Multiply the filtered stim_rpy by a gain, this gain changes if the cabin is past a maximum location

            if whichgain_type == 1
                gain = 1;
            else

                % Simulating Simulinks' real-time functionality:
                switch whichaxis
                    case 'xaxis'
                        x_max = 75;
                        margin_max = 25;
                        x_min = 75;
                        margin_min = 25;

                    case 'yaxis'
                        x_max = 120;
                        margin_max = 25;
                        x_min = 120;
                        margin_min = 25;

                    case 'zaxis'
                        x_max = 70;
                        margin_max = 10;
                        x_min = 70;
                        margin_min = 10;
                end

                % same for x and y -axis
                load(sprintf('smooth_final_out_lim_NOsubinput_target_ang_speed_%d_gainEQ1', tar_ang_speed(i))) 
                for b = 1:length(smooth_final_out_lim)
                    x = smooth_final_out_lim(b);

                    if x < x_max - margin_max && x >= 0
                        gain(b,1) = 1; %#ok<SAGROW>
                    elseif x > -x_min + margin_min && x < 0
                        gain(b,1) = 1;
                    elseif x >= x_max - margin_max
                        x1 = (x - x_max + margin_max);
                        gain(b,1) = exp(-abs(x1)/margin_max);
                    else
                        x1 = (x + x_min - margin_min);
                        gain(b,1) = exp(-abs(x1)/margin_max);
                    end
                end

            end


            figure
            subplot(5,1,1)
            plot(t, u, 'b', 'LineWidth', 2)
            hold on
            plot(tout, Stim_xyz.*gain, 'Color', orange, 'LineWidth', 2)
            title(sprintf('Stimulation: tar ang speed %i*0.05 (blue), filtered (orange)', tar_ang_speed(i)))

            %

            % ----------------------------------
            % Modeling the command to iMose:
            % ----------------------------------
            % During trial (trigger=0), send Stim_xyz plus the input of the subject (joystick is limited from -1 to 1, then multiplied
            % by 30.  Meaning that subject can only put in an input at max of 30 cm/s)

            % Making up a fake subject response
            k = 20;
            %subject = 0.5*(-sin((2*pi/k)*t))';  % subject does a sin, subject does half of max input
            subject = zeros(length(t), 1);   % subject does nothing

            subplot(5,1,2)
            plot(t, subject, 'LineWidth', 2)
            title('Fake subject input (Subject does nothing): w/o gain')

            % ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

            input = Stim_xyz + 30*subject;

            subplot(5,1,3)
            plot(t, input, 'r', 'LineWidth', 2)
            title('Subject*30 + Stim xyz input')

            % ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

            T = 0.2;
            num = 1;
            den = [1 (3.2*pi)/T pi/(T*0.8)];
            sysout_commanded = tf(num, den);

            [y2, tout2, x2] = lsim(sysout_commanded, input, t);

            subplot(5,1,4)
            plot(tout2, y2, 'g', 'LineWidth', 2)

            % What the integrator does (sums the values)
            yout(1) = 0;
            for q = 2:length(tout2)
                yout(q,1) = yout(q-1,1) + y2(q);
            end

            hold on
            plot(tout2, yout, 'b', 'LineWidth', 2)
            title('Commanded output: before (green) and after (blue) integrator')




            % Modeling everything as a transfer function: can't do if 
            % Contribution of the Smooth Displacement filter: 
            % Jeremie probably added it so that the robot would not stop 
            T = 0.1;
            num = 1;
            den = [1 (3.2*pi)/T pi/(T*0.8)];
            sysout_smooth = tf(num, den);

            stepin = ones(length(t), 1); % input is a step function (0=zeroing/reset to 1=during trial)

            [y3, tout3, x3] = lsim(sysout_smooth, stepin, t);  % not modeling gives increasing output

            % There is an intial condition for both integrators: the lsim function only
            % takes one intial condition.  Could either break the system into two parts
            % or use one of the intial conditions, perhaps the one relavant for the second order dynamics
            x00 = [0; y3(1:length(y3-1))];  % output delayed by one time step (for intial condition between xdot and x)

            for h = 2:length(x00)
                x0(h-1,1) = ((x00(h)-x00(h-1))/0.004).*((T*0.8)/pi);  % difference in the output delayed by one time step * ((T*0.8)/pi) (for intial condition between xdoubledot and xdot)  
            end

            % figure
            % plot(x00, 'b')
            % hold on
            % plot(x0, 'g')

            [y4, tout4, x4] = lsim(sysout_smooth, stepin, t, x00);

            % Multiply command final out by a smooth curve (from 0 to 1 to 0)
            smooth_final_out = y4.*yout;

            subplot(5,1,5)
            plot(tout2, smooth_final_out, 'b', 'LineWidth', 2)



            % Stay within ellipse: limit x and y to stay in same space
            switch whichaxis
                case 'xaxis'
                    y_in = zeros(length(smooth_final_out), 1);  % Assuming there is no y movement (both stim and joystick)
                    x_in = smooth_final_out;

                    X_size = 70;   % cm
                    Y_size = 120;  % cm

                    y = y_in*(X_size/Y_size);

                    R = sqrt((x_in.*x_in) + (y.*y));

                    if R >= 1
                        R_out = R/X_size;
                    else
                        R_out = 1;
                    end

                    x_out = x_in/R_out;
                    y_out = y_in/R_out;

                    smooth_final_out_lim = x_out;

                case 'yaxis'
                    y_in = smooth_final_out;
                    x_in = zeros(length(smooth_final_out), 1);

                    X_size = 70;   % cm
                    Y_size = 120;  % cm

                    y = y_in*(X_size/Y_size);

                    R = sqrt((x_in.*x_in) + (y.*y));

                    if R >= 1
                        R_out = R/X_size;
                    else
                        R_out = 1;
                    end

                    x_out = x_in/R_out;
                    y_out = y_in/R_out;

                    smooth_final_out_lim = y_out;

                case 'zaxis'
                    smooth_final_out_lim = smooth_final_out;
            end






            % Boundary check: to see if the movement does not exceed a certain value.

            switch whichaxis
                case 'xaxis'
                    % ----------------------------
                    % Boundary check for x-axis:
                    % ----------------------------
                    x_max = 75;  % x-axis
                    margin_max = 25;  % x-axis
                    x_min = 75;  % x-axis
                    margin_min = 25;  % x-axis

                    for b = 1:length(smooth_final_out_lim)
                        x = smooth_final_out_lim(b,1);

                        if x < x_max - margin_max && x >= 0
                            y = x;
                            %gain = 1;
                        elseif x > -x_min + margin_min && x < 0
                            y = x;
                            %gain = 1;
                        elseif x >= x_max - margin_max
                            x1 = (x - x_max + margin_max);
                            y = x_max*(1 -  margin_max/x_max*exp(-abs(x1)/margin_max));
                            %gain = exp(-abs(x1)/margin_max);
                        else
                            x1 = (x + x_min - margin_min);
                            y = -x_min*(1 -  margin_min/x_min*exp(-abs(x1)/margin_min));
                            %gain = exp(-abs(x1)/margin_max);
                        end

                        smooth_final_out_lim_bou(b,1) = y; %#ok<SAGROW>
                    end

                case 'yaxis'
                    % ----------------------------
                    % Boundary check for y-axis:
                    % ----------------------------
                    x_max = 120;
                    margin_max = 25;
                    x_min = 120;
                    margin_min = 25;

                    for b = 1:length(smooth_final_out_lim)
                        x = smooth_final_out_lim(b,1);

                        if x < x_max - margin_max && x >= 0
                            y = x;
                            %gain = 1;
                        elseif x > -x_min + margin_min && x < 0
                            y = x;
                            %gain = 1;
                        elseif x >= x_max - margin_max
                            x1 = (x - x_max + margin_max);
                            y = x_max*(1 -  margin_max/x_max*exp(-abs(x1)/margin_max));
                            %gain = exp(-abs(x1)/margin_max);
                        else
                            x1 = (x + x_min - margin_min);
                            y = -x_min*(1 -  margin_min/x_min*exp(-abs(x1)/margin_min));
                            %gain = exp(-abs(x1)/margin_max);
                        end

                        smooth_final_out_lim_bou(b,1) = y; %#ok<SAGROW>
                    end

                case 'zaxis'
                    % ----------------------------
                    % Boundary check for y-axis:
                    % ----------------------------
                    x_max = 70;
                    margin_max = 10;
                    x_min = 70;
                    margin_min = 10;

                    for b = 1:length(smooth_final_out_lim)
                        x = smooth_final_out_lim(b,1);

                        if x < x_max - margin_max && x >= 0
                            y = x;
                            %gain = 1;
                        elseif x > -x_min + margin_min && x < 0
                            y = x;
                            %gain = 1;
                        elseif x >= x_max - margin_max
                            x1 = (x - x_max + margin_max);
                            y = x_max*(1 -  margin_max/x_max*exp(-abs(x1)/margin_max));
                            %gain = exp(-abs(x1)/margin_max);
                        else
                            x1 = (x + x_min - margin_min);
                            y = -x_min*(1 -  margin_min/x_min*exp(-abs(x1)/margin_min));
                            %gain = exp(-abs(x1)/margin_max);
                        end

                        smooth_final_out_lim_bou(b,1) = y; %#ok<SAGROW>
                    end
            end



            hold on
            plot(tout2, smooth_final_out_lim_bou, 'r', 'LineWidth', 2)
            ylabel('cm')
            xlabel('time (sec)')
            title(sprintf('Commanded %s output: before (blue) and after (red) boundary limitation', whichaxis))


            set(gcf, 'units', 'normalized', 'outerposition', [0 0 1 1]);
            set(gcf, 'PaperPositionMode', 'auto');


            if whichgain_type == 1
                %Simulating Simulinks' real-time functionality: Need to save the output
                %(smooth_final_out_lim) when gain=1 so that we can change the gain in the beginning
                save(sprintf('smooth_final_out_lim_NOsubinput_target_ang_speed_%d_gainEQ1',tar_ang_speed(i)), 'smooth_final_out_lim')
                print(gcf, '-dpng', sprintf('NOsubinput_target_ang_speed_%d_gainEQ1',tar_ang_speed(i)))
            else
                print(gcf, '-dpng', sprintf('NOsubinput_target_ang_speed_%d_gainEQval',tar_ang_speed(i)))
            end


        end  % end of target angular speed
        
    end   % end of gain
    
end  % end of whichaxis


%%

% transform to discrete 
%sysdis = c2d(sysout, 0.004);