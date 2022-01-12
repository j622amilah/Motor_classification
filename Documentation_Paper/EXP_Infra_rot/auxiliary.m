% S-file for auxiliary (Euler) equations

function [sys, x_0] = auxiliary(t,x,u,flag,ang_0)

% input vector  u = [p,q,r]
% state vector  x = [phi, teta, psi]
% output vector y = C * x; C is identity

%	FLAG	SYS	DESCRIPTION
%  	----	---	-----------
%	1	DX	state derivatives, dX/dT.
%	2	DS	discrete states, X(n+1).
%	3	Y	system outputs .
%	4	TNEXT	next time interval for update  (only discrete systems).
%	5	R	return the values of its root-functions.
%
%	For efficiency two other options have been added which tell the system 
%	that X, DS, T and U  are unchanged from the last call:


%		SIZES(1) number of continuous states
%		SIZES(2) number of discrete states. 
%		SIZES(3) number of outputs 
%		SIZES(4) number of inputs 
%		SIZES(5) number of roots that the system has. 
%		SIZES(6) set to 1 if the system has direct feed-through of 
%			 its inputs (used for systems within systems).

if abs(flag) == 1

   % compute non-linear functions
		
	phi	= x(1);
	teta	= x(2);
	psi	= x(3);

	aux_mat = [	1.,	tan(teta)*sin(phi),	tan(teta)*cos(phi);	
	   			0,		cos(phi),				-sin(phi);
					0.,	sin(phi)/cos(teta),	cos(phi)/cos(teta)];
	
	sys = aux_mat * u;	% Derivatives

elseif abs(flag) == 3

	sys =  x; 		% Outputs y = x

elseif abs(flag) == 0

	sys=[3,0,3,3,0,0]; 	x_0 = ang_0;

elseif abs(flag) == 9

	sys = [];		% Real time update (ignored).
end

