#include "gtest/gtest.h"  // access test macro
#include "Largest_Number.h"

TEST(Leet, Fail01){
    vector<int> input({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 });
    Solution sol;
    string output = sol.largestNumber(input);
    string expected = "9876543210";
    ASSERT_EQ(output, expected);
}


TEST(Leet, Fail02){
    vector<int> input({ 20, 1 });
    Solution sol;
    string output = sol.largestNumber(input);
    string expected = "201";
    ASSERT_EQ(output, expected);
}


TEST(Leet, Fail05){
    vector<int> input({ 12, 121 });
    Solution sol;
    string output = sol.largestNumber(input);
    string expected = "12121";
    ASSERT_EQ(output, expected);
}

TEST(Leet, Fail04){
    vector<int> input({ 824, 938, 1399, 5607, 6973, 5703, 9609, 4398, 8247 });
    Solution sol;
    string output = sol.largestNumber(input);
    string expected = "9609938824824769735703560743981399";
    ASSERT_EQ(output, expected);
}



TEST(Leet, Fail03){
    vector<int> input({ 121, 12 });
    Solution sol;
    string output = sol.largestNumber(input);
    string expected = "12121";
    ASSERT_EQ(output, expected);
}





TEST(Leet, Example){
    vector<int> input({ 3, 30, 34, 5, 9 });
    Solution sol;
    string output = sol.largestNumber(input);
    string expected = "9534330";
    ASSERT_EQ(output, expected);
}