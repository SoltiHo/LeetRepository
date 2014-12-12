// Given n non - negative integers a1, a2, ..., an, where each represents a point at coordinate(i, ai).
// n vertical lines are drawn such that the two endpoints of line i is at(i, ai) and(i, 0).
// Find two lines, which together with x - axis forms a container, such that the container contains the most water.
//
// Note: You may not slant the container.
#include <vector>
#include <algorithm>
using namespace std;

// not my algorithm
class Solution {
public:
    int maxArea(vector<int> &height) {
        int i = 0;
        int j = height.size() - 1;
        int maxArea = INT_MIN;
        while (i < j){
            maxArea = max(maxArea, min(height[i], height[j]) * (j - i));
            if (height[i] > height[j]){
                j--;
            }
            else{
                i++;
            }
        }
        return maxArea;
    }
};