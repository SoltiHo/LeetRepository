// Given two strings s and t, determine if they are isomorphic.
// 
// Two strings are isomorphic if the characters in s can be replaced to get t.
// 
// All occurrences of a character must be replaced with another character while preserving the order of characters.No two characters may map to the same character but a character may map to itself.
// 
// For example,
// Given "egg", "add", return true.
// 
// Given "foo", "bar", return false.
// 
// Given "paper", "title", return true.
// 
// Note:
// You may assume both s and t have the same length.

#include <string>
#include <vector>
#include <algorithm>
using namespace std;



class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<char> smap(256, 0);
        vector<char> tmap(256, 0);
        for (int i = 0; i < s.size(); ++i){
            if (smap[s[i]] == 0){
                // not mapped in s yet
                if (tmap[t[i]] != 0){
                    return false;
                }
                smap[s[i]] = t[i];
                tmap[t[i]] = s[i];
            }
            else{
                // already exist
                if (smap[s[i]] != t[i]){
                    return false;
                }
            }
        }
        return true;
    }
};