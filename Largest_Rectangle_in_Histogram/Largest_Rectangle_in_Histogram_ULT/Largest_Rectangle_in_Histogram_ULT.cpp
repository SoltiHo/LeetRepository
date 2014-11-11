#include "gtest/gtest.h"  // access test macro
#include "Largest_Rectangle_in_Histogram.h"

TEST(LeetCode, Fail03){
    vector<int> height;

    height.push_back(1);
    height.push_back(0);
    height.push_back(1);
    height.push_back(0);
    height.push_back(1);

    Solution sol;

    ASSERT_EQ(sol.largestRectangleArea(height), 1);
}

TEST(LeetCode, Fail02){
    vector<int> height;

    height.push_back(0);
    height.push_back(1);
    height.push_back(0);
    height.push_back(1);

    Solution sol;

    ASSERT_EQ(sol.largestRectangleArea(height), 1);
}


TEST(LeetCode, Fail01){
    vector<int> height;

    height.push_back(2);
    height.push_back(0);
    height.push_back(2);

    Solution sol;

    ASSERT_EQ(sol.largestRectangleArea(height), 2);
}
