#include "gtest/gtest.h"  // access test macro
#include "DistinctSubsequences.h"

#include <vector>


TEST(LeetTestCases, Fail02){
    string S = "anacondastreetracecar";
    string T = "contra";
    Solution sol;
    ASSERT_EQ(sol.numDistinct(S, T), 6);

}

TEST(LeetTestCases, Fail01){
    string S = "aabb";
    string T = "ab";
    Solution sol;
    ASSERT_EQ(sol.numDistinct(S, T), 4);

}


