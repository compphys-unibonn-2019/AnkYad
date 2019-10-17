clear
clc
Gsize=10
n=10
R=zeros(2,n)
for k=1:n
N=10*k
x=[0,0]
y=[0,0]
xmax=zeros(1,N)
ymax=zeros(1,N)
xgrid(2,1,7)
for i=1:N

    plot2d(x(:),y(:))
    xmax(i)=x(1)
    ymax(i)=y(1)
    plot(x(1),y(1),"ro-")
    sleep(1000)
    a=gca()
    a.children(1).children.line_mode="on"
    a.children(1).children.mark_mode="off"
    a.grid_style = [7,7]
    a.data_bounds=[-Gsize,-Gsize;Gsize,Gsize]
    xgrid(2)
    x(2)=x(1)
    y(2)=y(1)
    ch=grand(1,1,"uin",1,4)
    //disp(ch)
    select ch
    case 1 then 
        x(1)=x(1)+1
    case 2 then 
        x(1)=x(1)-1
    case 3 then 
        y(1)=y(1)+1
    case 4 then 
        y(1)=y(1)-1
    end
    if ((abs(x(1)) > Gsize) || (abs(y(1)) > Gsize)) then
        Gsize=Gsize +5
    end
end
//plot(r,LJ,"k-")
title("Random Walk")
scf(k+1)
R(1,k)=N
R(2,k)=sqrt(((xmax(N)-xmax(1))**2)+((ymax(N)-ymax(1)**2)))
disp(R(2,k),"*******************R******************")
end
//scf(2)
plot(R(1,:),R(2,:),"-o")
xgrid
title("No of Steps vs XRange")
