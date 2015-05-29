// Given an array of integers, find if the array contains any duplicates.
// Your function should return true if any value appears at least twice in the array, 
// and it should return false if every element is distinct.

#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> existing;
        for (auto i : nums){
            if (existing.count(i) > 0){
                return true;
            }
            existing.insert(i);
        }
        return false;
    }
};