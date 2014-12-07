
#include "gtest/gtest.h"  // access test macro
#include "Candy.h"


TEST(Candy, FAIL_04){
    std::vector<int> ratings({ 58, 21, 72, 77, 48, 9, 38, 71, 68, 77, 82, 47, 25, 94, 89, 54, 26, 54, 54, 99, 64, 71, 76, 63, 81, 82, 60, 64, 29, 51, 87, 87, 72, 12, 16, 20, 21, 54, 43, 41, 83, 77, 41, 61, 72, 82, 15, 50, 36, 69, 49, 53, 92, 77, 16, 73, 12, 28, 37, 41, 79, 25, 80, 3, 37, 48, 23, 10, 55, 19, 51, 38, 96, 92, 99, 68, 75, 14, 18, 63, 35, 19, 68, 28, 49, 36, 53, 61, 64, 91, 2, 43, 68, 34, 46, 57, 82, 22, 67, 89 });

    Solution sol;
    ASSERT_EQ(sol.candy(ratings), 208);
}

TEST(Candy, FAIL_03){
    std::vector<int> ratings;

    ratings.push_back(1);

    Solution sol;
    ASSERT_EQ(sol.candy(ratings), 1);
}


TEST(Candy, FAIL_02){
    std::vector<int> ratings;

    ratings.push_back(1);
    ratings.push_back(2);
    ratings.push_back(4);
    ratings.push_back(4);
    ratings.push_back(3);

    Solution sol;
    ASSERT_EQ(sol.candy(ratings), 9);
}


TEST(Candy, FAIL_01){
    std::vector<int> ratings;

    ratings.push_back(1);
    ratings.push_back(2);
    ratings.push_back(2);

    Solution sol;
    ASSERT_EQ(sol.candy(ratings), 4);
}


TEST(Candy, BASIC_EVEN){
    std::vector<int> ratings;

    ratings.push_back(3);
    ratings.push_back(1);
    ratings.push_back(1);
    ratings.push_back(3);
    ratings.push_back(4);
    ratings.push_back(1);

    Solution sol;
    ASSERT_EQ(sol.candy(ratings), 10);
}


TEST(Candy, BASIC_ODD){
    std::vector<int> ratings;

    ratings.push_back(1);
    ratings.push_back(2);
    ratings.push_back(6);
    ratings.push_back(2);
    ratings.push_back(4);

    Solution sol;
    ASSERT_EQ(sol.candy(ratings), 9);
}

TEST(Candy, FLAT_ODD){
    std::vector<int> ratings;

    ratings.push_back(2);
    ratings.push_back(2);
    ratings.push_back(2);
    ratings.push_back(2);
    ratings.push_back(2);

    Solution sol;
    ASSERT_EQ(sol.candy(ratings), 5);
}

TEST(Candy, FLAT_EVEN){
    std::vector<int> ratings;

    ratings.push_back(3);
    ratings.push_back(3);
    ratings.push_back(3);
    ratings.push_back(3);
    ratings.push_back(3);
    ratings.push_back(3);

    Solution sol;
    ASSERT_EQ(sol.candy(ratings), 6);
}

TEST(Candy, WAVE_EVEN_BIG_START){
    std::vector<int> ratings;

    ratings.push_back(3);
    ratings.push_back(1);
    ratings.push_back(3);
    ratings.push_back(1);
    ratings.push_back(3);
    ratings.push_back(1);

    Solution sol;
    ASSERT_EQ(sol.candy(ratings), 9);
}
TEST(Candy, WAVE_EVEN_SMALL_START){
    std::vector<int> ratings;
        
    ratings.push_back(1);
    ratings.push_back(3);
    ratings.push_back(1);
    ratings.push_back(3);
    ratings.push_back(1);
    ratings.push_back(3);

    Solution sol;
    ASSERT_EQ(sol.candy(ratings), 9);
}

TEST(Candy, WAVE_ODD_SMALL_START){
    std::vector<int> ratings;

    ratings.push_back(1);
    ratings.push_back(3);
    ratings.push_back(1);
    ratings.push_back(3);
    ratings.push_back(1);

    Solution sol;
    ASSERT_EQ(sol.candy(ratings), 7);
}
TEST(Candy, WAVE_ODD_BIG_START){
    std::vector<int> ratings;


    ratings.push_back(3);
    ratings.push_back(1);
    ratings.push_back(3);
    ratings.push_back(1);
    ratings.push_back(3);

    Solution sol;
    ASSERT_EQ(sol.candy(ratings), 8);
}