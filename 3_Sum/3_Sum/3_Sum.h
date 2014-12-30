// Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0 ? Find all unique triplets in the array which gives the sum of zero.
// 
// Note :
//      Elements in a triplet(a, b, c) must be in non - descending order. (ie, a <= b <= c)
//      The solution set must not contain duplicate triplets.
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &num) {
        vector<vector<int>> output;
        const int numSize = num.size();
        if (numSize > 2){
            sort(num.begin(), num.end());
            vector<int> counter;
            vector<int> numDist;
            unordered_map<int, int> map; // number --> counter array idx
            counter.push_back(1);
            numDist.push_back(num[0]);
            map.insert({ num[0], counter.size() - 1 });
            for (int i = 1; i < numSize; ++i){
                if (num[i] == num[i - 1]){
                    counter[counter.size() - 1]++;
                }
                else{
                    // a new number
                    counter.push_back(1);
                    numDist.push_back(num[i]);
                    map.insert({ num[i], counter.size() - 1});
                }
            }

            const int counterSize = counter.size();
            int remaining = 0;
            for (int headIdx = 0; headIdx <= counterSize - 1; ++headIdx){
                for (int TailIdx = headIdx + 1; TailIdx <= counterSize - 1; ++TailIdx){
                    remaining = 0 - numDist[headIdx] - numDist[TailIdx];
                    if (remaining == numDist[headIdx]){
                        if (counter[headIdx] > 1){
                            output.push_back({ numDist[headIdx], numDist[headIdx], numDist[TailIdx] });
                        }
                    }
                    else if (remaining == numDist[TailIdx]){
                        if (counter[TailIdx] > 1){
                            output.push_back({ numDist[headIdx], numDist[TailIdx], numDist[TailIdx] });
                        }
                    }
                    else if ((remaining > numDist[headIdx]) && (remaining < numDist[TailIdx])){
                        if ((map.count(remaining) == 1) && (map[remaining] > headIdx) && (map[remaining] < TailIdx)){
                            // found
                            output.push_back({ numDist[headIdx], numDist[map[remaining]], numDist[TailIdx] });
                        }
                    }
                }
            }
        

            if ((map.count(0) == 1) && (counter[map[0]] >= 3)){
                output.push_back({ 0, 0, 0 });
            }
        }
        return output;
    }

};