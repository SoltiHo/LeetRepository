//  You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices of substring(s) in S that 
//  is a concatenation of each word in L exactly once and without any intervening characters.
//  
//  For example, given:
//  S : "barfoothefoobarman"
//  L : ["foo", "bar"]
//  
//      You should return the indices : [0, 9].
//      (order does not matter).
#include <vector>
#include <iostream>
using namespace std;

void printTable(bool* t, const int startRow, const int rowInterval, const int rowSize, const int colSize){
    for (int i = 0; i < colSize; i += rowInterval){
        cout << i << ": ";
        for (int j = 0; j < rowSize; ++j){
            cout << t[(startRow + i) * rowSize + j] << ", ";
        }
        cout << endl;
    }
    cout << endl << endl;
}

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        this->SSize = S.size();
        this->WordSize = L[0].size();
        this->WordCount = L.size();
        // filter out basic cases
        vector<int> Output;
        if (this->SSize < this->WordCount * this->WordSize){
            //not possible to match
            return Output;
        }

        // initialize table
        const int TableColumnSize = this->SSize - this->WordSize + 1;
        const int TableSize = TableColumnSize * (this->WordCount);
        this->table = new bool[TableSize];
        memset(this->table, 0, sizeof(bool)*TableSize);

        // fill in the table
        bool match = false;
        for (int SIdx = 0; SIdx < TableColumnSize; ++SIdx){
            for (int WIdx = 0; WIdx < this->WordCount; ++WIdx){
                match = true;
                for (int CIdx = 0; CIdx < this->WordSize; ++CIdx){
                    if (S[SIdx + CIdx] != L[WIdx][CIdx]){
                        match = false;
                        break;
                    }
                }
                // this->WordCount is row size of the table
                this->table[SIdx * this->WordCount + WIdx] = match;
            }
        }

        // then use back tracking to find all solution
        bool* selectedArray = new bool[this->WordCount];
        memset(selectedArray, 0, sizeof(bool)*this->WordCount);
        Output.clear();
        bool solutionAccepted = false;
        for (int offset = 0; offset < this->WordSize; offset++){
            for (int rowIdx = 0; rowIdx + offset + (this->WordCount - 1) * this->WordSize< TableColumnSize; rowIdx += this->WordSize){

                if (rowIdx > 0){
                    if (memcmp(this->table + ((rowIdx + offset)*this->WordCount),
                        this->table + ((rowIdx - this->WordSize + offset)*this->WordCount),
                        sizeof(bool)* this->WordCount * this->WordCount * this->WordSize) == 0)
                    {

                        // the same table content
                        if (solutionAccepted){
                            // then repeat the solution with offset.
                            // the offset is already contained in rowIdx
                            Output.push_back(rowIdx + offset);
                        }
                        continue;

                    }

                }
                solutionAccepted = false;
                for (int wordIdx = 0; wordIdx < this->WordCount; ++wordIdx){
                    memset(selectedArray, 0, sizeof(bool)*this->WordCount);
                    if (this->table[(rowIdx + offset) * this->WordCount + wordIdx] == true){
                        selectedArray[wordIdx] = true;
                        solutionAccepted = solveByBackTracking(selectedArray, this->WordCount - 1, rowIdx + offset + this->WordSize);
                        if (solutionAccepted) {
                            Output.push_back(rowIdx + offset);
                            break;
                        }
                    }
                }

            }
        }


        return Output;
    }

    bool solveByBackTracking(bool* selectedArray, const int numWordNeeded, const int startRow){
        if (reject(selectedArray, numWordNeeded, startRow)){
            return false;
        }

        if (accept(selectedArray, numWordNeeded, startRow)){
            return true;
        }

        bool passed = false;
        for (int i = 0; i < this->WordCount; ++i){
            if ((selectedArray[i] == false) && (this->table[startRow*this->WordCount + i] == true)){
                // try this solution
                selectedArray[i] = true;
                passed = solveByBackTracking(selectedArray, numWordNeeded - 1, startRow + this->WordSize);
                if (passed) {
                    return true;
                }
                selectedArray[i] = false;
            }
        }
        return false;
    }

    bool reject(const bool* selectedArray, const unsigned int numWordNeeded, const int startRow){
        // check if the 1st char of the rest words still possible in relevant spots
        bool atLeastOneAvailable = false;
        for (unsigned int w = 0; w < numWordNeeded; ++w){
            atLeastOneAvailable = false;
            for (int i = 0; i < this->WordCount; ++i){
                if ((selectedArray[i] == false) && (this->table[(startRow + (w * this->WordSize))* this->WordCount + i] == true)){
                    atLeastOneAvailable = true;
                    break;
                }
            }
            if (!atLeastOneAvailable){
                return true;
            }
        }

        // check if at least one availabe in each column
        for (int i = 0; i < this->WordCount; ++i){
            atLeastOneAvailable = false;
            for (unsigned int w = 0; w < numWordNeeded; ++w){
                if (selectedArray[i] == true){
                    // previous selected should be considered as at least one available
                    atLeastOneAvailable = true;
                    continue;
                }
                if ((selectedArray[i] == false) && (this->table[(startRow + (w * this->WordSize))* this->WordCount + i] == true)){
                    atLeastOneAvailable = true;
                    break;
                }
            }
            if ((!atLeastOneAvailable) && (numWordNeeded > 0)){
                return true;
            }
        }

        return false;
    };


    bool accept(const bool* selectedArray, const int numWordNeeded, const int startRow){
        if (numWordNeeded == 0){
            return true;
        }

        for (int i = 0; i < numWordNeeded; ++i){
            for (int j = 0; j < this->WordCount; ++j){
                if ((selectedArray[j] == false) && (this->table[(startRow + (i * this->WordSize))* this->WordCount + j] == false)){
                    return false;
                }
            }
        }
        return true;
    }

    int SSize;
    int WordSize;
    int WordCount;
    bool* table;


    Solution() : SSize(0), WordSize(0), WordCount(0), table(NULL){};
};