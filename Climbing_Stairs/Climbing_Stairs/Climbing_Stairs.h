// You are climbing a stair case.It takes n steps to reach to the top.
// 
// Each time you can either climb 1 or 2 steps.In how many distinct ways can you climb to the top ?
#include <string>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int output = 0;
        if (n == 1){
            output = 1;
        }
        else if (n == 2){
            output = 2;
        }
        else if (n > 2){
            int buffer[2];
            buffer[0] = 1;
            buffer[1] = 2;

            // prev 1 is the other, and prev 2 is curr
            for (int i = 2; i < n; ++i){
                buffer[i & 0x1] = buffer[i & 0x1] + buffer[(i + 1) & 0x1];
            }
            
            output = buffer[(n - 1) & 0x1];
        }
        return output;
    }
};
