#include "gtest/gtest.h"  // access test macro
#include "BinaryTreeMaximumPathSum.h"

TEST(SingleNode, Positive){
    Solution sol;
    TreeNode single = { 0 };
    single.val = 1;
    ASSERT_EQ(sol.maxPathSum(&single), 1);
}

TEST(SingleNode, Negative){
    Solution sol;
    TreeNode single = { 0 };
    single.val = -1;
    ASSERT_EQ(sol.maxPathSum(&single), -1);
}


TEST(TwoNodes, NegativeCost){
    Solution sol;
    TreeNode single = { 0 };
    single.val = 2;
    single.left = new TreeNode{ 0 };
    single.left->val = -1;
    ASSERT_EQ(sol.maxPathSum(&single), 2);
}

