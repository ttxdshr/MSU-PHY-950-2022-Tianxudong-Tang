#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

void h1_style(TH1D* h1, const char* title){
  
  h1->GetXaxis()->SetTitle("X");
  h1->GetYaxis()->SetTitle("N(X)");
  h1->GetXaxis()->SetTitleSize(0.05);
  h1->GetYaxis()->SetTitleSize(0.05);

  h1->GetXaxis()->SetLabelSize(0.04);
  h1->GetYaxis()->SetLabelSize(0.04);
  h1->SetTitle(title);

  h1->SetMaximum(1.25*h1->GetMaximum());

}

double getChi2(TH1D* h1, TH1D* data)
{
  double chi2 = 0;
  cout << "The number of bin when getChi2: " << h1->GetNbinsX() << endl;
  for(int i=1; i<=h1->GetNbinsX(); i++){
    double model = h1->GetBinContent(i);
    if(model == 0) model += 1e-20; ///protect against zeros
    chi2 += pow(model-data->GetBinContent(i),2)/model; 
  }
  return chi2;
}

void hw4_q3b(){

  double x[20] = {0},y[20] = {0};
  int n = 20;
  int i = 0;
  for(int rebinF = n; rebinF>=1; rebinF--)
  {
    if(100%rebinF==0)
    {
        gStyle->SetOptStat(0);
        TFile* fin = new TFile("hw4_chi2.root","READ"); 
        TH1D* h1 = (TH1D*)fin->Get("Hypothesis 1");
        TH1D* data = (TH1D*)fin->Get("Data");
        
        h1->Scale(data->Integral());

        cout << "rebinF: " << rebinF << endl;
        
        data->Rebin(rebinF);
        h1->Rebin(rebinF);

        x[i] = 100/rebinF;
        y[i] = getChi2(h1,data);
        cout << "The number of bin: " << 100/rebinF << endl;
        cout << "Chi2 by hand: " << getChi2(h1,data) << endl;
        i+=1;
    }
  } 
        cout << "i: " << i << endl;
  auto g = new TGraph(i,x,y);
  g->SetTitle("The choice of histogram binning; Histogram bin number; Kai-square value");
  g->Draw("AC*");

  return;
}

