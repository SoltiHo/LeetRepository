#include "gtest/gtest.h"  // access test macro
#include "Merge_Intervals.h"


bool equal(vector<Interval> v1, vector<Interval> v2){
    if (v1.size() != v2.size()){
        return false;
    }
    while ((v1.size() > 0) && (v2.size() > 0)){
        for (int i = 0; i < v2.size(); ++i){
            if ((v1[0].start == v2[i].start) && (v1[0].end == v2[i].end)){
                v1.erase(v1.begin());
                v2.erase(v2.begin() + i);
                break;
            }
            if (i == v2.size() - 1){
                return false;
            }
        }
    }

    return true;
}

TEST(LeetCode, Fail02){
    vector<Interval> input = { { 1, 4 }, { 5, 6 } };

    Solution sol;
    vector<Interval> output = sol.merge(input);
    vector<Interval> expected = { { 1, 4 }, {5, 6} };

    ASSERT_TRUE(equal(output, expected));
}

TEST(LeetCode, Fail01){
    vector<Interval> input = { { 2, 3 }, { 0, 1 }, { 1, 2 }, { 3, 4 }, { 4, 5 }, { 1, 1 }, { 0, 1 }, { 4, 6 }, { 5, 7 }, { 1, 1 }, { 3, 5 } };

    Solution sol;
    vector<Interval> output = sol.merge(input);
    vector<Interval> expected = { { 0, 7 } };

    ASSERT_TRUE(equal(output, expected));
}
