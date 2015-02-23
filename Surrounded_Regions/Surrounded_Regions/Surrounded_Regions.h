// Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
// 
// A region is captured by flipping all 'O's into 'X's in that surrounded region.
// 
// For example,
// X X X X
// X O O X
// X X O X
// X O X X
// After running your function, the board should be :
// 
// X X X X
// X X X X
// X X X X
// X O X X
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// take recursive way, if a 'O' can finally reaches boundary, then the 'O' along the path can stay, otherwise modify to 'X'
// to avoid infinite loop, need to trace what's been on the path, so that no need to recursive on the 'O' already in path
class Solution {
public:
    void solve(vector<vector<char>> &board) {
        unordered_map<int, unordered_set<int>> path;
    }

    bool checkO(vector<vector<char>>& board, unordered_map<int, unordered_set<int>>& path, const int x, const int y, const int from){
        // from = 1, from left
        // from = 2, from top
        // from = 3, from right
        // from = 4, from bottom
        
        bool result = false;
        path[y].insert(x);
        // try right
        if ((board[y][x + 1] == 'O') && (from != 3) && (existOnThePath(path, x + 1, y) == false)){
            // recurse on the right 'O'
            if (checkO(board, path, x + 1, y, 1)){
                result = true;
            }
        }
        // try bottom
        else if ((board[y + 1][x] == 'O') && (from != 4) && (existOnThePath(path, x, y + 1) == false)){
            // recurse on the right 'O'
            path[y].insert(x);
            if (checkO(board, path, x + 1, y, 1)){
                return true;
            }
        }
    }

    bool existOnThePath(unordered_map<int, unordered_set<int>>& path, const int x, const int y){
        // y first and then x
        if (path.count(y) == 0){
            // not exist
            return false;
        }
        else if (path[y].count(x) == 0){
            // not exist
            return false;
        }
        else{
            return true;
        }
    }

    void pushToPath(unordered_map<int, unordered_set<int>>& path, const int x, const int y){
        path[y].insert(x);
    }
};