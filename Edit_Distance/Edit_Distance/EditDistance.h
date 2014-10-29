//   Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
//   
//   You have the following 3 operations permitted on a word :
//   
//   a) Insert a character
//   b) Delete a character
//   c) Replace a character

#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        // filter out easy cases
        const unsigned int wordSize1 = word1.size();
        const unsigned int wordSize2 = word2.size();
        if ((wordSize1 == 0) || (wordSize2 == 0)){
            // one or both of them are zero. the other just need to do all "insert"/"delete"
            return (wordSize1 + wordSize2);
        }

        // init the DP table
        // let index1 be x direction for word1 and index2 be y direction for word2
        const int rowSize = wordSize1 + 1;
        const int columnSize = wordSize2 + 1;
        int* scores = new int[rowSize * columnSize];

        for (unsigned int index1 = 0; index1 < rowSize; ++index1){
            // first row only
            scores[index1] = index1;
        }
        for (unsigned int index2 = 0; index2 < columnSize; ++index2){
            // first column only
            scores[index2 * rowSize] = index2;
        }

        int candidate1 = 0;
        int candidate2 = 0;
        int candidate3 = 0;
        for (unsigned int index2 = 1; index2 < columnSize; ++index2){
            for (unsigned int index1 = 1; index1 < rowSize; ++index1){
                // mismatch case, meaning replace a char in word1 with the one in word2
                candidate1 = scores[(index2 - 1) * rowSize + (index1 - 1)] + (word1.at(index1 - 1) == word2.at(index2 - 1) ? 0 : 1);

                // a gap in word2, meaning deleting a char in word1
                candidate2 = scores[(index2 - 1) * rowSize + index1] + 1;

                // a gap in word1, meaning inserting a char in word1 to match word2
                candidate3 = scores[(index2)* rowSize + (index1 - 1)] + 1;

                // find the minimum scores.
                scores[index2 * rowSize + index1] = min(min(candidate1, candidate2), candidate3);
            }
        }

        int result = scores[columnSize * rowSize - 1];
        delete[] scores;

        return result;
    }
};

