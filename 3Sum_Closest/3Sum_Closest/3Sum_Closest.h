// Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
// Return the sum of the three integers.You may assume that each input would have exactly one solution.
// 
// For example, given array S = { -1 2 1 - 4 }, and target = 1.
// 
// The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// if the new number is part of the answer, then S[n - 1]'s best solution is target - new number.
// if the new number is not part of the answer, then S[n - 1]'s solution = S[n]'s solution


class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int output = 0;
        const int numSize = num.size();
        if (numSize > 2) {
            sort(num.begin(), num.end());
            output = num[0] + num[1] + num[2]; //seed

            int currSum = 0;
            for (int i = 1; i < numSize - 1; ++i){
                int leftIdx = i - 1;
                int rightIdx = i + 1;
                while ((leftIdx >= 0) && (rightIdx <= numSize - 1)){
                    currSum = num[leftIdx] + num[i] + num[rightIdx];
                    if (abs(currSum - target) < abs(output - target)){
                        output = currSum;
                    }

                    if (currSum < target){
                        if (rightIdx != numSize - 1){
                            rightIdx++;
                        }
                        else {
                            break;
                        }
                    }
                    else if (currSum > target){
                        if (leftIdx > 0){
                            leftIdx--;
                        }
                        else{
                            break;
                        }
                    }
                    else{
                        // match
                        return currSum;
                    }

                }
            }
        }
        return output;
    }
};

