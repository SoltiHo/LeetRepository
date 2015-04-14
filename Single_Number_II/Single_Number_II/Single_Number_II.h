// Given an array of integers, every element appears three times except for one.Find that single one.
// 
// Note:
// Your algorithm should have a linear runtime complexity.Could you implement it without using extra memory ?

#include <unordered_map>
using namespace std;

class Solution_LatestTrial {
public:
    int singleNumber(int A[], int n) {
        int AA = 0; // twice
        int BB = 0; // once
        int lastAA = 0;
        int lastBB = 0;
        for (int i = 0; i < n; ++i){
            lastAA = AA;
            lastBB = BB;
            AA = (A[i] & lastBB) | (~A[i] & lastAA);
            BB = (A[i] & ~lastAA & ~lastBB) | (~A[i] & lastBB);
        }

        if (n % 3 == 2){
            return AA;
        }
        else{
            return BB;
        }
    }
};

class Solution_LogicTable {
public:
    int singleNumber(int A[], int n) {
        int once = 0;
        int twice = 0;
        int lastOnce = 0;
        int lastTwice = 0;
        for (int i = 0; i < n; ++i){
            lastOnce = once;
            lastTwice = twice;
            once = (A[i] & (~lastOnce) & (~lastTwice)) | (~A[i] & lastOnce);
            twice = (A[i] & lastOnce) | (~A[i] & lastTwice);
        }

        if (n % 3 == 2){
            return twice;
        }
        else{
            return once;
        }
    }
};

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