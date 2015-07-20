//Invert a binary tree.
//
//       4
//      / \
//     2   7
//    / \ / \
//   1  3 6  9
//
//  to
//
//       4
//      / \
//     7   2
//    / \ / \
//   9  6 3  1

#include <vector>

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
    TreeNode* invertTree(TreeNode* root) {
        revertSubtree(root);
        return root;
    }

    void revertSubtree(TreeNode* root){
        if (root){
            revertSubtree(root->left);
            revertSubtree(root->right);
            TreeNode* pTemp = root->left;
            root->left = root->right;
            root->right = pTemp;
        }
    }
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        return revertedClone(root);
    }

    TreeNode* revertedClone(TreeNode* root){
        TreeNode* pOutput = NULL;
        if (root){
            pOutput = new TreeNode(root->val);
            pOutput->left = revertedClone(root->right);
            pOutput->right = revertedClone(root->left);
        }
        return pOutput;
    }
};