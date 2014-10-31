//  Given a string S and a string T, count the number of distinct subsequences of T in S.
//  
//  A subsequence of a string is a new string which is formed from the original string by deleting some(can be none) of the characters 
//  without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
//  
//  Here is an example :
//  S = "rabbbit", T = "rabbit"
//  
//  Return 3.


#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

void printArray(int* array, int Xsize, int Ysize){
    for (int y = 0; y < Ysize; ++y){
        for (int x = 0; x < Xsize; ++x){
            cout << array[y*Xsize + x] << ",";
        }
        cout << endl;
    }
    cout << endl << endl;
}
class Solution {
public:
    int numDistinct(string S, string T) {
        const int Ssize = S.size();
        const int Tsize = T.size();
        // filter out some basic cases
        if (Ssize == Tsize){
            return ((S == T) ? 1 : 0);
        }
        if (Ssize < Tsize){
            // can't insert anything to S, so no way to match S to T
            return 0;
        }

        if (Tsize == 0){
            // delete all S to match T, only one
            return 1;
        }
        else if (Tsize == 1){
            // return count of the single char in S
            return count(S.begin(), S.end(), T[0]);
        }

        int* TcharCountArray = new int[Ssize * Tsize];
        memset(TcharCountArray, 0, sizeof(int)* Ssize * Tsize);

        int* possibleSubstringCountArray = new int[Ssize * Tsize];
        memset(possibleSubstringCountArray, 0, sizeof(int)* Ssize * Tsize);

        // fill in TcharCountArray
        for (int y = 0; y < Tsize; ++y){
            for (int x = Ssize - 1; x >= 0; --x){
                if (x == Ssize - 1){
                    if (S[x] == T[y]){
                        TcharCountArray[y*Ssize + x] = 1;
                    }
                }
                else{
                    TcharCountArray[y*Ssize + x] = TcharCountArray[y*Ssize + x + 1];
                    if (S[x] == T[y]){
                        TcharCountArray[y*Ssize + x]++;
                    }
                }
            }
        }

        // filter out easy case
        if (TcharCountArray[(Tsize - 1) * Ssize + Tsize - 1] == 0){
            return 0;
        }

        // fill possibleSubstringCountArray
        int countFromMovingBottomRight = 0;
        int countFromMovingRight = 0;
        for (int y = 0; y < Tsize; ++y){
            for (int x = y; x < Ssize; ++x){
                if (y == 0){
                    // the seed row
                    if (TcharCountArray[y*Ssize + x] > 0){
                        possibleSubstringCountArray[y*Ssize + x] = 1;
                    }
                }
                else{
                    if ((S[x - 1] == T[y - 1]) && (TcharCountArray[y*Ssize + x] > 0)){
                        countFromMovingBottomRight = possibleSubstringCountArray[(y - 1)*Ssize + (x - 1)];
                    }
                    else{
                        countFromMovingBottomRight = 0;
                    }

                    if (TcharCountArray[y*Ssize + x] > 0){
                        countFromMovingRight = possibleSubstringCountArray[y*Ssize + (x - 1)];
                    }
                    else{
                        countFromMovingRight = 0;
                    }

                    possibleSubstringCountArray[y*Ssize + x] = countFromMovingBottomRight + countFromMovingRight;
                }
                

            } // end for x looping

        } // end for y looping

        // sum up all possibility based on the last row
        int total = 0;
        for (int x = Ssize - 1; x >= Tsize - 1; --x){
            if (S[x] == T[Tsize - 1]){
                total += possibleSubstringCountArray[(Tsize - 1)* Ssize + x];
            }
        }

        delete[] possibleSubstringCountArray;
        delete[] TcharCountArray;
        return total;
    }
};

