// Given a 2D board and a word, find if the word exists in the grid.
// 
// The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring.
// The same letter cell may not be used more than once.
// 
// For example,
// Given board =
// 
// [
//     ["ABCE"],
//     ["SFCS"],
//     ["ADEE"]
// ]
// word = "ABCCED", ->returns true,
// word = "SEE", ->returns true,
// word = "ABCB", ->returns false.


#include <vector>
#include <unordered_set>
using namespace std;



//class Solution_FromForumNotMine {
//public:
//    int n, m;
//    bool vis[100][100];
//    int dx[4] = { 1, 0, -1, 0 };
//    int dy[4] = { 0, -1, 0, 1 };
//    bool dfs(int x, int y, int depth, vector<vector<char> > &board, string &word){
//        if (board[x][y] == word[depth]){
//            if (depth == word.length() - 1)
//                return true;
//            for (int i = 0; i<4; i++){
//                int nx = x + dx[i];
//                int ny = y + dy[i];
//                if (nx >= 0 && ny >= 0 && nx<n && ny<m && !vis[nx][ny]){
//                    vis[nx][ny] = true;
//                    if (dfs(nx, ny, depth + 1, board, word))
//                        return true;
//                    vis[nx][ny] = false;
//                }
//            }
//        }
//        return false;
//    }
//    bool check(int x, int y, vector<vector<char> > &board, string &word){
//        memset(vis, 0, sizeof(vis));
//        vis[x][y] = true;
//        return dfs(x, y, 0, board, word);
//    }
//    bool exist(vector<vector<char> > &board, string word) {
//        n = board.size();
//        m = board[0].size();
//        for (int i = 0; i<n; i++)
//            for (int j = 0; j<m; j++)
//                if (board[i][j] == word[0]){
//                    if (check(i, j, board, word))
//                        return true;
//                }
//
//        return false;
//    }
//};

class Solution_NormalTable {
public:
    enum NextEligibleMove{
        NORTH,
        SOUTH,
        WEST,
        EAST
    };
    bool exist(vector<vector<char> > &board, string word) {
        memset(this->paths, 0, sizeof(bool)* 10000);
        for (int y = 0; y < board.size(); ++y){
            for (int x = 0; x < board[y].size(); ++x){
                this->paths[y * 100 + x] = true;
                if (backTracking(board, word, x, y, 0)){
                    return true;
                }
                this->paths[y * 100 + x] = false;
            }
        }

        return false;
    }

    bool backTracking(vector<vector<char> > &board, string& word, int x, int y, int currIdxInWord){
        vector<NextEligibleMove> candidates;
        if (reject(board, word, x, y, currIdxInWord, candidates)){
            return false;
        }

        if (accept(word, currIdxInWord)){
            return true;
        }

        // recursive
        for (auto &c : candidates){
            switch (c){
            case NORTH:
                this->paths[(y - 1) * 100 + x] = true;
                if (backTracking(board, word, x, y - 1, currIdxInWord + 1)){
                    return true;
                }
                this->paths[(y - 1) * 100 + x] = false;
                break;
            case SOUTH:
                this->paths[(y + 1) * 100 + x] = true;
                if (backTracking(board, word, x, y + 1, currIdxInWord + 1)){
                    return true;
                }
                this->paths[(y + 1) * 100 + x] = false;
                break;
            case WEST:
                this->paths[y * 100 + x - 1] = true;
                if (backTracking(board, word, x - 1, y, currIdxInWord + 1)){
                    return true;
                }
                this->paths[y * 100 + x - 1] = false;
                break;
            case EAST:
                this->paths[y * 100 + x + 1] = true;
                if (backTracking(board, word, x + 1, y, currIdxInWord + 1)){
                    return true;
                }
                this->paths[y * 100 + x + 1] = false;
                break;
            }
        }
        return false;
    }

    bool reject(vector<vector<char> > &board, string& word, int x, int y, int currIdxInWord, vector<NextEligibleMove>& candidates){
        if (board[y][x] != word[currIdxInWord]){
            return true;
        }

        if (currIdxInWord < word.size() - 1){
            if (isAvailable(board, x, y - 1) && (word[currIdxInWord + 1] == board[y - 1][x])){
                candidates.push_back(NORTH);
            }
            if (isAvailable(board, x, y + 1) && (word[currIdxInWord + 1] == board[y + 1][x])){
                candidates.push_back(SOUTH);
            }
            if (isAvailable(board, x - 1, y) && (word[currIdxInWord + 1] == board[y][x - 1])){
                candidates.push_back(WEST);
            }
            if (isAvailable(board, x + 1, y) && (word[currIdxInWord + 1] == board[y][x + 1])){
                candidates.push_back(EAST);
            }

            if (candidates.size() == 0){
                return true;
            }
        }
        return false;
    }

    inline bool accept(string& word, int currIdxInWord){
        return (currIdxInWord == word.size() - 1);
    }

    bool isAvailable(vector<vector<char> > &board, int x, int y){
        if ((x < 0) || (y < 0)){
            return false;
        }

        if (y >= board.size()){
            return false;
        }

        if (x >= board[y].size() ){
            return false;
        }

        if (this->paths[y * 100 + x]){
            return false;
        }

        return true;
    }

    inline unsigned long long makeKey(int x, int y){
        unsigned long long output = 0;
        output = ((unsigned long long)y) << (sizeof(int) << 3);
        output += x;
        return output;
    }

    bool paths[10000];
};




class Solution_DFS {
public:
    bool exist(vector<vector<char> > &board, string word) {
        memset(this->paths, 0, sizeof(bool)* 10000);
        for (int y = 0; y < board.size(); ++y){
            for (int x = 0; x < board[y].size(); ++x){
                this->paths[y * 100 + x] = true;
                if (DFS(board, word, x, y, 0)){
                    return true;
                }
                this->paths[y * 100 + x] = false;
            }
        }

        return false;
    }

    bool DFS(vector<vector<char> > &board, string& word, int x, int y, int currIdxInWord){
        if (word[currIdxInWord] != board[y][x]){
            return false;
        }

        if (currIdxInWord == word.size() - 1){
            return true;
        }

        if (isAvailable(board, x, y + 1)){
            this->paths[(y + 1) * 100 + x] = true;
            if (DFS(board, word, x, y + 1, currIdxInWord + 1)){
                return true;
            }
            this->paths[(y + 1) * 100 + x] = false;
        }

        if (isAvailable(board, x, y - 1)){
            this->paths[(y - 1) * 100 + x] = true;
            if (DFS(board, word, x, y - 1, currIdxInWord + 1)){
                return true;
            }
            this->paths[(y - 1) * 100 + x] = false;
        }

        if (isAvailable(board, x + 1, y)){
            this->paths[y * 100 + x + 1] = true;
            if (DFS(board, word, x + 1, y, currIdxInWord + 1)){
                return true;
            }
            this->paths[y * 100 + x + 1] = false;
        }
       
        if (isAvailable(board, x - 1, y)){
            this->paths[y * 100 + x - 1] = true;
            if (DFS(board, word, x - 1, y, currIdxInWord + 1)){
                return true;
            }
            this->paths[y * 100 + x - 1] = false;
        }

        return false;
    }

    
    bool isAvailable(vector<vector<char> > &board, int x, int y){
        if ((x < 0) || (y < 0)){
            return false;
        }

        if (y >= board.size()){
            return false;
        }

        if (x >= board[y].size()){
            return false;
        }

        if (this->paths[y * 100 + x]){
            return false;
        }

        return true;
    }

    bool paths[10000];
};



class Solution_HashTable {
public:
    enum NextEligibleMove{
        NORTH,
        SOUTH,
        WEST,
        EAST
    };
    bool exist(vector<vector<char> > &board, string word) {
        for (int y = 0; y < board.size(); ++y){
            for (int x = 0; x < board[y].size(); ++x){
                this->paths.insert(makeKey(x, y));
                if (backTracking(board, word, x, y, 0)){
                    return true;
                }
                this->paths.erase(makeKey(x, y));
            }
        }
        return false;
    }

    bool backTracking(vector<vector<char> > &board, string& word, int x, int y, int currIdxInWord){
        vector<NextEligibleMove> candidates;
        if (reject(board, word, x, y, currIdxInWord, candidates)){
            return false;
        }

        if (accept(word, currIdxInWord)){
            return true;
        }

        // recursive
        for (auto &c : candidates){
            switch (c){
            case NORTH:
                this->paths.insert(makeKey(x, y - 1));
                if (backTracking(board, word, x, y - 1, currIdxInWord + 1)){
                    return true;
                }
                this->paths.erase(makeKey(x, y - 1));
                break;
            case SOUTH:
                this->paths.insert(makeKey(x, y + 1));
                if (backTracking(board, word, x, y + 1, currIdxInWord + 1)){
                    return true;
                }
                this->paths.erase(makeKey(x, y + 1));
                break;
            case WEST:
                this->paths.insert(makeKey(x - 1, y));
                if (backTracking(board, word, x - 1, y, currIdxInWord + 1)){
                    return true;
                }
                this->paths.erase(makeKey(x - 1, y));
                break;
            case EAST:
                this->paths.insert(makeKey(x + 1, y));
                if (backTracking(board, word, x + 1, y, currIdxInWord + 1)){
                    return true;
                }
                this->paths.erase(makeKey(x + 1, y));
                break;
            }
        }
        return false;
    }

    bool reject(vector<vector<char> > &board, string& word, int x, int y, int currIdxInWord, vector<NextEligibleMove>& candidates){
        if (board[y][x] != word[currIdxInWord]){
            return true;
        }

        if (currIdxInWord < word.size() - 1){
            if (isAvailable(board, x, y - 1) && (word[currIdxInWord + 1] == board[y - 1][x])){
                candidates.push_back(NORTH);
            }
            if (isAvailable(board, x, y + 1) && (word[currIdxInWord + 1] == board[y + 1][x])){
                candidates.push_back(SOUTH);
            }
            if (isAvailable(board, x - 1, y) && (word[currIdxInWord + 1] == board[y][x - 1])){
                candidates.push_back(WEST);
            }
            if (isAvailable(board, x + 1, y) && (word[currIdxInWord + 1] == board[y][x + 1])){
                candidates.push_back(EAST);
            }

            if (candidates.size() == 0){
                return true;
            }
        }
        return false;
    }

    inline bool accept(string& word, int currIdxInWord){
        return (currIdxInWord == word.size() - 1);
    }

    bool isAvailable(vector<vector<char> > &board, int x, int y){
        if ((x < 0) || (y < 0)){
            return false;
        }

        if (y >= board.size()){
            return false;
        }

        if (x >= board[y].size()){
            return false;
        }

        if (this->paths.find(makeKey(x, y)) != this->paths.end()){
            return false;
        }

        return true;
    }

    inline unsigned long long makeKey(int x, int y){
        unsigned long long output = 0;
        output = ((unsigned long long)y) << (sizeof(int) << 3);
        output += x;
        return output;
    }

    unordered_set<unsigned long long> paths;
};