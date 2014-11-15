//  Given a binary tree
//  
//  struct TreeLinkNode {
//      TreeLinkNode *left;
//      TreeLinkNode *right;
//      TreeLinkNode *next;
//  }
//  Populate each next pointer to point to its next right node.If there is no next right node, the next pointer should be set to NULL.
//  
//  Initially, all next pointers are set to NULL.
//  
//  Note:
//  
//  You may only use constant extra space.
//  You may assume that it is a perfect binary tree(ie, all leaves are at the same level, and every parent has two children).
//  For example,
//  Given the following perfect binary tree,
//  1
//  / \
//  2    3
//  / \ / \
//  4  5  6  7
//  After calling your function, the tree should look like :
//  1->NULL
//  / \
//  2 -> 3->NULL
//  / \ / \
//  4->5->6->7->NULL

#include <vector>
using namespace std;

// Definition for binary tree with next pointer.
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode* pCurr = root;
        TreeLinkNode* pLastOneSeen = NULL;
        TreeLinkNode* pNextLevelHead = NULL;
        while (pCurr) {
            if ((pCurr->left) && (pCurr->right)){
                // contain both
                if (pLastOneSeen){
                    pLastOneSeen->next = pCurr->left;
                }
                pLastOneSeen = pCurr->left->next = pCurr->right;
                if (pNextLevelHead == NULL){
                    pNextLevelHead = pCurr->left;
                }
            }
            else if (pCurr->left){
                // only left
                if (pLastOneSeen){
                    pLastOneSeen->next = pCurr->left;
                }
                pLastOneSeen = pCurr->left;
                if (pNextLevelHead == NULL){
                    pNextLevelHead = pCurr->left;
                }
            }
            else if (pCurr->right){
                // only right
                if (pLastOneSeen){
                    pLastOneSeen->next = pCurr->right;
                }
                pLastOneSeen = pCurr->right;
                if (pNextLevelHead == NULL){
                    pNextLevelHead = pCurr->right;
                }
            }
            else{
                // no children, do nothing
            }

            
            if (pCurr->next == NULL){
                // last node of current level
                // go to next level
                pCurr = pNextLevelHead;
                pNextLevelHead = NULL;
                pLastOneSeen = NULL;
            }
            else{
                pCurr = pCurr->next;
            }
        }
    }
};

class Solution_LinearSpace {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL){
            return;
        }

        vector<TreeLinkNode*> queue;

        int currLevelSize = 1;
        queue.push_back(root);
        int counter = 0;
        while (queue.size() > 0){
            for (int i = 0; i < currLevelSize; ++i){
                if (queue[i]->left){
                    queue.push_back(queue[i]->left);
                    counter++;
                }
                if (queue[i]->right){
                    queue.push_back(queue[i]->right);
                    counter++;
                }
                if (i == currLevelSize - 1){
                    // right most
                    queue[0]->right = NULL;
                }
                else{
                    // should point to the next one
                    queue[0]->right = queue[1];
                }
                queue.erase(queue.begin());
                if (i == currLevelSize - 1){
                    currLevelSize = counter;
                    counter = 0;
                    break;
                }
            }
        }
    }
};