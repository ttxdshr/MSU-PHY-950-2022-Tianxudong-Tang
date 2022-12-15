#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
#include<limits>

void hw6_q1()
{
    double confidence_level = 0.95;
    double gamma = 1 - confidence_level;
    double N = 1e6;
    double delta = 12;
    double p = 1;
    int a = 30;     //expected upper limit
    float inf = numeric_limits<float>::infinity();    //define infinity

    TF1 *f = new TF1("f","gaus",0,50);
    f->SetParameter(0, 1);

   while(p>0.05)
    {
        double mean_total = 20+delta;
        double sigma_nominal = 4;
        double sigma_delta = 0.25*delta;
        double sigma_total = pow(sigma_nominal,2) + pow(sigma_delta,2);
        sigma_total = sqrt(sigma_total);

        f->SetParameter(1, mean_total);
        f->SetParameter(2, sigma_total);

        p = f->Integral(-1.0*inf, a);
        p = p / f->Integral(-1.0*inf, inf);
        
        //cout<<"Lower prob is: "<< p <<endl;
            
        delta += 0.01;
    }
    
    // TCanvas* c1 = new TCanvas("c1","c1");
    // f->Draw();
        
    cout<<"The delta is: "<< delta <<endl;    
}