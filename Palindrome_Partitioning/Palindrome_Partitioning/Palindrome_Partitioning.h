//  Given a string s, partition s such that every substring of the partition is a palindrome.
//  
//  Return all possible palindrome partitioning of s.
//  
//  For example, given s = "aab",
//  Return
//  
//  [
//      ["aa", "b"],
//      ["a", "a", "b"]
//  ]
#include <vector>
using namespace std;

class Solution_LatestTrial_Naive {
public:
    vector<vector<string>> partition(string s) {
        const int sSize = s.size();
        vector<vector<string>> output;
        vector<string> buffer;
        recursivePartitioner(output, buffer, 0, s, sSize);
        
        return output;
    }

    void recursivePartitioner(vector<vector<string>>& output, vector<string>& buffer, int startIdx, string& s, const int sSize){
        if (startIdx == sSize){
            output.push_back(buffer);
        }
        else{
            for (int endIdx = startIdx; endIdx < sSize; ++endIdx){
                if (isPalindrome(s, startIdx, endIdx)){
                    buffer.push_back(s.substr(startIdx, endIdx - startIdx + 1));
                    recursivePartitioner(output, buffer, endIdx + 1, s, sSize);
                    buffer.pop_back();
                }
            }
        }
    }

    bool isPalindrome(string& s, int startIdx, int endIdx){
        while (startIdx < endIdx){
            if (s[startIdx++] != s[endIdx--]){
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    vector<vector<string>> partition(string s) {
        const unsigned int inputSize = s.size();
        vector<vector<string>>* solutions = new vector<vector<string>>[inputSize]();
        solutions[0].push_back({ s.substr(0,1) });
        for (unsigned int i = 1; i < inputSize; ++i){
            int offset = 0;
            for (unsigned j = 0; j < solutions[i - 1].size(); ++j){
                solutions[i].push_back(solutions[i - 1][j]);
                solutions[i][j].push_back(s.substr(i, 1));  // append self as a palindrome
                offset++;
            }

            // then search if the curr char can be a last char of a palindrome.
            int idx = i - 1;
            int palindromeLength = 0;
            bool isPalindrome = false;
            
            while (true){
                palindromeLength = i - idx + 1;
                isPalindrome = false;
                for (int j = 0; j < palindromeLength >> 1; ++j){
                    if (s[i - j] != s[idx + j]){
                        break;
                    }
                    if (j == (palindromeLength >> 1) - 1){
                        isPalindrome = true;
                    }
                }

                if (isPalindrome){
                    if (idx > 0){
                        for (int j = 0; j < solutions[idx - 1].size(); ++j){
                            solutions[i].push_back(solutions[idx - 1][j]);
                            solutions[i][offset + j].push_back(s.substr(idx, palindromeLength));
                        }
                        offset += solutions[idx - 1].size();
                    }
                    else{
                        // the palindrome starts from the very first char, where there is no previous solution
                        solutions[i].push_back({ s.substr(idx, palindromeLength) });
                    }
                }

                if (idx == 0){
                    break;
                }
                else{
                    idx--;
                }
            }
        }

        return solutions[inputSize - 1];
    }
};

