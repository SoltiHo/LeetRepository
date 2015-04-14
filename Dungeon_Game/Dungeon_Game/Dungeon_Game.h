// The demons had captured the princess(P) and imprisoned her in the bottom - right corner of a dungeon.The dungeon consists of M x N rooms laid out in a 2D grid.
// Our valiant knight(K) was initially positioned in the top - left room and must fight his way through the dungeon to rescue the princess.
// 
// The knight has an initial health point represented by a positive integer.If at any point his health point drops to 0 or below, he dies immediately.
// 
// Some of the rooms are guarded by demons, so the knight loses health(negative integers) upon entering these rooms; 
// other rooms are either empty(0's) or contain magic orbs that increase the knight's health(positive integers).
// 
// In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.
// 
// 
// Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.
// 
// For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path RIGHT->RIGHT->DOWN->DOWN.
//
//
// -2(K)   -3     3
// -5      -10    1
// 10      30    -5 (P)
// 
// Notes:
// 
// The knight's health has no upper bound.
// Any room can contain threats or power - ups, even the first room the knight enters and the bottom - right room where the princess is imprisoned.
#include <vector>
#include <algorithm>
using namespace std;



class SolutionLatestTrial {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        const int rowCount = dungeon.size();
        const int colCount = dungeon[0].size();
        
        // handle the last cell
        dungeon[rowCount - 1][colCount - 1] = minHealthNeeded(dungeon[rowCount - 1][colCount - 1], 1);

        // handle the last row
        for (int colIdx = colCount - 2; colIdx >= 0; --colIdx){
            dungeon[rowCount - 1][colIdx] = minHealthNeeded(dungeon[rowCount - 1][colIdx], dungeon[rowCount - 1][colIdx + 1]);
        }

        // handle the last col
        for (int rowIdx = rowCount - 2; rowIdx >= 0; --rowIdx){
            dungeon[rowIdx][colCount - 1] = minHealthNeeded(dungeon[rowIdx][colCount - 1], dungeon[rowIdx + 1][colCount - 1]);
        }

        // handle the rest
        for (int rowIdx = rowCount - 2; rowIdx >= 0; --rowIdx){
            for (int colIdx = colCount - 2; colIdx >= 0; --colIdx){
                int exitCriteria = min(dungeon[rowIdx + 1][colIdx], dungeon[rowIdx][colIdx + 1]);
                dungeon[rowIdx][colIdx] = minHealthNeeded(dungeon[rowIdx][colIdx], exitCriteria);
            }
        }

        return dungeon[0][0];
    }

    inline int minHealthNeeded(int loading, int exitCondition){
        return (exitCondition - loading > 0 ? exitCondition - loading : 1);
    }
};

// for each cell (x, y), it could come from the top or the left.
// want to pursuve the max min sum during the path
// greedy on min seen so far is not enough because there might be big plus in future cells
// so not a simple DP, need to 
class SolutionWrong {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        const int rowCount = dungeon.size();
        const int columnCount = dungeon[0].size();

        // handle the last row
        for (int i = columnCount - 2; i >= 0; --i){
            dungeon[rowCount - 1][i] += dungeon[rowCount - 1][i + 1];
        }

        // handle the last column
        for (int i = rowCount - 2; i >= 0; --i){
            dungeon[i][rowCount - 1] += dungeon[i + 1][rowCount - 1];
        }

        // handle the rest
        for (int i = rowCount - 2; i >= 0; --i){
            for (int j = columnCount - 2; j >= 0; --j){
                if (dungeon[i + 1][j] > dungeon[i][j + 1]){
                    // take [i + 1][j]
                    dungeon[i][j] += dungeon[i + 1][j];
                }
                else{
                    // take [i][j + 1]
                    dungeon[i][j] += dungeon[i][j + 1];
                }
            }
        }

        // decide the min health
        return dungeon[0][0] >= 0 ? 1 : abs(dungeon[0][0]) + 1;
    }
};


class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        rowCount = dungeon.size();
        columnCount = dungeon[0].size();
        vector<vector<int>> minPathSum(rowCount);
        for (auto& r : minPathSum){
            r.resize(columnCount, 0);
        }

        // handle the first row
        minPathSum[0][0] = dungeon[0][0];
        for (int i = 1; i < columnCount; ++i){
            dungeon[0][i] += dungeon[0][i - 1];
            minPathSum[0][i] = min(minPathSum[0][i - 1], dungeon[0][i]);
        }

        // handle the first column
        for (int i = 1; i < rowCount; ++i){
            dungeon[i][0] += dungeon[i - 1][0];
            minPathSum[i][0] = min(minPathSum[i - 1][0], dungeon[i][0]);
        }

        if ((columnCount == 1) || (rowCount == 1)){
            minHealth = minPathSum[rowCount - 1][columnCount - 1] >= 0 ? 1 : abs(minPathSum[rowCount - 1][columnCount - 1]) + 1;
        }
        else{
            minHealth = INT_MAX;
            findMinHealth(dungeon, minPathSum, 1, 1);
        }

        return minHealth;
    }

    void findMinHealth(vector<vector<int>>& dungeon, vector<vector<int>>& minOnThePath, const int i, const int j){
        // base case
        if (i == rowCount){
            minHealth = min(minHealth, minOnThePath[rowCount - 1][columnCount - 1] >= 0 ? 1 : abs(minOnThePath[rowCount - 1][columnCount - 1]) + 1);
        }
        else{
            // recursive
            bool tryFromTop = false;
            bool tryFromLeft = false;
            if ((minOnThePath[i - 1][j] <= minOnThePath[i][j - 1]) && (dungeon[i - 1][j] <= dungeon[i][j - 1])){
                // chose [i][j - 1]
                tryFromLeft = true;
            }
            else if ((minOnThePath[i - 1][j] >= minOnThePath[i][j - 1]) && (dungeon[i - 1][j] >= dungeon[i][j - 1])){
                // chose [i - 1][j]
                tryFromTop = true;
            }
            else{
                // one is larger the other is smaller, try both 
                tryFromTop = true;
                tryFromLeft = true;
            }

            int originalDungeonValue = dungeon[i][j];
            if (tryFromTop){
                // try [i - 1][j]
                dungeon[i][j] += dungeon[i - 1][j];
                minOnThePath[i][j] = min(minOnThePath[i - 1][j], dungeon[i][j]);
                //if ((minOnThePath[i][j] >= 0) || (abs(minOnThePath[i][j]) < minHealth)){
                    findMinHealth(dungeon, minOnThePath, j == columnCount - 1 ? i + 1 : i, j == columnCount - 1 ? 1 : j + 1);
                //}
                dungeon[i][j] = originalDungeonValue;
            }

            if (tryFromLeft){
                // chose [i][j - 1]
                dungeon[i][j] += dungeon[i][j - 1];
                minOnThePath[i][j] = min(minOnThePath[i][j - 1], dungeon[i][j]);
                //if ((minOnThePath[i][j] >= 0) || (abs(minOnThePath[i][j]) < minHealth)){
                    findMinHealth(dungeon, minOnThePath, j == columnCount - 1 ? i + 1 : i, j == columnCount - 1 ? 1 : j + 1);
                //}
            }
        }
    }

    int minHealth;
    int rowCount;
    int columnCount;

};


