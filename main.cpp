//
//  main.cpp
//  final project
//
//  Created by Junyao Zhao on 06/30/16.
//  Copyright 2016 Junyao Zhao. All rights reserved.
//

#include <iostream>
#include "function.hpp"
#include "option.hpp"


using namespace std;

int main() {
    string a="/StockPrice.csv";
    string b="/OptionPrice.csv";
    string c="/StockPriceLCI.csv";
    string d="/OptionPriceLCI.csv";
    calloutput(a,b);
    calloutput(c,d)
    return 0;
}
