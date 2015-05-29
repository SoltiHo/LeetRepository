// Given an index k, return the kth row of the Pascal's triangle.
// 
// For example, given k = 3,
// Return[1, 3, 3, 1].
// 
// Note:
// Could you optimize your algorithm to use only O(k) extra space ?
#include <vector>
using namespace std;



class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> output(rowIndex + 1, 0);
        output[0] = 1;
        for (int i = 0; i < rowIndex; ++i){
            for (int j = rowIndex; j > 0; --j){
                output[j] += output[j - 1];
            }
        }

        return output;
    }
};



class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> output;

        if (rowIndex >= 0){
            vector<int> buffer[2];
            buffer[0].resize(rowIndex + 1, 0);
            buffer[1].resize(rowIndex + 1, 0);
            buffer[0][0] = 1;
            buffer[1][0] = 1;

            for (int rowCursor = 1; rowCursor <= rowIndex; ++rowCursor){
                for (int i = 1; i <= rowCursor; ++i){
                    buffer[rowCursor % 2][i] = buffer[(rowCursor - 1) % 2][i] + buffer[(rowCursor - 1) % 2][i - 1];
                }
            }
            output = buffer[rowIndex % 2];
        }
        
        return output;
    }
};