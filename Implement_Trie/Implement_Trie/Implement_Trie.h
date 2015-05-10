// Implement a trie with insert, search, and startsWith methods.
// 
// Note:
// You may assume that all inputs are consist of lowercase letters a - z.
#include <string>
#include <unordered_map>
#include <memory>
using namespace std;

namespace IMPLEMENTATION_A2Z {
    class TrieNode {
    public:
        // Initialize your data structure here.
        TrieNode() : isAString(false) {
        }
        unique_ptr<TrieNode> map[26];
        bool isAString;
    };

    class Trie {
    public:
        Trie() {
            pRoot.reset(new TrieNode());
        }

        // Inserts a word into the trie.
        void insert(string s) {
            TrieNode* pCurr = pRoot.get();
            for (int i = 0; i < s.size(); ++i){
                if (!(pCurr->map[s[i] - 'a'])){
                    // doesn't exist
                    pCurr->map[s[i] - 'a'].reset(new TrieNode);
                }
                pCurr = pCurr->map[s[i] - 'a'].get();
                if (i == s.size() - 1){
                    pCurr->isAString = true;
                }
            }
        }

        // Returns if the word is in the trie.
        bool search(string key) {
            TrieNode* pCurr = pRoot.get();
            for (int i = 0; i < key.size(); ++i){
                if (!(pCurr->map[key[i] - 'a'])){
                    // doesn't exist
                    return false;
                }
                pCurr = pCurr->map[key[i] - 'a'].get();
            }
            return pCurr->isAString;
        }

        // Returns if there is any word in the trie
        // that starts with the given prefix.
        bool startsWith(string prefix) {
            TrieNode* pCurr = pRoot.get();
            for (int i = 0; i < prefix.size(); ++i){
                if (!(pCurr->map[prefix[i] - 'a'])){
                    // doesn't exist
                    return false;
                }
                pCurr = pCurr->map[prefix[i] - 'a'].get();
            }
            return true;
        }

    private:
        unique_ptr<TrieNode> pRoot;
    };

}

namespace IMPLEMENTATION_GENERAL {
    class TrieNode {
    public:
        // Initialize your data structure here.
        TrieNode() : isAString(false) {
        }
        unordered_map<char, unique_ptr<TrieNode>> map;
        bool isAString;
    };

    class Trie {
    public:
        Trie() {
            pRoot.reset(new TrieNode());
        }

        // Inserts a word into the trie.
        void insert(string s) {
            TrieNode* pCurr = pRoot.get();
            for (int i = 0; i < s.size(); ++i){
                if (pCurr->map.count(s[i]) == 0){
                    // doesn't exist
                    pCurr->map[s[i]].reset(new TrieNode);
                }
                pCurr = pCurr->map[s[i]].get();
                if (i == s.size() - 1){
                    pCurr->isAString = true;
                }
            }
        }

        // Returns if the word is in the trie.
        bool search(string key) {
            TrieNode* pCurr = pRoot.get();
            for (int i = 0; i < key.size(); ++i){
                if (pCurr->map.count(key[i]) == 0){
                    // doesn't exist
                    return false;
                }
                pCurr = pCurr->map[key[i]].get();
            }
            return pCurr->isAString;
        }

        // Returns if there is any word in the trie
        // that starts with the given prefix.
        bool startsWith(string prefix) {
            TrieNode* pCurr = pRoot.get();
            for (int i = 0; i < prefix.size(); ++i){
                if (pCurr->map.count(prefix[i]) == 0){
                    // doesn't exist
                    return false;
                }
                pCurr = pCurr->map[prefix[i]].get();
            }
            return true;
        }

    private:
        unique_ptr<TrieNode> pRoot;
    };

}


// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");