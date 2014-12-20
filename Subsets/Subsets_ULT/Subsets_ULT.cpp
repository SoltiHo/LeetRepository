#include "gtest/gtest.h"  // access test macro
#include "subsets.h"

TEST(Baisc, basic02){
    vector<int> input({ 3, 2, 4, 1 });
    Solution sol;
    vector<vector<int>> output = sol.subsets(input);
}

TEST(Baisc, basic01){
    vector<int> input({ 4, 1, 0 });
    Solution sol;
    vector<vector<int>> output = sol.subsets(input);
}
