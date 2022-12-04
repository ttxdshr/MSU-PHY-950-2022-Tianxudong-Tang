#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

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

void hw2_q4()
{
    TRandom3 r(1122);
    double a = 100*r.Uniform();
    double b = 100*r.Uniform();
    double len = 100;
    double x[100];
    double x2[100];
    for(int i = 0; i < len; i++){
        x[i] = 10*r.Uniform();
        x2[i] = a * x[i] + b;
    }
    
    double mean = average(x, len);
    double v = variance(x, len);
    cout << "a*mean+b = " << a*mean+b << "; " 
    << "a^2*variance = " << a*a*v << endl;

    double MEAN = average(x2, len);
    double V = variance(x2, len);
    cout << "MEAN = " << MEAN << "; " 
    << "VARIANCE = " << V << endl;

    if(abs(MEAN - (a*mean + b)) < 1e-6)
        cout<<"The E[x] relationship is proved to be true." << "\n" << endl;
    else 
        cout<<"The E[x] relationship is proved to be false." << "\n" << endl;
    if(abs(V - (a*a*v)) < 1e-6)
        cout<<"The V[x] relationship is proved to be true." << "\n" << endl;
    else 
        cout<<"The V[x] relationship is proved to be false." << "\n" << endl;
    
}
