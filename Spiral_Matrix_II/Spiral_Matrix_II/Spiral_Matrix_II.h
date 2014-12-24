// Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
// 
// For example,
// Given n = 3,
// 
// You should return the following matrix :
// [
//     [1, 2, 3],
//     [8, 9, 4],
//     [7, 6, 5]
// ]

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int>> output;
        if (n > 0){
            output.resize(n, {});
            for (auto& r : output){
                r.resize(n, 0);
            }
            int startR = 0;
            int startC = 0;
            int counter = 0;
            bool increasing = true;
            bool horizontal = true;
            const int destR = (n >> 1);
            const int destC = ((n - 1) >> 1);
            int curr = 0;
            while (true){
                while ((curr >= 0) && (curr < n) &&( output[startR][startC] == 0)){
                    output[startR][startC] = ++counter;
                    if (horizontal){
                        if (increasing){
                            curr = ++startC;
                        }
                        else{
                            curr = --startC;
                        }
                    }
                    else{
                        if (increasing){
                            curr = ++startR;
                        }
                        else{
                            curr = --startR;
                        }
                    }
                }

                if (output[destR][destC] != 0){
                    break;
                }

                if ((horizontal) && (increasing)){
                    horizontal = false;
                    startC--;
                    curr = ++startR;
                }
                else if ((horizontal) && (!increasing)){
                    horizontal = false;
                    startC++;
                    curr = --startR;
                }
                else if ((!horizontal) && (increasing)){
                    horizontal = true;
                    increasing = false;
                    startR--;
                    curr = --startC;
                }
                else if ((!horizontal) && (!increasing)){
                    horizontal = true;
                    increasing = true;
                    startR++;
                    curr = ++startC;
                }

            }

        }
        return output;
    }
};