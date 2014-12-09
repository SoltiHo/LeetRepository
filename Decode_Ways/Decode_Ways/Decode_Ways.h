// A message containing letters from A - Z is being encoded to numbers using the following mapping :
// 
// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// Given an encoded message containing digits, determine the total number of ways to decode it.
// 
// For example,
// Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
// 
// The number of ways decoding "12" is 2.

#include <string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        const int sSize = s.size();
        if (sSize == 0){
            return 0;
        }

        int buffer[3];
        memset(buffer, 0, sizeof(int)* 3);
        int prevDigit = 0;
        int currDigit = 0;
        int currIdx = 0;
        int prevOneIdx = 0;
        int prevTwoIdx = 0;

        for (int i = 0; i < sSize; ++i){
            currDigit = s[i] - 0x30;
            prevOneIdx = (currIdx + 3 - 1) % 3;
            prevTwoIdx = (currIdx + 3 - 2) % 3;
            buffer[currIdx] = 0;
            if (currDigit != 0){
                // self
                if (i > 0){
                    buffer[currIdx] += buffer[prevOneIdx];
                }
                else {
                    buffer[currIdx] += 1; // seed
                }
            }

            if ((prevDigit == 1) ||
                ((prevDigit == 2) && (currDigit <= 6)))
            {
                // could combine with the prev
                if (i > 1){
                    buffer[currIdx] += buffer[prevTwoIdx];
                }
                else{
                    buffer[currIdx] += 1; // seed
                }
            }
            prevDigit = currDigit;
            currIdx = (currIdx + 1) % 3;
        }

        int answerIdx = currIdx == 0 ? 2 : currIdx - 1;
        return buffer[answerIdx];
    }
};