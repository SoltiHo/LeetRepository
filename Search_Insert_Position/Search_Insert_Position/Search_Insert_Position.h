// Given a sorted array and a target value, return the index if the target is found.If not, return the index where it would be if it were inserted in order.
// 
// You may assume no duplicates in the array.
// 
// Here are few examples.
// [1, 3, 5, 6], 5 --> 2
// [1, 3, 5, 6], 2 --> 1
// [1, 3, 5, 6], 7 --> 4
// [1, 3, 5, 6], 0 --> 0


class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int output = 0;
        if (n > 0){
            if (A[0] == target){
                output = 0;
            }
            else if (A[n - 1] == target){
                output = n - 1;
            }
            else if (target < A[0]){
                output = 0;
            }
            else if (target > A[n - 1]){
                output = n;
            }
            else{
                output = binarySearch(A, 0, n - 1, target);
            }
        }
        return output;
    }

    int binarySearch(const int A[], const int startIdx, const int endIdx, const int target){
        // invariant: A[startIdx] < target and A[endIdx] > target
        if (endIdx - startIdx == 1){
            // 2 elements only, target not exist
            return startIdx + 1;
        }

        const int middleIdx = (startIdx + endIdx) >> 1;
        // recursive
        if (target == A[middleIdx]){
            return middleIdx;
        }
        else if (target > A[middleIdx]){
            // go right
            return binarySearch(A, middleIdx, endIdx, target);
        }
        else{
            // go left
            return binarySearch(A, startIdx, middleIdx, target);
        }
    }
};