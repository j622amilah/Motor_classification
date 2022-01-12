close all
clear all
clc

%UNTITLED4 Summary of this function goes here
%   Detailed explanation goes here

%f = fopen ('MT_0370027B_001-000.csv', 'r');
MT_0370027B_0010x2D000 = importdata('MT_0370027B_001-000.csv');

%récupérer la taille n de la matrice data_from_IMU et créér M à 4 colonne et n lignes
n=length(MT_0370027B_0010x2D000)-5;
%n=1055;

Mshort = zeros(n,4);
    string = MT_0370027B_0010x2D000{6,1};
    N=strread(string,'%s','delimiter','\t');

    roll0=str2double(N{3});

    pitch0=str2double(N{4});
    
    yaw0=str2double(N{5});
    
for i=1:n
   
    string=MT_0370027B_0010x2D000{i+5,1};
    N=strread(string,'%s','delimiter','\t');
    %Mshort(i,1)=(i-1)*0.01;
    dat.roll(i,1)=str2double(N{3})-roll0;
    dat.pitch(i,1)=str2double(N{4})-pitch0;
    dat.yaw(i,1)=str2double(N{5})-yaw0;
end

% test - Scale input values
chossen_max = 2;  
max_val = max(abs([dat.roll(:,1); dat.pitch(i,1); dat.yaw(i,1)]));
scal_val = max_val/chossen_max;  % change to 1 if no scale

Mshort(:,2) = dat.roll(:,1)./scal_val;
Mshort(:,3) = dat.pitch(:,1)./scal_val;
Mshort(:,4) = dat.yaw(:,1)./scal_val;

% Accelerations
Mshort(:,5) = zeros(n,1);
Mshort(:,6) = zeros(n,1);
Mshort(:,7) = zeros(n,1);

clear dat

% Make data a bit longer 
xtimes_longer = 5;  %change to 1 if you want to read the data without change
dat.r = [];
dat.p = [];
dat.y = [];
dat.ax = [];
dat.ay = [];
dat.az = [];
for i = 1:xtimes_longer
    dat.r = [dat.r; Mshort(:,2)];
    dat.p = [dat.p; Mshort(:,3)];
    dat.y = [dat.y; Mshort(:,4)];
    dat.ax = [dat.ax; Mshort(:,5)];
    dat.ay = [dat.ay; Mshort(:,6)];
    dat.az = [dat.az; Mshort(:,7)];
end
dat.time = linspace(0, 0.01*xtimes_longer*n, xtimes_longer*n)';

M = [dat.time, dat.r, dat.p, dat.y, dat.ax, dat.ay, dat.az];

max_acc = max([abs(dat.ax); abs(dat.ay); abs(dat.az)])

lenM1 = length(M)

clear i dat MT_0370027B_0010x2D000 string N chossen_max n scal_val xtimes_longer Mshort roll0 pitch0 yaw0 max_acc max_val

figure
t = M(:,1);
grid on
hold on
plot(t, M(:,2),'m')
plot(t, M(:,4),'g')
plot(t, M(:,3))
legend ('roll', 'yaw', 'pitch')
xlabel('temps (s)')
ylabel('Orientations en rad')

clear t

% --------- output M matrix to textfile in order to read line by line with collect_data.m ---------

% Create text file containing the M matrix, called dathere.txt in C:\Imose\BEC\Euromov\Motion_Patterns
fid = fopen('dathere.txt', 'w');
for i = 1:length(M)
    fprintf(fid, '%f     %f     %f     %f     %f     %f     %f\n', M(i,1), M(i,2), M(i,3), M(i,4), M(i,5), M(i,6), M(i,7));
end
fclose(fid);

clear all
