// Given a binary tree, determine if it is height - balanced.
// 
// For this problem, a height - balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.


#include <algorithm>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};





class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int depth = 0;
        return (DFS(root) == -1 ? false : true);
    }

    int DFS(TreeNode* pRoot){
        if (pRoot == NULL){
            return 0;
        }

        int leftDepth = DFS(pRoot->left);
        if (leftDepth == -1){
            // left subtree is not balanced
            return -1;
        }
        int rightDepth = DFS(pRoot->right);
        if (rightDepth == -1){
            // right subtree is not balanced
            return -1;
        }

        if (abs(leftDepth - rightDepth) > 1){
            return -1;
        }

        return max(leftDepth, rightDepth) + 1;
    }
};