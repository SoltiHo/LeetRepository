// Given a binary tree, find its minimum depth.
// 
// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
#include <queue>
using namespace std;

//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDepth(TreeNode *root) {
        int output = 0;
        if (root){
            queue<TreeNode*> nodeQueue;
            nodeQueue.push(root);
            int depth = 1;
            int levelCount = 0;
            bool found = false;
            while (!found){
                levelCount = nodeQueue.size();
                while (levelCount > 0){
                    if ((nodeQueue.front()->left == NULL) && (nodeQueue.front()->right == NULL)){
                        // found
                        found = true;
                        output = depth;
                        break;
                    }
                    if (nodeQueue.front()->left){
                        nodeQueue.push(nodeQueue.front()->left);
                    }
                    if (nodeQueue.front()->right){
                        nodeQueue.push(nodeQueue.front()->right);
                    }
                    nodeQueue.pop();
                    levelCount--;
                }
                depth++;
            }
        }
        return output;
    }
};