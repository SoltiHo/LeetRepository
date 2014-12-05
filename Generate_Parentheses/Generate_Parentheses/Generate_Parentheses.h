//  Given n pairs of parentheses, write a function to generate all combinations of well - formed parentheses.
//  
//  For example, given n = 3, a solution set is :
//  
//  "((()))", "(()())", "(())()", "()(())", "()()()"
#include <vector>
#include <algorithm>
using namespace std;

class Solution_Permutation {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> output;
        string buffer;

        if (n > 0){
            permuatation(output, buffer, n, n, 0);
        }
        return output;
    }

    void permuatation(vector<string>& output, string& buffer, int leftCount, int rightCount, int openningLeftCount){
        // base case
        if ((rightCount == 1) && (openningLeftCount == 1)){
            // the last add
            buffer.push_back(')');
            output.push_back(buffer);
            buffer.pop_back();
            return;
        }

        // recursive calls
        if (leftCount > 0){
            // try left
            leftCount--;
            openningLeftCount++;
            buffer.push_back('(');
            permuatation(output, buffer, leftCount, rightCount, openningLeftCount);
            buffer.pop_back();
            openningLeftCount--;
            leftCount++;
        }

        if ((rightCount > 0) && (openningLeftCount > 0)){
            // try right
            rightCount--;
            openningLeftCount--;
            buffer.push_back(')');
            permuatation(output, buffer, leftCount, rightCount, openningLeftCount);
            buffer.pop_back();
            openningLeftCount++;
            rightCount++;
        }
    }
};
class Solution_DP {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> output;
        vector<string> outputBuffer;
        int currsor = 0;
        if (n > 0){
            output.push_back("()"); // seed for n == 1
            for (int i = 1; i < n; ++i){
                for (auto s : output){
                    currsor = s.size() - 1;
                    s.push_back('(');
                    s.push_back(')');
                    outputBuffer.push_back(s);
                    while (true) {
                        if (s[currsor] == ')'){
                            // swap
                            swap(s[currsor], s[currsor + 1]);
                            outputBuffer.push_back(s);
                            currsor--;
                        }
                        else{ // '('
                            break;
                        }
                    }
                }
                output.clear();
                output = outputBuffer;
                outputBuffer.clear();
            }
        }
        return output;
    }
};
