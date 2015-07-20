// Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.
// 
// For example, given the following matrix :
// 
//   1 0 1 0 0
//   1 0 1 1 1
//   1 1 1 1 1
//   1 0 0 1 0
//   Return 4.

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


class Solution_Refine { // 12ms
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int output = 0;
        const int rowCount = matrix.size();
        if (rowCount > 0){
            const int columnCount = matrix[0].size();
            int maxSize = 0;
            vector<vector<int>> squareSizes(rowCount, vector<int>(columnCount, 0));
            for (int rowIdx = 0; rowIdx < rowCount; ++rowIdx){
                for (int colIdx = 0; colIdx < columnCount; ++colIdx){
                    if (matrix[rowIdx][colIdx] == '1'){
                        int largestPossibleSize = 1; 
                        if ((colIdx > 0) && (rowIdx > 0)){
                            largestPossibleSize += min(squareSizes[rowIdx - 1][colIdx], squareSizes[rowIdx][colIdx - 1]);
                            largestPossibleSize = min(largestPossibleSize, squareSizes[rowIdx - 1][colIdx - 1] + 1);
                        }
                        squareSizes[rowIdx][colIdx] = largestPossibleSize; // changes the meaning of the cell
                        maxSize = max(maxSize, largestPossibleSize);
                    }
                }
            }

            output = maxSize * maxSize;
        }
        return output;
    }
};

class Solution { // 16ms
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int output = 0;
        const int rowCount = matrix.size();
        if (rowCount > 0){
            const int columnCount = matrix[0].size();
            vector<vector<int>> horizontalAccu(rowCount, vector<int>(columnCount, 0));
            vector<vector<int>> verticalAccu(rowCount, vector<int>(columnCount, 0));
            for (int rowIdx = 0; rowIdx < rowCount; ++rowIdx){
                for (int colIdx = 0; colIdx < columnCount; ++colIdx){
                    if (matrix[rowIdx][colIdx] == '1'){
                        horizontalAccu[rowIdx][colIdx] = 1 + (colIdx > 0 ? horizontalAccu[rowIdx][colIdx - 1] : 0);
                        verticalAccu[rowIdx][colIdx] = 1 + (rowIdx > 0 ? verticalAccu[rowIdx - 1][colIdx] : 0);
                    }
                }
            }

            // start calculating square
            int maxSize = 0;
            for (int rowIdx = 0; rowIdx < rowCount; ++rowIdx){
                for (int colIdx = 0; colIdx < columnCount; ++colIdx){
                    if (matrix[rowIdx][colIdx] == '1'){
                        int largestPossibleSize = min(horizontalAccu[rowIdx][colIdx], verticalAccu[rowIdx][colIdx]);
                        if ((colIdx > 0) && (rowIdx > 0)){
                            largestPossibleSize = min(largestPossibleSize, horizontalAccu[rowIdx - 1][colIdx - 1] + 1);
                        }
                        horizontalAccu[rowIdx][colIdx] = largestPossibleSize; // changes the meaning of the cell
                        maxSize = max(maxSize, largestPossibleSize);
                    }
                }
            }

            output = maxSize * maxSize;
        }
        return output;
    }
};