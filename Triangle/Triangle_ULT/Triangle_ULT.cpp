#include "gtest/gtest.h"  // access test macro
#include "Triangle.h"

TEST(Leet, Fail02){
    vector<vector<int>> input({ { -1 }, { 2, 3 }, { 1, -1, -3 } });
    Solution sol;

    ASSERT_EQ(sol.minimumTotal(input), -1);

}




TEST(Leet, Fail01){
    vector<vector<int>> input({ { -10 } });
    Solution sol;

    ASSERT_EQ(sol.minimumTotal(input), -10);
    
}
