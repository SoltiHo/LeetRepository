// Given an array of integers, every element appears three times except for one.Find that single one.
// 
// Note:
// Your algorithm should have a linear runtime complexity.Could you implement it without using extra memory ?

#include <unordered_map>
using namespace std;

class Solution_HashTable {
public:
    int singleNumber(int A[], int n) {
        unordered_map<int, int> counter;
        unordered_map<int, int>::iterator it;
        for (int i = 0; i < n; ++i){
            if ((it = counter.find(A[i])) == counter.end()){
                // new number
                counter.insert({ A[i], 1 });
            }
            else{
                it->second++;
            }
        }

        for (auto& i : counter){
            if (i.second != 3){
                return i.first;
            }
        }
    }
};


class Solution {
public:
    int singleNumber(int A[], int n) {
        unordered_map<int, int> counter;
        unordered_map<int, int>::iterator it;
        for (int i = 0; i < n; ++i){
            if ((it = counter.find(A[i])) == counter.end()){
                // new number
                counter.insert({ A[i], 1 });
            }
            else{
                it->second++;
            }
        }

        for (auto& i : counter){
            if (i.second != 3){
                return i.first;
            }
        }
    }
};