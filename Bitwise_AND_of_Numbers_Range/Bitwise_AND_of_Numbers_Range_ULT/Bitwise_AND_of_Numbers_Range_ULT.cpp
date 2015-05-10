#include "gtest/gtest.h"  // access test macro
#include "Bitwise_AND_of_Numbers_Range.h"

TEST(LeetTestCases, Fail03){
    Solution sol;
    ASSERT_EQ(sol.rangeBitwiseAnd(1, 3), 0);

}

TEST(LeetTestCases, Fail01){
    Solution sol;
    ASSERT_EQ(sol.rangeBitwiseAnd(0, 2147483647), 0);

}

TEST(LeetTestCases, Fail02){
    Solution sol;
    ASSERT_EQ(sol.rangeBitwiseAnd(2000, 2147483647), 0);

}
