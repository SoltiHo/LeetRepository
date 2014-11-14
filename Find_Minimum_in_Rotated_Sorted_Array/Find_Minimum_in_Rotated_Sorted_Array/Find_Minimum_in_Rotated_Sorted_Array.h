//  Suppose a sorted array is rotated at some pivot unknown to you beforehand.
//  
//  (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//  
//  Find the minimum element.
//  
//  You may assume no duplicate exists in the array.

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMin(vector<int> &num) {
        if (num.size() == 1){
            return num[0];
        }
        else if (num.size() == 2){
            return min(num[0], num[1]);
        }

        int pivotIdx = findPivot(num, 0, num.size());
        if (pivotIdx == -1){
            return num[0];
        }
        else{
            return num[pivotIdx];
        }
    }

    int findPivot(vector<int> &num, const int start, const int length){
        if (length <= 1){
            return -1;  // not found
        }
        else if (length == 2){
            if (num[start] > num[start + 1]){
                // found
                return (start + 1);
            }
            else{
                return -1;
            }
        }

        // recursive
        int middleIdx = start + (length >> 1);
        // true recursive
        if (num[start] > num[middleIdx]){
            // pivot in left
            return findPivot(num, start, (length >> 1) + 1);
        }
        else if (num[start] < num[middleIdx]){
            // pivot in right
            return findPivot(num, start + (length >> 1), length - (length >> 1));
        }
        else{
            // middle value == start value
            // need to further decide where the pivot is
            if (wholeIntervalFlat(num, start, (length >> 1) + 1)){
                // left is all flat, then pivot is in right
                return findPivot(num, start + (length >> 1), length - (length >> 1));
            }
            else{
                // right is all flat, then pivot is in left
                return findPivot(num, start, (length >> 1) + 1);
            }
        }
    }

    bool wholeIntervalFlat(vector<int> &num, const int start, const int length){
        const int compareBase = num[start + length - 1];
        for (int i = length; i; --i){
            if (compareBase != num[start + i - 1]){
                return false;
            }
        }
        return true;
    }
};