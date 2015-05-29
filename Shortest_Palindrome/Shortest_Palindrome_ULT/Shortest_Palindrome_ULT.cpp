#include "gtest/gtest.h"  // access test macro
#include "Shortest_Palindrome.h"


TEST(Baisc, basic02){
    Solution sol;
    ASSERT_EQ(sol.shortestPalindrome("eteyvqncxvkoffzxhkdpwnaodvgnmofexuhrotdvzeih"), "hiezvdtorhuxefomngvdoanwpdkhxzffokvxcnqvyeteyvqncxvkoffzxhkdpwnaodvgnmofexuhrotdvzeih");
}


TEST(Baisc, basic01){
    Solution sol;
    ASSERT_EQ(sol.shortestPalindrome("abbacd"), "dcabbacd");
}


TEST(Slow, basic02){
    Solution_SLOW sol;
    ASSERT_EQ(sol.shortestPalindrome("eteyvqncxvkoffzxhkdpwnaodvgnmofexuhrotdvzeih"), "hiezvdtorhuxefomngvdoanwpdkhxzffokvxcnqvyeteyvqncxvkoffzxhkdpwnaodvgnmofexuhrotdvzeih");
}


TEST(Slow, basic01){
    Solution_SLOW sol;
    ASSERT_EQ(sol.shortestPalindrome("abbacd"), "dcabbacd");
}
