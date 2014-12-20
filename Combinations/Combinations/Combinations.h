// Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
// 
// For example,
// If n = 4 and k = 2, a solution is :
// 
// [
//     [2, 4],
//     [3, 4],
//     [2, 3],
//     [1, 2],
//     [1, 3],
//     [1, 4],
// ]
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        if ((n > 0) && (k > 0)){
            bool* candidates = new bool[n];
            memset(candidates, 0, sizeof(bool)* n);
            vector<int> buffer;
            permutation(candidates, n, 0, buffer, k);
            delete[] candidates;
        }

        return this->output;
    }

    void permutation(bool* candidates, const int candidateCount, const int startIdx, vector<int>& buffer, const int depth){
        if (buffer.size() == depth){
            this->output.push_back(buffer);
        }
        else{
            for (int i = startIdx; i < candidateCount; ++i){
                if (!candidates[i]){
                    candidates[i] = true;
                    buffer.push_back(i + 1);
                    permutation(candidates, candidateCount, i + 1, buffer, depth);
                    buffer.pop_back();
                    candidates[i] = false;
                }
            }
        }
    }
    vector<vector<int>> output;
};