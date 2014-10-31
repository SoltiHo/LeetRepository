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

void clear(stack<int>& toBeCleared){
    stack<int> localEmpty;
    swap(localEmpty, toBeCleared);
}

class Solution {
public:
    int longestValidParentheses(string s) {
        const unsigned int stringSize = s.size();
        int* stopperArray = new int[stringSize];
        stack<int> paranthesesStack;
        memset(stopperArray, 0, sizeof(int)*stringSize);

        // left to right scan
        for (int i = 0; i < stringSize; ++i){
            if (s[i] == '('){
                paranthesesStack.push(i);
            }
            else{
                // ')'
                if (paranthesesStack.size() == 0){
                    // stopper
                    stopperArray[i] = 1;
                }
                else{
                    paranthesesStack.pop();
                }
            }
        }

        // right to left scan
        clear(paranthesesStack);
        for (int i = stringSize - 1; i >= 0 ; --i){
            if (s[i] == ')'){
                paranthesesStack.push(i);
            }
            else{
                // '('
                if (paranthesesStack.size() == 0){
                    // stopper
                    stopperArray[i] = 1;
                }
                else{
                    paranthesesStack.pop();
                }
            }
        }

        // calculate the max length
        bool inValid = false;
        int maxLength = 0;
        int currentLength = 0;
        for (int i = 0; i < stringSize; ++i){
            if (stopperArray[i] == 0){
                if (inValid == false){
                    inValid = true;
                }
                currentLength++;
            }
            else{
                if (inValid == true){
                    inValid = false;
                    if (maxLength < currentLength){
                        maxLength = currentLength;
                    }
                    currentLength = 0;
                }
            }
        }

        if (inValid){
            inValid = false;
            if (maxLength < currentLength){
                maxLength = currentLength;
            }
            currentLength = 0;
        }

        delete[] stopperArray;
        return maxLength;
    }
};

