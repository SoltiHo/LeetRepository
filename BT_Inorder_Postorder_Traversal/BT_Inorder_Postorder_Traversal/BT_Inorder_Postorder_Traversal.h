// Given inorder and postorder traversal of a tree, construct the binary tree.
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.size() == 0){
            return NULL;
        }
        else if (inorder.size() == 1){
            return new TreeNode(inorder[0]);
        }

        return constructTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }

    TreeNode* constructTree(vector<int> &inorder, vector<int> &postorder, const int inorderStartIdx, const int inorderEndIdx, const int postorderStartIdx, const int postorderEndIdx){
        const int rootValue = postorder[postorderEndIdx];
        int rootIdxInInorder = inorderStartIdx;
        while (inorder[rootIdxInInorder] != rootValue){
            rootIdxInInorder++;
        }

        const int leftSubtreeSize = rootIdxInInorder - inorderStartIdx;
        const int rightSubtreeSize = inorderEndIdx - rootIdxInInorder;

        const int leftInorderStart = leftSubtreeSize ? inorderStartIdx : -1;
        const int leftInorderEnd = leftSubtreeSize ? rootIdxInInorder - 1 : -1;
        const int leftPostorderStart = leftSubtreeSize ? postorderStartIdx : -1;
        const int leftPostorderEnd = leftSubtreeSize ? postorderStartIdx + leftSubtreeSize - 1 : -1;;
        const int rightInorderStart = rightSubtreeSize ? rootIdxInInorder  + 1 : -1;
        const int rightInorderEnd = rightSubtreeSize ? inorderEndIdx : -1;
        const int rightPostorderStart = rightSubtreeSize ? postorderStartIdx + leftSubtreeSize : -1;
        const int rightPostorderEnd = rightSubtreeSize ? postorderEndIdx - 1: -1;

        TreeNode* pRoot = new TreeNode(rootValue);
        TreeNode* pLeftSubtree = NULL;
        TreeNode* pRightSubtree = NULL;

        if (leftSubtreeSize > 0){
            pLeftSubtree = constructTree(inorder, postorder, leftInorderStart, leftInorderEnd, leftPostorderStart, leftPostorderEnd);
        }

        if (rightSubtreeSize > 0){
            pRightSubtree = constructTree(inorder, postorder, rightInorderStart, rightInorderEnd, rightPostorderStart, rightPostorderEnd);
        }

        pRoot->left = pLeftSubtree;
        pRoot->right = pRightSubtree; 

        return pRoot;
    }
};