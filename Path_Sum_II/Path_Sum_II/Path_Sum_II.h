//  Given a binary tree and a sum, find all root - to - leaf paths where each path's sum equals the given sum.
//  
//  For example :
//  Given the below binary tree and sum = 22,
//        5
//       / \
//      4   8
//     /   / \
//    11  13  4
//   / \     / \
//  7   2   5   1
//  return
//  [
//      [5, 4, 11, 2],
//      [5, 8, 4, 5]
//  ]

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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        if (root){
            DFS(root, sum);
        }
        return this->output;
    }


    void DFS(TreeNode *root, int sum) {
        // base cases, assume the caller the responsibilty of checking root to be non-NULL
        if((root->left == NULL) && (root->right == NULL)){
            // leaf node
            if (root->val == sum){
                // add one solution
                this->buffer.push_back(root->val);
                this->output.push_back(this->buffer);
                this->buffer.pop_back();
            }
            return;
        }

        this->buffer.push_back(root->val);
        sum -= root->val;
        if (root->left){
            DFS(root->left, sum);
        }

        if (root->right){
            DFS(root->right, sum);
        }
        sum += root->val;
        this->buffer.pop_back();
    }

    vector<int> buffer;
    vector<vector<int>> output;
};