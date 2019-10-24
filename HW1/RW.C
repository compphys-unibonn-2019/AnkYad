//Shows the random walk for number of steps 10,20,30 ... 

void RW()
{
 int steps=10, range=5;
 int x[100], y[100], ch;
 auto rand = new TRandom(0);
 TCanvas *c1 = new TCanvas("c1","Graph Draw Options",200,10,800,800);
 c1->SetGrid();
 for (int j=0; j<steps; j++)
 {

  TGraph *step = new TGraph();
  TGraph *step2 = new TGraph();
  x[0]=0;
  y[0]=0;
  N=10+j*10;
  for(int i=0; i<N-1; i++)	
  {
	ch=rand->Integer(4);
	//cout << ch << endl;
	x[i+1]=x[i];
	y[i+1]=y[i];
	if(ch==0)      x[i+1]=x[i]+1;
	else if(ch==1) x[i+1]=x[i]-1;
	else if(ch==2) y[i+1]=y[i]+1;
	else 	       y[i+1]=y[i]-1;
  }
  for (int i=0; i<N; i++)
  {
	step->SetPoint(i,x[i],y[i]);
	step->SetMarkerStyle(1);
	step->Draw("same AL");
	if ((abs(x[i])>range) || (abs(y[i])>range)) range+=5;
	step->GetXaxis()->SetLimits(-range,range);
	step->GetYaxis()->SetRangeUser(-range,range);
	step2->SetPoint(0,x[i],y[i]);
	step2->Draw("same *");
	step->Draw("same L");
	c1->Update();
	sleep(1);
  }
 for (int i=0; i<100; i++)
 	{x[i]=y[i]=0;}
  delete step;
  delete step2;
 }
 return 0;
}
