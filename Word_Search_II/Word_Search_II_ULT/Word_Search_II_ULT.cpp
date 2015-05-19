#include "gtest/gtest.h"  // access test macro
#include "Word_Search_II.h"

TEST(Baisc, basic02){
    vector<vector<char>> board({ { 'a', 'a' } });
    vector<string> words({ "a" });
    Solution sol;
    vector<string> expected({ "a" });
    ASSERT_EQ(sol.findWords(board, words), expected);
}


TEST(Baisc, basic01){
    vector<vector<char>> board({ { 'a' } });
    vector<string> words({ "a" });
    Solution sol;
    vector<string> expected({"a"});
    ASSERT_EQ(sol.findWords(board, words), expected);
}
