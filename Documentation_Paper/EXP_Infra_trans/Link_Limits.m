function OutOfLimits = Link_Limits( J_ANG )
% tests whether the links are within the set soft limits

% soft limits on the links (NED convention)

%#eml

SL = [   175    130     88    200    61    200
        -175    -20    -88   -200   -61   -200];

OutOfLimits = zeros(6);


for i = 1 : 6
    if J_ANG(i) >= SL(1,i)
        OutOfLimits(i) = i;
    end
    if J_ANG(i) <= SL(2,i)
        OutOfLimits(i) = -i;
    end   
end
          
end
