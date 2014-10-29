// Given a binary tree, return the postorder traversal of its nodes' values.
// Note: Recursive solution is trivial, could you do it iteratively?
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

struct Record {
    TreeNode* pNode;
    bool checked;
    Record() : pNode(NULL), checked(false){};
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        stack<Record> nodeStack;
        Record temp;
        vector<int> answer;
        if (root == NULL){
            return answer;
        }
        
        temp.pNode = root;
        temp.checked = false;
        nodeStack.push(temp);
        
        TreeNode* pNodeBeingChecked = NULL;
        while (nodeStack.size() > 0){
            if ((nodeStack.top().pNode->left == NULL) && (nodeStack.top().pNode->right == NULL)){
                answer.push_back(nodeStack.top().pNode->val);
                nodeStack.pop();
            }
            else{
                if (nodeStack.top().checked){
                    answer.push_back(nodeStack.top().pNode->val);
                    nodeStack.pop();
                }
                else{
                    nodeStack.top().checked = true;
                    pNodeBeingChecked = nodeStack.top().pNode;
                    if (pNodeBeingChecked->right){
                        temp.pNode = pNodeBeingChecked->right;
                        nodeStack.push(temp);
                    }
                    if (pNodeBeingChecked->left){
                        temp.pNode = pNodeBeingChecked->left;
                        nodeStack.push(temp);
                    }
                }
            }
        }

        return answer;
    }
};