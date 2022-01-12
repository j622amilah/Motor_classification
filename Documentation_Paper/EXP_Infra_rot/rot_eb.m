function y = rot_eb(x)

% Euler rotation, for transforming: x_b = E(e->b) x_e

% inputs:	x(1:3) = x_e		vector in earth system 
%				x(4:6) = angles	phi,teta,psi

% output:	y(1:3) = x_b		vector in body system

	for i = 1:3
      xe(i,1) 		= x(i);
      angles(i)  	= x(i+3);
   end
   
   x_b =  eul_eb(angles) * xe;
   
   y = x_b;
   