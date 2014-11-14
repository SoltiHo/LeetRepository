// Given an array of non - negative integers, you are initially positioned at the first index of the array.
// 
// Each element in the array represents your maximum jump length at that position.
// 
// Your goal is to reach the last index in the minimum number of jumps.
// 
// For example :
// Given array A = [2, 3, 1, 1, 4]
// 
// The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

#include <string>
#include <algorithm>
using namespace std;


class Solution {
public:
    int jump(int A[], int n) {
        if (n == 1){
            return 0;
        }
        if (A[0] == 0){
            return INT_MAX;
        }
        if (n == 2){
            return 1;
        }

        char* possible = new char[n]();
        int steps = 0;
        int currJumpFirst = 0;
        int currJumpEnd = 0;
        int nextJumpEnd = 0;
        int temp;

        possible[0] = 0xFF;
        while (true){
            steps++;
            for (int i = currJumpEnd; i >= currJumpFirst; --i){
                int sizeToSet = min(n - 1 - i, A[i]);
                nextJumpEnd = max(nextJumpEnd, i + sizeToSet);
                memset(possible + 1 + i, 0xFF, sizeof(char)* sizeToSet);
                if (possible[n - 1] != 0){
                    break;
                }
            }
            if (possible[n - 1] != 0){
                // solution found
                break;
            }

            currJumpFirst = currJumpFirst + 1;
            currJumpEnd = nextJumpEnd;
        }


        delete[] possible;
        return steps;
    }
};