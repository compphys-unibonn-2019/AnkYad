title("Central Limit Theorem")
xlabel("number of points n")
ylabel("Mean/Variance")
for i=1:25
    n=i
    for j=1:10000
        temp=0
        for k=1:n
            temp=temp+rand()
        end
        z(j)=((temp-(n/2))*(sqrt(12)/sqrt(n)))
    end
    avg=sum(z)/10000;
    var=sum((z-avg).*(z-avg))/10000
    plot(n,avg,"ko",n,var,"ks")
end
legend("Mean","Variance")
xgrid(2,1,7)
