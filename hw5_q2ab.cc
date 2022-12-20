#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
#include<limits>
#include "Math/MultiRootFinder.h"

void hw5_q2()
{
double z[4] = {0.0,6e-6,12e-6,18e-6};
int n[4] = {1880,940,530,305};
double pi = 3.1415926;
double A = 4*pi*pow(0.52e-4,3) *(0.063e-3)*9.8/(3*293);
cout<<"A = "<<A<<endl;

ROOT::Math::MultiRootFinder* r = new ROOT::Math::MultiRootFinder();

// auto f1 = [z,n,A](const double * x)
//     {return z[0]+z[1]+z[2]+z[3]-x[0]*(exp(A*z[0]/x[1]) + exp(A*z[1]/x[1]) + exp(A*z[2]/x[1]) + exp(A*z[3]/x[1]));};
// auto f2 = [z,n,A](const double * x)
//     {return z[0]+z[1]+z[2]+z[3]-x[0]*(z[0]*exp(A*z[0]/x[1]) + z[1]*exp(A*z[1]/x[1]) + z[2]*exp(A*z[2]/x[1]) + z[3]*exp(A*z[3]/x[1]));};

   TF2 *f1 = new TF2("f1","[0] - x[0]*(exp([1]/x[1]) + exp([2]/x[1]) + exp([3]/x[1]) + exp([4]/x[1]))");
   TF2 *f2 = new TF2("f2","[0] - x[0]*([1]*exp([2]/x[1]) + [3]*exp([4]/x[1]) + [5]*exp([6]/x[1]) + [7]*exp([8]/x[1]))");

   f1->SetParameters(n[0]+n[1]+n[2]+n[3], -A*z[0], -A*z[1], -A*z[2], -A*z[3]);
   f2->SetParameters(n[0]*z[0]+n[1]*z[1]+n[2]*z[2]+n[3]*z[3], z[0],-A*z[0], z[1],-A*z[1], z[2],-A*z[2], z[3],-A*z[3]);

   ROOT::Math::WrappedMultiTF1 g1(*f1,2);
   ROOT::Math::WrappedMultiTF1 g2(*f2,2);

   r->AddFunction(g1);
   r->AddFunction(g2);
   int printlevel = 1;
   r->SetPrintLevel(printlevel);

   // starting point
   double x0[2]={1880, 1.38e-23};
   r->Solve(x0);

   double NA = 8.32e7/x0[1];

   std::cout << "v = " << x0[0] << std::endl;
   std::cout << "k = " << x0[1] << std::endl;
   std::cout << "NA = " << NA << std::endl;
}