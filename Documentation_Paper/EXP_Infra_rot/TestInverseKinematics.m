%--------------------------------------------------------------------------
%               Test Inverse Kinematics 
%--------------------------------------------------------------------------

clear all

global J_ANG_0

RTD = 180/pi;
DTR = pi/180;

% enter 3-D position in room coordinates, NED

x_e = input('enter x-coordinate (cm): ');
y_e = input('enter y-coordinate (cm): ');
z_e = input('enter z_coordinate (cm); ');
POS = [x_e y_e z_e]';

phi   = input('enter roll angle (deg): ');
theta = input('enter pitch angle (deg): ');
psi   = input('enter yaw angle (deg): ');
EUL_ANG = [phi theta psi]';

% inverse kinematics algorithm
J_ANG_0 = InitialGuess( POS );

vec = [];
for alpha = 0 : 1 : 1
    
    POS(2) = 140*sin(DTR*alpha);
    if ~isempty(J_ANG_0)
        [J_ANG_0, N]  = InverseKinematics( POS, EUL_ANG, J_ANG_0, 2);
    else
        fprintf('Sorry! no solution for out of reach or out of limits...\n')
    end
    vec = [vec; alpha, POS', EUL_ANG', J_ANG_0(1), -J_ANG_0(2:6)']
    pause
end

figure(1)

SL = [   175       20      88    200    61    200
         -175     -130    -88   -200   -61   -200];
col = [ 1 0 1 0 1 0
        0 1 1 0 0 1
        0 0 0 1 1 1]';
        
for i = 1 : 6
    plot(vec(:,1), vec(:,i+7), 'LineWidth',3,'Color',col(i,:));
    hold on
    plot([vec(1,1),vec(end,1)], [SL(1,i),SL(1,i)],'LineWidth',2,'Color',col(i,:));
    plot([vec(1,1),vec(end,1)], [SL(2,i),SL(2,i)],'LineWidth',2,'Color',col(i,:));
    pause
end
    
    

