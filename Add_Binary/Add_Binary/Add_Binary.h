// Given two binary strings, return their sum(also a binary string).
// 
// For example,
// a = "11"
// b = "1"
// Return "100".
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        const int aSize = a.size();
        const int bSize = b.size();

        // make the two strings equal size
        if (aSize > bSize){
            // prepend '0' to b
            b.insert(0, aSize - bSize, '0');
        }
        else if (aSize < bSize){
            a.insert(0, bSize - aSize, '0');
        }


        int carry = 0;
        string sum;
        for (int i = max(aSize, bSize) - 1; i >= 0; --i){
            if ((a[i] == '0') && (b[i] == '0')){
                sum.insert(0, 1, '0' + carry);
                carry = 0;
            }
            else if (((a[i] != '0') && (b[i] == '0')) || ((a[i] == '0') && (b[i] != '0'))){
                sum.insert(0, 1, '0' + (1 ^ carry)); // if carry = 1, 1 ^ carry = 0, otherwise 1 ^ carry = 1
                carry = carry & 1;
            }
            else { // ((a[i] != '0') && (b[i] != '0'))
                sum.insert(0, 1, '0' + carry);
                carry = 1;
            }
        }
        if (carry){
            sum.insert(0, 1, '1');
        }

        return sum;
    }
};