//Given an array of size n, find the majority element.The majority element is the element that appears more than floor(n / 2) times.
//
//You may assume that the array is non - empty and the majority element always exist in the array.
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &num) {
        int majority = INT_MIN;
        int count = 0;
        for (auto i : num){
            if (majority == i){
                count++;
            }
            else if (count > 0){
                count--;
            }
            else{
                majority = i;
            }
        }
        return majority;
    }
};