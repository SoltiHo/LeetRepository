// Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
// 
// click to show follow up.
// 
// Follow up :
// Did you use extra space ?
// A straight forward solution using O(mn) space is probably a bad idea.
// A simple improvement uses O(m + n) space, but still not the best solution.
// Could you devise a constant space solution ?

#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

// O(1) space
class Solution_ConstantSpace_Marking {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        const int rowCount = matrix.size();
        const int columnCount = matrix[0].size();
        srand(time(NULL));
        int mark = 0; 

        bool markFound = false;
        bool breakEarly = false;
        while (!markFound){
            mark = ((rand() - (RAND_MAX >> 1)) * RAND_MAX) + (rand() - (RAND_MAX >> 1));
            breakEarly = false;
            for (int r = 0; r < rowCount; ++r){
                for (int c = 0; c < columnCount; ++c){
                    if ((r == rowCount - 1) && (c == columnCount - 1) && (matrix[r][c] != mark)){
                        markFound = true;
                    }
                    if (matrix[r][c] == mark){
                        breakEarly = true;
                        break;
                    }
                }
                if (breakEarly){
                    break;
                }
            }
        }

        for (int r = 0; r < rowCount; ++r){
            for (int c = 0; c < columnCount; ++c){
                if (matrix[r][c] == 0){
                    markToBeSetZero(matrix, r, c, mark);
                }
            }
        }

        // update all marks to zero
        for (int r = 0; r < rowCount; ++r){
            for (int c = 0; c < columnCount; ++c){
                if (matrix[r][c] == mark){
                    matrix[r][c] = 0;
                }
            }
        }
    }

    // mark = INT_MIN
    void markToBeSetZero(vector<vector<int>>& matrix, const int rowIdx, const int colIdx, const int mark){
        for (auto& r : matrix){
            if (r[colIdx] != 0){
                r[colIdx] = mark;
            }
        }
        for (auto& c : matrix[rowIdx]){
            if (c != 0){
                c = mark;
            }
        }
    }
};

// O(m + n) space
class Solution_LinearSpace {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        const int rowCount = matrix.size();
        const int columnCount = matrix[0].size();
        bool* ColumnCheckTable = new bool[columnCount];
        memset(ColumnCheckTable, 0, sizeof(bool)*columnCount);
        bool* RowCheckTable = new bool[rowCount];
        memset(RowCheckTable, 0, sizeof(bool)*rowCount);
        for (int r = 0; r < rowCount; ++r){
            for (int c = 0; c < columnCount; ++c){
                if (matrix[r][c] == 0){
                    ColumnCheckTable[c] = true;
                    RowCheckTable[r] = true;
                }
            }
        }

        for (int i = 0; i < columnCount; ++i){
            if (ColumnCheckTable[i]){
                for (auto& r : matrix){
                    r[i] = 0;
                }
            }
        }
        for (int i = 0; i < rowCount; ++i){
            if (RowCheckTable[i]){
                memset(matrix[i].data(), 0, sizeof(int)*columnCount);
            }
        }
        delete[] ColumnCheckTable;
        delete[] RowCheckTable;
    }
};