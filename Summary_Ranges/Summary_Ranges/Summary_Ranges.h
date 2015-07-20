// Given a sorted integer array without duplicates, return the summary of its ranges.
// 
// For example, given[0, 1, 2, 4, 5, 7], return["0->2", "4->5", "7"].
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> output;
        int lastNum = INT_MIN;
        bool hasNeighbor = false;
        for (auto i : nums){
            if (i == lastNum + 1){
                // consecutive number
                hasNeighbor = true;
            }
            else{
                // end the last range, and start a new one
                if (hasNeighbor){
                    output.rbegin()->append("->");
                    output.rbegin()->append(to_string(lastNum));
                }
                output.push_back(to_string(i));
                hasNeighbor = false;
            }
            lastNum = i;
        }
        if (hasNeighbor){
            output.rbegin()->append("->");
            output.rbegin()->append(to_string(lastNum));
        }
        return output;
    }
};


class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> output;
        int lastNum = INT_MIN;
        bool freshNewRange = true;
        bool hasNeighbor = false;
        for (auto i : nums){
            if (freshNewRange){
                // fresh new range
                output.push_back(to_string(i));
                freshNewRange = false;
            }
            else if (i == lastNum + 1){
                // consecutive number
                hasNeighbor = true;
            }
            else{
                // end the last range, and start a new one
                if (hasNeighbor){
                    output.rbegin()->append("->");
                    output.rbegin()->append(to_string(lastNum));
                }
                output.push_back(to_string(i));
                hasNeighbor = false;
            }
            lastNum = i;
        }
        if (hasNeighbor){
            output.rbegin()->append("->");
            output.rbegin()->append(to_string(lastNum));
        }
        return output;
    }
};