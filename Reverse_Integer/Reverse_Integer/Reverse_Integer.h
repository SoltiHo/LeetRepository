// Reverse digits of an integer.
// 
// Example1: x = 123, return 321
//       Example2 : x = -123, return -321
//
//
// Have you thought about this ?
// Here are some good questions to ask before coding.Bonus points for you if you have already thought through this!
//
// If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
//
// Did you notice that the reversed integer might overflow ? Assume the input is a 32 - bit integer, then the reverse of 1000000003 overflows.How should you handle such cases ?
//
// For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
//
// Update(2014 - 11 - 10) :
// Test cases had been added to test the overflow behavior.

#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool isNegative = false;
        if (x < 0){
            if (x == INT_MIN){
                // can't change it back to positive
                return 0;
            }
            // map it back to positive
            x = ~x + 1;
            isNegative = true;
        }

        int output = 0;
        int threshold = INT_MAX / 10;
        while (x > 0){
            if (output <= threshold){
                output = (output * 10) + (x % 10);
                x /= 10;
            }
            else{
                // overflow
                return 0;
            }
        }

        return isNegative ? (~output + 1) : output;
    }
};