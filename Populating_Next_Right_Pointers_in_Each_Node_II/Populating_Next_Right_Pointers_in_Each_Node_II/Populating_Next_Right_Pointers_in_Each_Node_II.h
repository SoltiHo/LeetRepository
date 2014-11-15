//  Follow up for problem "Populating Next Right Pointers in Each Node".
//  
//  What if the given tree could be any binary tree ? Would your previous solution still work ?
//  
//  Note :
//  
//       You may only use constant extra space.
//       For example,
//       Given the following binary tree,
//       1
//       / \
//       2    3
//       / \    \
//       4   5    7
//       After calling your function, the tree should look like :
//  1->NULL
//  / \
//  2 -> 3->NULL
//  / \    \
//  4-> 5 -> 7->NULL
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
