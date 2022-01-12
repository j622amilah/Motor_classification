function [J_ANG, N] = InitialGuess( POS )
% for computing an initial guess for the inverse kinematics algorithm
% The initial guess uses only links A1, A2, A3 and assumes that the
% cabin at the end is straight and level and aligned with the arm
% Thus A4 and A6 are zero and A5 is A2 + A3
% We use the NED convention
% This algorithm has a closed form solution and is based on the cosine rule
% However, due to the offset of the centerline of link A4 55 mm below the
% center of rotation of link A3, some small corrections have to be made;
% this is done iteratively. The gist of this routine is to shozw that
% identical results are obtained with the fully-fledged 6-DOF inverse
% algorithm.
%
%   Written by Arthur Grunwald, November 11, 2014
%   Added correction because of offset of link A4, Dec 2, 2014

RTD = 180/pi;
DTR = pi/180;

% soft limits on the links (NED convention)
SL = [   175    130     88    200    61    200
        -175    -20    -88   -200   -61   -200];

% define length of the links

l1          = 50.;   % arm length in cm
l2          = 130.; 
l3          = 66.;
l4          = 36.5;
l5          = 29.;
offset      = 5.5;             % vertical offset of the center line of
                               % joint 4 from centerline of arm A3
                               % joint 4 from centerline of arm A3
Height_A2   = 104.5 + 106;     % height link A2 above the ground

x = POS(1);
y = POS(2);
z = POS(3);

N = 1;
A3_old = -90;

% This iterative loop serves to correct for the offset of link A4
% A first good guess is to assume that A3 is initially 90 deg

while(1)
    % compute dimensions of triangle
    l = sqrt(x*x + y*y);
    e = l - l1 - l5;
    h = -(Height_A2 + z);
    
    % The corrections to the length of the triangle because of the offset
    % of link 4
    b_corr = offset/cos((90+A3_old)*DTR);
    c_corr = offset*tan((90+A3_old)*DTR);
    
    b = l2 - b_corr;
    c = l3 + l4 + c_corr;
    d = sqrt(e^2 + h^2);
    
    % employ cosine rule on angles alpha and beta of triangle
    cos_alpha = (b*b + d*d - c*c)/(2*b*d);
    cos_beta  = (b*b + c*c - d*d)/(2*b*c);
    
    alpha = RTD*acos(cos_alpha);
    beta  = RTD*acos(cos_beta);
    delta = RTD*atan2(h, e);
    
    % the link angles
    A1 = RTD*atan2(y, x);
    A2 = alpha + delta;
    A3 = beta - 180;
    A4 = 0;
    A5 = -(A2 + A3);
    A6 = 0;
    
    d_A3 = A3 - A3_old;
    if norm(d_A3) < 1.e-5
        break
    end
    N = N + 1;
    A3_old = A3;
    if N > 10
        fprintf(1,'No Convergence in initialization algorithm...\n');
        break;
    end
end
 
J_ANG = [A1 A2 A3 A4 A5 A6]';

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

fprintf('In initial guess All links within limits...\n\n')

end

