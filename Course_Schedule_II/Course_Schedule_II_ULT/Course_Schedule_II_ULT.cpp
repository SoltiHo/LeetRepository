#include "gtest/gtest.h"  // access test macro
#include "Course_Schedule_II.h"




TEST(Basic, FAIL08){
    vector<pair<int, int>> input({ { 0, 1 }, { 0, 2 }, { 1, 2 } });
    vector<int> expected{ 0, 1, 2 };
    Solution sol;
    ASSERT_EQ(sol.findOrder(3, input), expected);
}


TEST(Basic, FAIL06){
    vector<pair<int, int>> input({ { 0, 1 }, { 3, 1 }, { 1, 3 }, { 3, 2 } });
    vector<int> expected;
    Solution sol;
    ASSERT_EQ(sol.findOrder(4, input), expected);
}

TEST(Basic, FAIL02){
    vector<pair<int, int>> input({ { 1, 0 }, { 2, 1 } });
    vector<int> expected{ 0, 1, 2};
    Solution sol;
    ASSERT_EQ(sol.findOrder(3, input), expected);
}

TEST(Basic, FAIL07){
    vector<pair<int, int>> input({ { 0, 1 } });
    vector<int> expected({1, 0});
    Solution sol;
    ASSERT_EQ(sol.findOrder(2, input), expected);
}


TEST(Basic, FAIL03){
    vector<pair<int, int>> input({ { 1, 0 } });
    vector<int> expected({ 0, 1 });
    Solution sol;
    ASSERT_EQ(sol.findOrder(2, input), expected);
}



TEST(Basic, FAIL05){
    vector<pair<int, int>> input({});
    vector<int> expected({0});
    Solution sol;
    ASSERT_EQ(sol.findOrder(1, input), expected);
}






TEST(Basic, FAIL04){
    vector<pair<int, int>> input({});
    vector<int> expected({ 0 });
    Solution sol;
    ASSERT_EQ(sol.findOrder(1, input), expected);
}







TEST(Basic, FAIL01){
    vector<pair<int, int>> input({ { 1, 0 }, { 2, 0 }, { 0, 1 } });
    vector<int> expected;
    Solution sol;
    ASSERT_EQ(sol.findOrder(3, input), expected);
}

