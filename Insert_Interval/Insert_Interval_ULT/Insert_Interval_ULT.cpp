#include "gtest/gtest.h"  // access test macro
#include "Insert_Interval.h"

bool compareTwoIntervalVector(vector<Interval> &intervals1, vector<Interval> &intervals2){
    if (intervals1.size() != intervals2.size()){
        return false;
    }

    for (unsigned int i = 0; i < intervals1.size(); ++i){
        if ((intervals1[i].start != intervals2[i].start) || (intervals1[i].end != intervals2[i].end)){
            return false;
        }
    }

    return true;
}

TEST(MultipleIntervals, RightOnEdge_InBetween){
    std::vector<Interval> intervals;
    Interval temp = { 0, 0 };
    temp.start = 1;
    temp.end = 5;
    intervals.push_back(temp);

    temp.start = 6;
    temp.end = 8;
    intervals.push_back(temp);

    Interval newInterval = { 5, 6 };
    Solution sol;

    sol.insert(intervals, newInterval);

    std::vector<Interval> answer;
    temp.start = 1;
    temp.end = 8;
    answer.push_back(temp);

    ASSERT_TRUE(compareTwoIntervalVector(intervals, answer));
}



TEST(SingleInterval, RightOnEdge_Tail){
    std::vector<Interval> intervals;
    Interval temp = { 0, 0 };
    temp.start = 1;
    temp.end = 5;
    intervals.push_back(temp);

    Interval newInterval = { 5, 7 };
    Solution sol;

    sol.insert(intervals, newInterval);

    std::vector<Interval> answer;
    temp.start = 1;
    temp.end = 7;
    answer.push_back(temp);

    ASSERT_TRUE(compareTwoIntervalVector(intervals, answer));
}


TEST(SingleInterval, RightOnEdge_Head){
    std::vector<Interval> intervals;
    Interval temp = { 0, 0 };
    temp.start = 1;
    temp.end = 5;
    intervals.push_back(temp);

    Interval newInterval = { 0, 1 };
    Solution sol;

    sol.insert(intervals, newInterval);

    std::vector<Interval> answer;
    temp.start = 0;
    temp.end = 5;
    answer.push_back(temp);

    ASSERT_TRUE(compareTwoIntervalVector(intervals, answer));
}

TEST(SingleInterval, PartiallyOverlap_Tail){
    std::vector<Interval> intervals;
    Interval temp = { 0, 0 };
    temp.start = 1;
    temp.end = 5;
    intervals.push_back(temp);

    Interval newInterval = { 3, 9 };
    Solution sol;

    sol.insert(intervals, newInterval);

    std::vector<Interval> answer;
    temp.start = 1;
    temp.end = 9;
    answer.push_back(temp);

    ASSERT_TRUE(compareTwoIntervalVector(intervals, answer));
}


TEST(SingleInterval, PartiallyOverlap_Head){
    std::vector<Interval> intervals;
    Interval temp = { 0, 0 };
    temp.start = 1;
    temp.end = 5;
    intervals.push_back(temp);

    Interval newInterval = { 0, 3 };
    Solution sol;

    sol.insert(intervals, newInterval);

    std::vector<Interval> answer;
    temp.start = 0;
    temp.end = 5;
    answer.push_back(temp);

    ASSERT_TRUE(compareTwoIntervalVector(intervals, answer));
}


TEST(SingleInterval, TotallyOverlap){
    std::vector<Interval> intervals;
    Interval temp = { 0, 0 };
    temp.start = 1;
    temp.end = 5;
    intervals.push_back(temp);

    Interval newInterval = { 1, 7 };
    Solution sol;

    sol.insert(intervals, newInterval);

    std::vector<Interval> answer;
    temp.start = 1;
    temp.end = 7;
    answer.push_back(temp);

    ASSERT_TRUE(compareTwoIntervalVector(intervals, answer));
}

TEST(MultipleIntervals, IndependentInBetween){
    std::vector<Interval> intervals;
    Interval temp = { 0, 0 };
    temp.start = 1;
    temp.end = 2;
    intervals.push_back(temp);

    temp.start = 3;
    temp.end = 5;
    intervals.push_back(temp);

    temp.start = 8;
    temp.end = 10;
    intervals.push_back(temp);

    temp.start = 12;
    temp.end = 16;
    intervals.push_back(temp);

    Interval newInterval = { 6, 7 };
    Solution sol;

    sol.insert(intervals, newInterval);

    std::vector<Interval> answer;
    temp.start = 1;
    temp.end = 2;
    answer.push_back(temp);

    temp.start = 3;
    temp.end = 5;
    answer.push_back(temp);

    temp.start = 6;
    temp.end = 7;
    answer.push_back(temp);

    temp.start = 8;
    temp.end = 10;
    answer.push_back(temp);

    temp.start = 12;
    temp.end = 16;
    answer.push_back(temp);
    ASSERT_TRUE(compareTwoIntervalVector(intervals, answer));
}

TEST(MultipleIntervals, Tail){
    std::vector<Interval> intervals;
    Interval temp = { 0, 0 };
    temp.start = 1;
    temp.end = 2;
    intervals.push_back(temp);

    temp.start = 3;
    temp.end = 5;
    intervals.push_back(temp);

    temp.start = 6;
    temp.end = 7;
    intervals.push_back(temp);

    temp.start = 8;
    temp.end = 10;
    intervals.push_back(temp);

    temp.start = 12;
    temp.end = 16;
    intervals.push_back(temp);

    Interval newInterval = { 13, 19 };
    Solution sol;

    sol.insert(intervals, newInterval);

    std::vector<Interval> answer;
    temp.start = 1;
    temp.end = 2;
    answer.push_back(temp);

    temp.start = 3;
    temp.end = 5;
    answer.push_back(temp);

    temp.start = 6;
    temp.end = 7;
    answer.push_back(temp);

    temp.start = 8;
    temp.end = 10;
    answer.push_back(temp);

    temp.start = 12;
    temp.end = 19;
    answer.push_back(temp);
    ASSERT_TRUE(compareTwoIntervalVector(intervals, answer));
}

TEST(MultipleIntervals, Head){
    std::vector<Interval> intervals;
    Interval temp = { 0, 0 };
    temp.start = 1;
    temp.end = 2;
    intervals.push_back(temp);

    temp.start = 3;
    temp.end = 5;
    intervals.push_back(temp);

    temp.start = 6;
    temp.end = 7;
    intervals.push_back(temp);

    temp.start = 8;
    temp.end = 10;
    intervals.push_back(temp);

    temp.start = 12;
    temp.end = 16;
    intervals.push_back(temp);

    Interval newInterval = { 0, 5 };
    Solution sol;

    sol.insert(intervals, newInterval);

    std::vector<Interval> answer;
    temp.start = 0;
    temp.end = 5;
    answer.push_back(temp);

    temp.start = 6;
    temp.end = 7;
    answer.push_back(temp);

    temp.start = 8;
    temp.end = 10;
    answer.push_back(temp);

    temp.start = 12;
    temp.end = 16;
    answer.push_back(temp);
    ASSERT_TRUE(compareTwoIntervalVector(intervals, answer));
}


TEST(MultipleIntervals, Example01){
    std::vector<Interval> intervals;
    Interval temp = { 0, 0 };    
    temp.start = 1;
    temp.end = 3;
    intervals.push_back(temp);

    temp.start = 6;
    temp.end = 9;
    intervals.push_back(temp);

    Interval newInterval = { 2, 5 };
    Solution sol;

    sol.insert(intervals, newInterval);

    std::vector<Interval> answer;
    temp.start = 1;
    temp.end = 5;
    answer.push_back(temp);

    temp.start = 6;
    temp.end = 9;
    answer.push_back(temp);

    ASSERT_TRUE(compareTwoIntervalVector(intervals, answer));
}

TEST(MultipleIntervals, Example02){
    std::vector<Interval> intervals;
    Interval temp = { 0, 0 };
    temp.start = 1;
    temp.end = 2;
    intervals.push_back(temp);

    temp.start = 3;
    temp.end = 5;
    intervals.push_back(temp);

    temp.start = 6;
    temp.end = 7;
    intervals.push_back(temp);

    temp.start = 8;
    temp.end = 10;
    intervals.push_back(temp);

    temp.start = 12;
    temp.end = 16;
    intervals.push_back(temp);

    Interval newInterval = { 4, 9 };
    Solution sol;

    sol.insert(intervals, newInterval);

    std::vector<Interval> answer;
    temp.start = 1;
    temp.end = 2;
    answer.push_back(temp);

    temp.start = 3;
    temp.end = 10;
    answer.push_back(temp);

    temp.start = 12;
    temp.end = 16;
    answer.push_back(temp);
    ASSERT_TRUE(compareTwoIntervalVector(intervals, answer));
}


TEST(MultipleIntervals, IdenticalToExisting){
    std::vector<Interval> intervals;
    Interval temp = { 0, 0 };
    temp.start = 1;
    temp.end = 2;
    intervals.push_back(temp);

    temp.start = 3;
    temp.end = 5;
    intervals.push_back(temp);

    temp.start = 6;
    temp.end = 7;
    intervals.push_back(temp);

    temp.start = 8;
    temp.end = 10;
    intervals.push_back(temp);

    temp.start = 12;
    temp.end = 16;
    intervals.push_back(temp);

    Interval newInterval = { 3, 5 };
    Solution sol;

    sol.insert(intervals, newInterval);

    std::vector<Interval> answer;
    temp.start = 1;
    temp.end = 2;
    answer.push_back(temp);

    temp.start = 3;
    temp.end = 5;
    answer.push_back(temp);

    temp.start = 6;
    temp.end = 7;
    answer.push_back(temp);

    temp.start = 8;
    temp.end = 10;
    answer.push_back(temp);

    temp.start = 12;
    temp.end = 16;
    answer.push_back(temp);
    ASSERT_TRUE(compareTwoIntervalVector(intervals, answer));
}