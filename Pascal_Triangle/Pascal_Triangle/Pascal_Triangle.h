// Given numRows, generate the first numRows of Pascal's triangle.
// 
// For example, given numRows = 5,
// Return
// 
// [
//     [1],
//     [1, 1],
//     [1, 2, 1],
//     [1, 3, 3, 1],
//     [1, 4, 6, 4, 1]
// ]

#include <vector>
using namespace std;

// --->
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> output;
        if (numRows > 0){
            // insert the seed
            output.resize(numRows, vector<int>(1, 0));
            output[0].push_back(1);
            output[0].push_back(0);

            // generate the remaining rows
            int rowIdx = 1;
            while (rowIdx < numRows){
                for (int colIdx = 1; colIdx <= rowIdx + 1; ++colIdx){
                    output[rowIdx].push_back(output[rowIdx - 1][colIdx] + output[rowIdx - 1][colIdx - 1]);
                }
                output[rowIdx].push_back(0);
                rowIdx++;
            }
            
            // remove the placeholders
            for (auto& r : output){
                r.pop_back();
                r.erase(r.begin());
            }
        }
        return output;
    }
};


class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> output;
        if (numRows > 0){
            // insert the seed
            output.resize(numRows, vector<int>(1, 1));
            
            // generate the remaining rows
            int rowIdx = 1;
            while (rowIdx < numRows){
                for (int colIdx = 1; colIdx < rowIdx; ++colIdx){
                    output[rowIdx].push_back(output[rowIdx - 1][colIdx] + output[rowIdx - 1][colIdx - 1]);
                }
                output[rowIdx++].push_back(1);
            }
        }
        return output;
    }
};