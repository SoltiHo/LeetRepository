// Say you have an array for which the ith element is the price of a given stock on day i.
// 
// If you were only permitted to complete at most one transaction(ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int lowestPriceIndex = 0;
        int lowestPrice = INT_MAX;
        int overallProfit = 0;
        int ifSellTodayProfit = 0;

        const unsigned int size = prices.size();
        for (unsigned int i = 0; i < size; ++i){
            // keep remembering the lowest in the past
            if (prices[i] < lowestPrice){
                lowestPrice = prices[i];
                lowestPriceIndex = i;
            }

            if (i != lowestPriceIndex){
                ifSellTodayProfit = (prices[i] - lowestPrice);
                if (ifSellTodayProfit > overallProfit){
                    overallProfit = ifSellTodayProfit;
                }
            }
        }

        return overallProfit;
    }
};