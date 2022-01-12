function y = final_soft_limit( x, x_max, x_min, margin_max, margin_min)

%--------------------------------------------------------------------------
%
%   argin_max and margin_min are the margins in which the exponetial
%   saturation takes place
%
%   x_max, x_min and margin_max and margin_min allow to compute the
%   factor between 0 and 1 of x_max and x_min of the linear range
%
%   Please note that x_max and x_min, margin_max and margin_min, are
%   all positive values; where the max is for the positive values of x and 
%   the min for the negative values
%
%--------------------------------------------------------------------------
   
    if x < x_max - margin_max && x >= 0
        y = x;
    elseif x > -x_min + margin_min && x < 0
        y = x;
    elseif x >= x_max - margin_max
        x1 = (x - x_max + margin_max);
        y = x_max*(1 -  margin_max/x_max*exp(-abs(x1)/margin_max));
    else
        x1 = (x + x_min - margin_min);
        y = -x_min*(1 -  margin_min/x_min*exp(-abs(x1)/margin_min));
end

