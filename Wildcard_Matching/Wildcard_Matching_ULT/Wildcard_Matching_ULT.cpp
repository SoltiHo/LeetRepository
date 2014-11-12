#include "gtest/gtest.h"  // access test macro
#include "WildcardMatching.h"

#include <vector>

TEST(LeetCode, Fail02){
    char* s = "baaba\0";
    char* p = "*b*b*a\0";

    Solution sol;
    ASSERT_EQ(sol.isMatch(s, p), true);

}

TEST(LeetCode, Fail03){
    char* s = "aaaabbaa\0";
    char* p = "*b*a*aa\0";

    Solution sol;
    ASSERT_EQ(sol.isMatch(s, p), false);

}

TEST(LeetCode, Fail01){
    char* s = "abbbba\0";
    char* p = "a**a*?\0";

    Solution sol;
    ASSERT_EQ(sol.isMatch(s, p), false);

}


TEST(Basic, MyTest01){
    char* s = new char[5];
    s[4] = '\0';
    for (int i = 0; i < 4; ++i){
        s[i] = 'a';
    }
    char* p = new char[7];
    p[0] = '*';
    p[5] = '*';
    p[6] = '\0';
    for (int i = 1; i < 5; ++i){
        p[i] = 'a';
    }

    Solution sol;
    ASSERT_EQ(sol.isMatch(s, p), true);

}



TEST(Leetcode, Timeout07){
    char* s = new char[32317];
    s[32316] = '\0';
    for (int i = 0; i < 32316; ++i){
        s[i] = 'a';
    }
    char* p = new char[32319];
    p[0] = '*';
    p[32317] = '*';
    p[32318] = '\0';
    for (int i = 1; i < 32317; ++i){
        p[i] = 'a';
    }

    Solution sol;
    ASSERT_EQ(sol.isMatch(s, p), true);

}


TEST(Leetcode, Timeout06){
    char* s = new char[32317];
    s[32316] = '\0';
    for (int i = 0; i < 32316; ++i){
        s[i] = 'a';
    }
    char* p = new char[32320];
    p[0] = '*';
    p[32318] = '*';
    p[32319] = '\0';
    for (int i = 1; i < 32318; ++i){
        p[i] = 'a';
    }

    Solution sol;
    ASSERT_EQ(sol.isMatch(s, p), false);

}


TEST(Leetcode, Timeout05){
    char* s = "aabb\0";
    char* p = "a?b*b\0";

    Solution sol;
    ASSERT_EQ(sol.isMatch(s, p), true);

}



TEST(Leetcode, Timeout04){
    char* s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\0";
    char* p = "*aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa*\0";

    Solution sol;
    ASSERT_EQ(sol.isMatch(s, p), true);

}

TEST(Leetcode, Timeout03){
    char* s = "aaabbbbaaaabbabbbbaabbabaaababaababaaaaaaabaaababbaababbaababbbaaaaabaabbabbaabaababbaabababbbbbbbbabbaabbaaabaababaabaababababababbbbbbabbabbaabbaabaaaaaababaabbbaaabaaabbbbbbbbbaabaabaaabaaabbabbabb\0";
    char* p = "****a*b*b**b*bbb*b**bba***b**b*b*b**ba***b*b*a*b*b*****a**aaa*baaa*ba*****a****ba*a****a**b*******a*a\0";

    Solution sol;
    ASSERT_EQ(sol.isMatch(s, p), false);

}

TEST(Basic, Example05){
    char* s = "ab\0";
    char* p = "?*\0";

    Solution sol;
    ASSERT_EQ(sol.isMatch(s, p), true);
}


TEST(Leetcode, Timeout02){
    char* s = "bbaaaabaaaaabbabbabbabbababaabababaabbabaaabbaababababbabaabbabbbbbbaaaaaabaabbbbbabbbbabbabababaaaaa\0";
    char* p = "******aa*bbb*aa*a*bb*ab***bbba*a*babaab*b*aa*a****\0";

    Solution sol;
    ASSERT_EQ(sol.isMatch(s, p), false);

}

TEST(Leetcode, Timeout01){
    char* s = "aaabababaaabaababbbaaaabbbbbbabbbbabbbabbaabbababab\0";
    char* p = "*ab***ba**b*b*aaab*b\0";

    Solution sol;
    ASSERT_EQ(sol.isMatch(s, p), true);

}

TEST(Basic, Test03){
    char* s = "\0";
    char* p = "*bcda\0";

    Solution sol;
    ASSERT_EQ(sol.isMatch(s, p), false);

}

TEST(Basic, Test02){
    char* s = "abcda\0";
    char* p = "a*bcda\0";

    Solution sol;
    ASSERT_EQ(sol.isMatch(s, p), true);

}

TEST(Basic, Test01){
    char* s = "abcda\0";
    char* p = "a*a\0";

    Solution sol;
    ASSERT_EQ(sol.isMatch(s, p), true);

}

TEST(Basic, Example01){
    char* s = "aa\0";
    char* p = "a\0";
    
    Solution sol;
    ASSERT_EQ(sol.isMatch(s, p), false);

}
TEST(Basic, Example02){
    char* s = "aa\0";
    char* p = "aa\0";

    Solution sol;
    ASSERT_EQ(sol.isMatch(s, p), true);

}

TEST(Basic, Example03){
    char* s = "aaa\0";
    char* p = "aa\0";

    Solution sol;
    ASSERT_EQ(sol.isMatch(s, p), false);

}

TEST(Basic, Example04){
    char* s = "aa\0";
    char* p = "*\0";

    Solution sol;
    ASSERT_EQ(sol.isMatch(s, p), true);

}



TEST(Basic, Example06){
    char* s = "aa\0";
    char* p = "a*\0";

    Solution sol;
    ASSERT_EQ(sol.isMatch(s, p), true);

}

TEST(Basic, Example07){
    char* s = "aab\0";
    char* p = "c*a*b\0";

    Solution sol;
    ASSERT_EQ(sol.isMatch(s, p), false);

}