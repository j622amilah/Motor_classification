function y = rot_be(x)

% Euler rotation, for transforming: x_e = E(b->e) x_b

% inputs:	x(1:3) = x_b		vector in body system 
%				x(4:6) = angles	phi,teta,psi

% output:	y(1:3) = x_e		vector in earth system

	for i = 1:3
      xb(i,1) 		= x(i);
      angles(i)  	= x(i+3);
   end
   
   x_e =  eul_eb(angles)'* xb; % NOTE!!! we take the transpose of eul_eb
   
   y = x_e;
