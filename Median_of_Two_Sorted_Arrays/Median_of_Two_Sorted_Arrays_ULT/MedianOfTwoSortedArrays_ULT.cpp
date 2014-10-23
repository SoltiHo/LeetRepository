
#include "gtest/gtest.h"  // access test macro
#include "MedianOfTwoSortedArrays.h"

TEST(MedianOfTwoSortedArrays, OneEmptyArray_02){
    int A[9];
    int B[10];

    for (unsigned int i = 0; i < 10; ++i){
        if (i < 9){
            A[i] = 2 * i + 1;
        }
        B[i] = 2 * i;
    }

    Solution sol;
    ASSERT_EQ(sol.findMedianSortedArrays(A, 9, B, 0), 9.0);
}

TEST(MedianOfTwoSortedArrays, OneEmptyArray_01){
    int A[9];
    int B[10];

    for (unsigned int i = 0; i < 10; ++i){
        if (i < 9){
            A[i] = 2 * i + 1;
        }
        B[i] = 2 * i;
    }

    Solution sol;
    ASSERT_EQ(sol.findMedianSortedArrays(A, 0, B, 10), 9.0);
}

TEST(MedianOfTwoSortedArrays, Basic_02){
    int A[9];
    int B[10];

    for (unsigned int i = 0; i < 10; ++i){
        if (i < 9){
            A[i] = 2 * i + 1;
        }
        B[i] = 2 * i;
    }

    Solution sol;
    ASSERT_EQ(sol.findMedianSortedArrays(A, 9, B, 10), 9.0);
}

TEST(MedianOfTwoSortedArrays, Basic_01){
    int A[10];
    int B[10];

    for (unsigned int i = 0; i < 10; ++i){
        A[i] = 2 * i + 1;
        B[i] = 2 * i;
    }


    Solution sol;
    ASSERT_EQ(sol.findMedianSortedArrays(A, 10, B, 10), 9.50);
}
