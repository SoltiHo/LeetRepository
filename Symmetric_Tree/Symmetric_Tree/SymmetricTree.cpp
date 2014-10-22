#include <cstdio>
#include <cstdlib>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
bool isIdentical(TreeNode *rootLeft, TreeNode *rootRight){
    // compare value
    if (((rootLeft == NULL) && (rootRight != NULL)) || ((rootLeft != NULL) && (rootRight == NULL))) {
        // one is Null, the other is not
        return false;
    }
    else if ((rootLeft == NULL) && (rootRight == NULL)){
        // both Null
        return true;
    }
    else{
        // both NOT null
        if (rootLeft->val != rootRight->val){
            return false;
        }
        else{
            return (isIdentical(rootLeft->left, rootRight->right)) && (isIdentical(rootLeft->right, rootRight->left));
        }
    }
}

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (root == NULL){
            return true;
        }
        else if(((root->left) && (!(root->right))) || (!((root->left)) && (root->right))){
            // one is blank while the other is not
            return false;
        }
        else if((root->left == NULL) && (root->right == NULL)){
            // both null
            return true;
        }
        else{
            // both has something, then the left and the right need to be mirrored.
            return isIdentical(root->left, root->right);
        }
    }
};