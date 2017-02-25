//
//  option.cpp
//  final project
//
//  Created by Junyao Zhao on 06/30/16.
//  Copyright 2016 Junyao Zhao. All rights reserved.
//
#include <cmath>
#include "option.hpp"
#include "function.hpp"

calloption::calloption()
{
    T=0, K=0;
}

calloption::calloption(double t, double k)
{
    T=t;
    K=k;
}

putoption::putoption(double t, double k) 
{
    T=t;
    K=k;
}

putoption::putoption()
{
    T=0;
    K=0;
}

void option::getk(double strike){
    K=strike;
}

void option::gett(double t){
    T=t;
}

double calloption::price(double S,        // price of stock or underlying security
                         double r,        // interest rate
                         double q,        // dividend yield
                         double sig      // volatility
)const
{
    double d1, d2;
    
    d1 = (log(S/K) + (r-q +(sig*sig)*0.5 ) * T )
    / (sig * sqrt(T));
    d2 = d1 - sig*sqrt(T);
    
    return S*exp(-q*T)*N(d1) - K*exp(-r*T)*N(d2) ;

}


double putoption::price(
               double S,        // price of stock or underlying security
               double r,        // interest rate
               double q,        // dividend yield
               double sig      // volatility
)const

{
    double d1, d2;
    
    d1 = (log(S/K) + (r-q +(sig*sig)*0.5 ) * T )
    / (sig * sqrt(T));
    d2 = d1 - sig*sqrt(T);
    
    return K*exp(-r*T)*N(-d2) - S*exp(-q*T)*N(-d1) ;
    
}

double calloption::impliedVolatity(double S,double optPrice,double r, calloption op){
    double testPrice;
    double q=0;
    
    double sig = 0.;
    double stepSize = 0.1;
    int iterFlag = 1;  // used to decide when to stop iteration
    double stepSign = 1.; // used to control direction and size of steps
    int i;
    
    for(i = 1; i < 300 && iterFlag < 40; i++)
    {
        sig += stepSize;

        testPrice =op.price( S, r, q, sig);

    if((testPrice *stepSign) > (optPrice * stepSign))
    {
        // cout << endl;
        stepSign = -stepSign;
        stepSize = -(stepSize * 0.1);
        iterFlag++;
    }
    }
    
if ((i==30) | (iterFlag==4)) {
    cout << "i=" << i << endl
    << "iterFlag=" << iterFlag << endl;
    }
    return sig;
}

double putoption::impliedVolatity(double S, double optPrice, double r, putoption op){
    double testPrice;
    double q=0;
    
    double sig = 0.;
    double stepSize = 0.1;
    int iterFlag = 1;  // used to decide when to stop iteration
    double stepSign = 1.; // used to control direction and size of steps
    int i;
    
    for(i = 1; i < 300 && iterFlag < 40; i++)
    {
        sig += stepSize;
        
        testPrice =op.price( S, r, q, sig);
    
    if((testPrice *stepSign) > (optPrice * stepSign))
    {
        // cout << endl;
        stepSign = -stepSign;
        stepSize = -(stepSize * 0.1);
        iterFlag++;
    }
    }
    
    if ((i==30) | (iterFlag==4)) {
        cout << "i=" << i << endl
        << "iterFlag=" << iterFlag << endl;
    }
    return sig;
}


