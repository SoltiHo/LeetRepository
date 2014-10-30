//  Say you have an array for which the ith element is the price of a given stock on day i.
//  
//  Design an algorithm to find the maximum profit.You may complete as many transactions as you like. (ie, buy one and sell one share of the stock multiple times).
//  However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

#include <vector>
using namespace std;



class Solution {
public:
    int maxProfit(vector<int> &prices) {
        const unsigned int size = prices.size();
        if (size < 2){
            return 0;
        }
        // basic strategy, if up-turn today, then buy at yesterday
        //                 if down-turn today, then sell at yesterday
        //                 start with buy
        int previousBuyPrice = INT_MIN;
        int totalProfit = 0;
        bool alreadyBuy = false;
        for (unsigned int i = 1; i < size; ++i){
            if (prices[i] < prices[i - 1]){
                // down turn
                if (alreadyBuy){
                    // Sell
                    totalProfit += (prices[i - 1] - previousBuyPrice);
                    alreadyBuy = false;
                }
            }
            else if (prices[i] > prices[i - 1]){
                // up turn
                if (!alreadyBuy){
                    // Buy
                    previousBuyPrice = prices[i - 1];
                    alreadyBuy = true;
                }
            } 
        }

        if (alreadyBuy){
            totalProfit += (prices[size - 1] - previousBuyPrice);
        }

        if ((alreadyBuy == false) && (previousBuyPrice == INT_MIN)){
            // always upgoing, never down turn
            // or, always downgoing, never up turn
            if (prices[size - 1] > prices[0]){
                // always upgoing. but at first day and sell at the last day
                totalProfit += (prices[size - 1] - prices[0]);
            }
            
        }
        return totalProfit;
    }
};

