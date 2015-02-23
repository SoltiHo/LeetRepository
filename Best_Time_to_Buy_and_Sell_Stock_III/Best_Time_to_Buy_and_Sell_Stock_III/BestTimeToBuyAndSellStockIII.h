//  Say you have an array for which the ith element is the price of a given stock on day i.
//  
//  Design an algorithm to find the maximum profit.You may complete at most two transactions.
//  
//  Note:
//  You may not engage in multiple transactions at the same time(ie, you must sell the stock before you buy again).

#include <vector>
#include <algorithm>
using namespace std;



class Solution_LatestTrial_geniusOnForum {
public:
    int maxProfit(vector<int> &prices) {
        int bestAfterBuyingFirstBalance = INT_MIN;
        int bestAfterBuyingSecondBalance = INT_MIN;
        int bestAfterSellingFirstBalance = 0;  // init to 0 because if it's below 0, then we don't do transactions
        int bestAfterSellingSecondBalance = 0;

        for (auto& i : prices){
            bestAfterSellingSecondBalance = max(bestAfterSellingSecondBalance, bestAfterBuyingSecondBalance + i);
            bestAfterBuyingSecondBalance = max(bestAfterBuyingSecondBalance, bestAfterSellingFirstBalance - i);
            bestAfterSellingFirstBalance = max(bestAfterSellingFirstBalance, bestAfterBuyingFirstBalance + i);
            bestAfterBuyingFirstBalance = max(bestAfterBuyingFirstBalance, 0 - i);
        }
        return bestAfterSellingSecondBalance;  // return 2nd is enough because if the 2nd transaction doesn't help, it won't survive the max operations
    }
};

class Solution_LatestTrial {
public:
    // this is wrong algorithm
    int maxProfit(vector<int> &prices) {
        int output = 0;
        int bestSingleTransactionProfitBefore = 0;
        int minPriceAfterBestSingleTransaction = INT_MAX;
        int minPriceEver = INT_MAX;
        for (auto& p : prices){
            // evaluate curr p to be the sell of the 2nd transaction
            if ((p > minPriceAfterBestSingleTransaction) && (bestSingleTransactionProfitBefore != 0)){
                // meaning 2nd transaction possible
                output = max(output, p - minPriceAfterBestSingleTransaction + bestSingleTransactionProfitBefore);
            }
            // evaluate curr p to be the sell of the only transaction
            if ((p > minPriceEver) && (p - minPriceEver > bestSingleTransactionProfitBefore)){
                minPriceAfterBestSingleTransaction = p;
                bestSingleTransactionProfitBefore = p - minPriceEver;
                output = max(output, bestSingleTransactionProfitBefore);
            }

            // update mins
            minPriceEver = min(minPriceEver, p);
            minPriceAfterBestSingleTransaction = min(minPriceAfterBestSingleTransaction, p);
        }


        return output;
    }
};



struct Upturn {
    int price;
    int bestProfitBeofre;
};

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        const unsigned int size = prices.size();
        if (size < 2){
            return 0;
        }
        else if (size == 2){
            if (prices[1] > prices[0]){
                return (prices[1] - prices[0]);
            }
            else{
                return 0;
            }
        }
        // Assume S is the opt solution for P1,... Pn.  could be one or two transaction
        // Pn could be part of S or not.
        // if Pn is not part of S, then S is still the opt soultion for P1,... Pn-1
        // if Pn is part of S, then Pn must be a sell point
        //        - a sell point of the only transaction.
        //               profit = Pn - previous lowest price
        //        - a sell point of the 2nd transaction
        //               every previous low point could be its corresonding buy point, say Pk
        //               and its correspoinding 1st transaction is the single best transaction for P1... Pk-1
        //               profit = Pn - Pk + best 1st transaction for Pk-1,  for k = 0 ~ n-1.  (not every k needed, only up-turns)

        int bestTotalProfit = 0;
        vector<Upturn> upturns;
        Upturn temp;
        vector<int> candidates;
        int lowestPrice = INT_MAX;
        int bestSingleTransactionBenefitSoFar = 0;
        int* bestSingleTransactionProfit = new int[size];
        int ifSellTodayProfit = 0;

        bestSingleTransactionProfit[0] = 0;
        for (unsigned int i = 0; i < size; ++i){
            // detect up-turn
            if (i >= 2){
                if ((prices[i] > prices[i - 1]) && (prices[i - 2] >= prices[i - 1])) {
                    // local minimum at [i - 1]
                    temp.bestProfitBeofre = bestSingleTransactionProfit[i - 2];
                    temp.price = prices[i - 1]; // the local minimum
                    upturns.push_back(temp);
                }
            }

            if (i >= 1){
                // if the trend is decreasing, no need to check, since the last day won't be a better sell point
                if (prices[i] > prices[i - 1]){
                    // calculate the candidates
                    candidates.push_back(bestTotalProfit); // best profit so far, meaning Pn is not involved
                    push_heap(candidates.begin(), candidates.end());  // O(log n) operation

                    ifSellTodayProfit = prices[i] - lowestPrice; // if Pn is involved and one single tranaction
                    candidates.push_back(ifSellTodayProfit);
                    push_heap(candidates.begin(), candidates.end());  // O(log n) operation

                    for (unsigned int j = 0; j < upturns.size(); ++j){
                        candidates.push_back(prices[i] - upturns[j].price + upturns[j].bestProfitBeofre);
                        push_heap(candidates.begin(), candidates.end());  // O(log n) operation
                    }

                    // update the best profit
                    bestTotalProfit = candidates[0];
                    candidates.clear();
                }
            }

            // maintain best single transaction history
            if (i >= 1){
                bestSingleTransactionProfit[i] = max(bestSingleTransactionBenefitSoFar, prices[i] - lowestPrice);
                bestSingleTransactionBenefitSoFar = bestSingleTransactionProfit[i];
            }
            // decide the lowest price ever.  do this last so that don't affect the calculation above
            if (prices[i] < lowestPrice) {
                lowestPrice = prices[i];
            }

        }
        return bestTotalProfit;
    }
};

