// Given a linked list, return the node where the cycle begins.If there is no cycle, return null.
// 
// Follow up :
// Can you solve it without using extra space ?

#include <vector>
#include <unordered_set>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution_HareAndTurtle {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* pCycle = NULL;
        if ((head) && (head->next)){
            if (head == head->next){
                pCycle = head;
            }
            else{
                ListNode* pTurtle = head;
                ListNode* pHare = head->next;

                while (pTurtle != pHare){
                    if ((pHare->next == NULL) || (pHare->next->next == NULL)){
                        break;
                    }
                    else{
                        pHare = pHare->next->next;
                        pTurtle = pTurtle->next;
                    }
                }
                if (pTurtle == pHare){
                    pHare = head;
                    pTurtle = pTurtle->next;
                    while (pTurtle != pHare){
                        pTurtle = pTurtle->next;
                        pHare = pHare->next;
                    }
                    pCycle = pTurtle;
                }
            }
        }
        return pCycle;
    }
};


class Solution_Hash {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* pCycle = NULL;
        if ((head) && (head->next)){
            unordered_set<ListNode*> prevNodes;
            ListNode* pCurr = head;
            while (pCurr){
                if (prevNodes.find(pCurr) != prevNodes.end()){
                    // found
                    pCycle = pCurr;
                    break;
                }
                else{
                    prevNodes.insert(pCurr);
                    pCurr = pCurr->next;
                }
            }
        }
        return pCycle;
    }
};
