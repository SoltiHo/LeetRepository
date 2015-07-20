#include "gtest/gtest.h"  // access test macro
#include "Text_Justification.h"

bool equal(vector<string>& a, vector<string>& b){
    if (a.size() != b.size()){
        return false;
    }
    for (int i = 0; i < a.size(); ++i){
        if (a[i] != b[i]){
            return false;
        }
    }
    return true;
}

TEST(LeetCode, Fail05){
    vector<string> input = { "a" };
    int L = 2;

    Solution sol;
    vector<string> output = sol.fullJustify(input, L);
    vector<string> expected =
    { "a " };

    ASSERT_TRUE(equal(output, expected));
}

TEST(LeetCode, Fail04){
    vector<string> input = { "a" };
    int L = 1;

    Solution sol;
    vector<string> output = sol.fullJustify(input, L);
    vector<string> expected =
    { "a"};

    ASSERT_TRUE(equal(output, expected));
}

TEST(LeetCode, Fail03){
    vector<string> input = { "Listen", "to", "many,", "speak", "to", "a", "few." };
    int L = 6;

    Solution sol;
    vector<string> output = sol.fullJustify(input, L);
    vector<string> expected = {
        "Listen",
        "to    ",
        "many, ",
        "speak ",
        "to   a",
        "few.  "};

    ASSERT_TRUE(equal(output, expected));
}

TEST(LeetCode, Fail02){
    vector<string> input = {"a", "b", "c", "d", "e"};
    int L = 1;

    Solution sol;
    vector<string> output = sol.fullJustify(input, L);
    vector<string> expected = {
        "a",
        "b",
        "c",
        "d",
        "e" };

    ASSERT_TRUE(equal(output, expected));
}


TEST(LeetCode, Fail01){
    vector<string> input = { "This", "is", "an", "example", "of", "text", "justification." };
    int L = 16;

    Solution sol;
    vector<string> output = sol.fullJustify(input, L);
    vector<string> expected = 
      { "This    is    an",
        "example  of text",
        "justification.  " };

    ASSERT_TRUE(equal(output, expected));
}
