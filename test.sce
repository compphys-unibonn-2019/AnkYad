d=rand(1,10000,'normal');  // the gaussian random sample
scf(1);histplot(20,d)
scf(2);histplot(20,d,normalization=%f)
scf(3);histplot(20,d,leg='rand(1,10000,''normal'')',style=5)
scf(4);histplot(20,d,leg='rand(1,10000,''normal'')',style=16, rect=[-3,0,3,0.5]);
