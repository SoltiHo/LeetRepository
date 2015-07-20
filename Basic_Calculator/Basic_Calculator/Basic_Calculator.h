// Implement a basic calculator to evaluate a simple expression string.
// 
// The expression string may contain open(and closing parentheses), the plus + or minus sign - , non - negative integers and empty spaces .
// 
// You may assume that the given expression is always valid.
// 
// Some examples :
// "1 + 1" = 2
// " 2-1 + 2 " = 3
// "(1+(4+5+2)-3)+(6+8)" = 23
// Note : Do not use the eval built - in library function.
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int output = 0;

        return output;
    }

    int calculateWithoutParenthesis(string& s, int& currIdx){
        // invariant: currIdx is pointing to '('
        currIdx++;
        int output = 0;
        int currNumber = -1;
        while (s[currIdx] != ')'){
            if ((s[currIdx] >= '0') && (s[currIdx] <= '9')){
                
            }
            else if (s[currIdx] == '('){

            }
        }
    }
};