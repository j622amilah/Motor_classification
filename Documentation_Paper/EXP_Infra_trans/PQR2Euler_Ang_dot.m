function  Euler_Ang_dot = PQR2Euler_Ang_dot( Omega, Euler_Ang )
%--------------------------------------------------------------------------
%   translates PQR to Eulre angle rates
%   
%   Omega:              P, Q, R Rad/sec) in colums of 3
%   Euler_Ang:          phi, theta, psi (not used) in rad
%   Euler_Ang_dot:      phi_dot, theta_dot, psi_dot, in rad/sec
%
%   Arthur J. Grunwald, Nov. 12 2014
%--------------------------------------------------------------------------
%#eml
phi     = Euler_Ang(1);
theta   = Euler_Ang(2);

tan_tet = tan(theta);
cos_tet = cos(theta);
cos_phi = cos(phi);
sin_phi = sin(phi);

Aux_Mat = [	1.,     tan_tet*sin_phi,	tan_tet*cos_phi;	
	   		0,		cos_phi,			-sin_phi;
			0.,     sin_phi/cos_tet,	cos_phi/cos_tet];
        
Euler_Ang_dot = Aux_Mat*Omega;

end

