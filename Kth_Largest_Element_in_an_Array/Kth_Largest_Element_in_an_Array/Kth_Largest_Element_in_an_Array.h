// Find the kth largest element in an unsorted array.Note that it is the kth largest element in the sorted order, not the kth distinct element.
// 
// For example,
// Given[3, 2, 1, 5, 6, 4] and k = 2, return 5.
// 
// Note:
// You may assume k is always valid, 1 <= k <= array's length.
#include <vector>
#include <ctime>
using namespace std;


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        const int arraySize = nums.size();
        const int targetSortedIdx = arraySize - k;

        srand(time(NULL));
        int currArrayStartIdx = 0;
        int currArrayEndIdx = arraySize - 1;  // search range: currArrayStartIdx ~ currArrayEndIdx, inclusive

        while (currArrayStartIdx <= currArrayEndIdx){
            int pivotOffset = rand() % (currArrayEndIdx - currArrayStartIdx + 1);
            swap(nums[currArrayStartIdx], nums[currArrayStartIdx + pivotOffset]);
            int firstLargerThanPivotIdx = currArrayStartIdx;

            for (int i = currArrayStartIdx + 1; i <= currArrayEndIdx; ++i){
                if (nums[i] <= nums[currArrayStartIdx]){
                    firstLargerThanPivotIdx++;
                    swap(nums[firstLargerThanPivotIdx], nums[i]);
                }
            }
            // move pivot to firstLargerThanPivotIdx
            swap(nums[firstLargerThanPivotIdx], nums[currArrayStartIdx]);

            if (firstLargerThanPivotIdx == targetSortedIdx){
                return nums[firstLargerThanPivotIdx];
            }
            else if (firstLargerThanPivotIdx < targetSortedIdx){
                // go to right
                currArrayStartIdx = firstLargerThanPivotIdx + 1;
            }
            else{
                // go to left
                currArrayEndIdx = firstLargerThanPivotIdx - 1;
            }
        }
    }
};