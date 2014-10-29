#include "gtest/gtest.h"  // access test macro
#include "RegularExpressionMatching.h"

TEST(Simple, Example01){
    char* s = new char[3];
    s[0] = s[1] = 'a';
    s[2] = '\0';

    char* p = new char[2];
    p[0] = 'a';
    p[1] = '\0';

    Solution sol;
    ASSERT_FALSE(sol.isMatch(s, p));
}

TEST(Simple, Example02){
    char* s = new char[3];
    s[0] = s[1] = 'a';
    s[2] = '\0';

    char* p = new char[3];
    p[0] = p[1] = 'a';
    p[2] = '\0';

    Solution sol;
    ASSERT_TRUE(sol.isMatch(s, p));
}

TEST(Simple, Example03){
    char* s = new char[4];
    s[2] = s[0] = s[1] = 'a';
    s[3] = '\0';

    char* p = new char[3];
    p[0] = p[1] = 'a';
    p[2] = '\0';

    Solution sol;
    ASSERT_FALSE(sol.isMatch(s, p));
}

TEST(Simple, Example04){
    char* s = new char[3];
    s[0] = s[1] = 'a';
    s[2] = '\0';

    char* p = new char[3];
    p[0] = 'a';
    p[1] = '*';
    p[2] = '\0';

    Solution sol;
    ASSERT_TRUE(sol.isMatch(s, p));
}

TEST(Simple, Example05){
    char* s = new char[3];
    s[0] = s[1] = 'a';
    s[2] = '\0';

    char* p = new char[3];
    p[0] = '.';
    p[1] = '*';
    p[2] = '\0';

    Solution sol;
    ASSERT_TRUE(sol.isMatch(s, p));
}

TEST(Simple, Example06){
    char* s = new char[3];
    s[0] = 'a';
    s[1] = 'b';
    s[2] = '\0';

    char* p = new char[3];
    p[0] = '.';
    p[1] = '*';
    p[2] = '\0';

    Solution sol;
    ASSERT_TRUE(sol.isMatch(s, p));
}

TEST(Simple, Example07){
    char* s = new char[4];
    s[0] = 'a';
    s[1] = 'a';
    s[2] = 'b';
    s[3] = '\0';

    char* p = new char[6];
    p[0] = 'c';
    p[1] = '*';
    p[2] = 'a';
    p[3] = '*';
    p[4] = 'b';
    p[5] = '\0';

    Solution sol;
    ASSERT_TRUE(sol.isMatch(s, p));
}

TEST(Simple, Fail01){
    char* s = new char[4];
    s[0] = 'a';
    s[1] = 'a';
    s[2] = 'a';
    s[3] = '\0';

    char* p = new char[4];
    p[0] = 'a';
    p[1] = '*';
    p[2] = 'a';
    p[3] = '\0';

    Solution sol;
    ASSERT_TRUE(sol.isMatch(s, p));
}


TEST(Simple, Fail02){
    char* s = new char[4];
    s[0] = 'a';
    s[1] = 'a';
    s[2] = 'a';
    s[3] = '\0';

    char* p = new char[9];
    p[0] = 'a';
    p[1] = 'b';
    p[2] = '*';
    p[3] = 'a';
    p[4] = '*';
    p[5] = 'c';
    p[6] = '*';
    p[7] = 'a';
    p[8] = '\0';

    Solution sol;
    ASSERT_TRUE(sol.isMatch(s, p));
}

TEST(Simple, Fail03){
    char* s = new char[2];
    s[0] = 'a';
    s[1] = '\0';

    char* p = new char[7];
    p[0] = '.';
    p[1] = '*';
    p[2] = '.';
    p[3] = '.';
    p[4] = 'a';
    p[5] = '*';
    p[6] = '\0';

    Solution sol;
    ASSERT_FALSE(sol.isMatch(s, p));
}

TEST(Simple, Fail04){
    char* s = new char[3];
    s[0] = 'a';
    s[1] = 'b';
    s[2] = '\0';

    char* p = new char[5];
    p[0] = '.';
    p[1] = '*';
    p[2] = '.';
    p[3] = '.';
    p[4] = '\0';

    Solution sol;
    ASSERT_TRUE(sol.isMatch(s, p));
}

TEST(Simple, Fail05){
    char* s = new char[15];
    s[0] = 'a';
    s[1] = 'a';
    s[2] = 'a';
    s[3] = 'a';
    s[4] = 'a';
    s[5] = 'a';
    s[6] = 'a';
    s[7] = 'a';
    s[8] = 'a';
    s[9] = 'a';
    s[10] = 'a';
    s[11] = 'a';
    s[12] = 'a';
    s[13] = 'b';
    s[14] = '\0';

    char* p = new char[26];
    p[0] = 'a';
    p[1] = '*';
    p[2] = 'a';
    p[3] = '*';
    p[4] = 'a';
    p[5] = '*';
    p[6] = 'a';
    p[7] = '*';
    p[8] = 'a';
    p[9] = '*';
    p[10] = 'a';
    p[11] = '*';
    p[12] = 'a';
    p[13] = '*';
    p[14] = 'a';
    p[15] = '*';
    p[16] = 'a';
    p[17] = '*';
    p[18] = 'a';
    p[19] = '*';
    p[20] = 'a';
    p[21] = '*';
    p[22] = 'a';
    p[23] = '*';
    p[24] = 'b';
    p[25] = '\0';

    Solution sol;
    ASSERT_TRUE(sol.isMatch(s, p));
}