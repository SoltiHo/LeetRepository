#include "gtest/gtest.h"  // access test macro
#include "Contains_Duplicate_III.h"

TEST(Hash, Fail02){
    Solution sol;
    vector<int> input({ 1, 3, 1 });

    ASSERT_EQ(sol.containsNearbyAlmostDuplicate(input, 2, 1), true);
}



TEST(Hash, Fail01){
    Solution sol;
    vector<int> input({ 2, 4 });
    
    ASSERT_EQ(sol.containsNearbyAlmostDuplicate(input, 1, 1), false);
}
