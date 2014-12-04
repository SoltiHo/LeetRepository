#include "gtest/gtest.h"  // access test macro
#include "Evaluate_Reverse_Polish_Notation.h"


TEST(Leet, Basic01){
    vector<string> intput({ "-1", "1", "*", "-1", "+" });
    Solution sol;
    
    ASSERT_EQ(sol.evalRPN(intput), -2);
}

// --------------------------------------------------------------------

