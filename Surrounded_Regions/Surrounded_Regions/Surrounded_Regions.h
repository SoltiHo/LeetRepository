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

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        this->boardHeight = board.size();
        if (this->boardHeight){
            this->boardWidth = board[0].size();
            if (this->boardWidth){
                for (int i = 0; i < boardWidth; ++i){
                    if (board[0][i] == 'O'){
                        board[0][i] = 'P';
                        markSurviver(board, 0, i);
                    }
                }

                for (int i = 1; i < boardHeight; ++i){
                    if (board[i][boardWidth - 1] == 'O'){
                        board[i][boardWidth - 1] = 'P';
                        markSurviver(board, i, boardWidth - 1);
                    }
                }

                for (int i = 0; i < boardWidth - 1; ++i){
                    if (board[boardHeight - 1][i] == 'O'){
                        board[boardHeight - 1][i] = 'P';
                        markSurviver(board, boardHeight - 1, i);
                    }
                }

                for (int i = 1; i < boardHeight - 1; ++i){
                    if (board[i][0] == 'O'){
                        board[i][0] = 'P';
                        markSurviver(board, i, 0);
                    }
                }


                for (auto& r : board){
                    for (auto& c : r){
                        if (c == 'O'){
                            c = 'X';
                        }
                        else if (c == 'P'){
                            c = 'O';
                        }
                    }
                }

            }
        }
        
    }

    void markSurviver(vector<vector<char>> &board, int rowIdx, int colIdx){
        vector<pair<int, int>> buffer;
        pair<int, int> temp = { rowIdx, colIdx };
        buffer.push_back(temp);
        while (buffer.size() > 0){
            temp = buffer[0];
            buffer.erase(buffer.begin());
            if ((temp.first - 1 >= 0) && (board[temp.first - 1][temp.second] == 'O')){
                board[temp.first - 1][temp.second] = 'P';
                buffer.push_back({temp.first - 1, temp.second});
            }
            if ((temp.first + 1 <= boardHeight - 1) && (board[temp.first + 1][temp.second] == 'O')){
                board[temp.first + 1][temp.second] = 'P';
                buffer.push_back({ temp.first + 1, temp.second });
            }
            if ((temp.second - 1 >= 0) && (board[temp.first][temp.second - 1] == 'O')){
                board[temp.first][temp.second - 1] = 'P';
                buffer.push_back({ temp.first, temp.second - 1});
            }
            if ((temp.second + 1 <= boardWidth - 1) && (board[temp.first][temp.second + 1] == 'O')){
                board[temp.first][temp.second + 1] = 'P';
                buffer.push_back({ temp.first, temp.second + 1 });
            }
        }
    }

    int boardWidth;
    int boardHeight;
};