#include "gtest/gtest.h"  // access test macro
#include "Word_Search.h"


TEST(Leet, Fail05){
    vector<vector<char>> input({ { 'a', 'a' } });
    string key = "aaa";
    SolutionLatest sol;

    ASSERT_FALSE(sol.exist(input, key));

}

TEST(Leet, Fail04){
    vector<vector<char>> input({ { 'a', 'a' } });
    string key = "aa";
    SolutionLatest sol;

    ASSERT_TRUE(sol.exist(input, key));

}

TEST(Leet, Fail03){
    vector<vector<char>> input({ { 'a' } });
    string key = "a";
    SolutionLatest sol;

    ASSERT_TRUE(sol.exist(input, key));

}

TEST(Leet, Fail02){
    vector<vector<char>> input({ { 'a' } });
    string key = "ab";
    SolutionLatest sol;

    ASSERT_FALSE(sol.exist(input, key));

}



TEST(Leet, Fail01){
    vector<vector<char>> input({ { 'A', 'B', 'C', 'E' }, { 'S', 'F', 'C', 'S' }, { 'A','D','E','E' } });
    string key = "ABCB";
    SolutionLatest sol;

    ASSERT_FALSE(sol.exist(input, key));
    
}
