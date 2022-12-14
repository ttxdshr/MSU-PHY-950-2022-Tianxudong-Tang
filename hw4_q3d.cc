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
  for(int i=1; i<=h1->GetNbinsX(); i++){
    double model = h1->GetBinContent(i);
    if(model == 0) model += 1e-20; ///protect against zeros
    chi2 += pow(model-data->GetBinContent(i),2)/model; 
  }
  return chi2;
}


void hw4_q3d(){
  gStyle->SetOptStat(0);

  TFile* fin = new TFile("hw4_chi2.root","READ");

  TH1D* h1 = (TH1D*)fin->Get("Hypothesis 1");
  TH1D* h2 = (TH1D*)fin->Get("Hypothesis 2");
  TH1D* data = (TH1D*)fin->Get("Data");

//  Combine 4 bins into 1
  int rebinF = 4;
  data->Rebin(rebinF);
  h1->Rebin(rebinF);
  h2->Rebin(rebinF);

  h1->Scale(data->Integral());
  h2->Scale(data->Integral());

  int N1 = 23;
  int N2 = 22;
  Double_t p1 = TMath::Prob(getChi2(h1,data), N1);
  Double_t p2 = TMath::Prob(getChi2(h2,data), N2);
  
  cout<<"p1 is: "<<p1<<endl;
  cout<<"p2 is: "<<p2<<endl;  


  return;
}