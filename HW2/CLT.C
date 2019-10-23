//Central Limit theorem

//Average
double Avg (double Ar[], int size)
{ 
  double sum = 0;       
  double avg;          
  for (int i = 0; i < size; ++i) 
  {
      sum += Ar[i];
   }
   avg = sum / size;

   return avg;
}


//Variance
double Var (double Ar[], double avg, int size)
{ 
  double sum = 0;       
  double var;          
  for (int i = 0; i < size; ++i) 
  {
      sum += ((Ar[i]-avg)*(Ar[i]-avg));
   }
   var = sum / size;

   return var;
}


//Zn
double Zn(int n)
{
  auto rand = new TRandom(0);
  double temp=0, Z;
  for (int i=0; i<n; i++)
  {
	temp = temp + rand->Rndm();
  }
  Z = (temp - (double(n)/2) ) * (TMath::Sqrt(12)/TMath::Sqrt(double(n)));
  return Z;
}


//Zero
void Zero(double Z[], int size)
{
  for (int i=0; i<size; i++)
	Z[i]=0;
}

//Main fun
void CLT()
{
  double Z[10000]={0}, mean, var;
  int N=10000,n;
  TCanvas *c1 = new TCanvas("c1","Central Limit Theorem",200,10,800,600);
  TGraph* Gr1 = new TGraph();
  TGraph* Gr2 = new TGraph();
  auto mg = new TMultiGraph();
  for (int j=0; j<25; j++)
  {
	n=j+1;
  	for (int i=0; i<N; i++)
  	{
		Z[i]=Zn(n);
  	}
  	mean = Avg(Z, N);
  	var = Var(Z, mean, N);
	Zero(Z,N);
  	//cout << "AVG " << mean << endl;
  	//cout << "Var " << var << endl;
	Gr1->SetPoint(j,n,mean);
	Gr2->SetPoint(j,n,var);
  }
  Gr1->SetMarkerStyle(3);
  Gr1->SetTitle("Mean values");
  Gr2->SetTitle("Variance");
  c1->SetGrid();
  mg->Add(Gr1);
  Gr2->SetMarkerColor(2);
  Gr2->SetMarkerStyle(21);
  mg->Add(Gr2);
  mg->Draw("AP");
  c1->BuildLegend();
  return 0;
}
