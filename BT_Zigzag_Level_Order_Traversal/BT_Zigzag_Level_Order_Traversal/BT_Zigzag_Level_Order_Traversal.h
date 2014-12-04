//  Given a binary tree, return the zigzag level order traversal of its nodes' values. 
//  (ie, from left to right, then right to left for the next level and alternate between).
//  
//  For example :
//  Given binary tree{ 3, 9, 20, #, #, 15, 7 },
//    3
//   / \
//  9  20
//     / \
//   15   7
//  return its zigzag level order traversal as :
//  [
//      [3],
//      [20, 9],
//      [15, 7]
//  ]

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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> output;
        if (root){
            stack<TreeNode*> leftFirst;
            stack<TreeNode*> rightFirst;
            rightFirst.push(root);
            bool currentlyLeftFirst = false;
            bool firstInCurrentLevel = true;
            TreeNode* pCurr = NULL;
            while ((leftFirst.size() > 0) || (rightFirst.size() > 0)){
                if (currentlyLeftFirst){
                    // left first
                    pCurr = leftFirst.top();
                    leftFirst.pop();
                    if (firstInCurrentLevel){
                        output.push_back({ pCurr->val });
                        firstInCurrentLevel = false;
                    }
                    else{
                        output[output.size() - 1].push_back(pCurr->val);
                    }

                    // the next level is right first
                    if (pCurr->right){
                        rightFirst.push(pCurr->right);
                    }
                    if (pCurr->left){
                        rightFirst.push(pCurr->left);
                    }


                    if (leftFirst.size() == 0){
                        // completed current level
                        firstInCurrentLevel = true;
                        currentlyLeftFirst = false;
                    }
                }
                else{
                    // right first
                    pCurr = rightFirst.top();
                    rightFirst.pop();
                    if (firstInCurrentLevel){
                        output.push_back({pCurr->val});
                        firstInCurrentLevel = false;
                    }
                    else{
                        output[output.size() - 1].push_back(pCurr->val);
                    }

                    // the next level is left first
                    if (pCurr->left){
                        leftFirst.push(pCurr->left);
                    }
                    if (pCurr->right){
                        leftFirst.push(pCurr->right);
                    }

                    if (rightFirst.size() == 0){
                        // completed current level
                        firstInCurrentLevel = true;
                        currentlyLeftFirst = true;
                    }
                }
            }

        }
        return output;
    }
};