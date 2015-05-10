// Given a range[m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
//
// For example, given the range[5, 7], you should return 4.
#include <vector>
#include <cmath>

using namespace std;
class SolutionLinear {
public:
    int rangeBitwiseAnd(int m, int n) {
        int output = m & n;
        int mask = 0;
        while (m != n) {
            mask = (mask << 1) + 1;
            m >>= 1;
            n >>= 1;
        }
        return output & (~mask);
    }
};


class SolutionLog {
public:
    int rangeBitwiseAnd(int m, int n) {
        if (m == n){
            return m;
        }

        int output = m & n;
        int mask = (1 << ((int)log2(m ^ n) + 1)) - 1;
        return output & (~mask);
    }
};

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if (m == n){
            return m;
        }

        int output = m & n;
        int lastSameIndex = 0;
        int temp = m ^ n;
        int upperBound = 31;
        int lowerBound = 0;
        // binary search
        while (true){
            // base case, exit
            if (((temp >= table[lastSameIndex]) && (lastSameIndex < 30) && (temp < table[lastSameIndex + 1])) ||
                (lastSameIndex == 30)){
                // found
                break;
            }

            // go to next iteration
            if ((temp > table[lastSameIndex]) && (temp >= table[lastSameIndex + 1])){
                // jump right
                lowerBound = lastSameIndex;
                lastSameIndex = (upperBound + lastSameIndex) >> 1;
            }
            //else if ((temp < table[lastSameIndex]) && (temp < table[lastSameIndex + 1])){
            else{
                // jump left
                upperBound = lastSameIndex;
                lastSameIndex = (lowerBound + lastSameIndex) >> 1;
            }
        }


        int mask = (1 << lastSameIndex + 1) - 1;
        return output & (~mask);
    }

    Solution() : table({ 0x1, 0x3, 0x7, 0xF, 0x1F, 0x3F, 0x7F, 0xFF, 0x1FF, 0x3FF, 0x7FF, 0xFFF, 0x1FFF, 0x3FFF, 0x7FFF, 0xFFFF /*15*/,
        0x1FFFF, 0x3FFFF, 0x7FFFF, 0xFFFFF, 0x1FFFFF, 0x3FFFFF, 0x7FFFFF, 0xFFFFFF, 0x1FFFFFF, 0x3FFFFFF, 0x7FFFFFF, 0xFFFFFFF, 0x1FFFFFFF, 0x3FFFFFFF, 0x7FFFFFFF }){}
    // 0 --> 15 -->23 -->27 --> 29 --> 30 --> 30 ....
    vector<int> table;
};