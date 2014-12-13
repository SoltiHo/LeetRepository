//  Follow up for "Remove Duplicates":
//  What if duplicates are allowed at most twice ?
//  
//  For example,
//  Given sorted array A = [1, 1, 1, 2, 2, 3],
//  
//  Your function should return length = 5, and A is now[1, 1, 2, 2, 3].

#include <string>
using namespace std;
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 0){
            return 0;
        }

        int accumulatingCount = 0;
        int tailIdx = 0;
        int currPeriodHead = 0;
        for (int i = 0; i < n; ++i){
            if (accumulatingCount){
                if (A[i] == A[i - 1]){
                    accumulatingCount++;
                }
                else{
                    // close the period
                    if (accumulatingCount > 2){
                        accumulatingCount = 2;
                    }
                    //memcpy(A + tailIdx, A + currPeriodHead, sizeof(int)* accumulatingCount);
                    A[tailIdx] = A[currPeriodHead];
                    if (accumulatingCount == 2){
                        A[tailIdx + 1] = A[currPeriodHead];
                    }

                    tailIdx += accumulatingCount;
                    accumulatingCount = 1;
                    currPeriodHead = i;
                }
            }
            else{
                // started a new number
                accumulatingCount = 1;
                currPeriodHead = i;
            }
        }

        // close the last period
        if (accumulatingCount > 2){
            accumulatingCount = 2;
        }
        A[tailIdx] = A[currPeriodHead];
        if (accumulatingCount == 2){
            A[tailIdx + 1] = A[currPeriodHead];
        }
        tailIdx += accumulatingCount;

        return tailIdx;
    }
};