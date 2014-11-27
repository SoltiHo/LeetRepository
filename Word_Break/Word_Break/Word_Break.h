// Given a string s and a dictionary of words dict, determine if s can be segmented into a space - separated sequence of one or more dictionary words.
// 
// For example, given
// s = "leetcode",
// dict = ["leet", "code"].
// 
// Return true because "leetcode" can be segmented as "leet code".
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution_DP {
    bool wordBreak(string s, unordered_set<string> &dict) {
        const int sSize = s.size();
        vector<bool> DPtable(sSize, false);
        for (int i = 0; i < sSize; ++i){
            for (int j = i; j >= 0; --j){
                if (dict.find(s.substr(j, i - j + 1)) != dict.end()){
                    if (j > 0){
                        DPtable[i] = DPtable[j - 1];
                    }
                    else{
                        DPtable[i] = true;
                    }

                    if (DPtable[i]){
                        break;
                    }
                }
            }
        }

        return DPtable[sSize - 1];
    }
};

class Solution_BackTracking {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        this->tempSize = s.size();
        this->temp = new char[this->tempSize]();
        bool result = wordBreakBackTracking(s, dict);
        delete[] this->temp;
        return result;
    }

    bool wordBreakBackTracking(string s, unordered_set<string> &dict) {
        if (reject(s, dict)){
            return false;
        }

        if (accept(s)){
            return true;
        }

        unordered_set<string>::iterator it;
        for (it = dict.begin(); it != dict.end(); it++){
            size_t found = 0;
            size_t accu = 0;
            for (found = s.find(*it); found != string::npos; accu += (found + 1), found = s.substr(accu).find(*it)){
                // left first
                if ((found > 0) && (wordBreakBackTracking(s.substr(0, found), dict) == false)){
                    continue;
                }

                // right
                if ((found + (*it).size() < s.size()) && (wordBreakBackTracking(s.substr(found + (*it).size()), dict) == false)){
                    continue;
                }
                return true;
            }
        }

        return false;
    }

    bool reject(string& s, unordered_set<string> &dict){
        bool result = false;
        if (s.size() > 0){
            unordered_set<string>::iterator it;
            for (it = dict.begin(); it != dict.end(); it++){
                size_t found = 0;
                size_t accu = 0;
                for (found = s.find(*it); found != string::npos; accu += (found + 1), found = s.substr(accu).find(*it)){
                    memset(temp + accu + found, 0xFF, (*it).size());
                }
            }

            for (unsigned int i = 0; i < s.size(); ++i){
                if (temp[i] == 0){
                    result = true;
                    break;
                }
            }
        }

        memset(this->temp, 0, tempSize);
        return result;
    }

    bool accept(string& s){
        if (s.size() == 0){
            return true;
        }
        return false;
    }

    char* temp;
    int tempSize;
};