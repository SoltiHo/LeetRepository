// Given a matrix of m x n elements(m rows, n columns), return all elements of the matrix in spiral order.
// 
// For example,
// Given the following matrix :
// 
// [
//     [1, 2, 3],
//     [4, 5, 6],
//     [7, 8, 9]
// ]
// You should return[1, 2, 3, 6, 9, 8, 7, 4, 5].
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> output;
        if (matrix.size() > 0){
            const int rowCount = matrix.size();
            const int colCount = matrix[0].size();
            peelMatrix(matrix, output, 0, 0, rowCount, colCount);
        }
        return output;
    }

    void peelMatrix(vector<vector<int> > &matrix, vector<int>& output, const int startRowIdx, const int startColIdx, const int rowCount, const int colCount){
        for (int i = 0; i < colCount; ++i){
            output.push_back(matrix[startRowIdx][startColIdx + i]);
        }

        for (int i = 0; i < rowCount - 1; ++i){
            output.push_back(matrix[startRowIdx + 1 + i][startColIdx + colCount - 1]);
        }

        if (rowCount > 1){
            for (int i = 0; i < colCount - 1; ++i){
                output.push_back(matrix[startRowIdx + rowCount - 1][startColIdx + colCount - 2 - i]);
            }
        }

        if (colCount > 1){
            for (int i = 0; i < rowCount - 2; ++i){
                output.push_back(matrix[startRowIdx + rowCount - 2 - i][startColIdx]);
            }
        }

        if ((rowCount > 2) && (colCount > 2)){
            peelMatrix(matrix, output, startRowIdx + 1, startColIdx + 1, rowCount - 2, colCount - 2);
        }
    }
};