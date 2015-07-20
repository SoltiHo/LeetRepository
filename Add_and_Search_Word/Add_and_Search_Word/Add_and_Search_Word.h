// Design a data structure that supports the following two operations :
// 
// void addWord(word)
// bool search(word)
// search(word) can search a literal word or a regular expression string containing only letters a - z or ".".  A "." means it can represent any one letter.
// 
// For example :
// 
// addWord("bad")
// addWord("dad")
// addWord("mad")
// search("pad") -> false
// search("bad") -> true
// search(".ad") -> true
// search("b..") -> true
// Note:
// You may assume that all words are consist of lowercase letters a - z.

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
#include <string>
#include <memory>

using namespace std;

class WordDictionary {
public:
    struct TrieNode {
        bool isString;
        unique_ptr<TrieNode> table[26];

        TrieNode() : isString(false) {};
    };
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* pCurr = &(this->root);
        for (auto c : word){
            if (pCurr->table[c - 'a'] == NULL){
                pCurr->table[c - 'a'].reset(new TrieNode);
            }
            pCurr = pCurr->table[c - 'a'].get();
        }
        pCurr->isString = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return DFS(&(this->root), word, 0);
    }

    bool DFS(TrieNode* pCurr, string& word, int depth){
        if (depth == word.size()){
            if ((pCurr != NULL) && (pCurr->isString == false)){
                return false;
            }
            else{
                return true;
            }
        }

        if (word[depth] == '.'){
            for (int i = 0; i < 26; ++i){
                if ((pCurr->table[i].get() != NULL) && (DFS(pCurr->table[i].get(), word, depth + 1))){
                    return true;
                }
            }
            return false;
        }
        else if (pCurr->table[word[depth] - 'a'].get() != NULL){
            return DFS(pCurr->table[word[depth] - 'a'].get(), word, depth + 1);
        }
        else{
            return false;
        }
    }
    TrieNode root;
};
