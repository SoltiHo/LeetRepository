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
#include <vector>
using namespace std;



class Solution_LatestTrial_DP {
public:
    int numDistinct(string S, string T) {
        const int SSize = S.size();
        const int TSize = T.size();
        int output = 0;

        if ((SSize > 0) && (TSize > 0) && (SSize >= TSize)){
            vector<int> buffer(SSize + 1, 0);
            int currBeforeUpdate = 0;
            int PrevBeforeUpdate = 0;
            for (int Sidx = 0; Sidx < SSize; ++Sidx){
                if (S[Sidx] == T[0]){
                    buffer[Sidx + 1] += 1;
                }
                buffer[Sidx + 1] += buffer[Sidx];

            }
            for (int Tidx = 1; Tidx < TSize; ++Tidx){
                PrevBeforeUpdate = buffer[Tidx];
                for (int Sidx = Tidx; Sidx < SSize; ++Sidx){
                    currBeforeUpdate = buffer[Sidx + 1];
                    buffer[Sidx + 1] = 0;
                    if (S[Sidx] == T[Tidx]){
                        buffer[Sidx + 1] += PrevBeforeUpdate;
                    }
                    buffer[Sidx + 1] += buffer[Sidx];
                    PrevBeforeUpdate = currBeforeUpdate;
                }
            }

            output = buffer[SSize];
        }
        return output;
    }
};

class Solution_LatestTrial_Naive {
public:
    int numDistinct(string S, string T) {
        int output = 0;
        progress(S, T, 0, 0, output);
        return output;
    }

    void progress(string& S, string& T, const int Sidx, const int Tidx, int& success){
        if ((Sidx < S.size()) && (Tidx < T.size())){
            if (S[Sidx] == T[Tidx]){
                // try match
                if (S.size() - (Sidx + 1) >= T.size() - (Tidx + 1)){
                    progress(S, T, Sidx + 1, Tidx + 1, success);
                }
            }
            // try not match
            if (S.size() - (Sidx + 1) >= T.size() - Tidx){
                progress(S, T, Sidx + 1, Tidx, success);
            }
        }
        else if ((Sidx == S.size()) && (Tidx == T.size())){
            success++;
        }
    }
};


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

