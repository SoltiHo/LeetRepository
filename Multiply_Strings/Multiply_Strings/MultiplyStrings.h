//Given two numbers represented as strings, return multiplication of the numbers as a string.
//
//Note: The numbers can be arbitrarily large and are non - negative.

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 0x30 ~ 0x39 = 0~9
class Solution {
public:
    string multiply(string num1, string num2) {
        int size1 = num1.size();
        int size2 = num2.size();
        string answer;
        vector<string> outputBuffer;

        unsigned int carry = 0;
        unsigned int temp = 0;
        unsigned int num2Digit = 0;
        string tempString;
        for (int j = size2; j; --j){
            num2Digit = num2[j - 1] - 0x30;
            carry = 0;
            tempString.clear();
            for (int i = size1; i; --i){
                temp = (num1[i - 1] - 0x30) * num2Digit + carry;
                carry = (temp / 10); // the reminder is ignored since this is a int
                tempString.insert(tempString.begin(), (temp % 10) + 0x30);
            }
            if (carry > 0){
                tempString.insert(tempString.begin(), carry + 0x30);
            }
            outputBuffer.push_back(tempString);
        }
        

        tempString.clear();
        carry = 0;
        for (int i = 0; i < (size1 + size2); ++i){
            temp = 0;
            for (int j = 0; j <= min(i, size1); ++j){
                if ((i - j >= outputBuffer.size()) || ((int)(outputBuffer[i - j].size()) - 1 - j < 0)){
                    continue;
                }
                temp += (outputBuffer[i - j][outputBuffer[i - j].size() - 1 - j] - 0x30);
            }
            temp += carry;
            carry = (temp / 10);
            answer.insert(answer.begin(), (temp % 10) + 0x30);
        }
        if (carry > 0){
            answer.insert(answer.begin(), carry + 0x30);
        }

        // process leading 0
        while ((answer[0] == '0') && (answer.size() > 1)){
            answer.erase(answer.begin());
        }

        return answer;
    }
};