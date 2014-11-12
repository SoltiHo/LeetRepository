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
#include <iostream>
using namespace std;

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
                    // previous is also a *, no need to repeat, so skip this one
                    pSize++;
                    continue;
                }
            }
            preprocessedP.push_back(p[pSize]);
            pSize++;
        }

        // find the longest non-wildcard string and cut the problem into 2 parts
        int currStartIdx = 0;
        int maxStartIdx = 0;
        int maxLength = 0;
        int currLength = 0;
        bool inCounting = false;;
        int pNonAsteriskLength = 0;
        for (int i = 0; i < preprocessedP.size(); ++i){
            if ((preprocessedP[i] != '?') && (preprocessedP[i] != '*')){
                // non wildcard char
                if (!inCounting){
                    currStartIdx = i;
                    inCounting = true;
                }
                pNonAsteriskLength++;
            }
            else{
                // wildcard char
                if (inCounting){
                    // close the counting and produce the length
                    currLength = i - currStartIdx;
                    if (maxLength < currLength){
                        maxLength = currLength;
                        maxStartIdx = currStartIdx;
                    }
                    inCounting = false;
                }

                if (preprocessedP[i] == '?'){
                    pNonAsteriskLength++;
                }
            }
        }

        if (inCounting){
            // close the counting and produce the length
            currLength = preprocessedP.size() - currStartIdx;
            if (maxLength < currLength){
                maxLength = currLength;
                maxStartIdx = currStartIdx;
            }
        }

        if (pNonAsteriskLength > sSize){
            // can never match, no enough char in s to satisfy non-asterisk char in p
            return false;
        }

        // s must have the same non-wildcard string, otherwise it can never match
        for (int i = 0; i <= sSize - maxLength; ++i){
            if (memcmp(s + i, preprocessedP.data() + maxStartIdx, sizeof(char)* maxLength) == 0){
                // match found 
                bool result = false;
                // compare the left remaining
                result = isMatch_DP(s, i, preprocessedP.data(), maxStartIdx);
                if (result == false){
                    // left remaining is already impossible
                    continue;
                }
                // compare the right remaining
                result = isMatch_DP(s + i + maxLength, sSize - i - maxLength,
                    preprocessedP.data() + maxStartIdx + maxLength, preprocessedP.size() - maxStartIdx - maxLength);

                if (result == true){
                    // both match
                    return true;
                }
            }
        }

        return false;
    }

    bool isMatch_DP(const char *s, const int sSize, const char *p, const int pSize) {
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
            bool matched = false;
            for (int i = 0; i < pSize; ++i){
                if ((p[i] != '*') && (p[i] != '?') && (p[i] != s[0])){
                    return false;
                }

                // char matched or matched with a '?'
                if ((p[i] == s[0]) || (p[i] == '?')){
                    if (matched){
                        // too many '?' that must take at least one char
                        // so return false since it's impossible to match the extra '?'
                        return false;
                    }
                    else{
                        matched = true;
                    }
                }
            }
            return true;
        }
        else{
            // sSize >= 2
            if (pSize <= 0){
                return false;
            }
            else if (pSize == 1){
                if (p[0] != '*'){
                    return false;
                }
                return true;
            }
        }

        // initialize the global DP table
        int** possiblePath = new int*[3];
        memset(possiblePath, 0, sizeof(int*)* 3);
        possiblePath[0] = new int[sSize];
        memset(possiblePath[0], 0, sizeof(int)* sSize);
        possiblePath[1] = new int[sSize];
        memset(possiblePath[1], 0, sizeof(int)* sSize);

        int fromTopLeft = 0;
        int fromLeft = 0;
        int possiblePathFound = 0;
        bool firstNonZeroInPrevRowFound = false;
        int currentRowIdx = 0;
        int prevRowIdx = 0;

        bool result = false;
        for (int y = 0; y < pSize; ++y){
            firstNonZeroInPrevRowFound = false;
            possiblePathFound = 0;
            currentRowIdx = y % 2;
            prevRowIdx = (currentRowIdx + 1) % 2;
            memset(possiblePath[currentRowIdx], 0, sizeof(int)* sSize);
            for (int x = 0; x < sSize; ++x){
                if (y == 0){
                    // seed row
                    if (p[0] == '*'){
                        possiblePath[currentRowIdx][x] = 1;
                        possiblePathFound++;
                    }
                    else if (p[y] == '?'){
                        if (x == 0){
                            possiblePath[currentRowIdx][x] = 1;
                            possiblePathFound++;
                            break;
                        }
                    }
                    else if (p[y] == s[x]){
                        if ((x == 0) && (s[x] == p[y])){
                            possiblePath[currentRowIdx][x] = 1;
                            possiblePathFound++;
                            break;
                        }
                    }
                    else{
                        // p[0] is not '?' nor '*' and it doesn't match s[0], impossible to match
                        result = false;
                        goto finish;
                    }
                } // end first row
                else {
                    // regular rows
                    if (p[y] == '*'){
                        if (possiblePath[prevRowIdx][x] == 1){
                            firstNonZeroInPrevRowFound = true;
                        }

                        if (firstNonZeroInPrevRowFound){
                            // found, just repeat 1
                            possiblePath[currentRowIdx][x] = 1;
                            possiblePathFound++;
                        }
                    }
                    else if (p[y] == '?'){
                        if ((x > 0) && (possiblePath[prevRowIdx][x - 1] == 1)){
                            // '?' matches any char, no need to check char
                            possiblePath[currentRowIdx][x] = 1;
                            possiblePathFound++;
                        }

                        if (p[y - 1] == '*'){
                            if (((x > 0) && (possiblePath[prevRowIdx][x - 1] == 1)) ||
                                ((x == 0) && (possiblePath[prevRowIdx][x] == 1)))
                            {
                                // '?' matches any char, no need to check char
                                possiblePath[currentRowIdx][x] = 1;
                                possiblePathFound++;
                            }
                        }
                    }
                    else{
                        // normal char 
                        if ((x > 0) && (possiblePath[prevRowIdx][x - 1] == 1) && (p[y] == s[x])){
                            // char matched
                            possiblePath[currentRowIdx][x] = 1;
                            possiblePathFound++;
                        }

                        if (p[y - 1] == '*'){
                            if (((x > 0) && (possiblePath[prevRowIdx][x - 1] == 1) && (p[y] == s[x])) ||
                                ((x == 0) && (possiblePath[prevRowIdx][x] == 1) && (p[y] == s[x])))
                            {
                                // '?' matches any char, no need to check char
                                possiblePath[currentRowIdx][x] = 1;
                                possiblePathFound++;
                            }
                        }

                    }
                }
            }

            if (possiblePathFound == 0){
                // no possible path found
                result = false;
                goto finish;
            }
        }

        result = (possiblePath[currentRowIdx][sSize - 1] == 1);
    finish:

        delete[] possiblePath[0];
        delete[] possiblePath[1];
        delete[] possiblePath;
        return result;
    }
};



