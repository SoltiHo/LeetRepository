// Given a set of candidate numbers(C) and a target number(T), find all unique combinations in C where the candidate numbers sums to T.
// 
// The same repeated number may be chosen from C unlimited number of times.
// 
// Note:
// All numbers(including target) will be positive integers.
// Elements in a combination(a1, a2, ..., ak) must be in non - descending order. (ie, a1 >= a2 >= ... >= ak).
// The solution set must not contain duplicate combinations.
// For example, given candidate set 2, 3, 6, 7 and target 7,
// A solution set is :
// [7]
// [2, 2, 3]

#include <vector>
#include <algorithm>
using namespace std;



class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> output;
        if (candidates.size() > 0){
            sort(candidates.begin(), candidates.end());
            vector<int> buffer;
            findCombination(candidates, target, 0, 0, buffer, output);
        }
        return output;
    }

    void findCombination(vector<int>& candidates, int target, int currSum, int currIdx, vector<int>& buffer, vector<vector<int>>& output){
        if (currSum == target){
            output.push_back(buffer);
        }

        while ((currIdx < candidates.size()) && (candidates[currIdx] <= target - currSum)){
            buffer.push_back(candidates[currIdx]);
            findCombination(candidates, target, currSum + candidates[currIdx], currIdx, buffer, output);
            buffer.pop_back();
            currIdx++;
        }
    }
};


class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> output;
        vector<int> buffer;
        sort(candidates.begin(), candidates.end());
        recursive(output, candidates, buffer, target, 0);

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
                    recursive(output, candidates, buffer, target - candidates[i], i);
                    buffer.pop_back();
                }
            }
        }
    }
};