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
#include <algorithm>

using namespace std;


class Solution_VerticalThenHorizontal {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool output = false;
        const int rowCount = matrix.size();
        if (rowCount){
            const int colCount = matrix[0].size();
            int targetRowIdx = BS_Vertical(matrix, 0, rowCount - 1, target);
            if (targetRowIdx != -1){
                output = binary_search(matrix[targetRowIdx].begin(), matrix[targetRowIdx].end(), target);
            }
        }
        return output;
    }

    int BS_Vertical(vector<vector<int>>& matrix, const int headIdx, const int tailIdx, const int target){
        // this is to find if the target's row idx, so returning int
        if (headIdx > tailIdx){
            return -1; // don't exist
        }

        int middleIdx = headIdx + ((tailIdx - headIdx) >> 1);
        if (matrix[middleIdx][0] <= target) {
            if ((middleIdx == matrix.size() - 1) || (matrix[middleIdx + 1][0] > target)){
                return middleIdx;
            }
            else{
                // go down
                return BS_Vertical(matrix, middleIdx + 1, tailIdx, target);
            }
        }
        else { // matrix[middleIdx][0] > target
            // go up
            return BS_Vertical(matrix, headIdx, middleIdx - 1, target);
        }
    }
};


class Solution_Treat2DLike1D {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool output = false;
        const int rowCount = matrix.size();
        if (rowCount){
            const int colCount = matrix[0].size();
            const int totalCount = rowCount * colCount;
            // do binary search
            output = BS(matrix, rowCount, colCount, 0, totalCount - 1, target);
        }
        return output;
    }


    bool BS(vector<vector<int>>& matrix, const int rowCount, const int colCount, const int head1DIdx, const int tail1DIdx, const int target){
        if (head1DIdx > tail1DIdx){
            // not found
            return false;
        }
        
        int middle1DIdx = head1DIdx + ((tail1DIdx - head1DIdx) >> 1);
        pair<int, int> middle2DIdx = translate(middle1DIdx, rowCount, colCount);
        if (matrix[middle2DIdx.first][middle2DIdx.second] == target){
            // found
            return true;
        }
        else if (matrix[middle2DIdx.first][middle2DIdx.second] < target){
            return BS(matrix, rowCount, colCount, middle1DIdx + 1, tail1DIdx, target);
        }
        else{
            return BS(matrix, rowCount, colCount, head1DIdx, middle1DIdx - 1, target);
        }
    }


    pair<int, int> translate(const int idxIn1D, const int rowCount, const int colCount){
        pair<int, int> output;
        output.first = idxIn1D / colCount;
        output.second = idxIn1D - colCount * output.first;
        return output;
    }
};


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