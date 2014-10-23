// There are two sorted arrays A and B of size m and n respectively.Find the median of the two sorted arrays.The overall run time complexity should be O(log(m + n)).
#include <iostream>

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        const unsigned int medianIndex = ((m + n) >> 1);
        // if odd size then this is the exact the middle one
        // if even size, then this is the 1st of the right half, the output need to be ((last of left) + (1st of right))/2

        bool needToAveragePreviousOne = ((m + n) == (medianIndex << 1));  
        // if m + n = 6, medianIndex = 3, needToAveragePreviousOne = true
        // if m + n = 5, medianIndex = 2, needToAveragePreviousOne = false

        unsigned int Aindex = 0;
        unsigned int Bindex = 0;
        unsigned int currIndex = 0;
        double CurrentNumber = 0;
        double PreviousNumbers = 0;

        while (currIndex <= medianIndex){
            if ((Aindex < m) && (Bindex < n)){
                // both array has something left
                if (A[Aindex] < B[Bindex]){
                    // take one from A
                    PreviousNumbers = CurrentNumber;
                    CurrentNumber = A[Aindex];
                    Aindex++;
                    currIndex++;
                }
                else{
                    // take from B
                    PreviousNumbers = CurrentNumber;
                    CurrentNumber = B[Bindex];
                    Bindex++;
                    currIndex++;
                }
            }
            else if (Aindex < m) {
                // B is out
                // take one from A
                PreviousNumbers = CurrentNumber;
                CurrentNumber = A[Aindex];
                Aindex++;
                currIndex++;
            }
            else{
                // A is out
                // take from B
                PreviousNumbers = CurrentNumber;
                CurrentNumber = B[Bindex];
                Bindex++;
                currIndex++;
            }
        }

        if (needToAveragePreviousOne){
            return (CurrentNumber + PreviousNumbers) / 2.0;
        }
        else{
            return CurrentNumber;
        }
        

    }
};