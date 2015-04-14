#include "gtest/gtest.h"  // access test macro
#include "Number_of_Islands.h"


TEST(LeetCode, Fail01){
    vector<vector<char>> input = { { '1', '1', '1' }, { '0', '1', '0' }, { '1', '1', '1' } };

    Solution sol;
    int output = sol.numIslands(input);
    ASSERT_EQ(output, 1);

}



