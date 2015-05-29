// Given an array of integers and an integer k, return true if and only if there are two distinct indices i and j in the array 
// such that nums[i] = nums[j] and the difference between i and j is at most k.
#include <vector>
#include <unordered_set>
using namespace std;


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> existing;
        for (int i = 0; (i < k) && (i < nums.size()); ++i){
            if (existing.count(nums[i]) != 0){
                return true;
            }
            existing.insert(nums[i]);
        }

        for (int i = k; i < nums.size(); ++i){
            if (existing.count(nums[i]) != 0){
                return true;
            }
            existing.insert(nums[i]);
            existing.erase(nums[i - k]);
        }

        return false;
    }
};