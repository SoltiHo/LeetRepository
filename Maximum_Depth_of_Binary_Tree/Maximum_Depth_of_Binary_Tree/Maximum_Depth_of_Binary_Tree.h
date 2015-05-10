// Given a binary tree, find its maximum depth.
// 
// The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

#include <algorithm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Solution {
public:
    int maxDepth(TreeNode* root) {
        int maxDepth = 0;
        DFS(root, 0, maxDepth);
        return maxDepth;
    }

    void DFS(TreeNode* pRoot, int depth, int& maxDepth){
        if (pRoot == NULL){
            maxDepth = max(maxDepth, depth);
            return;
        }
        DFS(pRoot->left, depth + 1, maxDepth);
        DFS(pRoot->right, depth + 1, maxDepth);
    }
};