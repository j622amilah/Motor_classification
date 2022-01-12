%%read and plot data from a txt file
fileID='subject1.txt';
formatSpec='%f';

FILE=fopen(fileID,'r');
temp=fscanf(FILE,formatSpec)';
fclose('all');
rc=length(temp);
clear temp
r=rc/8;

FILE=fopen(fileID,'r');
result.alltogether=fscanf(FILE,formatSpec,[8,r])';

[vals indices]=unique(result.alltogether(:,1));

result.sprintf('trial%i',vals(1,1))=result.alltogether(1:indices(1),:);

for i=2:length(vals)
    result.sprintf('trial%i',vals(i,1))=result.alltogether(indices(i-1):indices(i),:);

end


clear rc r vals indices

