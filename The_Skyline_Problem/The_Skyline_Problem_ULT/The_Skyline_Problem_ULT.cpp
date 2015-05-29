#include "gtest/gtest.h"  // access test macro
#include "The_Skyline_Problem.h"



TEST(Baisc, basic04){
    vector<vector<int>> intput({ { 3, 7, 8 }, { 3, 8, 7 }, { 3, 9, 6 }, { 3, 10, 5 }, { 3, 11, 4 }, { 3, 12, 3 }, { 3, 13, 2 }, { 3, 14, 1 } });
    vector<pair<int, int>> expected({ { 2, 7 }, { 4, 0 } });
    Solution sol;
    ASSERT_EQ(sol.getSkyline(intput), expected);
}

TEST(Baisc, basic03){
    vector<vector<int>> intput({ { 1, 5, 3 }, { 1, 5, 3 }, { 1, 5, 3 } });
    vector<pair<int, int>> expected({ { 2, 7 }, { 4, 0 } });
    Solution sol;
    ASSERT_EQ(sol.getSkyline(intput), expected);
}

TEST(Baisc, basic02){
    vector<vector<int>> intput({ { 2, 4, 7 }, { 2, 4, 5 }, { 2, 4, 6 } });
    vector<pair<int, int>> expected({ { 2, 7 }, { 4, 0 } });
    Solution sol;
    ASSERT_EQ(sol.getSkyline(intput), expected);
}

TEST(Baisc, basic01){
    vector<vector<int>> intput({ { 0, 2, 3 }, { 2, 5, 3 } });
    vector<pair<int, int>> expected({ { 0, 3 }, { 5, 0 } });
    Solution sol;
    ASSERT_EQ(sol.getSkyline(intput), expected);
}
