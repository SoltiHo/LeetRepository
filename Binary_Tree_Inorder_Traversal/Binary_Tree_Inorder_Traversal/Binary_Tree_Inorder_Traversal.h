//  Given a binary tree, return the inorder traversal of its nodes' values.
//  
//  For example :
//  Given binary tree{ 1, #, 2, 3 },
//  1
//   \
//    2
//   /
//  3
//  return[1, 3, 2].
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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> output;
        bool popped = false;
        if (root){
            stack<TreeNode*> nodeStack;
            TreeNode* pCurr = NULL;
            nodeStack.push(root);
            while (nodeStack.size() > 0){
                pCurr = nodeStack.top();
                if ((pCurr->left) && (!popped)){
                    nodeStack.push(pCurr->left);
                    popped = false;
                }
                else{
                    output.push_back(pCurr->val);
                    nodeStack.pop();
                    popped = true;
                    if (pCurr->right){
                        // got right but no left
                        nodeStack.push(pCurr->right);
                        popped = false;
                    }
                }
            }
        }
        return output;
    }
};