#include "gtest/gtest.h"  // access test macro
#include "Word_Break_II.h"


TEST(Leet, Fail02){
    string input("ab");
    unordered_set<string> dict{ "a", "b" };
    Solution sol;

    vector<string> expected({ "a b"});
    ASSERT_EQ(sol.wordBreak(input, dict), expected);
}


TEST(Leet, Fail01){
    string input("a");
    unordered_set<string> dict{ "a" };
    Solution sol;

    vector<string> expected({ "a" });
    ASSERT_EQ(sol.wordBreak(input, dict), expected);
}



