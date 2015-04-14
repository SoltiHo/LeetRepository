// Rotate an array of n elements to the right by k steps.
// 
// For example, with n = 7 and k = 3, the array[1, 2, 3, 4, 5, 6, 7] is rotated to[5, 6, 7, 1, 2, 3, 4].
// 
// Note:
// Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
// 
// [show hint]
// 
// Hint :
//     Could you do it in - place with O(1) extra space ?

#include <algorithm>
using namespace std;

// [1, 2, 3]  0 --> no change
// [1, 2, 3]  1 --> [3, 1, 2]
// [1, 2, 3]  2 -->
class Solution {
public:
    void rotate(int nums[], int n, int k) {
        int offset = k % n; 
        int bufferStart = (n - offset) % n;  // % n is for offset = 0 case
        int srcIdx = 0;
        int dstIdx = bufferStart;
        while ((srcIdx < n) && (srcIdx != dstIdx)){
            swap(nums[srcIdx++], nums[dstIdx++]);
            if (dstIdx == n){
                dstIdx = bufferStart;
            }
            if (srcIdx == bufferStart){
                bufferStart = dstIdx;
            }
        }
    }
};


class Solution {
public:
    void rotate(int nums[], int n, int k) {
        k = k % n;
        if (k > 0){
            int* temp = new int[n - k];
            memcpy(temp, nums, sizeof(int)* (n - k));

            // might overlap
            if ((k << 1) <= n){
                // no overlop
                memcpy(nums, nums + n - k, sizeof(int)* k);
            }
            else{
                // overlap
                for (int i = 0; i < k; ++i){
                    nums[i] = nums[i + n - k];
                }
            }

            memcpy(nums + k, temp, sizeof(int)* (n - k));
        }
    }
};



