// Find all possible combinations of k numbers that add up to a number n, 
// given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
// 
// Ensure that numbers within the set are sorted in ascending order.
// 
// 
// Example 1:
// 
// Input : k = 3, n = 7
// 
// Output :
// 
//        [[1, 2, 4]]
// 
//         Example 2 :
// 
//         Input : k = 3, n = 9
// 
//             Output :
// 
//                    [[1, 2, 6], [1, 3, 5], [2, 3, 4]]
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> output;
        vector<int> buffer;
        FindCombination(output, buffer, k, n, 0, 1);
        return output;
    }

    void FindCombination(vector<vector<int>>& output, vector<int>& buffer, const int k, const int n, const int currSum, const int currIdx){
        // invariant: currIdx is not yet included.
        if (buffer.size() == k){
            // no need to proceed
            if (currSum == n){
                output.push_back(buffer);
            }
        }
        else{
            // not enough
            for (int i = currIdx; i <= 9; ++i){
                if (n - currSum >= currIdx){
                    buffer.push_back(i);
                    FindCombination(output, buffer, k, n, currSum + i, i + 1);
                    buffer.pop_back();
                }
                else{
                    // no need to check more, because it's going bigger.
                    break;
                }
            }
        }
    }
};