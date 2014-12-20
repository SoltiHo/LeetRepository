// Given a set of distinct integers, S, return all possible subsets.
// 
// Note:
// Elements in a subset must be in non - descending order.
// The solution set must not contain duplicate subsets.
// For example,
// If S = [1, 2, 3], a solution is :
// 
// [
//     [3],
//     [1],
//     [2],
//     [1, 2, 3],
//     [1, 3],
//     [2, 3],
//     [1, 2],
//     []
// ]
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        const int Scount = S.size();
        vector<vector<int>> output;
        if (Scount > 0){
            sort(S.begin(), S.end());
            const int outputSize = (1 << Scount) - 1;
            output.resize(outputSize);

            int originalSize = 0;
            int newSize = 0;
            output[0].push_back(S[0]);  // seed
            for (int i = 1; i < Scount; ++i){
                originalSize = (1 << i) - 1;
                newSize = originalSize << 1;
                copy(output.begin(), output.begin() + originalSize, output.begin() + originalSize);
                for (int j = originalSize; j < newSize; ++j){
                    output[j].push_back(S[i]);
                }
                output[(1 << (i + 1)) - 2].push_back(S[i]);
            }
        }
        output.push_back({});
        return output;
    }
};