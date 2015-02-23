//Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
//The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

#include <string>
#include <stack>
using namespace std;
// [ 0x5b,  ] 0x5d
// 
class Solution {
public:
    bool isValid(string s) {
        stack<char> openStack;
        bool breakEarly = false;
        for (auto& c : s){
            switch (c){
            case '(':
            case '[':
            case '{':
                openStack.push(c);
                break;
            case ')':
                if ((openStack.size() > 0) && (openStack.top() == '(')){
                    openStack.pop();
                }
                else{
                    breakEarly = true;
                }
                break;
            case ']':
                if ((openStack.size() > 0) && (openStack.top() == '[')){
                    openStack.pop();
                }
                else{
                    breakEarly = true;
                }
                break;
            case '}':
                if ((openStack.size() > 0) && (openStack.top() == '{')){
                    openStack.pop();
                }
                else{
                    breakEarly = true;
                }
                break;
            default:
                breakEarly = true;
                break;
            }
            if (breakEarly){
                break;
            }
        }
        return ((!breakEarly) && (openStack.size() == 0));
    }
};