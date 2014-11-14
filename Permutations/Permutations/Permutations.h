//  Given a collection of numbers, return all possible permutations.
//  
//  For example,
//  [1, 2, 3] have the following permutations :
//  [1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], and[3, 2, 1].


#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int> &num) {
        // sort first, easier to deal with duplicated numbers
        sort(num.begin(), num.end());

        vector<int> selected;
        solveByRecursive(selected, num);

        return this->output;
    }

    void solveByRecursive(vector<int> selected, vector<int> candidates){
        if (candidates.size() == 0){
            this->output.push_back(selected);
        }
        else{
            int temp = 0;
            for (int i = 0; i < candidates.size(); ++i){
                if ((i > 0) && (candidates[i] == candidates[i - 1])){
                    continue;

                }
                temp = candidates[i];
                selected.push_back(temp);
                candidates.erase(candidates.begin() + i);
                solveByRecursive(selected, candidates);
                // restore
                selected.pop_back();
                candidates.insert(candidates.begin() + i, temp);
            }
        }
    }
    vector<vector<int>> output;
};

