// Given two binary trees, write a function to check if they are equal or not.
// 
// Two binary trees are considered equal if they are structurally identical and the nodes have the same value.


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q){
            return true;
        }
        else if ((!p && q) || (p && !q)){
            // only 1 of them is null
            return false;
        }
        else if (p->val != q->val){
            return false;
        }

        if (!isSameTree(p->left, q->left)){
            return false;
        }

        return isSameTree(p->right, q->right);
    }
};