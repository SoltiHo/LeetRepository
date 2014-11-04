#include "gtest/gtest.h"  // access test macro
#include "ScrambleString.h"

TEST(LeetCode, Fail01){
    string original = "abb";
    string scramble = "bab";

    Solution sol;

    ASSERT_TRUE(sol.isScramble(original, scramble));
}

TEST(Basic, MyTest05){
    string original = "great";
    string scramble = "artge";

    Solution sol;

    ASSERT_FALSE(sol.isScramble(original, scramble));
}

TEST(Basic, MyTest04){
    string original = "great";
    string scramble = "aterg";

    Solution sol;

    ASSERT_TRUE(sol.isScramble(original, scramble));
}

TEST(Basic, MyTest03){
    string original = "great";
    string scramble = "aetrg";

    Solution sol;

    ASSERT_TRUE(sol.isScramble(original, scramble));
}


TEST(Basic, MyTest02){
    string original = "great";
    string scramble = "eatrg";

    Solution sol;

    ASSERT_TRUE(sol.isScramble(original, scramble));
}


TEST(Basic, MyTest01){
    string original = "great";
    string scramble = "rgeat";

    Solution sol;
    
    ASSERT_TRUE(sol.isScramble(original, scramble));
}


