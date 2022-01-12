function out = ForKinSim( vec )
%--------------------------------------------------------------------------
%
%   This function solves the FORWARD kinematics of the 6-DOF KUKA arm and
%   wrist. This is the  version,
%   embedded in Simulink. The input and output are vectors that include the
%   list of parameters as defined herafter
%
%       *** Input variables, vec(1:13) ***
%
%   vec(1: 3)    POS         Room coordinates of flange, NED in cm
%   vec(4: 6)    EUL_ANG     Euler angles of the flange, phi, theta, psi, in deg
%   vec(1:6)     J_ANG_0     The joint angles, in deg
%
%       *** Output Variables ***
%
%   out(1: 3)    POS         Room coordinates of flange, NED in cm
%   out(4: 6)    EUL_ANG     Euler angles of the flange, phi, theta, psi, in deg
%
%   The North_East_Down convention is used and psi, theta, phi rotation
%   sequence; A2, A3, A5 are up positive and A4, A6 right rotation positive
%   Note that this is different from the KUKA convention
%
%   Written by Arthur J. Grunwald, Nov. 23, 2014
%
%--------------------------------------------------------------------------

DTR = pi/180.;
RTD = 180/pi;

% reload variables
% the algorithm works in rad, so ang is in rad
J_ANG       = vec(1:6);   % Initial guess of the joint angles, in deg
ang         = J_ANG*DTR;

% reserve place for output
out = zeros(6,1);

% define length of arms
l1          = 50.;   % arm length in cm
l2          = 130.;
l3          = 66.;
l4          = 36.5;
l5          = 29.;
d           = 5.5;             % vertical offset of the center line of
% joint 4 from centerline of arm A3
Height_A2   = 104.5 + 105;     % height link A2 above the ground


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

x_cabin = [0; 0; 0];    % x,y,z cabin reference point (cm)
% to which the translation is made
x6 = [x_cabin; 1];
p = D1*D2*D3*D4*D5*D6*x6;
pos = p(1:3);        % position of the cabin reference point in the
% NED system (cm)

% computed Euler angles from links A1-A6
% Euler matrices for rotation from e->b (note the transpose)
E = E6'*E5'*E4'*E3'*E2'*E1';
eul_ang = DCM2Eul( E );

% place into output vector
out(1:3,1) = pos-[0;0;Height_A2];
out(4:6,1) = RTD*eul_ang;

end

