#include "gtest/gtest.h"  // access test macro
#include "Maximal_Square.h"



TEST(Test, basic01){
    Solution sol;
    vector<vector<char>> input = { { '0', '1' } };
    ASSERT_EQ(sol.maximalSquare(input), 1);
}
