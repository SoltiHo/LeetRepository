// Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).
// 
// For example, the 32 - bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.

#include <stdint.h>

class Solution {
public:
#define MASK01 0xAAAAAAAA  // 1010 1010 ...
#define MASK11 0x55555555  // 0101 0101 ...
#define MASK02 0xCCCCCCCC  // 1100 1100 ...
#define MASK22 0x33333333  // 0011 0011 ...
#define MASK03 0xF0F0F0F0  // 1111 0000 ...
#define MASK33 0x0F0F0F0F  // 0000 1111 ...
#define MASK04 0xFF00FF00  // 1111 1111 0000 0000 ....
#define MASK44 0x00FF00FF  // 0000 0000 1111 1111 ....
#define MASK05 0xFFFF0000  // 1111 1111 1111 1111 ....
#define MASK55 0x0000FFFF  // 0000 0000 0000 0000 ....

    int hammingWeight(uint32_t n) {
        n = ((n & MASK01) >> 1) + (n & MASK11);
        n = ((n & MASK02) >> 2) + (n & MASK22);
        n = ((n & MASK03) >> 4) + (n & MASK33);
        n = ((n & MASK04) >> 8) + (n & MASK44);
        n = ((n & MASK05) >> 16) + (n & MASK55);

        return n;
    }
};



class Solution {
public:

    int table[16] = { 0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4 };

    int hammingWeight(uint32_t n) {
        int output = 0;
        while (n > 0){
            output += table[n & 0x0F];
            n >>= 4;
        }
        
        return output;
    }
};