//  There are N children standing in a line.Each child is assigned a rating value.
//  
//  You are giving candies to these children subjected to the following requirements :
//  
//  Each child must have at least one candy.
//  Children with a higher rating get more candies than their neighbors.
//  What is the minimum candies you must give ?
#include <vector>
#include <algorithm>
#include <iostream>
void compareNeighbor(unsigned int* candyAllocation, const unsigned int firstChileIndex, const unsigned int numOfChildren, std::vector<int> &ratings){
    // base cases
    if (numOfChildren == 1){
        candyAllocation[firstChileIndex] = 1;
    }
    else if (numOfChildren == 2) {
        if (ratings[firstChileIndex] > ratings[firstChileIndex + 1]){
            candyAllocation[firstChileIndex] = 2;
            candyAllocation[firstChileIndex + 1] = 1;
        }
        else if (ratings[firstChileIndex] == ratings[firstChileIndex + 1]){
            candyAllocation[firstChileIndex] = 1;
            candyAllocation[firstChileIndex + 1] = 1;
        }
        else{
            candyAllocation[firstChileIndex] = 1;
            candyAllocation[firstChileIndex + 1] = 2;
        }
    }
    else{
        // recursive call
        // allocate for the basic for the left
        compareNeighbor(candyAllocation, firstChileIndex, numOfChildren >> 1, ratings);

        // allocate for the basic for the right
        compareNeighbor(candyAllocation, firstChileIndex + (numOfChildren >> 1), numOfChildren - (numOfChildren >> 1), ratings);

        // compare the left and the right part. 
        const unsigned int middleRoundedUp = firstChileIndex + (numOfChildren >> 1); // the child in the middle, rounded up.  (0,4)-->2,  (0,3)-->1, (1,4)-->3, (1,3) -->2
        if (ratings[middleRoundedUp - 1] > ratings[middleRoundedUp]){
            if (candyAllocation[middleRoundedUp - 1] <= candyAllocation[middleRoundedUp]){
                //shift the left
                candyAllocation[middleRoundedUp - 1] = candyAllocation[middleRoundedUp] + 1;  // shift the one at the boundary

                // then propagate the shift till no need to shift
                for (unsigned int i = 1; i < (numOfChildren >> 1); ++i){
                    if ((ratings[middleRoundedUp - 1 - i + 1] < ratings[middleRoundedUp - 1 - i]) &&
                        (candyAllocation[middleRoundedUp - 1 - i + 1] >= candyAllocation[middleRoundedUp - 1 - i]))
                    {
                        candyAllocation[middleRoundedUp - 1 - i] = candyAllocation[middleRoundedUp - 1 - i + 1] + 1;
                        break;
                    }
                    else{
                        break;                        
                    }
                }
            }
        }
        else if (ratings[middleRoundedUp - 1] < ratings[middleRoundedUp]){
            if (candyAllocation[middleRoundedUp - 1] >= candyAllocation[middleRoundedUp]){
                //shift the right
                candyAllocation[middleRoundedUp] = candyAllocation[middleRoundedUp - 1] + 1;

                for (unsigned int i = 1; i < (numOfChildren - (numOfChildren >> 1)); ++i){
                    if ((ratings[middleRoundedUp + i - 1] < ratings[middleRoundedUp + i]) &&
                        (candyAllocation[middleRoundedUp + i - 1] >= candyAllocation[middleRoundedUp + i]))
                    {
                        candyAllocation[middleRoundedUp + i] = candyAllocation[middleRoundedUp + i - 1] + 1;
                    }
                    else{
                        break;    
                    }
                }
            }
        }
        // no need to change if equal

    }
}
class Solution {
public:
    int candy(std::vector<int> &ratings) {
        unsigned int numOfChildren = ratings.size();
        unsigned int* A = new unsigned int[numOfChildren];
        memset(A, 0, sizeof(unsigned int)*numOfChildren);

        compareNeighbor(A, 0, numOfChildren, ratings);

        int totalCandy = 0;
        for (unsigned int i = numOfChildren; i; --i){

            totalCandy += A[i - 1];
        }

        // for debugging only
        std::cout << "Candy:" << std::endl;
        for (unsigned int i = 0; i < numOfChildren; ++i){
            std::cout << A[i] << ", ";
        }
        std::cout << std::endl << "ratings:" << std::endl;
        // for debugging only
        for (unsigned int i = 0; i < numOfChildren; ++i){
            std::cout << ratings[i] << ", ";
        }
        std::cout << std::endl;


        delete[] A;
        return totalCandy;
    }
};

