#include "gtest/gtest.h"  // access test macro
#include "4Sum.h"




TEST(DP, Fail03){
    vector<int> input({ 0, 1, 5, 0, 1, 5, 5, -4 });
    int target = 11;
    Solution_DP sol;

    vector<vector<int>> expected({ { 0, 1, 5, 5 }, { -4, 5, 5, 5 } });
    ASSERT_EQ(sol.fourSum(input, target), expected);
}

TEST(DP, Fail01){
    vector<int> input({ 0, 0, 0, 0 });
    int target = 0;
    Solution_DP sol;

    vector<vector<int>> expected({ { 0, 0, 0, 0 } });
    ASSERT_EQ(sol.fourSum(input, target), expected);
}

TEST(DP, Fail02){
    vector<int> input({ 1, 4, -3, 0, 0, 0, 5, 0 });
    int target = 0;
    Solution_DP sol;

    vector<vector<int>> expected({ { 0, 0, 0, 0 } });
    ASSERT_EQ(sol.fourSum(input, target), expected);
}

TEST(DP, Fail04){
    vector<int> input({ -5, 5, 4, -3, 0, 0, 4, -2 });
    int target = 4;
    Solution_DP sol;

    vector<vector<int>> expected({ { -3, -2, 4, 5 }, { -5, 0, 4, 5 } });
    ASSERT_EQ(sol.fourSum(input, target), expected);
}

// --------------------------------------------------------------------

TEST(Permutation_Sorted, Timeout03){
    vector<int> input({ -493, -482, -482, -456, -427, -405, -392, -385, -351, -269, -259, -251, -235, -235, -202, -201, -194, -189, -187, -186, -180, -177, -175, -156, -150, -147, -140, -122, -112, -112, -105, -98, -49, -38, -35, -34, -18, 20, 52, 53, 57, 76, 124, 126, 128, 132, 142, 147, 157, 180, 207, 227, 274, 296, 311, 334, 336, 337, 339, 349, 354, 363, 372, 378, 383, 413, 431, 471, 474, 481, 492 });
    int target = 6189;
    Solution_Permutation_Sorted sol;

    vector<vector<int>> expected(
    { { -10, 2, 9, 10 }, { -9, 1, 9, 10 }, { -9, 6, 7, 7 }, { -8, 2, 7, 10 }, { -7, 1, 7, 10 },
    { -7, 2, 6, 10 }, { -7, 2, 7, 9 }, { -6, -2, 9, 10 }, { -6, 1, 6, 10 }, { -6, 1, 7, 9 },
    { -6, 2, 6, 9 }, { -5, 1, 6, 9 }, { -5, 2, 7, 7 }, { -4, -4, 9, 10 }, { -4, -2, 7, 10 },
    { -4, 1, 7, 7 }, { -4, 2, 6, 7 }, { -2, 1, 2, 10 } });

    ASSERT_EQ(sol.fourSum(input, target), expected);
}

TEST(Permutation_Sorted, Fail01){
    vector<int> input({ 0 });
    int target = 0;
    Solution_Permutation_Sorted sol;

    vector<vector<int>> expected;
    ASSERT_EQ(sol.fourSum(input, target), expected);
}

TEST(Permutation_Sorted, Timeout01){
    vector<int> input({ -4, -3, -2, -1, 0, 0, 1, 2, 3, 4 });
    int target = 0;
    Solution_Permutation_Sorted sol;

    vector<vector<int>> expected(
    { { -4, -3, 3, 4 }, { -4, -2, 2, 4 }, { -4, -1, 1, 4 }, { -4, -1, 2, 3 },
      { -4,  0, 0, 4 }, { -4,  0, 1, 3 }, { -3, -2, 1, 4 }, { -3, -2, 2, 3 },
      { -3, -1, 0, 4 }, { -3, -1, 1, 3 }, { -3,  0, 0, 3 }, { -3,  0, 1, 2 },
      { -2, -1, 0, 3 }, { -2, -1, 1, 2 }, { -2,  0, 0, 2 }, { -1,  0, 0, 1 } });

    ASSERT_EQ(sol.fourSum(input, target), expected);
}

TEST(Permutation_Sorted, Timeout02){
    vector<int> input({ -9, 6, -10, 1, -4, -6, -5, 2, -2, -7, -8, 7, -8, -9, -9, 7, -4, 9, 10 });
    int target = 11;
    Solution_Permutation_Sorted sol;

    vector<vector<int>> expected(
    { { -10, 2, 9, 10 }, { -9, 1, 9, 10 }, { -9,  6, 7,  7 }, { -8,  2, 7, 10 }, { -7,  1, 7, 10 }, 
      { -7,  2, 6, 10 }, { -7, 2, 7,  9 }, { -6, -2, 9, 10 }, { -6,  1, 6, 10 }, { -6,  1, 7,  9 },
      { -6,  2, 6,  9 }, { -5, 1, 6,  9 }, { -5,  2, 7,  7 }, { -4, -4, 9, 10 }, { -4, -2, 7, 10 }, 
      { -4,  1, 7,  7 }, { -4, 2, 6,  7 }, { -2,  1, 2, 10 } });

    ASSERT_EQ(sol.fourSum(input, target), expected);
}




// --------------------------------------------------------------------

TEST(Permutation, Fail01){
    vector<int> input({ 0 });
    int target = 0;
    Solution_Permutation sol;

    vector<vector<int>> expected;
    ASSERT_EQ(sol.fourSum(input, target), expected);
}

TEST(Permutation, Timeout01){
    vector<int> input({ -4, -3, -2, -1, 0, 0, 1, 2, 3, 4 });
    int target = 0;
    Solution_Permutation sol;

    vector<vector<int>> expected(
    { { -4, -3, 3, 4 }, { -4, -2, 2, 4 }, { -4, -1, 1, 4 }, { -4, -1, 2, 3 }, 
      { -4,  0, 0, 4 }, { -4,  0, 1, 3 }, { -3, -2, 1, 4 }, { -3, -2, 2, 3 }, 
      { -3, -1, 0, 4 }, { -3, -1, 1, 3 }, { -3,  0, 0, 3 }, { -3,  0, 1, 2 }, 
      { -2, -1, 0, 3 }, { -2, -1, 1, 2 }, { -2,  0, 0, 2 }, { -1,  0, 0, 1 } });

    ASSERT_EQ(sol.fourSum(input, target), expected);
}

TEST(Permutation, Timeout02){
    vector<int> input({ -9, 6, -10, 1, -4, -6, -5, 2, -2, -7, -8, 7, -8, -9, -9, 7, -4, 9, 10 });
    int target = 11;
    Solution_Permutation sol;

    vector<vector<int>> expected(
    { { -9,  6, 7,  7 }, { -9, 1, 9, 10 }, { -2, 1, 2, 10 }, { -10,  2, 9, 10 }, { -6, -2, 9, 10 }, 
      { -6,  1, 6, 10 }, { -6, 1, 7,  9 }, { -6, 2, 6,  9 }, {  -4, -2, 7, 10 }, { -4,  1, 7,  7 }, 
      { -4, -4, 9, 10 }, { -4, 2, 6,  7 }, { -5, 1, 6,  9 }, {  -5,  2, 7,  7 }, { -7,  1, 7, 10 },
      { -7,  2, 6, 10 }, { -7, 2, 7,  9 }, { -8, 2, 7, 10 } });

    ASSERT_EQ(sol.fourSum(input, target), expected);
}


TEST(Permutation, Timeout03){
    vector<int> input({ -493, -482, -482, -456, -427, -405, -392, -385, -351, -269, -259, -251, -235, -235, -202, -201, -194, -189, -187, -186, -180, -177, -175, -156, -150, -147, -140, -122, -112, -112, -105, -98, -49, -38, -35, -34, -18, 20, 52, 53, 57, 76, 124, 126, 128, 132, 142, 147, 157, 180, 207, 227, 274, 296, 311, 334, 336, 337, 339, 349, 354, 363, 372, 378, 383, 413, 431, 471, 474, 481, 492 });
    int target = 6189;
    Solution_Permutation sol;

    vector<vector<int>> expected(
    { { -10, 2, 9, 10 }, { -9, 1, 9, 10 }, { -9, 6, 7, 7 }, { -8, 2, 7, 10 }, { -7, 1, 7, 10 },
    { -7, 2, 6, 10 }, { -7, 2, 7, 9 }, { -6, -2, 9, 10 }, { -6, 1, 6, 10 }, { -6, 1, 7, 9 },
    { -6, 2, 6, 9 }, { -5, 1, 6, 9 }, { -5, 2, 7, 7 }, { -4, -4, 9, 10 }, { -4, -2, 7, 10 },
    { -4, 1, 7, 7 }, { -4, 2, 6, 7 }, { -2, 1, 2, 10 } });

    ASSERT_EQ(sol.fourSum(input, target), expected);
}

// --------------------------------------------------------------------

