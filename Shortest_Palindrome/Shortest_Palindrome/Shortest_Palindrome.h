// Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it.Find and return the shortest palindrome you can find by performing this transformation.
// 
// For example :
// 
// Given "aacecaaa", return "aaacecaaa".
// 
// Given "abcd", return "dcbabcd".

#include <string>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    // Rolling Hash
    Solution() : a(3), k(60623){};
    unsigned int a; // position prime
    unsigned int k; // a prime number for modulo

    string shortestPalindrome(string s) {
        const int sSize = s.size();
        if (sSize == 0){
            return "";
        }
        if (sSize == 1){
            return s;
        }
        // left start idx is always 0
        int leftEndIdx = (sSize >> 1) - 1;
        int rightStartIdx = (sSize + 1) >> 1;
        int rightEndIdx = sSize - 1;

        unsigned int leftHashValue = 0;
        for (int i = leftEndIdx; i >= 0; --i){
            leftHashValue = ((leftHashValue * a + (s[i] - 'a')) + k) % k;
        }

        unsigned int rightHashValue = 0;
        for (int i = rightStartIdx; i <= rightEndIdx; ++i){
            rightHashValue = ((rightHashValue * a + (s[i] - 'a')) + k) % k;
        }

        unsigned int factor = 1;
        for (int i = 0; i < leftEndIdx; ++i){
            factor = (factor * a);
        }

        int temp = 1;
        while ((leftHashValue != rightHashValue) && (leftEndIdx >= 0)){
            if (rightEndIdx % 2){
                // right end idx is odd
                // left hash is shrinking by 1 char
                leftHashValue = ((leftHashValue - factor * (s[leftEndIdx] - 'a')) + k ) % k;

                // right hash end idx is shrinking by 1, start idx remain the same
                rightHashValue = ((rightHashValue - (s[rightEndIdx] - 'a')) / a + k) % k;

                // factor is deducted by 1
                factor /= a;

                rightEndIdx--;
                leftEndIdx--;
            }
            else{
                // right end idx is even
                // left hash remain the same
                // right hash end idx is shrinking by 1, start idx is deducted by 1 too.
                rightHashValue = (((rightHashValue - (s[rightEndIdx] - 'a')) / a + (s[rightStartIdx - 1] - 'a') * factor) + k )% k;
                rightEndIdx--;
                rightStartIdx--;
            }
        }
        s.insert(s.begin(), s.rbegin(), s.rbegin() + (sSize - rightEndIdx - 1));
        return s;
    }

    bool isPalindrome(string& s, int endIdx){
        int startIdx = 0;
        while (startIdx < endIdx){
            if (s[startIdx] != s[endIdx]){
                return false;
            }
            startIdx++;
            endIdx--;
        }
        return true;
    }

};

class Solution_SLOW {
public:
    // N ^ 2, too slow
    string shortestPalindrome(string s) {
        const int sSize = s.size();
        int endIdx = s.size() - 1;
        while (!isPalindrome(s, endIdx)){
            endIdx--;
        }
        s.insert(s.begin(), s.rbegin(), s.rbegin() + (sSize - endIdx - 1));
        return s;
    }

    bool isPalindrome(string& s, int endIdx){
        int startIdx = 0;
        while (startIdx < endIdx){
            if (s[startIdx] != s[endIdx]){
                return false;
            }
            startIdx++;
            endIdx--;
        }
        return true;
    }
};