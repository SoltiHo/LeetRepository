// Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.
// 
// Return all such possible sentences.
// 
// For example, given
// s = "catsanddog",
// dict = ["cat", "cats", "and", "sand", "dog"].
// 
// A solution is["cats and dog", "cat sand dog"].

#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        const int sSize = s.size();
        const int dSize = dict.size();
        vector<string> dummy;
        if ((dSize == 0) || (sSize == 0)){
            return dummy;
        }

        vector<vector<const string*>> match(sSize);
        unordered_set<string>::iterator it;
        for (int i = 0; i < sSize; ++i){
            for (int j = i; j >= 0; --j){
                if ((it = dict.find(s.substr(j, i - j + 1))) != dict.end()){
                    if (j > 0){
                        if (match[j - 1].size() > 0){
                            match[i].push_back(&(*it));
                        }
                    }
                    else{
                        match[i].push_back(&(*it));
                    }
                }
            }
        }

        if (match[sSize - 1].size() > 0){
            string outputBuffer;
            constructSolutions(outputBuffer, sSize - 1, match, dict);
            return this->output;
        }
        else{
            return dummy;
        }
        
    };

    void constructSolutions(string& outputBuffer, const int currIdx, vector<vector<const string*>>& match, unordered_set<string> &dict){
        if (currIdx < 0){
            this->output.push_back(outputBuffer);
            return;
        }

        int nextIdx = 0;
        int insertedSize = 0;
        int wordSize = 0;
        const bool isNotFirstWord = (outputBuffer.size() != 0);
        for (auto& pWord : match[currIdx]){
            if (isNotFirstWord){
                outputBuffer.insert(0, " ");
                insertedSize++;
            }
            wordSize = pWord->size();
            outputBuffer.insert(0, *pWord);
            insertedSize += wordSize;
            nextIdx = currIdx - wordSize;
            constructSolutions(outputBuffer, nextIdx, match, dict);
            outputBuffer.erase(0, insertedSize);
            insertedSize = 0;
        }
    }

    vector<string> output;
};