//
//  option.hpp
//  final project
//
//  Created by Junyao Zhao on 06/30/16.
//  Copyright 2016 Junyao Zhao. All rights reserved.
//

#ifndef option_h
#define option_h

class option{
public:
    
    option(){}
    
    virtual void getk(double strike);
    virtual void gett(double t);
    virtual~option(){}
    double K;
    double T;

private:
    
};


class calloption : public option
{
public:
    calloption();
    calloption(double t, double k);
    virtual double price(double S,        // price of stock or underlying security
                         double r,        // interest rate
                         double q,        // dividend yield
                         double sig      // volatility
    )const;

    virtual double impliedVolatity(double S,double optPrice, double r, calloption op);
    
    virtual~calloption(){}
    
private:
    
};


class putoption : public option
{
public:
    putoption();
    putoption(double t, double k);
    virtual double price(
                  double S,        // price of stock or underlying security
                  double r,        // interest rate
                  double q,        // dividend yield
                  double sig      // volatility
    )const;

    virtual double impliedVolatity(double S,double optPrice,double r, putoption op);
    
    virtual~putoption(){}
    
private:
    
};


#endif /* option_h */
