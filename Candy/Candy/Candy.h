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
using namespace std;

class Solution_Greedy_LatestTrial {
public:
    int candy(vector<int> &ratings) {
        const int ratingCount = ratings.size();
        vector<int> candyAssignment(ratingCount, 1);
        for (int i = 1; i < ratingCount; ++i){
            if (ratings[i] > ratings[i - 1]){
                candyAssignment[i] = candyAssignment[i - 1] + 1;
            }
        }
        for (int i = ratingCount - 1; i > 0; --i){
            if (ratings[i] < ratings[i - 1]){
                candyAssignment[i - 1] = max(candyAssignment[i] + 1, candyAssignment[i - 1]);
            }
        }
        
        int output = 0;
        for (auto& i : candyAssignment){
            output += i;
        }
        return output;
    }
};

class Solution_Greedy {
public:
    int candy(vector<int> &ratings) {
        const int ratingCount = ratings.size();
        vector<int> candies;
        candies.reserve(ratingCount);
        
        candies.push_back(1);
        for (int i = 1; i < ratingCount; ++i){
            if (ratings[i] > ratings[i - 1]){
                candies.push_back(candies[i - 1] + 1);
            }
            else{
                candies.push_back(1);
            }
        }

        for (int j = ratingCount - 1; j; --j){
            if ((ratings[j - 1] > ratings[j]) && (candies[j - 1] <= candies[j])){
                candies[j - 1] = candies[j] + 1;
            }
        }

        int sum = 0;
        for (auto& i : candies){
            sum += i;
        }
        return sum;
    }

};

class Solution_DP {
    // for every new kid, it could be
    // 1. higher than the previous kid
    //      - allocate the previou kid's candies + 1
    // 2. equal to the revious kid
    //      - allocate one
    // 3. less than the previous kid
    //      - if the previous kid has more than one, allocate the previous kid - 1
    //      - else allocate the new kid one, shift the previous kids by the amount to  be larger than 1.
    //           - the propagation stopped at "<=" neighbor, only the ">" neighbor whose breaks the relationship needs to propagate

    // this solution hit LTE on LEET, at the worst case scenario where all previous candies need update for every new kid.
    // i.e. 5, 4, 3, 2, 1
    // so adding preprocessing part to improve the performance
public:
    int candy(vector<int> &ratings) {
        const int ratingCount = ratings.size();
        // data preprocessing
        int increasingCount = 0;
        int decreasingCount = 0;
        for (int i = 1; i < ratingCount; ++i){
            if (ratings[i] < ratings[i - 1]){
                decreasingCount++;
            }
            else if (ratings[i] > ratings[i - 1]){
                increasingCount++;
            }
        }

        if (decreasingCount > increasingCount){
            // reverse the ratings
            int head = 0;
            int tail = ratingCount - 1;
            while (tail > head){
                swap(ratings[tail--], ratings[head++]);
            }
        }

        // actual solving the problem
        vector<int> candies;
        candies.reserve(ratingCount);
        candies.push_back(1); //seed
        for (int i = 1; i < ratingCount; ++i){
            int debugCurrRating = ratings[i];

            int debugPrevRating = ratings[i - 1];
            int debugPrevCandies = candies[i - 1];
            if (ratings[i] > ratings[i - 1]){
                //candies[i] = candies[i - 1] + 1;
                candies.push_back(candies[i - 1] + 1);
            }
            else if (ratings[i] == ratings[i - 1]){
                //candies[i] = 1;
                candies.push_back(1);
            }
            else{  // ratings[i] < ratings[i - 1]
                //candies[i] = 1;
                candies.push_back(1);
                if (candies[i - 1] == 1){
                    // propagate
                    int j = i - 1;
                    while (true){
                        candies[j]++;
                        if ((j > 0) && (candies[j] == candies[j - 1]) && (ratings[j] < ratings[j - 1])){
                            j--;
                        }
                        else{
                            break;
                        }
                    }
                    
                }
            }
        }



        int sum = 0;
        for (auto& i : candies){
            sum += i;
        }
        return sum;
    }
};

class Solution_DivideAndConquer {
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
};

