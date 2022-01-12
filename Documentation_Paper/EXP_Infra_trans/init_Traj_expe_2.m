clear N B trials_results
N=zeros(200,8);
B=Rand_trials;
%Acc_x_mat=zeros(100,1);
%Z_mat=zeros(100,1);
%theta_mat=zeros(100,1);



%create a new txt file for current subject which will contain all the trials data
i=1;
n=1;
while(i~=-1)
    
    i=fopen(sprintf('subject%i.txt',n));
    n=n+1;
    if(i~=-1)
        fclose('all');
    end
end
n=n-1;
fopen(sprintf('subject%i.txt',n),'w');

fclose('all');