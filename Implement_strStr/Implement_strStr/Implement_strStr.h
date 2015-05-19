// Implement strStr().
// 
// Returns the index of the first occurrence of needle in haystack, or - 1 if needle is not part of haystack.
// 
// Update(2014 - 11 - 02) :
// The signature of the function had been updated to return the index instead of the pointer.
// If you still see your function signature returns a char * or String, please click the reload button  to reset your code definition.

#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.size() < needle.size()){
            return -1;
        }

        const int rollingLength = needle.size();
        unsigned int targetHash = 0;
        for (auto c : needle){
            targetHash = rollingHash(c, 0, rollingLength, targetHash);
        }

        unsigned int candidateHash = 0;
        for (int i = 0; i < rollingLength; ++i){
            candidateHash = rollingHash(haystack[i], 0, rollingLength, candidateHash);
        }
        if ((candidateHash == targetHash) && (haystack.substr(0, rollingLength) == needle)){
            return 0;
        }

        for (int i = rollingLength; i < haystack.size(); ++i){
            candidateHash = rollingHash(haystack[i], haystack[i - rollingLength], rollingLength, candidateHash, true);
            if ((candidateHash == targetHash) && (haystack.substr(i - rollingLength + 1, rollingLength) == needle)){
                return i - rollingLength + 1;
            }
        }

        return -1;
    }

    unsigned int rollingHash(char newChar, char leavingChar, int targetDepth, unsigned int currHash, bool eject = false){
        if (eject){
            // need to esape one char
            currHash -= (unsigned int)pow(7, targetDepth - 1) * (leavingChar - 'a');
        }
        return currHash * 7 + (newChar - 'a');
    }
};