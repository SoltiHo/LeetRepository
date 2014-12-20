#include "gtest/gtest.h"  // access test macro
#include "Divide_Two_Integers.h"
TEST(Baisc, basic04){
    // Input: -2147483648, -1
    // Output : -2147483648
    // Expected : 2147483647
    Solution sol;
    ASSERT_EQ(sol.divide(0 - 2147483648, -1), 2147483647);
}

TEST(Baisc, basic03){
    Solution sol;

    ASSERT_EQ(sol.divide(2, 2), 1);
}

TEST(Baisc, basic02){
    Solution sol;

    ASSERT_EQ(sol.divide(0 - 1010369383, 0 - 2147483648), 0);
}

TEST(Baisc, basic01){
    Solution sol;

    ASSERT_EQ(sol.divide(5, 2), 2);
}
