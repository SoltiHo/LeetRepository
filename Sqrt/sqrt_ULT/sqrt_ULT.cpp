#include "gtest/gtest.h"  // access test macro
#include "sqrt.h"

TEST(Baisc, basic04){
    int input = 2;
    Solution sol;

    ASSERT_EQ(sol.sqrt(input), 1);
}
TEST(Baisc, basic03){
    int input = 1;
    Solution sol;

    ASSERT_EQ(sol.sqrt(input), 1);
}

TEST(Baisc, basic02){
    int input = 169;
    Solution sol;

    ASSERT_EQ(sol.sqrt(input), 13);
}

TEST(Baisc, basic01){
    int input = 8192;
    Solution sol;

    ASSERT_EQ(sol.sqrt(input), 90);
}
