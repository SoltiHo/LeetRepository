#include "gtest/gtest.h"  // access test macro
#include "InterleavingString.h"

TEST(InterleavingString, Fail_02){

    std::string s1 = "aa";
    std::string s2 = "ab";
    std::string s3 = "aaab";

    Solution sol;
    ASSERT_EQ(sol.isInterleave(s1, s2, s3), true);
}

TEST(InterleavingString, Fail_01){

    std::string s1 = "a";
    std::string s2 = "";
    std::string s3 = "c";

    Solution sol;
    ASSERT_EQ(sol.isInterleave(s1, s2, s3), false);
}

TEST(InterleavingString, Example01){

    std::string s1 = "aabcc";
    std::string s2 = "dbbca";
    std::string s3 = "aadbbcbcac";

    Solution sol;
    ASSERT_EQ(sol.isInterleave(s1, s2, s3), true);
}

TEST(InterleavingString, Example02){

    std::string s1 = "aabcc";
    std::string s2 = "dbbca";
    std::string s3 = "aadbbbaccc";

    Solution sol;
    ASSERT_EQ(sol.isInterleave(s1, s2, s3), false);
}