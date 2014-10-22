
#include "gtest/gtest.h"  // access test macro
#include "Candy.h"


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