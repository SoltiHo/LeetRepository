// Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
// 
// Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
// 
// Note:
// You are not suppose to use the library's sort function for this problem.
// 
// click to show follow up.
// 
// Follow up :
// A rather straight forward solution is a two - pass algorithm using counting sort.
// First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
// 
// Could you come up with an one - pass algorithm using only constant space ?


#include <algorithm>
using namespace std;
class Solution {
public:
    void sortColors(int A[], int n) {
        int OneStartIdx = -1;
        int TwoStartIdx = -1;
        for (int i = 0; i < n; ++i){
            if (A[i] == 0){
                if (OneStartIdx > -1){
                    if (TwoStartIdx > -1){
                        swap(A[OneStartIdx], A[TwoStartIdx++]);
                    }
                    swap(A[i], A[OneStartIdx++]);
                }
                else if (TwoStartIdx > -1){
                    swap(A[i], A[TwoStartIdx++]);
                }
            }
            else if (A[i] == 1){
                if (OneStartIdx > -1){
                    if (TwoStartIdx > -1){
                        swap(A[i], A[TwoStartIdx++]);
                    }
                }
                else{
                    // first 1 ever
                    if (TwoStartIdx > -1){
                        swap(A[i], A[TwoStartIdx++]);
                        OneStartIdx = TwoStartIdx - 1;
                    }
                    else{
                        // no 2 either
                        OneStartIdx = i;
                    }
                }
            }
            else{
                // A[i] == 2
                if (TwoStartIdx == -1){
                    TwoStartIdx = i;
                }
            }
        } // end for loop
    }
};


