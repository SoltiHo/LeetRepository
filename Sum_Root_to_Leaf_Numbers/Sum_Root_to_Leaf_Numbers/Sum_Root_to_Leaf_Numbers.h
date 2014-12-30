//  Given a binary tree containing digits from 0 - 9 only, each root - to - leaf path could represent a number.
//  
//  An example is the root - to - leaf path 1->2->3 which represents the number 123.
//  
//  Find the total sum of all root - to - leaf numbers.
//  
//  For example,
//  
//    1
//   / \
//  2   3
//  The root - to - leaf path 1->2 represents the number 12.
//  The root - to - leaf path 1->3 represents the number 13.
//  
//  Return the sum = 12 + 13 = 25.

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
    int sumNumbers(TreeNode *root) {
        int output = 0;
        if (root){
            DFS(output, root, 0);
        }
        return output;
    }

    void DFS(int& output, TreeNode* pRoot, int Sum){
        if ((pRoot->left) || (pRoot->right)){
            // non-leaf
            if (pRoot->left){
                DFS(output, pRoot->left, Sum * 10 + pRoot->val);
            }
            if (pRoot->right){
                DFS(output, pRoot->right, Sum * 10 + pRoot->val);
            }
        }
        else{
            // leaf
            output += (Sum * 10 + pRoot->val);
        }
    }
};


