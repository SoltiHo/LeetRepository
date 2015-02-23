// Say you have an array for which the ith element is the price of a given stock on day i.
// 
// Design an algorithm to find the maximum profit.You may complete at most k transactions.
// 
// Note:
// You may not engage in multiple transactions at the same time(ie, you must sell the stock before you buy again).
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;


class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        const int pSize = prices.size();
        int maxProfit = 0;

        if ((pSize >= 2) && (k > 0)){
            if (k > (pSize >> 1)){
                // as many transaction as possible, so just catch every positive gain.
                int lastPrice = INT_MAX;
                for (auto& p : prices){
                    if (p > lastPrice){
                        maxProfit += p - lastPrice;
                    }
                    lastPrice = p;
                }
            }
            else{
                const int transactionCount = k > (pSize >> 1) ? pSize >> 1 : k;
                const int bestResultCount = transactionCount << 1;
                vector<int> bestResults(bestResultCount, 0);

                // bestResultCount[0] is the sell of the last transaction
                // bestResultCount[1] is the buy of the last transaction
                // bestResultCount[2] is the sell of the 2nd to the last transaction
                // bestResultCount[3] is the buy of the 2nd to the last transaction
                // .....
                // bestResultCount[bestResultCount - 2] is the sell of the 1st transaction
                // bestResultCount[bestResultCount - 1] is the buy of the 1st transaction
                for (int i = 1; i < bestResultCount; i += 2){
                    // init the "buy" results to INT_MIN
                    bestResults[i] = INT_MIN;
                }

                for (auto& p : prices){
                    for (int i = 0; i < bestResultCount; ++i){
                        if (i % 2 == 0){
                            // sell
                            bestResults[i] = max(bestResults[i], bestResults[i + 1] + p);
                        }
                        else if (i == bestResultCount - 1){
                            // the last entry.  it's a buy
                            bestResults[i] = max(bestResults[i], 0 - p);
                        }
                        else{
                            // buy
                            bestResults[i] = max(bestResults[i], bestResults[i + 1] - p);
                        }
                    }
                }

                maxProfit = bestResults[0];
            }
        }

        return maxProfit;
    }
};