#include "gtest/gtest.h"  // access test macro
#include "Word_Search.h"




TEST(Leet, Fail01){
    vector<vector<char>> input({ { 'A', 'B', 'C', 'E' }, { 'S', 'F', 'C', 'S' }, { 'A','D','E','E' } });
    string key = "ABCB";
    Solution_DFS sol;

    ASSERT_FALSE(sol.exist(input, key));
    
}
