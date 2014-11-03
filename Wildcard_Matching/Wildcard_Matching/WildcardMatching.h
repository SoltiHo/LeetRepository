// Implement wildcard pattern matching with support for '?' and '*'.
// 
// '?' Matches any single character.
// '*' Matches any sequence of characters(including the empty sequence).
// 
// The matching should cover the entire input string(not partial).
// 
// The function prototype should be :
// bool isMatch(const char *s, const char *p)
// 
// Some examples :
// isMatch("aa", "a") --> false
// isMatch("aa", "aa") --> true
// isMatch("aaa", "aa") --> false
// isMatch("aa", "*") --> true
// isMatch("aa", "a*") --> true
// isMatch("ab", "?*") --> true
// isMatch("aab", "c*a*b") --> false


#include <vector>
#include <algorithm>
using namespace std;

vector<int> asterixVector;
vector<int> questionMarkVector;

bool isMatchByDivideAndConquer(const char *s, int sSize, const char *p, int pSize){
    // filter out some basic cases,  truncate unnecessary parts
    int numTruncatedFromLeft = 0;
    int numTruncatedFromRight = 0;
    for (int i = 0; i < min(sSize, pSize); ++i){
        if ((s[i] != p[i]) && (p[i] != '*') && (p[i] != '?')){
            return false;
        }
        else if ((p[i] == '*') || (p[i] == '?')){
            break;
        }
        else{
            // regular char matched, can be truncated
            numTruncatedFromLeft++;
        }
    }

    if (numTruncatedFromLeft > 0){
        s = s + numTruncatedFromLeft;
        sSize -= numTruncatedFromLeft;
        p = p + numTruncatedFromLeft;
        pSize -= numTruncatedFromLeft;
    }

    for (int i = 0; i < min(sSize, pSize); ++i){
        if ((s[sSize - 1 - i] != p[pSize - 1 - i]) && (p[pSize - 1 - i] != '*') && (p[pSize - 1 - i] != '?')){
            return false;
        }
        else if ((p[pSize - 1 - i] == '*') || (p[pSize - 1 - i] == '?')){
            break;
        }
        else{
            // regular char matched, can be truncated
            numTruncatedFromRight++;
        }
    }

    if (numTruncatedFromRight > 0){
        sSize -= numTruncatedFromRight;
        pSize -= numTruncatedFromRight;
    }


    // filter out base cases
    if (sSize <= 0){
        if (pSize <= 0){
            return true;
        }
        else{
            for (int i = 0; i < pSize; ++i){
                if (p[i] != '*'){
                    return false;
                }
            }
            return true;
        }
    }
    else if (sSize == 1){
        if (pSize <= 0){
            return false;
        }
        bool notMatchedYet = true;
        for (int i = 0; i < pSize; ++i){
            if ((p[i] != '*') && (p[i] != '?') && (p[i] != s[0])){
                return false;
            }
            if ((p[i] == s[0]) || (p[i] == '?')){
                if (notMatchedYet){
                    notMatchedYet = false;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
    else{
        if (pSize <= 0){
            return false;
        }
        else if (pSize == sSize){
            for (int i = 0; i < pSize; ++i){
                if ((s[i] != p[i]) && (p[i] != '*') && (p[i] != '?')){
                    return false;
                }
            }
            return true;
        }
        else if (pSize == 1){
            if (p[0] != '*'){
                return false;
            }
            return true;
        }
    }



    // scan through p to find its longest fixed substring (without ? or *)
    int currentLength = 0;
    int currentStartIndex = -1;
    int longestLength = 0;
    int longestStartIndex = -1;

    // find the longest fixed string.  O(m)
    // and record the '?'s and '*'s
    asterixVector.clear();
    questionMarkVector.clear();
    for (int i = 0; i < pSize; ++i){
        if ((p[i] != '*') && (p[i] != '?')){
            currentLength++;
            if (currentStartIndex == -1){
                currentStartIndex = i;
            }
        }
        else{
            // '*' or '?'
            if (longestLength < currentLength){
                longestLength = currentLength;
                longestStartIndex = currentStartIndex;
            }
            currentStartIndex = -1;
            currentLength = 0;

            if (p[i] == '*'){
                asterixVector.push_back(i);
            }
            else {
                // '?'
                questionMarkVector.push_back(i);
            }
        }
    }
    if ((currentLength > 0) && (longestLength < currentLength)){
        longestLength = currentLength;
        longestStartIndex = currentStartIndex;
    }


    if (longestStartIndex == -1){
        // no fixed string, only * or ?
        if (sSize >= questionMarkVector.size()){
            return true;
        }
        else{
            return false;
        }
    }

    // fixedStringStarts
    // scan through s to find the occurrence
    int fixedStringStarts = 0;
    bool results = false;
    while (fixedStringStarts >= 0){
        for (int i = 0; i < sSize; ++i){
            fixedStringStarts = -1;
            if (s[i] == p[longestStartIndex]){
                for (int x = 0; (x < longestLength) && (i + x < sSize); ++x){
                    if (s[i + x] != p[longestStartIndex + x]){
                        break;
                    }
                    if (x == longestLength - 1){
                        // survive to the last, this is a match
                        fixedStringStarts = i;

                        // then we can recursive call based on the fixed strings
                        while ((results == false) && (fixedStringStarts >= 0)){
                            results =
                                (isMatchByDivideAndConquer(s, fixedStringStarts, p, longestStartIndex)) &&   // the left remaining
                                (isMatchByDivideAndConquer(s + fixedStringStarts + longestLength, sSize - fixedStringStarts - longestLength,
                                p + longestStartIndex + longestLength, pSize - longestStartIndex - longestLength));     // the right remaining

                            if (results == false){
                                // this one doesn't work, try next one
                                fixedStringStarts = -1;
                            }
                            else{
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }

    return results;
}


class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // find the length of the two strings
        unsigned int sSize = 0;
        unsigned int pSize = 0;
        while (*(s + sSize) != '\0'){
            sSize++;
        }

        string preprocessedP;
        while (*(p + pSize) != '\0'){
            if (p[pSize] == '*'){
                if ((pSize > 0) && (p[pSize - 1] == '*')){
                    pSize++;
                    continue;
                }
            }
            preprocessedP.push_back(p[pSize]);
            pSize++;
        }

        return isMatchByDivideAndConquer(s, sSize, preprocessedP.data(), preprocessedP.size());
    }



    //bool isMatch_pureDP(const char *s, const char *p) {
    //    // find the length of the two strings
    //    unsigned int sSize = 0;
    //    unsigned int pSize = 0;
    //    while (*(s + sSize) != '\0'){
    //        sSize++;
    //    }

    //    while (*(p + pSize) != '\0'){
    //        pSize++;
    //    }

    //    // initialize availabilityTable table
    //    // '*' and '?' don't need to check

    //    availabilityTable = new int[sSize * pSize];

    //    for (int y = 0; y < pSize; ++y){
    //        for (int x = sSize - 1; x >= 0; --x){
    //            if ((p[y] == '*') || (p[y] == '?')){
    //                continue;
    //            }
    //            if (s[x] == p[y]){
    //                availabilityTable[y*sSize + x] = 1;
    //            }
    //            if (x < sSize - 1){
    //                availabilityTable[y*sSize + x] += availabilityTable[y*sSize + x + 1];
    //            }
    //        }
    //    }


    //    // initialize the global DP table

    //    globalDPTable = new int[sSize * pSize];
    //    memset(globalDPTable, 0, sizeof(int)* sSize * pSize);

    //    int fromTopLeft = 0;
    //    int fromLeft = 0;
    //    for (int y = 0; y < pSize; ++y){
    //        for (int x = 0; x < sSize; ++x){
    //            if (y == 0){
    //                // seed row
    //                if (p[y] == '*'){
    //                    globalDPTable[y*sSize + x] = 1;
    //                }
    //                else if (p[y] == '?'){
    //                    if (x == 0){
    //                        globalDPTable[y*sSize + x] = 1;
    //                    }
    //                }
    //                else if (p[y] == s[x]){
    //                    if ((x == 0) && (s[x] == p[y])){
    //                        globalDPTable[y*sSize + x] = 1;
    //                    }
    //                }
    //            } // end first row
    //            else {
    //                // regular rows
    //                if (p[y] == '*'){
    //                    // fromTopLeft
    //                    if ()
    //                }
    //                else if (p[y] == '?'){
    //                    if (x == 0){
    //                        globalDPTable[y*sSize + x] = 1;
    //                    }
    //                }
    //                else if (p[y] == s[x]){
    //                    if ((x == 0) && (s[x] == p[y])){
    //                        globalDPTable[y*sSize + x] = 1;
    //                    }
    //                }
    //            }
    //        }
    //    }
    //}

    // correct but slow
    bool isMatch_simpleRecursive(const char *s, const char *p) {
        // base cases
        if (*s == '\0'){
            if (*p == '\0'){
                return true;
            }
            else if (*p == '*'){
                unsigned int i = 0;
                while (*(p + i) == '*'){
                    i++;
                }
                return isMatch(s, p + i);
            }
            else {
                return false;
            }
        }
        else{
            if (*p == '\0'){
                return false;
            }
        }



        bool results = false;
        if (*s == *p){
            // char match
            results = isMatch(s + 1, p + 1);
        }
        else if (*p == '*'){
            // to control the amount of recursive calls,
            // split into 3 layers of call
            // plus, consecutive * is the same as single *
            // want to avoid redundant call from multiple *

            unsigned int i = 0;
            while (*(p + i) == '*'){
                i++;
            }

            if (isMatch(s + 1, p + i) == true){
                results = true;
            }
            else if (isMatch(s, p + i) == true){
                results = true;
            }
            else if (isMatch(s + 1, p)){
                results = true;
            }
            else{
                results = false;
            }
        }
        else if (*p == '?'){
            results = isMatch(s + 1, p + 1);
        }
        else{
            // char doesn't match, and *p is not a wildcard.
            // no way to match.
            results = false;
        }

        return results;
    }
};



