#include "gtest/gtest.h"  // access test macro
#include "BestTimeToBuyAndSellStockIII.h"


TEST(LeetTestCases, Fail05){
    vector<int> prices;
    prices.push_back(2);
    prices.push_back(1);
    prices.push_back(2);
    prices.push_back(1);
    prices.push_back(0);
    prices.push_back(0);
    prices.push_back(1);

    Solution sol;
    ASSERT_EQ(sol.maxProfit(prices), 2);

}

TEST(LeetTestCases, Fail04){
    vector<int> prices;
    prices.push_back(2);
    prices.push_back(1);
    prices.push_back(2);
    prices.push_back(0);
    prices.push_back(1);

    Solution sol;
    ASSERT_EQ(sol.maxProfit(prices), 2);

}


TEST(LeetTestCases, Fail03){
    vector<int> prices;
    prices.push_back(2);
    prices.push_back(1);
    prices.push_back(4);

    Solution sol;
    ASSERT_EQ(sol.maxProfit(prices), 3);

}


TEST(LeetTestCases, Fail02){
    vector<int> prices;
    for (unsigned int i = 10000; i; --i){
        prices.push_back(i);
    }
    
    for (unsigned int i = 16004; i; --i){
        prices.push_back(0);
    }

    Solution sol;
    ASSERT_EQ(sol.maxProfit(prices), 0);

}

TEST(LeetTestCases, Fail01){
    vector<int> prices;
    prices.push_back(1);
    prices.push_back(2);
    prices.push_back(4);

    Solution sol;
    ASSERT_EQ(sol.maxProfit(prices), 3);

}


TEST(ManyPrices, Monotonically_Increasing){
    vector<int> prices;
    prices.push_back(1);
    prices.push_back(2);
    prices.push_back(4);
    prices.push_back(4);
    prices.push_back(7);
    prices.push_back(9);
    prices.push_back(9);

    Solution sol;
    ASSERT_EQ(sol.maxProfit(prices), 8);

}

TEST(ManyPrices, Monotonically_Decreasing){
    vector<int> prices;
    prices.push_back(9);
    prices.push_back(9);
    prices.push_back(7);
    prices.push_back(4);
    prices.push_back(4);
    prices.push_back(2);
    prices.push_back(1);


    Solution sol;
    ASSERT_EQ(sol.maxProfit(prices), 0);

}