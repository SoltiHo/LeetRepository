// Given a collection of candidate numbers(C) and a target number(T), find all unique combinations in C where the candidate numbers sums to T.
// 
// Each number in C may only be used once in the combination.
// 
// Note:
// All numbers(including target) will be positive integers.
// Elements in a combination(a1, a2, ..., ak) must be in non - descending order. (ie, a1 <= a2 <= ... <= ak).
// The solution set must not contain duplicate combinations.
// For example, given candidate set 10, 1, 2, 7, 6, 1, 5 and target 8,
// A solution set is :
// [1, 7]
// [1, 2, 5]
// [2, 6]
// [1, 1, 6]
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int>> output;
        vector<int> buffer;
        sort(num.begin(), num.end());
        recursive(output, num, buffer, target, 0);

        return output;
    }


    void recursive(vector<vector<int>>& output, vector<int>& candidates, vector<int>& buffer, int target, int firstIdx){
        if (target == 0){
            output.push_back(buffer);
        }
        else{
            for (int i = firstIdx; i < candidates.size(); ++i){
                if (candidates[i] > target){
                    // no need to continue
                    break;
                }

                if (((i > firstIdx) && (candidates[i] != candidates[i - 1])) || (i == firstIdx)){
                    buffer.push_back(candidates[i]);
                    recursive(output, candidates, buffer, target - candidates[i], i + 1);
                    buffer.pop_back();
                }
            }
        }
    }
};