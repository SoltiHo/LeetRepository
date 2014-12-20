// Divide two integers without using multiplication, division and mod operator.
// 
// If it is overflow, return MAX_INT.
#include <climits>
#include <cmath>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        int output = 0;
        if (divisor == 0){
            output = INT_MAX;
        }
        else if ((divisor == 1) || (divisor == -1)){
            if ((dividend == INT_MIN) && (divisor == -1)){
                // overflow
                output = INT_MAX;
            }
            else{
                output = divisor == 1 ? dividend : ~dividend + 1;
            }
        }
        else{
            long long di = (dividend == INT_MIN) ? ((long long)1 << 31) : ((long long)abs(dividend));
            long long dv = (divisor == INT_MIN) ? ((long long)1 << 31) : ((long long)abs(divisor));
            long long temp = dv;
            long long outputBuffer = 1;
            bool isNegative = false;
            if (((dividend < 0) && (divisor >= 0)) || ((dividend >= 0) && (divisor < 0))){
                isNegative = true;
            }

            while (di >= dv){
                while (temp < di){
                    temp <<= 1;
                    outputBuffer <<= 1;
                }
                if (temp > di){
                    temp >>= 1;
                    outputBuffer >>= 1;
                }
                di -= temp;

                output += outputBuffer;
                temp = dv;
                outputBuffer = 1;
            }

            if (isNegative){
                output = ~output + 1;
            }
        }

        return output;
    }
};