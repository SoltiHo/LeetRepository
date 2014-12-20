#include "gtest/gtest.h"  // access test macro
#include "Simplify_Path.h"


TEST(Baisc, basic02){
    string input("/.../");
    Solution sol;
    string output = sol.simplifyPath(input);
    string expected("/...");
    ASSERT_EQ(input, expected);

}


TEST(Baisc, basic01){
    string input("/./");
    Solution sol;
    string output = sol.simplifyPath(input);
    string expected("/");
    ASSERT_EQ(input, expected);

}
