// Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
// 
// For example :
// Given binary tree{ 3, 9, 20, #, #, 15, 7 },
//       3
//      / \
//     9  20
//        / \
//          15   7
// return its level order traversal as :
// [
//     [3],
//     [9, 20],
//     [15, 7]
// ]

#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class SolutionDFS {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> output;
        DFS(output, root, 0);
        return output;
    }


    void DFS(vector<vector<int>>& output, TreeNode* pCurr, int level){
        if (pCurr == NULL){
            return;
        }

        if (level == output.size()){
            // need to create one more level
            output.push_back(vector<int>(1, pCurr->val));
            //output.insert(output.begin(), vector<int>(1, pCurr->val));
        }
        else{
            output[level].push_back(pCurr->val);
            //output[output.size() - 1 - level].push_back(pCurr->val);
        }

        DFS(output, pCurr->left, level + 1);
        DFS(output, pCurr->right, level + 1);
    }
};


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> output;
        if (root){
            int currLevelSize = 1;
            queue<TreeNode*> q;
            q.push(root);
            vector<int> buffer;
            while (q.size()){
                if (q.front()->left){
                    q.push(q.front()->left);
                }
                if (q.front()->right){
                    q.push(q.front()->right);
                }
                buffer.push_back(q.front()->val);
                q.pop();
                currLevelSize--;
                if (currLevelSize == 0){
                    //output.insert(output.begin(), buffer);
                    output.push_back(buffer);
                    buffer.clear();
                    currLevelSize = q.size();
                }
            }

        }

        return output;
    }
};