//  Given a binary tree, flatten it to a linked list in - place.
//  
//  For example,
//  Given
//  
//  1
//  / \
//  2   5
//  / \   \
//  3   4   6
//  The flattened tree should look like :
//  1
//  \
//  2
//  \
//  3
//  \
//  4
//  \
//  5
//  \
//  6
//  click to show hints.
//  
//  Hints:
//  If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution_Iterative {
public:
    void flatten(TreeNode* root){
        stack<TreeNode*> children;

        if (root){
            children.push(root);
            TreeNode* pCurr = NULL;
            TreeNode* pLast = NULL;
            while (children.size() > 0){
                pCurr = children.top();
                children.pop();

                if (pCurr->right){
                    children.push(pCurr->right);
                }

                if (pCurr->left){
                    children.push(pCurr->left);
                }

                pCurr->left = NULL;

                if (pLast){
                    pLast->right = pCurr;
                }
                pLast = pCurr;
            }
        }
    }
};


class Solution_Recursive {
public:
    void flatten(TreeNode* root){
        flattenTheTree(root);
    }

    TreeNode* flattenTheTree(TreeNode *root) {
        TreeNode* pLeftTail = NULL;
        TreeNode* pRightTail = root;
        if ((root) && (root->left || root->right)){
            if (root->left){
                pRightTail = pLeftTail = flattenTheTree(root->left);
            }

            if (root->right){
                pRightTail = flattenTheTree(root->right);
            }

            if (pLeftTail) {
                pLeftTail->right = root->right;
                root->right = root->left;
            }

            root->left = NULL;
        }
        return pRightTail;
    }
};