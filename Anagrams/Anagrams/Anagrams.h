// Given an array of strings, return all groups of strings that are anagrams.
// 
// Note: All inputs will be in lower - case.
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, int> map; // int is the first time idx, -1 means already output
        vector<string> output;
        const int strsSize = strs.size();
        string temp;
        for (int i = 0; i < strsSize; ++i){
            temp = strs[i];
            sort(temp.begin(), temp.end());
            if (map.find(temp) == map.end()){
                // first time
                map[temp] = i;
            }
            else{
                // previously exist
                if (map[temp] != -1){
                    // first time repeat, output the previous one too
                    output.push_back(strs[map[temp]]);
                    map[temp] = -1;
                }
                output.push_back(strs[i]);
            }
        }
        return output;
    }
};
