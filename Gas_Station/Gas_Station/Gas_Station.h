// There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
// 
// You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station(i + 1).You begin the journey with an empty tank at one of the gas stations.
// 
// Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
// 
// Note:
// The solution is guaranteed to be unique.
#include <vector>
using namespace std;


class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        const int stationCount = gas.size();
        int accumulatedBalance = 0;
        int maxAccumulatedBalanceIdx = 0;
        int maxAccumulatedBalance = 0;
        for (int i = stationCount - 1; i >= 0; --i){
            accumulatedBalance += gas[i] - cost[i];
            if (maxAccumulatedBalance < accumulatedBalance){
                maxAccumulatedBalance = accumulatedBalance;
                maxAccumulatedBalanceIdx = i;
            }
        }

        int output = -1;
        if (accumulatedBalance >= 0){
            output = maxAccumulatedBalanceIdx;
        }
        return output;
    }
};