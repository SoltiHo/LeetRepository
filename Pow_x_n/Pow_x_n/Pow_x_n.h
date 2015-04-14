// Implement pow(x, n).
#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:
    double pow(double x, int n) {
        double output = 1.0;
        if (n < 0){
            x = 1.0 / x;
            n = -1 * n;
        }
        double factor = x;
        while (n > 0){
            if (n & 1){
                output *= factor;
            }
            factor *= factor;
            n >>= 1;
        }
        return output;
    }
};