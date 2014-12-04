//  Given a binary tree, return the preorder traversal of its nodes' values.
//  
//  For example :
//  Given binary tree{ 1, #, 2, 3 },
//  1
//   \
//    2
//   /
//  3
//  return[1, 2, 3].
//  
//  Note: Recursive solution is trivial, could you do it iteratively ?

#include <vector>
#include <stack>
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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> output;
        if (root){
            stack<TreeNode*> nodes;
            TreeNode* pCurr = NULL;
            nodes.push(root);
            while (nodes.size() > 0){
                pCurr = nodes.top();
                nodes.pop();
                if (pCurr->right){
                    nodes.push(pCurr->right);
                }
                if (pCurr->left){
                    nodes.push(pCurr->left);
                }
                output.push_back(pCurr->val);
            }
        }
        return output;
    }
};