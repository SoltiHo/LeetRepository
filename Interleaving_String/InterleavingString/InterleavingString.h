#include <string>
#include <iostream>

class Solution {
public:
    bool isInterleave(std::string s1, std::string s2, std::string s3) {
        int string_1_size = s1.size();
        int string_2_size = s2.size();
        int string_3_sige = s3.size();

        if (string_3_sige != (string_1_size + string_2_size)){
            return false;
        }

        // 1D
        if (string_1_size == 0) {
            return (s2 == s3);
        }
        if (string_2_size == 0) {
            return (s1 == s3);
        }

        // 2D
        const unsigned int truthTableSize = (string_1_size + 1) * (string_2_size + 1);
        const unsigned int rowSize = string_1_size + 1;
        int* truthTable = new int[truthTableSize];  // [0] ~ [truthTableSize - 1]
        memset(truthTable, 0, sizeof(int)*truthTableSize);  // init to all false

        // init the first row and column by checking if S3 is solely S2 or S1
        for (int x1 = 0; x1 < string_1_size; ++x1){
            if (s1.at(x1) == s3.at(x1)){
                truthTable[x1 + 1] = 1;
            }
            else{
                break;
            }
        }

        for (int x2 = 0; x2 < string_2_size; ++x2){
            if (s2.at(x2) == s3.at(x2)){
                truthTable[(x2 + 1) * rowSize] = 1;
            }
            else{
                break;
            }
        }

        // For debugging only
        for (int x2 = 0; x2 < (string_2_size + 1); ++x2){
            for (int x1 = 0; x1 < (string_1_size + 1); ++x1){
                std::cout << truthTable[x2*rowSize + x1] << ", ";
            }
            std::cout << std::endl;
        }


        for (int x1 = 1; x1 < (string_1_size + 1); ++x1){
            for (int x2 = 1; x2 < (string_2_size + 1); ++x2){
                if (((truthTable[(x2 - 1)*rowSize + x1] == 1) && (s3.at(x1 + x2 - 1) == s2.at(x2 - 1))) ||  // Down move
                    ((truthTable[x2 * rowSize + x1 - 1] == 1) && (s3.at(x1 + x2 - 1) == s1.at(x1 - 1))))      // Right move
                {
                    truthTable[x2*rowSize + x1] = 1;
                }
            }
        }


        // For debugging only
        std::cout << std::endl << std::endl;
        for (int x2 = 0; x2 < (string_2_size + 1); ++x2){
            for (int x1 = 0; x1 < (string_1_size + 1); ++x1){
                std::cout << truthTable[x2*rowSize + x1] << ", ";
            }
            std::cout << std::endl;
        }


        if (truthTable[truthTableSize - 1] == 0){
            delete[] truthTable;
            return false;
        }
        else{
            delete[] truthTable;
            return true;
        }
    }
};