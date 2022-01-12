
close all
clear all
clc

% Generate all cases

fileID = fopen('C:\Imose\BEC\Euromov\Motion_Patterns\output.txt', 'w');
fclose(fileID);

velval = [30; 40; 50; 60; 70]; %20 %10
accval = [0; 1; 2; 3; 4; 5];
pitval = [0; 5.877401063; 11.77027199; 17.83846799; 24.14043078; 30.70251641];
%occval = [1.0; 1.1; 1.2; 1.3; 1.4; 1.5; 1.6; 2.0; 2.2; 2.4; 2.6; 2.8; 3.0; 3.2];
occval = [1.0; 1.5; 2.0];

for vel = 1:length(velval)
    for acc = 1:length(accval)
        for occ = 1:length(occval)  
            fileID = fopen('C:\Imose\BEC\Euromov\Motion_Patterns\output.txt',  'a+');
            %fprintf(fileID, '%d      %f      %f      %f      %f\r\n', i, p(1,1), p(1,2), p(1,3), p(1,4));
            fprintf(fileID, '%d %d %f %f\r\n', velval(vel,1), accval(acc,1), pitval(acc,1), occval(occ,1));
            fclose(fileID);
        end
    end
    
end%



