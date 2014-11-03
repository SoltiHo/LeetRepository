#include "gtest/gtest.h"  // access test macro
#include "WildcardMatching.h"

#include <vector>
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