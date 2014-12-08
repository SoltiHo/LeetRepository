#include "gtest/gtest.h"  // access test macro
#include "Flatten_Binary_Tree_to_Linked_List.h"

bool compareList(TreeNode* pA, TreeNode* pB){
    if ((pA && !pB) || (!pA && pB)){
        return false;
    }

    while (pA && pB){
        if (pA->val != pB->val){
            return false;
        }
        pA = pA->right;
        pB = pB->right;
    }

    if (!pA && !pB){
        return true;
    }
    else{
        return false;
    }
}
TEST(Leet, Basic01){
    TreeNode root(1);
    TreeNode right(2);
    root.right = &right;
    Solution sol;
    sol.flatten(&root);

    TreeNode expectedRoot(1);
    TreeNode expectedRight(2);
    expectedRoot.right = &expectedRight;

    ASSERT_TRUE(compareList(&root, &expectedRoot));
}


TEST(Leet, Basic02){
    TreeNode root(1);
    TreeNode* pCurr = &root;
    pCurr->left = new TreeNode(2);
    pCurr = pCurr->left;
    pCurr->left = new TreeNode(3);
    Solution sol;
    sol.flatten(&root);

    TreeNode expectedRoot(1);
    TreeNode expectedRight(2);
    expectedRoot.right = &expectedRight;

    ASSERT_TRUE(compareList(&root, &expectedRoot));
}

