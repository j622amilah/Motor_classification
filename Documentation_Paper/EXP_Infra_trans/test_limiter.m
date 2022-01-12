clear all

x_max = 50;
x_min = 20;
margin_max = 5;
margin_min = 5;

vec = [];

for x = -50: 0.1: 100
    y = final_soft_limit( x, x_max, x_min, margin_max, margin_min);
    vec = [vec; x, y];
end

plot(vec(:,1), vec(:,2))