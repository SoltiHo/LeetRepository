#include "gtest/gtest.h"  // access test macro
#include "Maximum_Subarray.h"
TEST(Leet, Fail03){
    vector<int> input({ 2, 2, 0, -1 });
    Solution sol;

    ASSERT_EQ(sol.maxSubArray(input.data(), input.size()), 4);
}

TEST(Leet, Fail05){
    vector<int> input({ -9, -2, 1, 8, 7, -6, 4, 9, -9, -5, 0, 5, -2, 5, 9, 7 });
    Solution sol;

    ASSERT_EQ(sol.maxSubArray(input.data(), input.size()), 33);
}

TEST(Leet, Fail04){
    vector<int> input({-1, 0 });
    Solution sol;

    ASSERT_EQ(sol.maxSubArray(input.data(), input.size()), 0);
}



TEST(Leet, Fail02){
    vector<int> input({ -2, 1, -3, 4, -1, 2, 1, -5, 4 });
    Solution sol;

    ASSERT_EQ(sol.maxSubArray(input.data(), input.size()), 6);
}

TEST(Leet, Fail01){
    vector<int> input({ 1, 2, -1, -2, 2, 1, -2, 1, 4, -5, 4 });
    Solution sol;
    
    ASSERT_EQ(sol.maxSubArray(input.data(), input.size()), 6);
}
