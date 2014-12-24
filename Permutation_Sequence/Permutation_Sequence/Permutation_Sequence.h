// The set[1, 2, 3, …, n] contains a total of n! unique permutations.
// 
// By listing and labeling all of the permutations in order,
// We get the following sequence(ie, for n = 3) :
// 
// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence.
// 
// Note: Given n will be between 1 and 9 inclusive.
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    static const int FactorialTable[9];
    string getPermutation(int n, int k) {
        char* buffer = new char[n];
        k = k % FactorialTable[n - 1];
        k = (k == 0) ? FactorialTable[n - 1] : k;
        for (int i = 1; i <= n; ++i){
            buffer[i - 1] = (0x30 + i);
        }
        permutation(buffer, n, k);
        string output(buffer, n);
        delete[] buffer;
        return output;
    }

    void permutation(char* buffer, const int bufferSize, const int k){
        // invariant: buffer digit (M ~ LSD) is sorted, smallest to the largest, to be solved
        //            digit (MSD ~ M - 1) fixed number, solved from earlier iteration
        //            FactorialTable[M] > k, and FactorialTable[M-1] < k
        //            LSD = least significant digit = 1
        //            MSD = most significant digit = n
        //            buffer = [MSD MSD -1 .... LSD]
        // invariant: k > 0, not zero idx
        for (int i = 8; i; --i){
            if (FactorialTable[i] == k){
                // k is multiple of a certain factorial, meaning the last one of the group
                // just need to reverse the digits of the group.
                // ex., if k = 6, meaning 3 digits group, reverse the last 3 digits
                //      FactorialTable[2] is 6, so i = 2 for below
                reverseCharArray(buffer, bufferSize - 1 - i, bufferSize - 1);
                break;
            }
            else if ((FactorialTable[i] > k) && (FactorialTable[i - 1] < k)){
                // meanning need i - 1 digits permutation,
                // and depending on cycles needed, the leading number is extracted out first as temp
                char temp = buffer[bufferSize - i - 1 + ((k - 1) / FactorialTable[i - 1])];
                memmove(buffer + (bufferSize - i), buffer + (bufferSize - i - 1), ((k - 1) / FactorialTable[i - 1]));
                buffer[bufferSize - i - 1] = temp;
                permutation(buffer, bufferSize, (k - 1) % FactorialTable[i - 1] + 1);
                break;
            }
        }
    }

    void reverseCharArray(char* buffer, int startIdx, int endIdx){
        while (endIdx > startIdx){
            swap(buffer[endIdx], buffer[startIdx]);
            endIdx--;
            startIdx++;
        }
    }
};

const int Solution::FactorialTable[9]{ 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };