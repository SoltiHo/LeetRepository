// Find the contiguous subarray within an array(containing at least one number) which has the largest sum.
// 
// For example, given the array[-2, 1, -3, 4, -1, 2, 1, -5, 4],
// the contiguous subarray[4, -1, 2, 1] has the largest sum = 6.
// 
// click to show more practice.
// 
// More practice:
// If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
#include <algorithm>
#include <climits>
#include <stack>
#include <vector>
using namespace std;

class Solution_DivideAndConquer {
public:
    int maxSubArray(int A[], int n) {
        int maxSum = 0;
        if (n > 0){
            maxSum = A[0];
            solveByDivideAndConquer(A, 0, n - 1, maxSum);
        }
        return maxSum;
    }

    pair<int, int> solveByDivideAndConquer(int A[], int startIdx, int endIdx, int& maxSum){
        pair<int, int> output = { A[startIdx], A[endIdx] }; // first = max sum including left boundary, second = max sum including right boundary
        if (endIdx == startIdx){
            output.second = output.first = max(A[startIdx], output.first);
            maxSum = max(maxSum, output.second);
        }
        else{
            int rightHalfStartIdx = startIdx + ((endIdx - startIdx) >> 1) + 1;
            // 0, 3 --> 2 --> 0,1 and 2,3
            // 0, 2 --> 2 --> 0,1 and 2
            // 0, 1 --> 1 --> 0 and 1
            pair<int, int> leftResult = solveByDivideAndConquer(A, startIdx, rightHalfStartIdx - 1, maxSum);
            pair<int, int> rightResult = solveByDivideAndConquer(A, rightHalfStartIdx, endIdx, maxSum);
            if ((leftResult.second > 0) || (rightResult.first > 0)){
                maxSum = max(maxSum, (leftResult.second > 0 ? leftResult.second : 0) + (rightResult.first > 0 ? rightResult.first : 0));
            }
            
            int temp = 0;
            for (int i = startIdx; i <= endIdx; ++i){
                temp += A[i];
                output.first = max(output.first, temp);
            }

            temp = 0;
            for (int i = endIdx; i >= startIdx; --i){
                temp += A[i];
                output.second = max(output.second, temp);
            }

        }

        return output;
    }
};


class Solution_DP2 {
public:
    int maxSubArray(int A[], int n) {
        int maxSum = 0;
        if (n > 0){
            int tillSum = A[0];
            maxSum = A[0];
            for (int i = 1; i < n; ++i){
                tillSum = max(A[i], tillSum + A[i]);
                maxSum = max(maxSum, tillSum);
            }
        }

        return maxSum;
    }
};

class Solution_DP1 {
public:
    int maxSubArray(int A[], int n) {
        int maxSum = 0;
        if (n > 0){
            maxSum = A[0];
            int minSum = A[0] >= 0 ? 0 : A[0];
            int curSum = A[0];
            for (int i = 1; i < n; ++i){
                curSum += A[i];
                if (curSum - minSum > maxSum){
                    maxSum = curSum - minSum;
                }
                if (curSum < minSum){
                    minSum = curSum;
                }
            }
        }

        return maxSum;
    }
};