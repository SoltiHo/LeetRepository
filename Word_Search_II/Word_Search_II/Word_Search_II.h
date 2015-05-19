// Given a 2D board and a list of words from the dictionary, find all words in the board.
// 
// Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring.
// The same letter cell may not be used more than once in a word.
// 
// For example,
// Given words = ["oath", "pea", "eat", "rain"] and board =
// 
// [
//     ['o', 'a', 'a', 'n'],
//     ['e', 't', 'a', 'e'],
//     ['i', 'h', 'k', 'r'],
//     ['i', 'f', 'l', 'v']
// ]
// Return["eat", "oath"].
// Note:
// You may assume that all inputs are consist of lowercase letters a - z.
#include <vector>
#include <string>
#include <memory>
using namespace std;

class Solution {
public:
    struct TrieNode {
        string word;
        unique_ptr<TrieNode> nextLevel[26];
    };
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> output;
        if ((board.size() > 0) && (board[0].size() > 0)){
            // translate dictionary to Trie
            unique_ptr<TrieNode> root(new TrieNode);
            TrieNode* pCurr = NULL;
            for (auto w : words){
                pCurr = root.get();
                for (auto c : w){
                    if (pCurr->nextLevel[c - 'a'] == NULL){
                        // new path
                        pCurr->nextLevel[c - 'a'].reset(new TrieNode);
                    }
                    pCurr = pCurr->nextLevel[c - 'a'].get();
                }
                pCurr->word = w;
            }

            for (int r = 0; r < board.size(); ++r){
                for (int c = 0; c < board[0].size(); ++c){
                    backTracking(board, r, c, root.get(), output);
                }
            }
        }
        return output;
    }

    
    void backTracking(vector<vector<char>>& board, int rowIdx, int colIdx, TrieNode* pCurr, vector<string>& output){
        if (reject(board, rowIdx, colIdx, pCurr)){
            return;
        }
        accept(pCurr->nextLevel[board[rowIdx][colIdx] - 'a'].get(), output);

        char temp = board[rowIdx][colIdx];
        board[rowIdx][colIdx] = 0;
        if (rowIdx + 1 < board.size()){
            backTracking(board, rowIdx + 1, colIdx, pCurr->nextLevel[temp - 'a'].get(), output);
        }
        if (rowIdx - 1 >= 0){
            backTracking(board, rowIdx - 1, colIdx, pCurr->nextLevel[temp - 'a'].get(), output);
        }
        if (colIdx + 1 < board[0].size()){
            backTracking(board, rowIdx, colIdx + 1, pCurr->nextLevel[temp - 'a'].get(), output);
        }
        if (colIdx - 1 >= 0){
            backTracking(board, rowIdx, colIdx - 1, pCurr->nextLevel[temp - 'a'].get(), output);
        }
        board[rowIdx][colIdx] = temp;
    }

    bool reject(vector<vector<char>>& board, int rowIdx, int colIdx, TrieNode* pCurr){
        if (board[rowIdx][colIdx] == 0){
            // repeated cell
            return true;
        }
        if (pCurr->nextLevel[board[rowIdx][colIdx] - 'a'] == NULL){
            // not matching
            return true;
        }
        return false;
    }
    void accept(TrieNode* pCurr, vector<string>& output){
        if (pCurr->word.size() > 0){
            output.push_back(pCurr->word);
            // prevent duplication, erase this candidate
            pCurr->word = "";
        }
    }

};


class Solution_TooSlow {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> output;
        if ((board.size() > 0) && (board[0].size() > 0)){
            for (auto& w : words){
                bool found = false;
                for (int i = 0; i < board.size(); ++i){
                    for (int j = 0; j < board[0].size(); ++j){
                        int currentCount = output.size();
                        DFS(board, i, j, w, 0, output);
                        found = output.size() > currentCount ? true : false;
                        if (found){
                            break;
                        }
                    }
                    if (found){
                        break;
                    }
                }
            }
        }
        return output;
    }

    void DFS(vector<vector<char>>& board, int rowIdx, int colIdx, string& word, int sIdx, vector<string>& output){
        if (word[sIdx] != board[rowIdx][colIdx]){
            return;
        }
        if (sIdx == word.size() - 1){
            // complete matching
            output.push_back(word);
            return;
        }

        board[rowIdx][colIdx] = 0;

        if ((rowIdx + 1 < board.size()) && (board[rowIdx + 1][colIdx] != 0)){
            DFS(board, rowIdx + 1, colIdx, word, sIdx + 1, output);
        }
        if ((rowIdx - 1 >= 0) && (board[rowIdx - 1][colIdx] != 0)){
            DFS(board, rowIdx - 1, colIdx, word, sIdx + 1, output);
        }
        if ((colIdx + 1 < board[0].size()) && (board[rowIdx][colIdx + 1] != 0)){
            DFS(board, rowIdx, colIdx + 1, word, sIdx + 1, output);
        }
        if ((colIdx - 1 >= 0) && (board[rowIdx][colIdx - 1] != 0)){
            DFS(board, rowIdx, colIdx - 1, word, sIdx + 1, output);
        }

        board[rowIdx][colIdx] = word[sIdx];
    }
};