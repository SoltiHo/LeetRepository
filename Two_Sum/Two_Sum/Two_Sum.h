// Given an array of integers, find two numbers such that they add up to a specific target number.
// 
// The function twoSum should return indices of the two numbers such that they add up to the target, 
// where index1 must be less than index2.Please note that your returned answers(both index1 and index2) are not zero - based.
// 
// You may assume that each input would have exactly one solution.
// 
// Input: numbers = { 2, 7, 11, 15 }, target = 9
//    Output : index1 = 1, index2 = 2

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution_Faster {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> output;
        const int numberCount = numbers.size();
        if (numberCount >= 2){
            unordered_map<int, int> map;
            unordered_map<int, int>::iterator it;
            for (int i = 0; i < numberCount; ++i){
                if ((it = map.find(target - numbers[i])) == map.end()){
                    // no match
                    map.insert({ numbers[i], i + 1 });
                }
                else{
                    // match
                    output.push_back(it->second);
                    output.push_back(i + 1);
                }
            }
        }
        return output;
    }
};

class Solution_Slow {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> output;
        const int numberCount = numbers.size();
        if (numberCount >= 2){
            unordered_map<int, vector<int>> map;
            unordered_map<int, vector<int>>::iterator it;
            for (int i = 0; i < numberCount; ++i){
                if ((it = map.find(numbers[i])) == map.end()){
                    // first time
                    map.insert({ numbers[i], { i + 1 } });
                }
                else{
                    it->second.push_back(i + 1);
                }

            }

            for (int i = 0; i < numberCount; ++i){
                if ((it = map.find(target - numbers[i])) != map.end()){
                    for (auto& c : it->second){
                        if (c != i + 1){
                            output.push_back(min(c, i + 1));
                            output.push_back(max(c, i + 1));
                            break;
                        }
                    }
                }
                if (output.size() > 0){
                    break;
                }
            }

        }
        return output;
    }
};
