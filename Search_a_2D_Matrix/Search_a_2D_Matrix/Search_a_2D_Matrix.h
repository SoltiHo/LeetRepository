// Write an efficient algorithm that searches for a value in an m x n matrix.This matrix has the following properties :
// 
// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.
// For example,
// 
// Consider the following matrix :
// 
// [
//     [1, 3, 5, 7],
//     [10, 11, 16, 20],
//     [23, 30, 34, 50]
// ]
// Given target = 3, return true.
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        const int rowCount = matrix.size();
        const int columnCount = matrix[0].size();
        bool output = false;

        if ((rowCount) && (columnCount) && (target >= matrix[0][0]) && (target <= matrix[rowCount - 1][columnCount - 1])){
            // decide row number first, use binary search too
            int startIdx = 0;
            int endIdx = rowCount - 1;
            int middleIdx = 0;
            int rowNumber = rowCount - 1;
            while (true){
                middleIdx = (startIdx + endIdx) >> 1;
                if ((target >= matrix[startIdx][0]) && (target <= matrix[startIdx][columnCount - 1])){
                    rowNumber = startIdx;
                    break;
                }
                if ((target >= matrix[endIdx][0]) && (target <= matrix[endIdx][columnCount - 1])){
                    rowNumber = endIdx;
                    break;
                }
                if ((target >= matrix[middleIdx][0]) && (target <= matrix[middleIdx][columnCount - 1])){
                    rowNumber = middleIdx;
                    break;
                }

                if (target < matrix[middleIdx][0]){
                    startIdx = startIdx + 1;
                    endIdx = middleIdx - 1;
                }
                else{
                    startIdx = middleIdx + 1;
                    endIdx = endIdx - 1;
                }

                if (endIdx < startIdx){
                    break;
                }
            }

            // binary search within the row
            startIdx = 0;
            endIdx = columnCount - 1;
            middleIdx = 0;
            while (true){
                middleIdx = (startIdx + endIdx) >> 1;
                if ((matrix[rowNumber][startIdx] == target) || (matrix[rowNumber][endIdx] == target) || (matrix[rowNumber][middleIdx] == target)){
                    output = true;
                    break;
                }

                if (target > matrix[rowNumber][middleIdx]){
                    startIdx = middleIdx + 1;
                    endIdx = endIdx - 1;
                }
                else{
                    startIdx = startIdx + 1;
                    endIdx = middleIdx - 1;
                }

                if (endIdx < startIdx){
                    break;
                }
            }
        }

        return output;
    }
};