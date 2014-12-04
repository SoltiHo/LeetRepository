// Given a linked list, determine if it has a cycle in it.
// 
// Follow up :
// Can you solve it without using extra space ?

#include <unordered_set>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution_Hash {
public:
    bool hasCycle(ListNode *head) {
        if (head){
            unordered_set<ListNode*> prevNodes;
            ListNode* pCurr = head;
            while (pCurr){
                if (prevNodes.find(pCurr) != prevNodes.end()){
                    // found
                    return true;
                }
                else{
                    prevNodes.insert(pCurr);
                    pCurr = pCurr->next;
                }
            }
        }
        return false;
    }
};


class Solution_HareAndTurtle {
public:
    bool hasCycle(ListNode *head) {
        if ((head) && (head->next)){
            ListNode* pTurtle = head;
            ListNode* pHare = head->next;
            while (pTurtle != pHare){
                if ((pHare->next == NULL) || (pHare->next->next == NULL)){
                    return false;
                }
                else{
                    pHare = pHare->next->next;
                    pTurtle = pTurtle->next;
                }
            }
            return true;
        }
        return false;
    }
};