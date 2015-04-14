// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
// 
// If such arrangement is not possible, it must rearrange it as the lowest possible order(ie, sorted in ascending order).
// 
// The replacement must be in - place, do not allocate extra memory.
// 
// Here are some examples.Inputs are in the left - hand column and its corresponding outputs are in the right - hand column.
// 1, 2, 3 --> 1, 3, 2
// 3, 2, 1 --> 1, 2, 3
// 1, 1, 5 --> 1, 5, 1

#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

class Solution_latestTrial {
public:
    void nextPermutation(vector<int> &num) {
        const int numSize = num.size();
        int reverseStartIdx = 0;
        for (int i = numSize - 1; i > 0; --i){
            if (num[i] > num[i - 1]){
                // found target, swap with the closet larger
                // i - 1 is the one to be increased
                // i is the first candidate, search back to find closer candidate
                int closetIdx = i;
                for (int j = i + 1; j <= numSize - 1; ++j){
                    if (num[j] > num[i - 1]){
                        closetIdx = j;
                    }
                    else{
                        break;
                    }
                }
                swap(num[i - 1], num[closetIdx]);
                reverseStartIdx = i;
                break;
            }
        }
        reverse(num, reverseStartIdx, numSize - 1);
    }
    void reverse(vector<int>& num, int startIdx, int endIdx){
        while (startIdx < endIdx){
            swap(num[startIdx++], num[endIdx--]);
        }
    }
};

// not my algorithm
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        const int numSize = num.size();
        int pivotIdx = -1;
        for (int i = numSize - 1; i > 0; --i){
            if (num[i - 1] < num[i]){
                pivotIdx = i - 1;
                break;
            }
        }

        int reverseIdx = 0;
        if (pivotIdx != -1){
            for (int j = numSize - 1; j > pivotIdx; --j){
                if (num[pivotIdx] < num[j]){
                    swap(num[pivotIdx], num[j]);
                    reverseIdx = pivotIdx + 1;
                    break;
                }
            }
        }
        reverse(num, reverseIdx, numSize - 1);
    }

    void reverse(vector<int>& num, int startIdx, int endIdx){
        while (endIdx > startIdx){
            swap(num[startIdx], num[endIdx]);
            startIdx++;
            endIdx--;
        }
    }
};
