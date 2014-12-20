#include "gtest/gtest.h"  // access test macro
#include "Set_Matrix_Zeroes.h"


//Input:[[0, 0, 0, 5], [4, 3, 1, 4], [0, 1, 1, 4], [1, 2, 1, 3], [0, 0, 1, 1]]
//Output : [[0, 0, 0, 0], [0, 0, 1, 4], [0, 0, 1, 4], [0, 0, 1, 3], [0, 0, 0, 0]]
//     Expected : [[0, 0, 0, 0], [0, 0, 0, 4], [0, 0, 0, 0], [0, 0, 0, 3], [0, 0, 0, 0]]


TEST(Baisc, basic03){
    vector<vector<int>> input({ { 0, 0, 0, 5 }, { 4, 3, 1, 4 }, { 0, 1, 1, 4 }, { 1, 2, 1, 3 }, { 0, 0, 1, 1 } });
    Solution sol;

    sol.setZeroes(input);

}

TEST(Baisc, basic02){
    vector<vector<int>> input({ { 0 }, { 1 } });
    Solution sol;

    sol.setZeroes(input);

}


TEST(Baisc, basic01){
    vector<vector<int>> input({ { 0, 1 } });
    Solution sol;

    sol.setZeroes(input);

}
