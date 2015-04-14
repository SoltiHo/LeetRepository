// Given two sorted integer arrays A and B, merge B into A as one sorted array.
// 
// Note:
// You may assume that A has enough space(size that is greater or equal to m + n) to hold additional elements from B.The number of elements initialized in A and B are m and n respectively.
#include <algorithm>
using namespace std;
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int dstIdx = m + n - 1;
        int Aidx = m - 1;
        int Bidx = n - 1;
        while (dstIdx >= 0){
            if ((Bidx < 0) || ((Aidx >= 0) && (A[Aidx] >= B[Bidx]))){
                A[dstIdx--] = A[Aidx--];
            }
            else{
                A[dstIdx--] = B[Bidx--];
            }
        }
    }
};