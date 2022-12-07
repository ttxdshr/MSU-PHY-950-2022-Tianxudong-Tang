#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
#include<limits>

void hw4_q2()
{
    TF1 *fe = new TF1("fe","gaus",-6,6);
    fe->SetParameter(0, 1);
    fe->SetParameter(1, 0);
    fe->SetParameter(2, 1);
    TF1 *fpi = new TF1("fpi","gaus",-6,6);
    fpi->SetParameter(0, 1);
    fpi->SetParameter(1, 2);
    fpi->SetParameter(2, 1);
    float inf = numeric_limits<float>::infinity();


    for(double x=1;x>-3;x-=0.01)
    {
        double epsilo_e = fe->Integral(-1.0*inf, x);
        double epsilo_pi = fpi->Integral(-1.0*inf,x);
        double purity = epsilo_e * 0.01/(epsilo_e * 0.01 + epsilo_pi * 0.99);
        if(purity >= 0.95)
        {
            cout<<"The purity right now is: "<< purity << endl;
            cout<<"The decision boundary is T < "<< x << endl;
            break;
        }
    }
}
