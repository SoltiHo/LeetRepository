// Note: This is an extension of House Robber.
//
// After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention.
// This time, all houses at this place are arranged in a circle.That means the first house is the neighbor of the last one.Meanwhile, 
// the security system for these houses remain the same as for those in the previous street.
//
// Given a list of non - negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int output = 0;
        if (nums.size() > 1){
            int all_prev1 = nums[0];
            int all_prev2 = 0;
            int firstExcluded_prev1 = 0;
            int firstExcluded_prev2 = 0;

            for (int i = 1; i < nums.size(); ++i){
                int all_new = max(all_prev1, all_prev2 + nums[i]);
                int firstExcluded_new = max(firstExcluded_prev1, firstExcluded_prev2 + nums[i]);
                all_prev2 = all_prev1;
                all_prev1 = all_new;
                firstExcluded_prev2 = firstExcluded_prev1;
                firstExcluded_prev1 = firstExcluded_new;
            }

            output = max(firstExcluded_prev1, all_prev2);
        }
        else if (nums.size() == 1){
            output = nums[0];
        }

        return output;
    }

};

