#include "gtest/gtest.h"  // access test macro
#include "Valid_Number.h"


TEST(Leet, Fail13){
    const char s[](" 005047e+6");
    Solution sol;
    ASSERT_EQ(sol.isNumber(s), true);
}

TEST(Leet, Fail12){
    const char s[]("92e1740e91");
    Solution sol;
    ASSERT_EQ(sol.isNumber(s), false);
}

TEST(Leet, Fail11){
    const char s[]("6e6.5");
    Solution sol;
    ASSERT_EQ(sol.isNumber(s), false);
}

TEST(Leet, Fail10){
    const char s[](".e1");
    Solution sol;
    ASSERT_EQ(sol.isNumber(s), false);
}

TEST(Leet, Fail09){
    const char s[]("46.e3");
    Solution sol;
    ASSERT_EQ(sol.isNumber(s), true);
}

TEST(Leet, Fail08){
    const char s[]("+ 1");
    Solution sol;
    ASSERT_EQ(sol.isNumber(s), false);
}

TEST(Leet, Fail07){
    const char s[]("+.8");
    Solution sol;
    ASSERT_EQ(sol.isNumber(s), true);
}

TEST(Leet, Fail06){
    const char s[](".1.");
    Solution sol;
    ASSERT_EQ(sol.isNumber(s), false);
}

TEST(Leet, Fail05){
    const char s[](". 1");
    Solution sol;
    ASSERT_EQ(sol.isNumber(s), false);
}

TEST(Leet, Fail04){
    const char s[]("3. ");
    Solution sol;
    ASSERT_EQ(sol.isNumber(s), true);
}

TEST(Leet, Fail03){
    const char s[]("1 4");
    Solution sol;
    ASSERT_EQ(sol.isNumber(s), false);
}


TEST(Leet, Fail02){
    const char s[]("3.");
    Solution sol;
    ASSERT_EQ(sol.isNumber(s), true);
}


TEST(Leet, Fail01){
    const char s[](".1");
    Solution sol;
    ASSERT_EQ(sol.isNumber(s), true);
}



TEST(Leet, Example01){
    const char s[]("0");
    Solution sol;
    ASSERT_EQ(sol.isNumber(s), true);
}

TEST(Leet, Example02){
    const char s[](" 0.1");
    Solution sol;
    ASSERT_EQ(sol.isNumber(s), true);
}

TEST(Leet, Example03){
    const char s[]("abc");
    Solution sol;
    ASSERT_EQ(sol.isNumber(s), false);
}

TEST(Leet, Example04){
    const char s[]("1 a");
    Solution sol;
    ASSERT_EQ(sol.isNumber(s), false);
}

TEST(Leet, Example05){
    const char s[]("2e10");
    Solution sol;
    ASSERT_EQ(sol.isNumber(s), true);
}