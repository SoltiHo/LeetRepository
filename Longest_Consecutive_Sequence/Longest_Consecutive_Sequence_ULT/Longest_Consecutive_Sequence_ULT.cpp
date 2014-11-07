#include "gtest/gtest.h"  // access test macro
#include "LongestConsecutiveSequence.h"
#include <ctime>
#include <cstdlib>


TEST(Leet, Fail01){
    vector<int> p;

    p.push_back(1);
    p.push_back(0);
    p.push_back(-1);

    Solution sol;

    ASSERT_EQ(sol.longestConsecutive(p), 3);
}

TEST(Leet, Fail02){
    vector<int> p;

    p.push_back(0);


    Solution sol;

    ASSERT_EQ(sol.longestConsecutive(p), 1);
}





TEST(Basic, MyTest01){
    vector<int> p;

    p.push_back(1);
    p.push_back(3);
    p.push_back(2);
    p.push_back(7);

    Solution sol;

    ASSERT_EQ(sol.longestConsecutive(p), 3);
}


TEST(Basic, MyTest02){
    vector<int> p;

    p.push_back(1);
    p.push_back(3);
    p.push_back(9);
    p.push_back(7);

    Solution sol;

    ASSERT_EQ(sol.longestConsecutive(p), 1);
}


