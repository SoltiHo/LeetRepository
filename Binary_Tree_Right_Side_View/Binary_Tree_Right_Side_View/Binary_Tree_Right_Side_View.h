// Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
//
//For example :
//  Given the following binary tree,
//      1          <-- -
//     / \
//    2   3         <-- -
//     \   \
//      5   4       <-- -
//  You should return[1, 3, 4].
//  

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
    vector<int> rightSideView(TreeNode *root) {
        vector<int> output;
        if (root){
            DFS(root, 0, output);
        }
        return output;
    }

    void DFS(TreeNode *root, const int level, vector<int>& output){
        if (output.size() > level){
            // size 1, --> only level 0
            // size 2, --> level 0, 1
            // no need to create one new position
            output[level] = root->val;
        }
        else{
            // need to create one more level, increment the depth
            output.push_back(root->val);
        }

        if (root->left){
            // travel left first, so that the right can overwrite it
            DFS(root->left, level + 1, output);
        }
        if (root->right){
            // then travel right
            DFS(root->right, level + 1, output);
        }
    }
};