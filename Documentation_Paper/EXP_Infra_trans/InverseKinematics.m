function [J_ANG, N]  = InverseKinematics( POS, EUL_ANG, J_ANG_0, print_flg)
%--------------------------------------------------------------------------
%
%   This function solves the inverse kinematics of the 6-DOF KUKA arm and
%   wrist by means of an iterative algorithm.
%
%       *** Input variables ***
%
%   POS         Room coordinates of flange, NED in cm
%   EUL_ANG     Euler angles of the flange, phi, theta, psi, in deg
%   J_ANG_0     Initial guess of the joint angles, in deg
%   print_flg   if set to 1 prints iterations for debugging purposes
%               if set to 2 prints the position and Euler angles after
%               if set to 3 prints the forward solution (first entry)
%               convergence of the algorithm
%
%       *** Output Variables ***
%
%   J_ANG       The six joint angles after convergence
%   N           Number of iterations, set to -1 for no convergence
%               -2 set for out of reach of arm links
%
%   The North_East_Down convention is used and psi, theta, phi rotation
%   sequence; A2, A3, A5 are up positive and A4, A6 right rotation positive
%   Note that this is different from the KUKA convention
%
%   Written by Arthur J. Grunwald, Nov. 14, 2014
%
%--------------------------------------------------------------------------
%#eml

DTR = pi/180.;
RTD = 180/pi;

% define length of arms

l1          = 50.;   % arm length in cm
l2          = 130.; 
l3          = 66.;
l4          = 36.5;
l5          = 29.;
d           = 5.5;             % vertical offset of the center line of
                               % joint 4 from centerline of arm A3
Height_A2   = 104.5 + 106;     % height link A2 above the ground

% soft limits on the links (NED convention)
SL = [   175    130     88    200    61    200
        -175    -20    -88   -200   -61   -200];


% offset the height so that level zero is now at the height of the A2 joint
POS(3) = POS(3) + Height_A2;

% set initial guess; the algorithm works in rad, so ang is in rad
N = 0;
ang = J_ANG_0*DTR;

% check for maximum range of arm links and exit with n = 2 when exceeded
L = l2 + l3 + l4 + l5;
R = sqrt(L^2 - POS(3)^2) + l1;
R1 = sqrt(POS(1)^2 + POS(2)^2);
if R1 > R-5;
   J_ANG = J_ANG_0;
    N = -2;
    fprintf(1,'Maximum range of arm links reached...\n');
    return
end


% --------------------------------
% 	start of iterative loop
% --------------------------------

while(1)
    
    % 4x4 Transfer matrices, include both rotation and translation
    
    ang = adjust_ang( ang ); % ang is brought in the range +-pi
    A1 = ang(1);
    A2 = ang(2);
    A3 = ang(3);
    A4 = ang(4);
    A5 = ang(5);
    A6 = ang(6);
    
    CA1 = cos(A1);
    SA1 = sin(A1);
    CA2 = cos(A2);
    SA2 = sin(A2);
    CA3 = cos(A3);
    SA3 = sin(A3);
    CA4 = cos(A4);
    SA4 = sin(A4);
    CA5 = cos(A5);
    SA5 = sin(A5);
    CA6 = cos(A6);
    SA6 = sin(A6);
    
    D1 = [CA1 -SA1 0 0; SA1 CA1 0 0; 0 0 1 0;  0 0 0 1];
    D2 = [CA2 0 SA2 l1; 0 1 0 0; -SA2 0 CA2 0; 0 0 0 1];
    D3 = [CA3 0 SA3 l2; 0 1 0 0; -SA3 0 CA3 0; 0 0 0 1];
    D4 = [1 0 0 l3; 0 CA4 -SA4 0; 0 SA4 CA4 d; 0 0 0 1];
    D5 = [CA5 0 SA5 l4; 0 1 0 0; -SA5 0 CA5 0; 0 0 0 1];
    D6 = [1 0 0 l5; 0 CA6 -SA6 0; 0 SA6 CA6 0; 0 0 0 1];
    
    % cut out the 3x3 DCM's for each of the transfer matrices
    % Note that the DCM is for rotation from b->e
    E1 = D1(1:3,1:3);
    E2 = D2(1:3,1:3);
    E3 = D3(1:3,1:3);
    E4 = D4(1:3,1:3);
    E5 = D5(1:3,1:3);
    E6 = D6(1:3,1:3);
    
    % --- computed position from links A1-A6 ---
    
    x_cabin = [0; 0; 0];     % x,y,z cabin reference point (cm)
                            % to which the translation is made
    x6 = [x_cabin; 1];
    p = D1*D2*D3*D4*D5*D6*x6;
    pos = p(1:3);           % position of the cabin reference point in the
                            % NED system (cm)
    
    % computed Euler angles from links A1-A6
    % Euler matrices for rotation from e->b (note the transpose)
    E = E6'*E5'*E4'*E3'*E2'*E1';
    eul_ang = DCM2Eul( E );
    
    if N == 0 && print_flg == 3
       fprintf('Forward solution for POS, EUL_ANG for first entry...\n');
       fprintf(1, '%10.1f %10.1f %10.1f %10.1f %10.1f %10.1f\n', ...
           pos-[0;0;Height_A2], RTD*eul_ang);
    end

        % determine the vectors of rotation of the endplate in e-system
        % for each one of the links; this is a 3x6 matrix, when multiplied
        % with the vector of the joint angles, it will give the vector
        % of rotation of the endplate (and also of the cabin reference point)
        % in the NED system
        
        e6 = E1*E2*E3*E4*E5*[1 0 0]'; % x-axis
        e5 = E1*E2*E3*E4*   [0 1 0]'; % y-axis
        e4 = E1*E2*E3*      [1 0 0]'; % x-axis
        e3 = E1*E2*         [0 1 0]'; % y-axis
        e2 = E1*            [0 1 0]'; % y-axis
        e1 = eye(3)*        [0 0 1]'; % z-axis
        
        e = [e1 e2 e3 e4 e5 e6];
        
        % in order to see the changes in phi, theta, psi that this rotation
        % vector causes, we have to transform e->b first in yaw and after that
        % in pitch
        cs_psi = cos(eul_ang(3));
        sn_psi = sin(eul_ang(3));
        cs_tet = cos(eul_ang(2));
        sn_tet = sin(eul_ang(2));
        
        PSI = [cs_psi sn_psi 0; -sn_psi cs_psi 0; 0 0 1];
        TET = [cs_tet 0 -sn_tet; 0 1 0; sn_tet 0 cs_tet];
        e = TET*PSI*e;
        
    
    % the derivatives of D1-D6 for eah one of the link angles
    dD1 = [-SA1 -CA1 0 0; CA1 -SA1 0 0; 0 0 0 0; 0 0 0 0];
    dD2 = [-SA2 0 CA2 0; 0 0 0 0; -CA2 0 -SA2 0; 0 0 0 0];
    dD3 = [-SA3 0 CA3 0; 0 0 0 0; -CA3 0 -SA3 0; 0 0 0 0];
    dD4 = [0 0 0 0; 0 -SA4 -CA4 0; 0 CA4 -SA4 0; 0 0 0 0];
    dD5 = [-SA5 0 CA5 0; 0 0 0 0; -CA5 0 -SA5 0; 0 0 0 0];
    dD6 = [0 0 0 0; 0 -SA6 -CA6 0; 0 CA6 -SA6 0; 0 0 0 0];
    
    % Hessian Matrix H; the inverse of this matrix determines the link
    % angle speed as a function of the speed of x,y,z and the speed of the
    % Euler angles
    
    h1 = dD1*D2*D3*D4*D5*D6*x6;
    h2 = D1*dD2*D3*D4*D5*D6*x6;
    h3 = D1*D2*dD3*D4*D5*D6*x6;
    h4 = D1*D2*D3*dD4*D5*D6*x6;
    h5 = D1*D2*D3*D4*dD5*D6*x6;
    h6 = D1*D2*D3*D4*D5*dD6*x6;
    
    h = [h1 h2 h3 h4 h5 h6]; % this 3x6 is th upper half of H
    H = [h(1:3,:); e];       % the lower 3x6 half is the matrix e
    
    d_ang = inv(H) * [( POS - pos ); (DTR*EUL_ANG - eul_ang)];
    ang = ang + d_ang;
    ang = adjust_ang( ang );
    if(norm(d_ang) < 1.e-7)
       J_ANG = RTD*ang;
      break; 
    end
    if print_flg == 1
        fprintf(1, '%2d %10.1e %10.1f %10.1f %10.1f %10.1f %10.1f %10.1f\n', N, norm(d_ang), RTD*ang);
    end
    N = N + 1;
    if N > 100
        N = -1;
        break;
    end
    J_ANG = RTD*adjust_ang( ang );
  
end

if N == -1    
    fprintf('No Convergence in inverse algorithm...\n');
else
    if print_flg == 2
        pos(3) = pos(3) - Height_A2;
        fprintf(1, '            N     A1       A2       A3       A4       A5       A6\n');
        fprintf(1, 'N, J_ANG:  %2d%8.2f %8.2f %8.2f %8.2f %8.2f %8.2f\n', N, RTD*ang);
        fprintf(1, 'POS, EUL_ANG:%8.1f %8.1f %8.1f %8.2f %8.2f %8.2f\n', pos, RTD*eul_ang);       
    end
end

% tests whether the links are within the set soft limits
for i = 1 : 6
    if J_ANG(i) >= SL(1,i)
        fprintf('Link %1d out of upper limit: ', i);
        J_ANG = [];
        return;
    elseif J_ANG(i) <= SL(2,i)
        fprintf('Link %1d out of lower limit: ', i);
        J_ANG = [];
        return;
    end
end

end




