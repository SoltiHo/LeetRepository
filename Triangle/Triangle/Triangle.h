// Given a triangle, find the minimum path sum from top to bottom.Each step you may move to adjacent numbers on the row below.
// 
// For example, given the following triangle
// [
//     [2],
//     [3, 4],
//     [6, 5, 7],
//     [4, 1, 8, 3]
// ]
// The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
// 
// Note:
// Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        const int vectorCount = triangle.size();

        vector<vector<int>> buffer;
        buffer.push_back({});
        buffer.push_back({});
        buffer[0].reserve(vectorCount + 1);
        buffer[1].reserve(vectorCount + 1);

        int bufferIdx = 0;
        int LastBufferIdx = 1;
        buffer[0].push_back(INT_MAX); // dummy seeds
        buffer[0].push_back(0);
        for (int i = 1; i <= vectorCount; ++i){
            bufferIdx = i % 2;
            LastBufferIdx = (i + 1) % 2;
            buffer[bufferIdx].clear();
            buffer[bufferIdx].push_back(INT_MAX); // dummy
            for (int j = 1; j <= i; ++j){
                buffer[bufferIdx].push_back(min(buffer[LastBufferIdx][j - 1], buffer[LastBufferIdx][j]) + triangle[i - 1][j - 1]);
            }
            buffer[bufferIdx].push_back(INT_MAX); // dummy
        }

        int minPathSum = INT_MAX;
        for (auto i : buffer[bufferIdx]){
            minPathSum = min(minPathSum, i);
        }

        return minPathSum;
    }
};