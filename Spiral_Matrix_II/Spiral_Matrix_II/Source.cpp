#include "Spiral_Matrix_II.h"
#include <iostream>
int main(){
    Solution sol;
    vector<vector<int>> output;
    output = sol.generateMatrix(3);

    for (auto& r : output){
        for (auto& i : r){
            cout << i << ", ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}