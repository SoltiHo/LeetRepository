#include "gtest/gtest.h"  // access test macro
#include "LongestValidParentheses.h"

#include <vector>

TEST(LeetTestCases, Fail04){
    string test = "(())()(()((";

    Solution sol;
    ASSERT_EQ(sol.longestValidParentheses(test), 6);

}

TEST(LeetTestCases, Fail03){
    string test = "()(()(((";

    Solution sol;
    ASSERT_EQ(sol.longestValidParentheses(test), 2);

}

TEST(LeetTestCases, Fail02){
    string test = "()(()";

    Solution sol;
    ASSERT_EQ(sol.longestValidParentheses(test), 2);

}

TEST(LeetTestCases, Fail01){
    string test = "(()()";

    Solution sol;
    ASSERT_EQ(sol.longestValidParentheses(test), 4);

}

TEST(Basic, PureLeft){
    string test = "((((((";

    Solution sol;
    ASSERT_EQ(sol.longestValidParentheses(test), 0);

}

TEST(Basic, PureRight){
    string test = ")))))";

    Solution sol;
    ASSERT_EQ(sol.longestValidParentheses(test), 0);

}


TEST(SingleSubstring, ValidFromStart_RightRemaining){
    string test = "()(())))";

    Solution sol;
    ASSERT_EQ(sol.longestValidParentheses(test), 6);

}

TEST(SingleSubstring, ValidFromStart_LeftRemaining){
    string test = "()(())(())()()(((";

    Solution sol;
    ASSERT_EQ(sol.longestValidParentheses(test), 14);

}

TEST(SingleSubstring, ValidFromEnd_RightRemaining){
    string test = "))()((()))";

    Solution sol;
    ASSERT_EQ(sol.longestValidParentheses(test), 8);

}

TEST(SingleSubstring, ValidFromEnd_LeftRemaining){
    string test = "(((())()()((()))";

    Solution sol;
    ASSERT_EQ(sol.longestValidParentheses(test), 14);

}