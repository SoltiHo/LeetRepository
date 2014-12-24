// Implement int sqrt(int x).
// 
// Compute and return the square root of x.
#include <cmath>

class Solution {
public:
    int sqrt(int x) {
        int numDigits = 0;
        int temp = x;
        while (temp > 0){
            numDigits++;
            temp /= 10;
        }

        int rootDigits = (numDigits + 1) >> 1;
        int delta = 0;
        int root = 0;
        for (int i = rootDigits; i; --i){
            delta = pow(10, i - 1);
            for (int j = 9; j >= 0; --j){
                if (pow(root + delta * j, 2) <= x){
                    root += delta * j;
                    break;
                }
            }
            if (pow(root, 2) == x){
                break;
            }
            
        }

        return root;

    }
};