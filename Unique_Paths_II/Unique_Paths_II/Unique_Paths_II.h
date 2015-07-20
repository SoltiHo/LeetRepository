// Follow up for "Unique Paths":
// 
// Now consider if some obstacles are added to the grids.How many unique paths would there be ?
// 
// An obstacle and empty space is marked as 1 and 0 respectively in the grid.
// 
// For example,
// There is one obstacle in the middle of a 3x3 grid as illustrated below.
// 
// [
//     [0, 0, 0],
//     [0, 1, 0],
//     [0, 0, 0]
// ]
// The total number of unique paths is 2.
#include <vector>
using namespace std;


class Solution_Latest {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int output = 0;
        const int rowCount = obstacleGrid.size();
        if (rowCount){
            const int colCount = obstacleGrid[0].size();
            if ((colCount > 0) && (obstacleGrid[0][0] != 1)){
                obstacleGrid[0][0] = 1; // seed, cannot be erased
                
                for (int rowIdx = 0; rowIdx < rowCount; ++rowIdx){
                    for (int colIdx = 0; colIdx < colCount; ++colIdx){
                        if (obstacleGrid[rowIdx][colIdx] == 1){
                            // obstacle, mark it to be 0. 
                            if ((rowIdx != 0) || (colIdx != 0)){
                                obstacleGrid[rowIdx][colIdx] = 0;
                            }
                        }
                        else{
                            // sum the path
                            obstacleGrid[rowIdx][colIdx] += (rowIdx > 0 ? obstacleGrid[rowIdx - 1][colIdx] : 0);
                            obstacleGrid[rowIdx][colIdx] += (colIdx > 0 ? obstacleGrid[rowIdx][colIdx - 1] : 0);
                        }
                    }
                }
                output = obstacleGrid[rowCount - 1][colCount - 1];
            }
        }
        return output;
    }
};

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        const int rowCount = obstacleGrid.size();
        const int colCount = obstacleGrid[0].size();

        obstacleGrid[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1; // seed
        for (int r = 1; r < rowCount; ++r){
            if (obstacleGrid[r][0] == 1){
                obstacleGrid[r][0] = 0;
            }
            else{
                obstacleGrid[r][0] = obstacleGrid[r - 1][0];
            }
        }

        for (int c = 1; c < colCount; ++c){
            if (obstacleGrid[0][c] == 1){
                obstacleGrid[0][c] = 0;
            }
            else{
                obstacleGrid[0][c] = obstacleGrid[0][c - 1];
            }
        }

        for (int c = 1; c < colCount; ++c){
            for (int r = 1; r < rowCount; ++r){
                if (obstacleGrid[r][c] == 1){
                    obstacleGrid[r][c] = 0;
                }
                else{
                    obstacleGrid[r][c] = obstacleGrid[r - 1][c] + obstacleGrid[r][c - 1];
                }
            }
        }

        return obstacleGrid[rowCount - 1][colCount - 1];
    }
};