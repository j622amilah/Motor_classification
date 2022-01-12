function y = alpha_beta(V_b)

% input vector  x = [U_a, V_a, W_a]
% output vector y = [alpha, beta, Vel_a]

U_a	= V_b(1);
V_a	= V_b(2);
W_a	= V_b(3);

Vel_a	= sqrt(U_a*U_a + V_a*V_a + W_a*W_a);
alpha	= atan(W_a/U_a);
beta	= asin(V_a/Vel_a);

y(1) = alpha;
y(2) = beta;
y(3) = Vel_a; % magnitude of vector V_b w.r.t. the air

