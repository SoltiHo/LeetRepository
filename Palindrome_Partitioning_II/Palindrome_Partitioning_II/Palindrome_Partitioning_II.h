//  Given a string s, partition s such that every substring of the partition is a palindrome.
//  
//  Return the minimum cuts needed for a palindrome partitioning of s.
//  
//  For example, given s = "aab",
//  Return 1 since the palindrome partitioning["aa", "b"] could be produced using 1 cut.
//  
//  Show Tags
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minCut(string s) {
        // if the new char is part of a palindrom, then its previous char must be also a part of palindrome
        const int inputSize = s.size();
        int output = 0;
        if (inputSize > 0){
            vector<int> cut(inputSize, 0);
            vector<int> palindromeHeadIdx(inputSize, -1);
            vector<bool> isMonotone(inputSize, false);
            for (int i = 1; i < inputSize; ++i){
                if (palindromeHeadIdx[i - 1] != -1){
                    // prev char is part of a palindrome
                    // check if the palindrome can be expanded
                    if ((palindromeHeadIdx[i - 1] - 1 >= 0) && (s[palindromeHeadIdx[i - 1] - 1] == s[i])){
                        // can be expanded
                        cut[i] = palindromeHeadIdx[i - 1] - 2 >= 0 ? cut[palindromeHeadIdx[i - 1] - 2] + 1 : 0;
                        palindromeHeadIdx[i] = palindromeHeadIdx[i - 1] - 1;
                        isMonotone[i] = (isMonotone[i - 1] && (s[i] == s[i - 1]));
                    }
                    else{
                        if ((isMonotone[i - 1]) && (s[i] == s[i - 1])){
                            cut[i] = cut[palindromeHeadIdx[i - 1]];
                            palindromeHeadIdx[i] = palindromeHeadIdx[i - 1];
                            isMonotone[i] = isMonotone[i - 1];
                        }
                        else{
                            checkForANewPalindrome(cut, palindromeHeadIdx, isMonotone, s, i);
                        }
                    }
                }
                else{
                    checkForANewPalindrome(cut, palindromeHeadIdx, isMonotone, s, i);
                }
            }
            output = cut[inputSize - 1];
        }
        return output;
    }

    void checkForANewPalindrome(vector<int>& cut, vector<int>& palindromeHeadIdx, vector<bool>& isMonotone, const string s, const int i){
        // check if a new palindrome can be started
        // check the i - 2 char first
        int cutCandidate0 = INT_MAX;
        int cutCandidate1 = INT_MAX;
        int cutCandidate2 = INT_MAX;
        if ((i - 2 >= 0) && (s[i - 2] == s[i])){
            // start a new palindrome with i - 2
            cutCandidate2 = i - 3 >= 0 ? cut[i - 3] + 1: 0;
        }

        if (s[i - 1] == s[i]) {
            cutCandidate1 = i - 2 >= 0 ? cut[i - 2] + 1 : 0;
        }

        cutCandidate0 = cut[i - 1] + 1;

        if ((cutCandidate0 < cutCandidate1) && (cutCandidate0 < cutCandidate2)){
            // pick cutCandidate0
            cut[i] = cutCandidate0;
        }
        else if ((cutCandidate1 < cutCandidate2) && (cutCandidate1 < cutCandidate0)){
            // pick cutCandidate1
            cut[i] = cutCandidate1;
            palindromeHeadIdx[i] = i - 1;
            isMonotone[i] = true;
        }
        else{
            // pick cutCandidate2
            cut[i] = cutCandidate2;
            palindromeHeadIdx[i] = i - 2;
            isMonotone[i] = (s[i] == s[i - 1]);
        }
    }
};


class Solution_SLOW {
public:
    int minCut(string s) {
        const int inputSize = s.size();
        if (inputSize <= 1){
            return 0;
        }

        int* minCutArray = new int[inputSize]();
        minCutArray[0] = 0;

        int currMin = INT_MAX;
        int currCut = 0;
        int startIdx = 0;
        for (int i = 1; i < inputSize; ++i){
            currMin = INT_MAX;
            startIdx = 0;
            while (startIdx <= i){
                if (isPalindrome(s.data() + startIdx, i - startIdx + 1)){
                    // palimdrome
                    currCut = startIdx > 0 ? minCutArray[startIdx - 1] + 1 : 0;
                    currMin = min(currMin, currCut);
                    if (currMin == 0){
                        // can't be lower, so no need to continue
                        break;
                    }
                }
                startIdx++;
            }
            minCutArray[i] = currMin;
        }

        int output = minCutArray[inputSize - 1];
        delete[] minCutArray;
        return output;
    }

    bool isPalindrome(const char* p, const int length){
        for (int i = 0; i < (length >> 1); ++i){
            if (p[i] != p[length - 1 - i]){
                return false;
            }
        }
        return true;
    }
};


class Solution_LatestTrial_Naive {
public:
    int minCut(string s) {
        const int sSize = s.size();
        vector<int> minCuts(sSize + 1, 0);
        if (sSize > 1){
            minCuts[0] = -1;
            for (int endIdx = 1; endIdx < sSize; ++endIdx){
                int bestChoiceCut = INT_MAX;
                for (int startIdx = 0; startIdx <= endIdx; ++startIdx){
                    if (isPalindrome(s, startIdx, endIdx)){
                        bestChoiceCut = min(bestChoiceCut, minCuts[startIdx - 1 + 1] + 1); // offset by 1 to avoid boundary checking
                        if (bestChoiceCut == 0){
                            break;
                        }
                    }
                }
                minCuts[endIdx + 1] = bestChoiceCut; // offset by 1 to avoid boundary checking
            }
        }
        return minCuts[sSize];
    }

    inline bool isPalindrome(string& s, int startIdx, int endIdx){
        while (startIdx < endIdx){
            if (s[startIdx++] != s[endIdx--]){
                return false;
            }
        }
        return true;
    }
};