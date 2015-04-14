// Given a 2d grid map of '1's(land) and '0's(water), count the number of islands.An island is surrounded by water and
// is formed by connecting adjacent lands horizontally or vertically.You may assume all four edges of the grid are all surrounded by water.
//
//Example 1:
//  11110
//  11010
//  11000
//  00000
// Answer : 1
//
//
// Example 2 : 
//  11000
//  11000
//  00100
//  00011
// Answer : 3
#include <vector>
#include <unordered_set>
using namespace std;


class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        int numOfIslands = 0;
        for (int i = 0; i < grid.size(); ++i){
            for (int j = 0; j < grid[0].size(); ++j){
                if (grid[i][j] == '1'){
                    numOfIslands++;
                    eraseIsland(i, j, grid);
                }
            }
        }
        return numOfIslands;
    }

    void eraseIsland(const int i, const int j, vector<vector<char>> &grid){
        grid[i][j] = '0';
        // up
        if ((i - 1 >= 0) && (grid[i - 1][j] == '1')){
            eraseIsland(i - 1, j, grid);
        }

        // down
        if ((i + 1 < grid.size()) && (grid[i + 1][j] == '1')){
            eraseIsland(i + 1, j, grid);
        }

        // left
        if ((j - 1 >= 0) && (grid[i][j - 1] == '1')){
            eraseIsland(i, j - 1, grid);
        }

        // right
        if ((j + 1 < grid[0].size()) && (grid[i][j + 1] == '1')){
            eraseIsland(i, j + 1, grid);
        }
    }
};

