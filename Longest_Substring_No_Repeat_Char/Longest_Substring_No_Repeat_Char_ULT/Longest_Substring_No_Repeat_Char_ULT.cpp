#include "gtest/gtest.h"  // access test macro
#include "Longest_Substring_No_Repeat_Char.h"



TEST(CharTable, Fail02){
    string input("hnwnkuewhsqmgbbuqcljjivswmdkqtbxixmvtrrbljptnsnfwzqfjmafadrrwsofsbcnuvqhffbsaqxwpqcac");
    Solution_CharTable sol;

    ASSERT_EQ(sol.lengthOfLongestSubstring(input), 12);
}

TEST(Hash, Fail02){
    string input("hnwnkuewhsqmgbbuqcljjivswmdkqtbxixmvtrrbljptnsnfwzqfjmafadrrwsofsbcnuvqhffbsaqxwpqcac");
    Solution_Hash sol;

    ASSERT_EQ(sol.lengthOfLongestSubstring(input), 12);
}

TEST(SearchBack, Fail02){
    string input("hnwnkuewhsqmgbbuqcljjivswmdkqtbxixmvtrrbljptnsnfwzqfjmafadrrwsofsbcnuvqhffbsaqxwpqcac");
    Solution_SearchBack sol;

    ASSERT_EQ(sol.lengthOfLongestSubstring(input), 12);
}

TEST(CharTable, Fail01){
    string input("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco");
    Solution_CharTable sol;

    ASSERT_EQ(sol.lengthOfLongestSubstring(input), 12);
}

TEST(Hash, Basic07){
    string input("a");
    Solution_Hash sol;

    ASSERT_EQ(sol.lengthOfLongestSubstring(input), 1);
}

TEST(Hash, Basic06){
    string input("abcdabcdeffghi");
    Solution_Hash sol;

    ASSERT_EQ(sol.lengthOfLongestSubstring(input), 6);
}

TEST(Hash, Fail01){
    string input("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco");
    Solution_Hash sol;

    ASSERT_EQ(sol.lengthOfLongestSubstring(input), 12);
}

TEST(Hash, Basic05){
    string input("abcbabcdefabcabc");
    Solution_Hash sol;

    ASSERT_EQ(sol.lengthOfLongestSubstring(input), 6);
}

TEST(Hash, Basic04){
    string input("abcdefg");
    Solution_Hash sol;

    ASSERT_EQ(sol.lengthOfLongestSubstring(input), 7);
}

TEST(Hash, Basic03){
    string input("aaaa");
    Solution_Hash sol;

    ASSERT_EQ(sol.lengthOfLongestSubstring(input), 1);
}

TEST(Hash, Basic02){
    string input("abcbad");
    Solution_Hash sol;

    ASSERT_EQ(sol.lengthOfLongestSubstring(input), 4);
}

TEST(Hash, Basic01){
    string input("abcba");
    Solution_Hash sol;

    ASSERT_EQ(sol.lengthOfLongestSubstring(input), 3);
}



TEST(SearchBack, Fail01){
    string input("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco");
    Solution_SearchBack sol;
    
    ASSERT_EQ(sol.lengthOfLongestSubstring(input), 12);
}

// --------------------------------------------------------------------

