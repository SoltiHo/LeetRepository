// Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
// 
// If the fractional part is repeating, enclose the repeating part in parentheses.
// 
// For example,
// 
// Given numerator = 1, denominator = 2, return "0.5".
// Given numerator = 2, denominator = 1, return "2".
// Given numerator = 2, denominator = 3, return "0.(6)".

#include <string>
#include <iostream>
#include <unordered_map>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string output;
        if (((numerator < 0) && (denominator >= 0)) || ((numerator > 0) && (denominator < 0))){
            output.push_back('-');
        } 
        long long nu = abs((long long)numerator);
        long long de = abs((long long)denominator);
        stringstream intPart;
        intPart << nu / de;
        output.append(intPart.str());

        long long remaining = nu % de;

        if (remaining > 0){
            output.push_back('.');
            unordered_map<int, int> devidents;
            unordered_map<int, int>::iterator it;

            remaining *= 10;
            it = devidents.find(remaining);
            while ((it == devidents.end()) && (remaining != 0)){
                output.push_back(0x30 + remaining / de);
                devidents.insert({ remaining, output.size() - 1 });

                remaining = remaining % de;
                remaining *= 10;
                it = devidents.find(remaining);
            }

            if (remaining != 0){
                output.insert(output.begin() + it->second, '(');
                output.push_back(')');
            }
        }
        return output;
    }
};