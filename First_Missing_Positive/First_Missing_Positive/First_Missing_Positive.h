// Given an unsorted integer array, find the first missing positive integer.
// 
// For example,
// Given[1, 2, 0] return 3,
// and[3, 4, -1, 1] return 2.
// 
// Your algorithm should run in O(n) time and uses constant space.

#include <unordered_map>
using namespace std;

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        unordered_map<int, int> hashTable;
        unordered_map<int, int>::iterator it;
        if (n == 0){
            return 1;
        }

        int lowerBound = 0;
        int upperBound = 0;
        for (int i = 0; i < n; ++i){
            if (A[i] > 0){
                it = hashTable.find(A[i]);
                if (it != hashTable.end()){
                    // found
                    continue;
                }
                else{
                    // not found
                    upperBound = lowerBound = A[i];

                    it = hashTable.find(A[i] - 1);
                    if (it != hashTable.end()){
                        // found previous key
                        upperBound = it->second;
                    }

                    it = hashTable.find(A[i] + 1);
                    if (it != hashTable.end()){
                        // found previous key
                        lowerBound = it->second;
                    }

                    hashTable[A[i]] = A[i];
                    hashTable[lowerBound] = upperBound;
                    hashTable[upperBound] = lowerBound;

                }
            }
        }


        int output = 1;
        it = hashTable.find(1);
        if (it != hashTable.end()){
            output = it->second + 1;
        }

        return output;
    }
};

