// Given n non - negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
// 
// For example,
// Given[0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1], return 6.

#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(int A[], int n) {
        int* leftHillTop = new int[n];
        int* rightHillTop = new int[n];
        memset(leftHillTop, 0, sizeof(int)* n);
        memset(rightHillTop, 0, sizeof(int)* n);

        // calculate hill top height
        int hillTopFromLeft = 0;
        int hillTopFromRight = 0;
        for (int i = n; i; --i){
            // scan from left
            leftHillTop[n - i] = hillTopFromLeft;

            if (hillTopFromLeft < A[n - i]){
                hillTopFromLeft = A[n - i];
            }
            // scan from right
            rightHillTop[i - 1] = hillTopFromRight;

            if (hillTopFromRight < A[i - 1]){
                hillTopFromRight = A[i - 1];
            }
        }

        // calculate water amount
        int totalWater = 0;
        int waterLevel = 0;
        for (int i = n; i; --i){
            waterLevel = min(leftHillTop[i - 1], rightHillTop[i - 1]);

            if (A[i - 1] < waterLevel){
                totalWater += (waterLevel - A[i - 1]);
            }
        }

        delete[] leftHillTop;
        delete[] rightHillTop;
        return totalWater;
    }
};

