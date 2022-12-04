#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

void func1()
{
    cout << "Hello World." << endl;
}

double func2()
{
    TRandom3 r(1122);
    
    TF1* f1 = new TF1("f1","gaus",0,32);   //xmin; xmax
    // set initial parameters of gaussian distribution
    f1->SetParameters(1, 16, 4); 
    // p1: constant for gaus 
    // p2: approximate mean value of the gaussian
    // p3: approximate sigma of the gaussian
    TH1F *h1 = new TH1F("h1","(b)Histogram from a Gaussian",100,0,32); //#of bin; xmin; xmax
    h1->FillRandom("f1",10000);
    h1->Fit("f1");

    TCanvas* c1 = new TCanvas("c","c1");
    h1->Draw();

    double mean = f1->GetParameter("Mean");

    return mean;
}

void func3(double a)
{
    double variable = a * 1e6;
    int mod = fmod(variable,10);
    TF1 *f2 = new TF1("f2","x+[0]*x*x",0,100);
    f2->SetParameter(0,mod);
    f2->SetParName(0,"mod");
    TCanvas* c2 = new TCanvas("c2","canvas 2");
    f2->Draw();
}

int hw2_q3()
{
    cout << "Let's do the Homework2! " << endl;
    func1();    //question(a)

    double mean = func2();    //question(b)
    cout << "The mean value of the Gaussian distribution: " << mean << endl;

    func3(mean);    //question(c)
    return 0;
}    