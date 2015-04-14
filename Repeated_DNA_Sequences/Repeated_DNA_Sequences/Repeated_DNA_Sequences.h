// All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG".
// When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
// 
// Write a function to find all the 10 - letter - long sequences(substrings) that occur more than once in a DNA molecule.
// 
// For example,
// 
// Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
// 
// Return:
// ["AAAAACCCCC", "CCCCCAAAAA"].
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;


class Solution { // too slow
#define KEY_MASK 0x000FFFFF
#define CHAR_MASK 0x06
public:
    // A(0x41): 00 --> key = ((key << 2) & KEY_MASK) + 0
    // C(0x43): 01 --> key = ((key << 2) & KEY_MASK) + 1
    // T(0x54): 10 --> key = ((key << 2) & KEY_MASK) + 2
    // G(0x47): 11 --> key = ((key << 2) & KEY_MASK) + 3
    vector<string> findRepeatedDnaSequences(string s) {
        const int sSize = s.size();
        vector<string> output;
        if (sSize >= 11){
            int key = 0;
            // preprocess the key
            for (int i = 0; i < 9; ++i){
                key = ((key << 2) & KEY_MASK) + ((s[i] & CHAR_MASK) >> 1);
            }

            // start handling the 1st 10-char pattern
            unordered_map<int, int> patterns;  // key --> startIdx.  if -1, meaning it has been repeawted before.  skip publishing the key
            vector<int> repeatedPattern;
            for (int i = 9; i < sSize; ++i){
                key = ((key << 2) & KEY_MASK) + ((s[i] & CHAR_MASK) >> 1);
                if (patterns.find(key) == patterns.end()){
                    // first new key
                    patterns[key] = i;
                }
                else{
                    // key exist before
                    if (patterns[key] != -1){
                        // enough
                        patterns[key] = -1;
                        repeatedPattern.push_back(key);
                    }
                }
            }

            // convert the repeated patterns to strings
            for (auto i : repeatedPattern){
                string p;
                for (int j = 0; j < 10; j++){
                    switch (i & 0x03){
                    case 0:
                        p.insert(0, 1, 'A');
                        break;
                    case 1:
                        p.insert(0, 1, 'C');
                        break;
                    case 2:
                        p.insert(0, 1, 'T');
                        break;
                    case 3:
                        p.insert(0, 1, 'G');
                        break;
                    }
                    i >>= 2;
                }
                output.push_back(p);
            }
        }
        return output;
    }
    

};


class Solution { // memory limit exceed
public:
    vector<string> findRepeatedDnaSequences(string s) {
        const int sSize = s.size();
        vector<string> output;
        if (sSize >= 20){
            string key;
            unordered_map<string, pair<int, int>> patterns;  // sequence --> startIdx
            for (int i = 0; i < sSize - 10; ++i){
                key = s.substr(i, 10);
                if (patterns.find(key) != patterns.end()){
                    // pre-exist
                    if (i >= patterns[key].first + 10){
                        // non-overlap
                        if (patterns[key].second == 1){
                            // first time repeat, record the solution
                            output.push_back(key);
                        }
                        patterns[key].second++;
                    }
                }
                else{
                    patterns[key] = {i, 1};
                }
            }
        }
        return output;
    }
};