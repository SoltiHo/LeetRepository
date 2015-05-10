//Given an integer n, return the number of trailing zeroes in n!.
//
//Note: Your solution should be in logarithmic time complexity.

#include <cmath>
class Solution {
public:
    int trailingZeroes(int n) {
        int output = 0;
        while (n > 0){
            output += n / 5;
            n /= 5;
        }
        return output;
    }
};