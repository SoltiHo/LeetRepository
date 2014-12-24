// Given a sorted array of integers, find the starting and ending position of a given target value.
// 
// Your algorithm's runtime complexity must be in the order of O(log n).
// 
// If the target is not found in the array, return[-1, -1].
// 
// For example,
// Given[5, 7, 7, 8, 8, 10] and target value 8,
// return[3, 4].
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> output;
        output.push_back(-1);
        output.push_back(-1);

        if ((n > 0) && (target >= A[0]) && (target <= A[n - 1])) {
            int hit = 0;
            lowerBound = 0;
            upperBound = n - 1;
            hit = binarySearchTarget(A, 0, n - 1, target);
            if (hit != -1){
                // found
                output.clear();
                int lowerB = (A[this->lowerBound] == target) ? -1 : binarySearchBoundary(A, this->lowerBound, hit, target, false);
                int higherB = (A[this->upperBound] == target) ? n : binarySearchBoundary(A, hit, this->upperBound, target, true);
                output.push_back(lowerB + 1);
                output.push_back(higherB - 1);
            }
        }
        return output;
    }

    int binarySearchTarget(int A[], const int startIdx, const int endIdx, int target){
        // invariants: A[startIdx - 1] != target, A[endIdx + 1] != target.
        if (A[startIdx] == target){
            return startIdx;
        }
        else if (A[endIdx] == target){
            return endIdx;
        }
        else if (endIdx - startIdx <= 1){
            // no middle elements
            return -1;
        }

        int middleIdx = ((endIdx + startIdx) >> 1);
        if (A[middleIdx] == target){
            return middleIdx;
        }
        else if (A[middleIdx] > target){
            lowerBound = startIdx;
            upperBound = middleIdx;
            return binarySearchTarget(A, startIdx + 1, middleIdx - 1, target);
        }
        else{ // middle < target
            lowerBound = middleIdx;
            upperBound = endIdx;
            return binarySearchTarget(A, middleIdx + 1, endIdx - 1, target);
        }
    }

    // the return value is the 1st number NOT EQUAL to the target
    int binarySearchBoundary(int A[], const int startIdx, const int endIdx, int target, bool upperBound){
        // invariants for upperBound : A[startIdx] == target, A[endIdx] != target;
        // invariants for lowerBound: A[startIdx] != target, A[endIdx] == target;
        if (endIdx - startIdx == 1){
            return upperBound ? endIdx : startIdx;
        }

        int middleIdx = ((endIdx + startIdx) >> 1);
        if (((A[middleIdx] != target) && (upperBound)) || ((A[middleIdx] == target) && (!upperBound))){
            // go left
            return binarySearchBoundary(A, startIdx, middleIdx, target, upperBound);
        }
        else{
            // go right
            return binarySearchBoundary(A, middleIdx, endIdx, target, upperBound);
        }
    }

    int lowerBound;
    int upperBound;
};