#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

void hw2_q6()
{
    TH1F *h1 = new TH1F("h1","(6)Histogram",100,0,1);
    TF1 *f1 = new TF1("f1","sin([0]*x)",0,1);
    f1->SetParameter(0, M_PI);
    TRandom3 r(1122);
    double x;
    double fx;
    for(int i=0;i<1e5;i++){
        x = r.Uniform();
        fx = f1->Eval(x);
        //cout<<x<<" and "<<fx<<endl;
        h1->Fill(fx);
    }
    double A = 1.0/h1->Integral();
    cout<<"Constant A is: "<< A << endl;
    h1->Scale(A);
    double Integral = h1->Integral();
    cout<<"The Integral of the function is: "<< Integral << endl;   
    //h1->Fit("f1");
    TCanvas* c1 = new TCanvas("c1","c1");
    h1->Draw();
}

