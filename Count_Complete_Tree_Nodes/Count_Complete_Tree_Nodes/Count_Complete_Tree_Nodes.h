// Given a complete binary tree, count the number of nodes.
// 
// Definition of a complete binary tree from Wikipedia :
// In a complete binary tree every level, except possibly the last, is completely filled, 
// and all nodes in the last level are as far left as possible.It can have between 1 and 2h nodes inclusive at the last level h.


#include <vector>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution_Refine {
public:
    int countNodes(TreeNode* root) {
        int output = 0;
        if (root){
            TreeNode* pCurr = root;
            int leftMaxDepth = -1;
            while (pCurr){
                leftMaxDepth++;
                pCurr = pCurr->left;
            }
            pCurr = root;
            int rightMaxDepth = -1;
            while (pCurr){
                rightMaxDepth++;
                pCurr = pCurr->right;
            }

            if (leftMaxDepth == rightMaxDepth){
                // perfect tree
                output = (1 << (leftMaxDepth + 1)) - 1;
            }
            else{
                int count = 0;
                bool found = false;  // critical point found
                findDepth(root, 0, leftMaxDepth, count, found);
                output = (1 << (rightMaxDepth + 1)) - 1 + count;
            }
        }
        return output;
    }

    int findDepth(TreeNode* root, int depth, int targetDepth, int& count, bool& found){
        if (root){
            // depth start from 0, and count start from 1.
            if (depth == targetDepth){
                count++;
            }

            int leftDepth = findDepth(root->left, depth + 1, targetDepth, count, found);
            if (!found){
                int rightDepth = findDepth(root->right, depth + 1, targetDepth, count, found);
                if (leftDepth != rightDepth){
                    found = true;  // skip the rest computation
                }
            }
            return leftDepth;
        }
        else{
            return depth;
        }
    }
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        int output = 0;
        if (root){
            TreeNode* pCurr = root;
            int leftMaxDepth = 0;
            while (pCurr){
                leftMaxDepth++;
                pCurr = pCurr->left;
            }
            pCurr = root;
            int rightMaxDepth = 0;
            while (pCurr){
                rightMaxDepth++;
                pCurr = pCurr->right;
            }

            if (leftMaxDepth == rightMaxDepth){
                // perfect tree
                output = (1 << leftMaxDepth) - 1;
            }
            else{
                vector<int> buffer;
                bool found = false;  // critical point found
                findDepth(root, 0, buffer, found);
                output = ((1 << (buffer.size() - 1)) - 1) + buffer.back();
            }
        }
        return output;
    }

    int findDepth(TreeNode* root, int depth, vector<int>& buffer, bool& found){
        if (root){
            // depth start from 0, and count start from 1.
            if (buffer.size() == depth){
                // open a new depth
                buffer.push_back(1);
            }
            else{
                buffer[depth]++;
            }

            int leftDepth = findDepth(root->left, depth + 1, buffer, found);
            if (!found){
                int rightDepth = findDepth(root->right, depth + 1, buffer, found);
                if (leftDepth != rightDepth){
                    found = true;  // skip the rest computation
                }
            }
            return leftDepth;
        }
        else{
            return depth;
        }
    }
};


