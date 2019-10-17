void RW()
{
 int N=1000, range, iter=100;
 int x[N*iter], y[N*iter], ch;
 double S[iter], R[iter], avg=0;
 //TCanvas *c1 = new TCanvas("c1","Graph Draw Options",200,10,800,800);
//________________________________________________________________________________
//
//First Loop for diferent number of steps
//
 for (int k=0; k<=90; k++) 
 {
  int range=5;
  N=1000+iter*(k);
  x[0]=0;
  y[0]=0;
  TGraph *step = new TGraph();
  TGraph *step2 = new TGraph();
  auto rand = new TRandom(0);
  //c1->SetGrid();
  avg=0;
//________________________________________________________________________________
//
// Loop for averaging out distance for a given step length
//
 for (int j=0; j<100; j++)
 {
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
	//cout << "------------" << endl;
	//cout << "x  " << x[i+1] << " y  " << y[i+1] << endl;
  }
//_________________________________________________________________________________
//
// Storing Distance values
//

  S[k]=N;
  //cout << "********************" << endl;
  //cout << "x  " << x[N-1] << " y  " << y[N-1] << endl;
  avg=avg+TMath::Sqrt(((x[N-1]-x[0])*(x[N-1]-x[0]))+((y[N-1]-y[0])*(y[N-1]-y[0])));
 } 
  R[k]=avg/100;
  cout << "steps  " << S[k] << "  Range  " << R[k] << endl ;

//_________________________________________________________________________________
//
// Plotting fancy step plot
//
  for (int i=0; i<N; i++)
  {
	step->SetPoint(i,x[i],y[i]);
	step->SetMarkerStyle(1);
	//step->Draw("same AL");
	if ((abs(x[i])>range) || (abs(y[i])>range)) range+=5;
	step->GetXaxis()->SetLimits(-range,range);
	step->GetYaxis()->SetRangeUser(-range,range);
	step2->SetPoint(0,x[i],y[i]);
	//step2->Draw("same *");
	//step->Draw("same L");
	//c1->Update();
	//sleep(1);
  }
 }
 TCanvas *c2 = new TCanvas("c2","Distribution",200,10,800,800);
 TH1F* hdist = new TH1F("hdist", "End to end Distribution", 91, 950,10050 );
 //TGraph* hdist = new TGraph();
 TF1* hN = new TF1("hN","sqrt(x)",1000,10000);
 for (int k=0; k<=90; k++)
 {
  hdist->Fill(S[k],R[k]);
  //hdist->SetPoint(k,S[k],R[k]);
  //hdist->Draw("same A*");
 }
 c2->SetGrid();
 hdist->Draw("HIST");
 hN->Draw("same");
 return 0;
}
