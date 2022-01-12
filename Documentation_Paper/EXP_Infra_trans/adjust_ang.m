function ang = adjust_ang( ang )
%#eml
for i = 1 : 6
    a = ang(i);
    while a >  pi a = a - 2*pi; end
    while a < -pi a = a + 2*pi; end
    ang(i) = a;
end

