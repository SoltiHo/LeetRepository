// Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum >= s.If there isn't one, return 0 instead.
// 
// For example, given the array[2, 3, 1, 2, 4, 3] and s = 7,
// the subarray[4, 3] has the minimal length under the problem constraint.

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int shortestLength = INT_MAX;
        bool candidateFound = false;
        if (nums.size() > 0){
            int startIdx = 0;
            int endIdx = 0;
            int currSum = nums[0];
            while (endIdx < nums.size()){
                if (currSum < s){
                    endIdx++;
                    currSum += nums[endIdx];
                }
                else{
                    // meet the requirement
                    candidateFound = true;
                    shortestLength = min(shortestLength, endIdx - startIdx + 1);
                    currSum -= nums[startIdx];
                    startIdx++;
                }
            }
        }

        return candidateFound ? shortestLength : 0;
    }
};