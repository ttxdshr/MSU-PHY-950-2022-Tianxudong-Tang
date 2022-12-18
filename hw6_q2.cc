#include <TMath.h>
#include <TRandom.h>
#include <iostream>
#include <fstream>
#include <cmath>

double average(double *x, double len)
{
    double sum = 0.0;
    for(int i = 0; i<len; i++)
        sum += x[i];
    return sum/len;
}

double variance(double *x, double len)
{
    double sum = 0;
    double avg = average(x, len);
    for(int i = 0; i<len; i++)
        sum += pow(x[i]-avg, 2);
    return sum/len;
}

void hw6_q2()
{
    double a = 0.5;
    double alpha = 0;
    while(abs(alpha-0.1585)>1e-3)
    {
        alpha = 0;
        a -= 0.001;    
        for(int i = 4; i < 19; i++){
            alpha += ROOT::Math::binomial_pdf(i,a,18);       //generate binomial distribution pdf        
        }
    }
    cout<<"a = "<< a <<endl;
    cout<<"alpha = "<<alpha<<endl;

    double b = 0.5;
    double beta = 0;
    while(abs(beta-0.1585)>1e-3)
    {
        b -= 0.001;  
        beta = 0;
        for(int i = 0; i < 5; i++){
            beta += ROOT::Math::binomial_pdf(i,b,18);       //generate binomial distribution pdf        
        }
    }
    cout<<"b = "<< b <<endl;
    cout<<"beta = "<<beta<<endl;

    double x[20];
    for(int j = 0; j < 19; j++)
    {
        x[j] = ROOT::Math::binomial_pdf(j,0.222,18);
    }
    double v = variance(x,19);
    v = sqrt(v);
    cout<<"variance = "<<v<<endl;
}

