#include "gtest/gtest.h"  // access test macro
#include "Next_Permutation.h"

TEST(Baisc, basic02){
    vector<int> input({ 1, 2});
    Solution sol;
    sol.nextPermutation(input);
    vector<int> expected({ 2, 1 });
    ASSERT_EQ(input, expected);

}

TEST(Baisc, basic01){
    vector<int> input({ 1, 2, 3 });
    Solution sol;
    sol.nextPermutation(input);
    vector<int> expected({1, 3, 2});
    ASSERT_EQ(input, expected);

}
