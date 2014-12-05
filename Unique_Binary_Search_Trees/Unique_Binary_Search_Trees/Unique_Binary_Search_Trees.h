//  Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
//  
//  For example,
//  Given n = 3, there are a total of 5 unique BST's.
//  
//  1         3     3      2      1
//   \       /     /      / \      \
//    3     2     1      1   3      2
//   /     /       \                 \
//  2     1         2                 3

#include <string>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if (n == 0){
            return 0;
        }
        int* solutionCount = new int[n]();
        int* buffer = new int[n]();

        solutionCount[0] = 1; // seed, for n == 1
        for (int i = 2; i <= n; ++i){
            memset(buffer, 0, sizeof(int)*n);
            for (int j = 0; j < n; ++j){
                if (solutionCount[j] > 0){
                    for (int k = 0; k <= j + 1; ++k){
                        buffer[k] += solutionCount[j];
                    }
                }
            }
            memcpy(solutionCount, buffer, sizeof(int)* n);
        }

        // sum the array
        int output = 0;
        for (int i = 0; i < n; ++i){
            output += solutionCount[i];
        }

        delete[] solutionCount;
        delete[] buffer;
        return output;
    }
};