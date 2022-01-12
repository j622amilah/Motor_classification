function ang = Rot2Ang( Rot )
% Conversion of a rotation vector in x-y-z coordinates to Euler angles

alpha = norm(Rot);
x = Rot(1)/alpha;
y = Rot(2)/alpha;
z = Rot(3)/alpha;


q = zeros(4);
cs = cos(0.5*alpha);
sn = sin(0.5*alpha);

q(1) = cs;
q(2) = sn*x;
q(3) = sn*y;
q(4) = sn*z;

ang = Quat2Ang( q )';

end

