//  A peak element is an element that is greater than its neighbors.
//  
//  Given an input array where num[i] != num[i + 1], find a peak element and return its index.
//  
//  The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
//  
//  You may imagine that num[-1] = num[n] = negative infinite
//  
//  For example, in array[1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
//  
//  click to show spoilers.
//  Note:
//  Your solution should be in logarithmic complexity.

#include <vector>
using namespace std;


class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        this->numSize = num.size();
        if (this->numSize == 1){
            return 0;
        }

        if (isPeak(num, 0)){
            return 0;
        }

        if (isPeak(num, this->numSize - 1)){
            return this->numSize - 1;
        }

        int upperBound = this->numSize - 1;  // exclusive boundaries
        int lowerBound = 0;
        int currIdx = 0;
        while (true){
            currIdx = ((upperBound + lowerBound) >> 1);
            if (isPeak(num, currIdx)){
                return currIdx;
            }
            else if (num[currIdx] > num[currIdx + 1]){
                // go left
                upperBound = currIdx;
            }
            else{
                // go right
                lowerBound = currIdx;
            }
        }
    }

    inline bool isPeak(const vector<int> &num, const int Idx){
        // exclude the size = 1 case
        if ((Idx == 0) && (num[0] > num[1])){
            return true;
        }
        else if ((Idx == this->numSize - 1) && (num[Idx] > num[Idx - 1])){
            return true;
        }
        
        return ((num[Idx] > num[Idx - 1]) && (num[Idx] > num[Idx + 1]));
    }

    int numSize;
};