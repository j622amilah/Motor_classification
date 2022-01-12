close all
clear all
clc


% C1: Initial speed	
% C2: visual acc
% C3: pitch angle
% C4: closer time

main_path = 'C:\Imose\BEC\Euromov\Motion_Patterns';
data_path = 'C:\Imose\BEC\Euromov\Motion_Patterns\output.txt';

cd(main_path);

A = importdata(data_path);
y = randperm(length(A));
for i = 1:length(A)
    B(i,:) = A(y(i),:);
end

save('B.mat', 'B')
    