// Determine if a Sudoku is valid, according to : Sudoku Puzzles - The Rules.
// 
// The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
// 
// 
// A partially filled sudoku which is valid.
// 
// Note :
//      A valid Sudoku board(partially filled) is not necessarily solvable.Only the filled cells need to be validated.

#include <vector>
using namespace std;
class SolutionLatestTrial {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool> existed(9, false);
        // check rows
        for (int rowIdx = 0; rowIdx < 9; rowIdx++){
            existed.assign(9, false);
            for (int colIdx = 0; colIdx < 9; colIdx++){
                if (board[rowIdx][colIdx] != '.'){
                    int currNumberIdx = board[rowIdx][colIdx] - '1'; // 1 map to idx 0
                    if (existed[currNumberIdx]){
                        // already exist
                        return false;
                    }
                    else{
                        existed[currNumberIdx] = true;
                    }
                }
                
            }
        }

        // check columns
        for (int colIdx = 0; colIdx < 9; colIdx++){
            existed.assign(9, false);
            for (int rowIdx = 0; rowIdx < 9; rowIdx++){
                if (board[rowIdx][colIdx] != '.'){
                    int currNumberIdx = board[rowIdx][colIdx] - '1'; // 1 map to idx 0
                    if (existed[currNumberIdx]){
                        // already exist
                        return false;
                    }
                    else{
                        existed[currNumberIdx] = true;
                    }
                }

            }
        }

        // check zooms
        for (int zoomIdx = 0; zoomIdx < 9; zoomIdx++){
            existed.assign(9, false);
            for (int zoomElementIdx = 0; zoomElementIdx < 9; zoomElementIdx++){
                int colIdx = (zoomIdx % 3) * 3 + (zoomElementIdx) % 3;  // 0, 3, 6 --> 0;  1, 4, 7 --> 1;  2, 5, 8 --> 2;
                int rowIdx = (zoomIdx / 3) * 3 + (zoomElementIdx) / 3;  // 0, 1, 2 --> 0;  3, 4, 5 --> 1;  6, 7, 8 --> 2;
                if (board[rowIdx][colIdx] != '.'){
                    int currNumberIdx = board[rowIdx][colIdx] - '1'; // 1 map to idx 0
                    if (existed[currNumberIdx]){
                        // already exist
                        return false;
                    }
                    else{
                        existed[currNumberIdx] = true;
                    }
                }
            }
        }
        return true;
    }
};
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        bool result = true; // default to true, if anything violates, change to false

        bool** columnHashTable;
        bool** rowHashTable;
        bool** sectorHashTable;

        columnHashTable = new bool*[9];
        rowHashTable = new bool*[9];
        sectorHashTable = new bool*[9];

        for (int i = 0; i < 9; ++i){
            columnHashTable[i] = new bool[9]();
            rowHashTable[i] = new bool[9]();
            sectorHashTable[i] = new bool[9]();
        }

        for (int row = 0; row < 9; ++row){
            for (int column = 0; column < 9; ++column){
                if (board[row][column] != '.'){
                    // non-empty cell, check if already exist
                    // check column
                    if (columnHashTable[column][board[row][column] - '1']){
                        // already exist
                        result = false;
                        break;
                    }
                    else{
                        columnHashTable[column][board[row][column] - '1'] = true;
                    }

                    // check row
                    if (rowHashTable[row][board[row][column] - '1']){
                        // already exist
                        result = false;
                        break;
                    }
                    else{
                        rowHashTable[row][board[row][column] - '1'] = true;
                    }

                    // check sector
                    if (sectorHashTable[(row / 3) * 3 + column / 3][board[row][column] - '1']){
                        // already exist
                        result = false;
                        break;
                    }
                    else{
                        sectorHashTable[(row / 3) * 3 + column / 3][board[row][column] - '1'] = true;
                    }
                }
            }
            if (!result){
                break;
            }
        }


        // recycle
        for (int i = 0; i < 9; ++i){
            delete[] columnHashTable[i];
            delete[] rowHashTable[i];
            delete[] sectorHashTable[i];
        }
        delete[] columnHashTable;
        delete[] rowHashTable;
        delete[] sectorHashTable;


        // return result
        return result;
    }
};