// You are a professional robber planning to rob houses along a street.Each house has a certain amount of money stashed, 
// the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and 
// it will automatically contact the police if two adjacent houses were broken into on the same night.
//
// Given a list of non - negative integers representing the amount of money of each house, determine the maximum amount of money 
// you can rob tonight without alerting the police.
#include <vector>
#include <algorithm>
using namespace std;


class SolutionLatest {
public:
    int rob(vector<int> &num) {
        int prev1result = 0;
        int prev2result = 0;
        for (auto n : num){
            int newResult = max(prev1result, prev2result + n);
            prev2result = prev1result;
            prev1result = newResult;
        }
        
        return prev1result;
    }
};

class Solution {
public:
    int rob(vector<int> &num) {
        int prev1result = 0;
        int prev2result = 0;
        bool prev1Robbed = false;
        int currResult = 0;
        for (auto i : num){
            if (prev1Robbed){
                if (prev1result > prev2result + i){
                    // prefer keeping the prev1 and skip curr
                    currResult = prev1result;
                    prev1Robbed = false;
                }
                else{
                    // keep current one
                    currResult = prev2result + i;
                    prev1Robbed = true;
                }
            }
            else{
                currResult = prev1result + i;
                prev1Robbed = true;
            }
            prev2result = prev1result;
            prev1result = currResult;
        }

        return currResult;
    }
};
