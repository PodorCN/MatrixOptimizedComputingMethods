//
//  main.cpp
//  MOCM
//
//  Created by MuYao Si on 2021-07-20.
//

#include <iostream>
#include "LogFactorial.h"
#include <ctime>
#include <vector>
#include <cmath>
//#include <Rcpp.h>

using namespace std;
//using namespace Rcpp;

// [[Rcpp::export]]
double sum(vector<double> vec)
{
    double vecLen = vec.size();
    double TEMP = 0;
    for(int i = 0; i < vecLen; i = i + 1)
    {
        TEMP = TEMP + vec[i];
    }
    return TEMP;
}

// [[Rcpp::export]]
int main() {
    const vector<double> data = {1,2,1,4,1.2,1.7,0.4,3.9};
    const int w = 5000;
    const int k = 3;
    const double lambda1 = 10.0;
    const double lambda2 = 9.0;
    const double dataSize =  data.size();
    vector<double> MGi(dataSize, 0);
    vector<double> MGj(5000, 0);
    for(int i = 0; i < dataSize; i = i + 1)
    {
        for(int j = k; j < w; j = j + 2)
        {
            MGj[j] = exp(log(k) + ((j+k)/2)*log(lambda1) + ((j-k)/2)*log(lambda2) - LogFactorial((j+k)/2) - LogFactorial((j-k)/2) + (j - 1) * log(data[i]) - (lambda1 + lambda2) * data[i]);
        }
        MGi[i] = log(sum(MGj));
        vector<double> MGj(5000,0);
    }
    cout << sum(MGi) << endl;
    return 0;
}
