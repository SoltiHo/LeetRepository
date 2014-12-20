// Given an integer, convert it to a roman numeral.
// 
// Input is guaranteed to be within the range from 1 to 3999.

#include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string output;
        while (num > 0){
            if (num >= 1000){
                output.push_back('M');
                num -= 1000;
            }
            else if (num >= 900){
                output.push_back('C');
                output.push_back('M');
                num -= 900;
            }
            else if (num >= 500){
                output.push_back('D');
                num -= 500;
            }
            else if (num >= 400){
                output.push_back('C');
                output.push_back('D');
                num -= 400;
            }
            else if (num >= 100){
                output.push_back('C');
                num -= 100;
            }
            else if (num >= 90){
                output.push_back('X');
                output.push_back('C');
                num -= 90;
            }
            else if (num >= 50){
                output.push_back('L');
                num -= 50;
            }
            else if (num >= 40){
                output.push_back('X');
                output.push_back('L');
                num -= 40;
            }
            else if (num >= 10){
                output.push_back('X');
                num -= 10;
            }
            else if (num >= 9){
                output.push_back('I');
                output.push_back('X');
                num -= 9;
            }
            else if (num >= 5){
                output.push_back('V');
                num -= 5;
            }
            else if (num >= 4){
                output.push_back('I');
                output.push_back('V');
                num -= 4;
            }
            else if (num > 0){
                output.push_back('I');
                num -= 1;
            }
        }
        return output;
    }
};
