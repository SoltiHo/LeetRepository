// Given a string, find the length of the longest substring without repeating characters.
// For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. 
// For "bbbbb" the longest substring is "b", with the length of 1.
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


class Solution_CharTable {
public:
    int lengthOfLongestSubstring(string s) {
        const int sSize = s.size();
        int maxLength = 0;
        if (sSize == 0){
            maxLength = 0;
        }
        else{
            int table[256];
            memset(table, 0xFF, sizeof(int)* 256);
            int tableSize = 0;
            int firstToBeDeleted = 0;
            int temp = 0;
            int currLength = 0;
            for (int i = 0; i < sSize; ++i){
                if (table[s[i]] == -1){
                    // not finding the char in the window
                    table[s[i]] = i;
                    tableSize++;
                }
                else{
                    // previously inserted already.
                    // generate one choice
                    currLength = tableSize;
                    maxLength = max(maxLength, currLength);

                    // delete the previous entry
                    temp = table[s[i]] + 1;
                    for (int j = firstToBeDeleted; j < temp; ++j){
                        table[s[j]] = -1; // delete by key
                        tableSize--;
                    }
                    firstToBeDeleted = temp;

                    // insert the new entry
                    table[s[i]] = i;
                    tableSize++;
                }
            }
            currLength = tableSize;
            maxLength = max(maxLength, currLength);
        }
        return maxLength;
    }
};

class Solution_Hash {
public:
    int lengthOfLongestSubstring(string s) {
        const int sSize = s.size();
        int maxLength = 0;
        if (sSize == 0){
            maxLength = 0;
        }
        else{
            unordered_map<char, int> window;
            unordered_map<char, int>::iterator it;
            int firstToBeDeleted = 0;
            int temp = 0;
            int currLength = 0;
            for (int i = 0; i < sSize; ++i){
                if ((it = window.find(s[i])) == window.end()){
                    // not finding the char in the window
                    window.insert({ s[i], i });
                }
                else{
                    // previously inserted already.
                    // generate one choice
                    currLength = window.size();
                    maxLength = max(maxLength, currLength);

                    // delete the previous entry
                    temp = it->second + 1;
                    for (int j = firstToBeDeleted; j < temp; ++j){
                        window.erase(s[j]); // delete by key
                    }
                    firstToBeDeleted = temp;

                    // insert the new entry
                    window.insert({ s[i], i });
                }
            }
            currLength = window.size();
            maxLength = max(maxLength, currLength);
        }
        return maxLength;
    }
};

class Solution_SearchBack {
public:
    int lengthOfLongestSubstring(string s) {
        const int sSize = s.size();
        int longestLength = 0;
        if (sSize > 1){
            int currLength = 0;
            vector<int> boundariesIdx;
            int boundary = 0;
            boundariesIdx.push_back(0);
            for (int i = 1; i < sSize; ++i){
                boundary = 0;
                for (int j = i - 1; j >= 0; --j){
                    boundary = max(boundary, boundariesIdx[j]);
                    if ((s[j] == s[i]) || (boundary == j + 1)){
                        // duplicated found, terminate
                        currLength = i - j;
                        longestLength = max(longestLength, currLength);
                        //if (currLength > longestLength){
                        //    longestLength = currLength;
                        //    cout << "i: " << i << ", j:" << j << endl;
                        //}
                        boundariesIdx.push_back(j + 1);
                        break;
                    }

                    if (j == 0){
                        currLength = i + 1;
                        longestLength = max(longestLength, currLength);
                        //if (currLength > longestLength){
                        //    longestLength = currLength;
                        //    cout << "i: " << i << ", j:" << j << endl;
                        //}
                        boundariesIdx.push_back(0);
                    }
                }
            }
        }
        else if (sSize == 1){
            longestLength = 1;
        }

        return longestLength;
    }
};