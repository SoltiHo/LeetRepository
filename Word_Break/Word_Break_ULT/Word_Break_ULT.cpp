#include "gtest/gtest.h"  // access test macro
#include "Word_Break.h"

TEST(Leet, Fail03){
    string input("aaaaaaa");
    unordered_set<string> dict{ "aaaa", "aaa" };
    Solution sol;
    ASSERT_EQ(sol.wordBreak(input, dict), true);
}

TEST(Leet, Fail02){
    string input("bb");
    unordered_set<string> dict{ "a", "b", "bbb", "bbbb" };
    Solution sol;
    ASSERT_EQ(sol.wordBreak(input, dict), true);
}

TEST(Leet, Fail01){
    string input("a");
    unordered_set<string> dict{ { "a" } };
    Solution sol;
    ASSERT_EQ(sol.wordBreak(input, dict), true);
}



