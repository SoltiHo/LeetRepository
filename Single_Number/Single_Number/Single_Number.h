// Given an array of integers, every element appears twice except for one.Find that single one.
// 
// Note:
// Your algorithm should have a linear runtime complexity.
// Could you implement it without using extra memory ?




class Solution_WhileLoop {
public:
    int singleNumber(int A[], int n) {
        int c = 0;
        int output = 0;
        while (c < n){
            output ^= A[c++];
        }

        return output;
    }
};


class Solution_ForLoop {
public:
    int singleNumber(int A[], int n) {
        int output = 0;
        for (int c = 0; c < n; ++c){
            output ^= A[c];
        }

        return output;
    }
};