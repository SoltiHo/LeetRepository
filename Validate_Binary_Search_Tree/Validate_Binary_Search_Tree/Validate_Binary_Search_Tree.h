// Given a binary tree, determine if it is a valid binary search tree(BST).
// 
// Assume a BST is defined as follows :
// 
// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.
#include <limits>
#include <algorithm>
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
    struct Range{
        int min;
        int max;
        Range() : min(INT_MAX), max(INT_MIN){};
    };

    bool isValidBST(TreeNode *root) {
        Range r;
        if (root){
            return BST(root, r);
        }
        else{
            return true;
        }
        
    }

    bool BST(TreeNode* root, Range& r){
        Range leftRange;
        bool isHealthy = true;
        if (root->left){
            if (!BST(root->left, leftRange)){
                return false;
            }
            if (root->val <= leftRange.max) {
                return false;
            }
        }

        Range rightRange;
        if (root->right){
            if (!BST(root->right, rightRange)){
                return false;
            }
            if (root->val >= rightRange.min){
                return false;
            }
        }

        r.min = min(root->val, leftRange.min);
        r.max = max(root->val, rightRange.max);
        return true;
    }
};
