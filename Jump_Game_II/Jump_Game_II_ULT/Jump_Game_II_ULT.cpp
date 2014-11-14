#include "gtest/gtest.h"  // access test macro
#include "Jump_Game_II.h"

TEST(LeetCode, Fail03){
    int A[12] = { 3, 4, 3, 1, 0, 7, 0, 3, 0, 2, 0, 3 };
    int n = 12;

    Solution sol;
    ASSERT_EQ(sol.jump(A, n), 3);

}

TEST(LeetCode, Example01){
    int A[5] = { 2, 3, 1, 1, 4 };
    int n = 5;

    Solution sol;
    ASSERT_EQ(sol.jump(A, n), 2);

}

TEST(LeetCode, Fail02){
    int A[5] = { 1, 2, 1, 1, 1 };
    int n = 5;

    Solution sol;
    ASSERT_EQ(sol.jump(A, n), 3);

}


TEST(LeetCode, Fail01){
    int A[2] = { 1, 2 };
    
    Solution sol;
    ASSERT_EQ(sol.jump(A, 2), 1);

}
