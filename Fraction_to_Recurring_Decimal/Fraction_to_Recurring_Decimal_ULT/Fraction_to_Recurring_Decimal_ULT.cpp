#include "gtest/gtest.h"  // access test macro
#include "Fraction_to_Recurring_Decimal.h"

TEST(Hash, Fail04){
    Solution sol;
    int nu = -1;
    int de = 0 - 2147483648;
    string expected("0.0000000004656612873077392578125");
    ASSERT_EQ(sol.fractionToDecimal(nu, de), expected);
}

TEST(Hash, Fail03){
    Solution sol;
    int nu = 7;
    int de = -12;
    string expected("-0.58(3)");
    ASSERT_EQ(sol.fractionToDecimal(nu, de), expected);
}

TEST(Hash, Fail02){
    Solution sol;
    int nu = 0 - 2147483648;
    int de = -1;
    string expected("2147483648");
    ASSERT_EQ(sol.fractionToDecimal(nu, de), expected);
}

TEST(Hash, Fail01){
    Solution sol;
    int nu = 1;
    int de = 6;
    string expected("0.1(6)");
    ASSERT_EQ(sol.fractionToDecimal(nu, de), expected);
}
