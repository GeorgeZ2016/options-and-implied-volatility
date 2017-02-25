//
//  function.cpp
//  final project
//
//  Created by Junyao Zhao on 06/30/16.
//  Copyright 2016 Junyao Zhao. All rights reserved.
//
#include "option.hpp"
#include "function.hpp"
#include <iostream>
#include <fstream>
#include <cmath>
#include "csv.h"

using namespace std;

double NP(double x)
{
    return (1.0/sqrt(2.0 * 3.1415)* exp(-x*x*0.5));
}

double N(double x)
{
    double a1 = 0.319381530;
    double a2 = -0.356563782;
    double a3 = 1.781477937;
    double a4 = -1.821255978;
    double a5 = 1.330274429;
    double k;
    
    k = 1/(1+0.2316419*x);
    
    if (x >= 0.0)
    {
        return (1 - NP(x)*((a1*k) + (a2* k*k) + (a3*k*k*k)
                           + (a4*k*k*k*k) + (a5*k*k*k*k*k)));
    }
    else
    {
        return (1-N(-x));
    }
}



void calloutput(string a, string b)
{
    double K, r, T;
    
    double bloombergIVM;
    
    double sig, optPrice, price;
    char optType;  // 'c' for call and 'p' for put
    optType = 'c';
    
    string infilename;
    string folder;
    folder = getenv("HOME") + (string) "/Desktop";
    
    /* open the data file for stock price and read the stock price */
    
    string not_used;
    float S_price;
    
    infilename=folder + a;
    io::CSVReader<2> inStock(infilename);
    
    inStock.set_header("StockPrice","Val");
    inStock.read_row(not_used, S_price);
    
    cout << "Stock Price = " << S_price << endl;
    
    
    /* compute implied volatility based on data from file
    
    
    /* open data file for option prices and skip the header */
    
    infilename=folder + b;
    io::CSVReader<5> inOption(infilename);
    
    inOption.set_header("T","K","CallPrice","r","BloombergIVM");
    inOption.next_line();
    
    printf("\n\nUsing C++ code from book, modified to iterate longer\n\n");
    printf("  My  Bloomberg   Call                   Risk-free   MY\n");
    printf("  IV     IV       Price      K        T    rate     Price\n");
    
    
    while (inOption.read_row(T,K,optPrice,r,bloombergIVM)) {
        calloption op(T,K);
        
        sig = op.impliedVolatity(S_price,optPrice,r,op);
        price=op.price(S_price, r, 0, sig);

        
        printf("%5.2f   %5.2f    $%5.2f   $%5.2f   %5.2f  %5.2f%%   $%5.2f\n",
               sig*100,
               bloombergIVM,
               optPrice,
               K,
               T,
               r*100,
               price);
        
    }
}



void putoutput(string a, string b)
{
    double K, r, T;
    
    double bloombergIVM;
    
    double sig, optPrice, price;
    char optType;  // 'c' for call and 'p' for put
    optType = 'c';
    
    string infilename;
    string folder;
    folder = getenv("HOME") + (string) "/Desktop";
    
    /* open the data file for stock price and read the stock price */
    
    string not_used;
    float S_price;
    
    infilename=folder + a;
    io::CSVReader<2> inStock(infilename);
    
    inStock.set_header("StockPrice","Val");
    inStock.read_row(not_used, S_price);
    
    cout << "Stock Price = " << S_price << endl;
    
    
    /* compute implied volatility based on data from file
     
     
     /* open data file for option prices and skip the header */
    
    infilename=folder + b;
    io::CSVReader<5> inOption(infilename);
    
    inOption.set_header("T","K","CallPrice","r","BloombergIVM");
    inOption.next_line();
    
    printf("\n\nUsing C++ code from book, modified to iterate longer\n\n");
    printf("  My  Bloomberg   Call                   Risk-free   MY\n");
    printf("  IV     IV       Price      K        T    rate     Price\n");
    
    
    while (inOption.read_row(T,K,optPrice,r,bloombergIVM)) {
        putoption op(T,K);
        
        sig = op.impliedVolatity(S_price,optPrice,r,op);
        price=op.price(S_price, r, 0, sig);
        
        printf("%5.2f   %5.2f    $%5.2f   $%5.2f   %5.2f  %5.2f%%   $%5.2f\n",
               sig*100,
               bloombergIVM,
               optPrice,
               K,
               T,
               r*100,
               price);
        
    }
}


