// Given a m x n grid filled with non - negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
// 
// Note: You can only move either down or right at any point in time.

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        const int rowCount = grid.size();
        const int colCount = grid[0].size();
        for (int r = 1; r < rowCount; ++r){
            grid[r][0] += grid[r - 1][0];
        }
        for (int c = 1; c < colCount; ++c){
            grid[0][c] += grid[0][c - 1];
        }

        for (int c = 1; c < colCount; ++c){
            for (int r = 1; r < rowCount; ++r){
                grid[r][c] += min(grid[r - 1][c], grid[r][c - 1]);
            }
        }

        return grid[rowCount - 1][colCount - 1];
    }
};