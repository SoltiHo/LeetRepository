#include "gtest/gtest.h"  // access test macro
#include "RecoverBinarySearchTree.h"

TEST(LeetCode, Fail02){
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);

    Solution sol;

    sol.recoverTree(root);
}

TEST(LeetCode, Fail01){
    TreeNode* root = new TreeNode(2);
    root->right = new TreeNode(1);

    Solution sol;

    sol.recoverTree(root);
}
