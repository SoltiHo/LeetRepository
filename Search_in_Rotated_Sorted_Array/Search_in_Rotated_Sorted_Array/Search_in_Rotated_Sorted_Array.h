//  Suppose a sorted array is rotated at some pivot unknown to you beforehand.
//  
//  (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//  
//  You are given a target value to search.If found in the array return its index, otherwise return -1.
//  
//  You may assume no duplicate exists in the array.

// if target is between the left half and right half, return -1
// if target < the first element of the left half, then continue to next level
// if target > the last element of the right half, then continue to next level

#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int search(int input[], int n, int target) {
        this->target = target;
        this->input = input;
        return binarySearch(0, n - 1);
    }

    int binarySearch(int startIdx, int endIdx){
        // base cases
        if (input[startIdx] == target){
            return startIdx;
        }
        else if (input[endIdx] == target){
            return endIdx;
        }
        
        const int currSize = endIdx - startIdx + 1;
        if (currSize <= 2){
            return -1;
        }
        

        // recursive
        const int middleIdx = (startIdx + endIdx) >> 1;
        if (input[middleIdx] == target){
            return middleIdx;
        }
        else{
            if (target > input[middleIdx]){
                if (input[startIdx] < input[endIdx]){
                    // normal array, not rotated
                    return binarySearch(middleIdx + 1, endIdx - 1);
                }
                else if ((input[middleIdx] > input[startIdx]) && (input[middleIdx] > input[endIdx])){
                    // min is at the right of middle point
                    return binarySearch(middleIdx + 1, endIdx - 1);
                }
                else{
                    // min is at the left of middle point
                    if (target > input[startIdx]){
                        return binarySearch(startIdx + 1, middleIdx - 1);
                    }
                    else{
                        return binarySearch(middleIdx + 1, endIdx - 1);
                    }
                }
            }
            else{
                // target < input[middleIdx]
                if (input[startIdx] < input[endIdx]){
                    // normal array, not rotated
                    return binarySearch(startIdx + 1, middleIdx - 1);
                }
                else if ((input[middleIdx] > input[startIdx]) && (input[middleIdx] > input[endIdx])){
                    // min is at the right of middle point
                    if (target < input[endIdx]){
                        return binarySearch(middleIdx + 1, endIdx - 1);
                    }
                    else{
                        return binarySearch(startIdx + 1, middleIdx - 1);
                    }
                }
                else{
                    // min is at the left of middle point
                    return binarySearch(startIdx + 1, middleIdx - 1);
                }
            }
        }
    }

    int target;
    int* input;
};

class Solution_FindCutFirst {
public:
    int search(int input[], int n, int target) {
        A = input;
        int pivotIdx = findPivotIdx(0, n);

        if (pivotIdx == -1){
            // a normal sorted array
            return binarySearch(0, n, target);
        }
        else if (A[pivotIdx] == target){
            return pivotIdx;
        }
        else{
            // A[pivotIdx] is the smallest
            if ((target > A[n - 1]) && (target <= A[pivotIdx - 1])){
                // in first part
                return binarySearch(0, pivotIdx, target);
            }
            else if ((target > A[pivotIdx]) && (target <= A[n - 1])){
                // in second part
                return binarySearch(pivotIdx + 1, n - 1 - pivotIdx, target);
            }
            else{
                return -1;
            }
        }
    }

    int findPivotIdx(int startIdx, int size){
        // let the pivot to be the true smallest element
        if (size <= 1){
            return -1;
        }
        else if (size == 2){
            if (A[startIdx] > A[startIdx + 1]){
                return startIdx + 1;
            }
            else{
                return -1;
            }
        }
        else{
            // more than 2 elements
            if (A[startIdx + 1] < A[startIdx]){
                return startIdx + 1;
            }
            else if (A[startIdx + size - 1] < A[startIdx + size - 2]){
                return startIdx + size - 1;
            }
        }

        // recursive
        int middleIdx = startIdx + (size >> 1);
        int headIdx = startIdx;
        int tailIdx = startIdx + size - 1;
        if ((A[middleIdx] < A[tailIdx]) && (A[middleIdx] < A[middleIdx - 1])){
            // middle idx is the pivot
            return middleIdx;
        }
        else if (A[middleIdx] > A[middleIdx + 1]){
            return middleIdx + 1;
        }
        else if ((A[headIdx] > A[middleIdx]) && (A[middleIdx] < A[tailIdx])){
            // pivot is in the left, startIdx,...., (middleIdx - 1)
            return findPivotIdx(headIdx, (size >> 1)); // exclude the middle one
        }
        else{
            // A[tailIdx] < A[startIdx] < A[middleIdx]
            // pivot is in the right, (middleIdx + 1),...., (size - 1)
            return findPivotIdx(middleIdx + 1, size - (size >> 1) - 1);
        }

    }

    int binarySearch(int startIdx, int size, int target){
        // base cases
        if (size == 0){
            return -1;
        }
        else if (size == 1){
            if (target == A[startIdx]){
                return startIdx;
            }
            else{
                return -1;
            }
        }
        else{
            // size >= 2
            if (target == A[startIdx]){
                // first element
                return startIdx;
            }
            else if (target == A[startIdx + size - 1]){
                // last element
                return startIdx + size - 1;
            }
            else if ((target < A[startIdx]) || (target > A[startIdx + size - 1])){
                // out of range
                return -1;
            }
        }

        // recursive
        int middleIdx = startIdx + (size >> 1);
        int leftHalfSize = (size >> 1);
        int rightHalfSize = size - leftHalfSize - 1; // exclude the middle node
        if (target == A[middleIdx]){
            return middleIdx;
        }
        else if (target > A[middleIdx]){
            return binarySearch(middleIdx + 1, rightHalfSize, target);
        }
        else{
            // target < A[middleIdx]
            return binarySearch(startIdx, leftHalfSize, target);
        }

    }

    Solution() : A(NULL){};

    // Data member
    int* A;
};