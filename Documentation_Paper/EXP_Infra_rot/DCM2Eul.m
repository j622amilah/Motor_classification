function ang = DCM2Eul( D )
% DCM to Euler angles
%#eml
ang = [ atan2(D(2,3), D(3,3));
        -asin(D(1,3));
        atan2(D(1,2), D(1,1))];
end

