#include "gtest/gtest.h"  // access test macro
#include "Maximum_Product_Subarray.h"

TEST(DP, Fail03){
    int input[5] = { 2, -5, -2, -4, 3 };
    int count = 5;
    Solution sol;
    ASSERT_EQ(sol.maxProduct(input, count), 24);
}

TEST(DP, Fail02){
    int input[3] = { -4, -3, -2 };
    int count = 3;
    Solution sol;
    ASSERT_EQ(sol.maxProduct(input, count), 12);
}

TEST(DP, Fail01){
    int input[3] = { -2, 0, -1 };
    int count = 3;
    Solution sol;
    ASSERT_EQ(sol.maxProduct(input, count), 0);
}
