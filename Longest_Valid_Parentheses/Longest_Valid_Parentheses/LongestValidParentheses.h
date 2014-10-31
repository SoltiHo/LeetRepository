//  Given a string containing just the characters '(' and ')', find the length of the longest valid(well - formed) parentheses substring.
//  
//  For "(()", the longest valid parentheses substring is "()", which has length = 2.
//  
//  Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
//  

#include <string>
#include <stack>
#include <algorithm>

using namespace std;

//int longestValidParentheses(const string& s, const unsigned int firstCharIndex, const unsigned int size){
//    // base cases
//    if (size <= 1){
//        return 0;
//    }
//    else if (size == 2){
//        if ((s.at(0) == '(') && (s.at(1) == ')')){
//            return 2;
//        }
//        else{
//            return 0;
//        }
//    }
//
//    // recursive calls
//    // calculate type 1 and type 2 
//    const unsigned int leftHalfSize = (size >> 1);
//    const unsigned int rightHalfSize = size - leftHalfSize;
//    int leftValidSubstringSize = longestValidParentheses(s, firstCharIndex, leftHalfSize);
//    int rightValidSubstringSize = longestValidParentheses(s, firstCharIndex + leftHalfSize, rightHalfSize);
//
//    // calculate type 3
//    const int leftHalfRightMostIndex = firstCharIndex + leftHalfSize - 1;
//    const int rightHalfLeftMostIndex = firstCharIndex + leftHalfSize;
//
//    stack<unsigned int> parenthesesStack;
//    for (int i = leftHalfRightMostIndex; i >= 0; --i){
//        if (s[i] == '('){
//            parenthesesStack.push(i);
//        }
//        else{
//            // ')'
//            if (parenthesesStack.size() > 0){
//                parenthesesStack.pop();
//            }
//            else{
//                // too many ')', valid substring stops here
//
//            }
//        }
//    }
//
//}

class Solution {
public:
    //int longestValidParentheses(string s) {
    //    // Strategy: There are 3 types of valid substring: 
    //    //      1. starts and ends left half
    //    //      2. starts and ends right half
    //    //      3. starts in left half and ends in right half
    //    //  So, by the Master Method, the complexity is O(n log n)

    //    //  1. and 2. can be calculated by recursive calls
    //    //  3. is the primary difficulty
    //    //  For the left, scan from right most to left most
    //    //     a. can only have "(" left
    //    //     b. the valid substring must be continuous from the last char
    //    //  For the right, scan from left most to right most
    //    //     a. can only have ")" left
    //    //     b. the valid substring must be continuous from the 1st char



    //}

    int longestValidParentheses(string s) {
        // filter out basic cases
        unsigned int stringSize = s.size();
        if (stringSize <= 1){
            return 0;
        }
        else if (stringSize == 2){
            if ((s.at(0) == '(') && (s.at(1) == ')')){
                return 2;
            }
            else{
                return 0;
            }
        }

        int validStart = 0;
        stack<int> leftParantheses;
        int rightMostPairedRightIndex = INT_MIN;
        int leftMostPopedOutLeftIndex = INT_MAX;
        bool inValidPhase = false;

        int longestValidPeriod = 0;
        int currentLength = 0;
        for (unsigned int i = 0; i < stringSize; ++i){
            if (s.at(i) == '('){
                // push one more (
                leftParantheses.push(i);
                if (inValidPhase == false){
                    inValidPhase = true;
                    validStart = i;
                }
            }
            else{
                // ')'
                if (leftParantheses.size() == 0){
                    if (inValidPhase){
                        // need to close this period, and calculate
                        inValidPhase = false;
                        currentLength = (i - 1) - validStart + 1;
                        if (currentLength > longestValidPeriod){
                            longestValidPeriod = currentLength;
                        }
                        leftMostPopedOutLeftIndex = INT_MAX;
                        rightMostPairedRightIndex = INT_MIN;
                    }
                }
                else{
                    rightMostPairedRightIndex = i;
                    if (leftMostPopedOutLeftIndex > leftParantheses.top()){
                        leftMostPopedOutLeftIndex = leftParantheses.top();
                    }
                    leftParantheses.pop();
                }
            }
        }

        if (leftParantheses.size() == 0){
            if ((inValidPhase) && (leftMostPopedOutLeftIndex != INT_MAX)){
                currentLength = rightMostPairedRightIndex - leftMostPopedOutLeftIndex + 1;
                if (currentLength > longestValidPeriod){
                    longestValidPeriod = currentLength;
                }
            }
        }
        else{
            if ((inValidPhase) && (leftMostPopedOutLeftIndex != INT_MAX)){
                if (leftParantheses.top() > rightMostPairedRightIndex){
                    int lastStart = leftMostPopedOutLeftIndex;
                    while (leftParantheses.size() > 0){
                        if (leftParantheses.top() < rightMostPairedRightIndex){
                            lastStart = leftParantheses.top() + 1;
                            break;
                        }
                        leftParantheses.pop();
                    }
                    currentLength = rightMostPairedRightIndex - lastStart + 1;
                }
                else{
                    currentLength = rightMostPairedRightIndex - max(leftMostPopedOutLeftIndex, leftParantheses.top() + 1) + 1;
                }
                

                if (currentLength > longestValidPeriod){
                    longestValidPeriod = currentLength;
                }
            }
        }

        return longestValidPeriod;
    }
};

