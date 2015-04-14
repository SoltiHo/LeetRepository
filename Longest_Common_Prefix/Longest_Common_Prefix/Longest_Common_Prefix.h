// Write a function to find the longest common prefix string amongst an array of strings.
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// if 0 string, return 0
// if 1 string, return the string
// if 2 string, then 
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string output;
        const int stringCount = strs.size();
        if (stringCount == 1){
            output = strs[0];
        }
        else if (stringCount > 1){
            // at least 2 strings
            // calculate the common prefix of the first two strings
            int prefixLength = 0;
            const int maxLength = min(strs[0].size(), strs[1].size());
            while ((strs[0][prefixLength] == strs[1][prefixLength]) && (prefixLength < maxLength)){
                prefixLength++;
            }

            // consume the 3rd strings onward, the length can only decrease
            for (int i = 2; i < stringCount; ++i){
                for (int newLength = 0; newLength < prefixLength; newLength++){
                    if (strs[i][newLength] != strs[0][newLength]){
                        prefixLength = newLength;
                        break;
                    }
                    else if (newLength == strs[i].size() - 1){
                        prefixLength = newLength + 1;
                    }
                }
            }
            output = strs[0].substr(0, prefixLength);
        }
        return output;
    }
};