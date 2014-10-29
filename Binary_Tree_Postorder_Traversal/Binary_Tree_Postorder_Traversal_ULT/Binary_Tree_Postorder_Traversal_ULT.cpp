#include "gtest/gtest.h"  // access test macro
#include "BinaryTreePostorderTraversal.h"



TEST(TestFailed, FromLeet01){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);

    Solution sol;
    vector<int> answer;
    answer = sol.postorderTraversal(root);

    vector<int> expected;
    expected.push_back(1);
    expected.push_back(2);
    expected.push_back(3);
    ASSERT_TRUE(answer == expected);

}
