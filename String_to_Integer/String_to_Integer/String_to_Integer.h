// Implement atoi to convert a string to an integer.
// 
// Hint: Carefully consider all possible input cases.If you want a challenge, please do not see below and ask yourself what are the possible input cases.
// 
//   Notes : It is intended for this problem to be specified vaguely(ie, no given input specs).You are responsible to gather all the input requirements up front.
// 
//           Update(2015 - 02 - 10) :
//           The signature of the C++ function had been updated.If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.

#include <string>

using namespace std;
class Solution {
public:
    int myAtoi(string str) {
        if (str.size() == 0){
            return 0;
        }

        bool isNegative = false;
        int charIdx = 0;
        while (str[charIdx] < '0' || str[charIdx] > '9'){
            if (str[charIdx] == '-'){
                isNegative = !isNegative;
            }
            charIdx++;
        }


        int output = 0;
        for (; charIdx < str.size(); charIdx++){
            output = output * 10 + (str[charIdx] - '0');
        }

        if (isNegative){
            output *= -1;
        }

        return output;
    }
};