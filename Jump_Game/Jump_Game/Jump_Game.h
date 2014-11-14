// Given an array of non - negative integers, you are initially positioned at the first index of the array.
// 
// Each element in the array represents your maximum jump length at that position.
// 
// Determine if you are able to reach the last index.
// 
// For example :
// A = [2, 3, 1, 1, 4], return true.
// 
// A = [3, 2, 1, 0, 4], return false.
#include <string>
using namespace std;

class Solution {
public:
    bool canJump(int A[], int n) {
        if (n <= 1){
            return true;
        }

        bool output = false;
        char* possible = new char[n]();
        possible[0] = 0xFF;
        for (int i = 0; i < n; ++i){
            if (possible[i] == 0){
                output = false;
                break;
            }

            if (A[i] > 0){
                if (i + 1 + A[i] <= n - 1){
                    memset(possible + i + 1, 0xFF, sizeof(char)*A[i]);
                }
                else{
                    memset(possible + i + 1, 0xFF, sizeof(char)*(n - 1 - i));
                }
            }

            if (possible[n - 1] != 0){
                output = true;
                break;
            }
        }

        delete[] possible;
        return output;
    }
};