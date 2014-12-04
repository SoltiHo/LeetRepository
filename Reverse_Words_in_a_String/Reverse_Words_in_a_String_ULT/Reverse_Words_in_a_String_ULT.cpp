#include "gtest/gtest.h"  // access test macro
#include "Reverse_Words_in_a_String.h"



TEST(Leet, Basic01){
    string intput(" a");
    Solution sol;
    sol.reverseWords(intput);

    string expected("a");
    ASSERT_EQ(intput, expected);
}

// --------------------------------------------------------------------

