// Given preorder and inorder traversal of a tree, construct the binary tree.
// 
// Note:
// You may assume that duplicates do not exist in the tree.

#include <vector>
using namespace std;


// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (inorder.size() == 0){
            return NULL;
        }
        else if (inorder.size() == 1){
            return new TreeNode(inorder[0]);
        }

        return constructTree(inorder, preorder, 0, inorder.size() - 1, 0, preorder.size() - 1);
    }

    TreeNode* constructTree(vector<int> &inorder, vector<int> &preorder, const int inorderStartIdx, const int inorderEndIdx, const int preorderStartIdx, const int preorderEndIdx){
        const int rootValue = preorder[preorderStartIdx];
        int rootIdxInInorder = inorderStartIdx;
        while (inorder[rootIdxInInorder] != rootValue){
            rootIdxInInorder++;
        }

        const int leftSubtreeSize = rootIdxInInorder - inorderStartIdx;
        const int rightSubtreeSize = inorderEndIdx - rootIdxInInorder;

        const int leftInorderStart = leftSubtreeSize ? inorderStartIdx : -1;
        const int leftInorderEnd = leftSubtreeSize ? rootIdxInInorder - 1 : -1;
        const int leftPreorderStart = leftSubtreeSize ? preorderStartIdx + 1 : -1;
        const int leftPreorderEnd = leftSubtreeSize ? preorderStartIdx + leftSubtreeSize : -1;;
        const int rightInorderStart = rightSubtreeSize ? rootIdxInInorder + 1 : -1;
        const int rightInorderEnd = rightSubtreeSize ? inorderEndIdx : -1;
        const int rightPreorderStart = rightSubtreeSize ? preorderStartIdx + leftSubtreeSize + 1 : -1;
        const int rightPreorderEnd = rightSubtreeSize ? preorderEndIdx : -1;

        TreeNode* pRoot = new TreeNode(rootValue);
        TreeNode* pLeftSubtree = NULL;
        TreeNode* pRightSubtree = NULL;

        if (leftSubtreeSize > 0){
            pLeftSubtree = constructTree(inorder, preorder, leftInorderStart, leftInorderEnd, leftPreorderStart, leftPreorderEnd);
        }

        if (rightSubtreeSize > 0){
            pRightSubtree = constructTree(inorder, preorder, rightInorderStart, rightInorderEnd, rightPreorderStart, rightPreorderEnd);
        }

        pRoot->left = pLeftSubtree;
        pRoot->right = pRightSubtree;

        return pRoot;
    }
};