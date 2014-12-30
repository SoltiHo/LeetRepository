#include "gtest/gtest.h"  // access test macro
#include "3_Sum.h"



TEST(Dijkstra, Timeout03){
    vector<int> input({ -1, 0, 1, 0 });
    Solution sol;
    vector<vector<int>> output = sol.threeSum(input);
    vector<vector<int>> expected = { { -1, 0, 1 } };
    ASSERT_EQ(output, expected);
}
