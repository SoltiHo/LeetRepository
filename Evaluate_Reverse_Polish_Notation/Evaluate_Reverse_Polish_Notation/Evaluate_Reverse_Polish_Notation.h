//  Evaluate the value of an arithmetic expression in Reverse Polish Notation.
//  
//  Valid operators are + , -, *, / .Each operand may be an integer or another expression.
//  
//  Some examples :
//  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
//  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
//  0 ~ 9 = 0x30 ~ 0x39
#include <vector>
#include <string>
#include <stack>

using namespace std;


class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> numbers;
        int temp;
        int operandLeft = 0;
        int operandRight = 0;
        for (auto& t : tokens){
            if (t == "+"){
                operandRight = numbers.top();
                numbers.pop();
                operandLeft = numbers.top();
                numbers.pop();

                temp = operandLeft + operandRight;

                numbers.push(temp);
            }
            else if (t == "-"){
                operandRight = numbers.top();
                numbers.pop();
                operandLeft = numbers.top();
                numbers.pop();

                temp = operandLeft - operandRight;

                numbers.push(temp);
            }
            else if (t == "*"){
                operandRight = numbers.top();
                numbers.pop();
                operandLeft = numbers.top();
                numbers.pop();

                temp = operandLeft * operandRight;

                numbers.push(temp);
            }
            else if (t == "/"){
                operandRight = numbers.top();
                numbers.pop();
                operandLeft = numbers.top();
                numbers.pop();
                
                temp = operandLeft / operandRight;

                numbers.push(temp);
            }
            else{
                // numbers
                numbers.push(atoi(t.c_str()));
            }
        }

        return numbers.top();
    }
};