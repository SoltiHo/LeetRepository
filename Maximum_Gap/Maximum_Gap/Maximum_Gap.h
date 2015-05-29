// Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
// 
// Try to solve it in linear time / space.
// 
// Return 0 if the array contains less than 2 elements.
// 
// You may assume all elements in the array are non - negative integers and fit in the 32 - bit signed integer range.
// 

#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int minValue = INT_MAX;
        int maxValue = INT_MIN;
        for (auto n : nums){
            minValue = min(minValue, n);
            maxValue = max(maxValue, n);
        }

        int bucketCount = (nums.size() - 1);
        int bucketSize = (maxValue - minValue) / bucketCount;
        vector<int> leftBoundary(bucketCount, )
    }
};

// not my algorithm
class Solution {
public:
    int maximumGap(vector<int> &num) {
        const int numCount = num.size();
        if (numCount <= 1){
            return 0;
        }
        else if (numCount == 2){
            return num[1] - num[0];
        }
        int numMin = INT_MAX;
        int numMax = INT_MIN;
        for (auto& i : num){
            numMin = min(numMin, i);
            numMax = max(numMax, i);
        }

        vector<int> minArray(numCount, INT_MAX);
        vector<int> maxArray(numCount, INT_MIN);
        const double cellDistance = ((double)numMax - numMin) / (numCount  - 1);
        int idx = 0;
        for (auto& i : num){
            idx = (int)((i - numMin) / cellDistance);
            minArray[idx] = min(minArray[idx], i);
            maxArray[idx] = max(maxArray[idx], i);
        }


        int maxDistance = 0;
        int lastMax = INT_MIN;
        for (int i = 0; i < numCount; ++i){
            if (minArray[i] == INT_MAX){
                // empty cell
                continue;
            }

            if (lastMax != INT_MIN){
                maxDistance = max(maxDistance, minArray[i] - lastMax);
            }
            lastMax = maxArray[i];
        }

        return maxDistance;
    }
};