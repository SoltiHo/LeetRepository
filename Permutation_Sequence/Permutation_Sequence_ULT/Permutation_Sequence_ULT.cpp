#include "gtest/gtest.h"  // access test macro
#include "Permutation_Sequence.h"

TEST(Baisc, basic05){
    Solution sol;
    string expected("3124");
    ASSERT_EQ(sol.getPermutation(4, 13), expected);
}


TEST(Baisc, basic04){
    Solution sol;
    string expected("4321");
    ASSERT_EQ(sol.getPermutation(4, 24), expected);
}

TEST(Baisc, basic03){
    Solution sol;
    string expected("3421");
    ASSERT_EQ(sol.getPermutation(4, 18), expected);
}

TEST(Baisc, basic02){
    Solution sol;
    string expected("2143");
    ASSERT_EQ(sol.getPermutation(4, 8), expected);
}
TEST(Baisc, basic01){
    Solution sol;
    string expected("1432");
    ASSERT_EQ(sol.getPermutation(4, 6), expected);
}

//1   1234
//2   1243
//3   1324
//4   1342
//5   1423
//6   1432
//
//7   2134
//8   2143
//9   2314
//10  2341
//11  2413
//12  2431
//
//13  3124
//14  3142
//15  3214
//16  3241
//17  3412
//18  3421
//
//19  4123
//20  4132
//21  4213
//22  4231
//23  4312
//24  4321