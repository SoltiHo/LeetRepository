// Reverse bits of a given 32 bits unsigned integer.
// 
// For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).
// 
// Follow up :
// If this function is called many times, how would you optimize it ?

#include <unordered_map>
using namespace std;


// fastest: generate lookup table



class Solution { // faster than hash table
#define MASK01_1 0xAAAAAAAA
#define MASK01_2 0x55555555
#define MASK02_1 0xCCCCCCCC
#define MASK02_2 0x33333333
#define MASK04_1 0xF0F0F0F0
#define MASK04_2 0x0F0F0F0F
#define MASK08_1 0xFF00FF00
#define MASK08_2 0x00FF00FF
#define MASK16_1 0xFFFF0000
#define MASK16_2 0x0000FFFF
public:
    uint32_t reverseBits(uint32_t n) {

        n = ((n & MASK01_1) >> 1) + ((n & MASK01_2) << 1);
        n = ((n & MASK02_1) >> 2) + ((n & MASK02_2) << 2);
        n = ((n & MASK04_1) >> 4) + ((n & MASK04_2) << 4);
        n = ((n & MASK08_1) >> 8) + ((n & MASK08_2) << 8);
        n = ((n & MASK16_1) >> 16) + ((n & MASK16_2) << 16);
        return n;
    }
};

class Solution {  // slower
#define MASK01_1 0xAAAAAAAA
#define MASK01_2 0x55555555
#define MASK02_1 0xCCCCCCCC
#define MASK02_2 0x33333333
#define MASK04_1 0xF0F0F0F0
#define MASK04_2 0x0F0F0F0F
#define MASK08_1 0xFF00FF00
#define MASK08_2 0x00FF00FF
#define MASK16_1 0xFFFF0000
#define MASK16_2 0x0000FFFF
public:
    uint32_t reverseBits(uint32_t n) {
        if (map.count(n) == 0){
            int oriN = n;
            n = ((n & MASK01_1) >> 1) + ((n & MASK01_2) << 1);
            n = ((n & MASK02_1) >> 2) + ((n & MASK02_2) << 2);
            n = ((n & MASK04_1) >> 4) + ((n & MASK04_2) << 4);
            n = ((n & MASK08_1) >> 8) + ((n & MASK08_2) << 8);
            n = ((n & MASK16_1) >> 16) + ((n & MASK16_2) << 16);
            map[oriN] = n;
        }
        else{
            n = map[n];
        }
        return n;
    }

    unordered_map<unsigned int, unsigned int> map;
};

