#include "gtest/gtest.h"  // access test macro
#include "Palindrome_Partitioning_II.h"

TEST(Leet, Fail09){
    string input("danaranad");
    Solution sol;
    ASSERT_EQ(sol.minCut(input), 0);
}

TEST(Leet, Fail03){
    string input("abbab");
    Solution sol;
    ASSERT_EQ(sol.minCut(input), 1);
}


TEST(Leet, Fail01){
    string input("aaabaa");
    Solution sol;
    ASSERT_EQ(sol.minCut(input), 1);
}

TEST(Leet, Fail05){
    string input("aabbaaaa");
    Solution sol;
    ASSERT_EQ(sol.minCut(input), 1);
}

TEST(Leet, Fail08){
    string input("aaaabbaa");
    Solution sol;
    ASSERT_EQ(sol.minCut(input), 1);
}





TEST(Leet, Fail07){
    string input("cbbbcc");
    Solution sol;
    ASSERT_EQ(sol.minCut(input), 1);
}

TEST(Leet, Fail06){
    string input("abcccb");
    Solution sol;
    ASSERT_EQ(sol.minCut(input), 1);
}



TEST(Leet, Fail04){
    string input("ab");
    Solution sol;
    ASSERT_EQ(sol.minCut(input), 1);
}







TEST(Leet, Fail02){
    string input("dde");
    Solution sol;
    ASSERT_EQ(sol.minCut(input), 1);
}



