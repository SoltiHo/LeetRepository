// Find the contiguous subarray within an array(containing at least one number) which has the largest product.
// 
// For example, given the array[2, 3, -2, 4],
// the contiguous subarray[2, 3] has the largest product = 6.
#include <limits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(int A[], int n) {
        if (n == 0){
            return 0;
        }
        if (n == 1){
            return A[0];
        }

        int maxP = INT_MIN;
        int currP = 0;
        int B2FirstNegativeProduct = 0;
        int LastNegative2BProduct = 0;
        bool hasProduct = false;
        for (int i = 0; i < n; ++i){
            maxP = max(maxP, A[i]);
            if (A[i] > 0){
                if (hasProduct) {
                    currP *= A[i];
                    LastNegative2BProduct *= A[i];
                }
                else{
                    currP = A[i];
                    hasProduct = true;
                }
            }
            else if (A[i] == 0){
                if (hasProduct) {
                    // output a candidate
                    if (currP >= 0){
                        maxP = max(maxP, currP);
                    }
                    else{
                        if (currP != B2FirstNegativeProduct){
                            maxP = max(maxP, currP / B2FirstNegativeProduct);
                        }
                        if (currP != LastNegative2BProduct){
                            maxP = max(maxP, currP / LastNegative2BProduct);
                        }
                    }
                    B2FirstNegativeProduct = 0;
                    LastNegative2BProduct = 0;
                    hasProduct = false;
                }
            }
            else{
                // A[i] < 0
                if (hasProduct) {
                    if (B2FirstNegativeProduct == 0){
                        // first negaive, output a candidate
                        maxP = max(maxP, currP);
                        B2FirstNegativeProduct = currP*A[i];
                    }
                    currP *= A[i];
                    LastNegative2BProduct = A[i];
                }
                else{
                    LastNegative2BProduct = B2FirstNegativeProduct = currP = A[i];
                    hasProduct = true;
                }

            }
        }

        if (hasProduct){
            // output a candidate
            if (currP >= 0){
                maxP = max(maxP, currP);
            }
            else{
                if (currP != B2FirstNegativeProduct){
                    maxP = max(maxP, currP / B2FirstNegativeProduct);
                }
                if (currP != LastNegative2BProduct){
                    maxP = max(maxP, currP / LastNegative2BProduct);
                }
            }
        }

        return maxP;
    }
};