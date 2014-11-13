#include "gtest/gtest.h"  // access test macro
#include "MinimumWindowSubstring.h"


TEST(LeetCode, Fail07){
    string S = "ab";
    string T = "A";

    Solution sol;
    string output = sol.minWindow(S, T);
    string expectedOutput = "";

    ASSERT_TRUE(output == expectedOutput);
}

TEST(LeetCode, Fail06){
    string S = "a";
    string T = "aa";

    Solution sol;
    string output = sol.minWindow(S, T);
    string expectedOutput = "";

    ASSERT_TRUE(output == expectedOutput);
}


TEST(LeetCode, Fail05){
    string S = "ask_not_what_your_country_can_do_for_you_ask_what_you_can_do_for_your_country";
    string T = "ask_country";

    Solution sol;
    string output = sol.minWindow(S, T);
    string expectedOutput = "sk_not_what_your_c";

    ASSERT_TRUE(output == expectedOutput);
}


TEST(LeetCode, Fail04){
    string S = "cbabcabba";
    string T = "acab";

    Solution sol;
    string output = sol.minWindow(S, T);
    string expectedOutput = "abca";

    ASSERT_TRUE(output == expectedOutput);
}

TEST(LeetCode, Fail03){
    string S = "bbaa";
    string T = "aba";

    Solution sol;
    string output = sol.minWindow(S, T);
    string expectedOutput = "baa";

    ASSERT_TRUE(output == expectedOutput);
}

TEST(LeetCode, Fail02){
    string S = "bba";
    string T = "ab";

    Solution sol;
    string output = sol.minWindow(S, T);
    string expectedOutput = "ba";

    ASSERT_TRUE(output == expectedOutput);
}

TEST(LeetCode, Fail01){
    string S = "aa";
    string T = "aa";

    Solution sol;
    string output = sol.minWindow(S, T);
    string expectedOutput = "aa";

    ASSERT_TRUE(output == expectedOutput);
}





TEST(Basic, Example01){
    string S = "ADOBECODEBANC";
    string T = "ABC";

    Solution sol;
    string expectedOutput = "BANC";
    string output = sol.minWindow(S, T);

    ASSERT_TRUE(output == expectedOutput);
}

