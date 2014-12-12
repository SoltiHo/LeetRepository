// Given a linked list, swap every two adjacent nodes and return its head.
// 
// For example,
// Given 1->2->3->4, you should return the list as 2->1->4->3.
// 
// Your algorithm should use only constant space.You may not modify the values in the list, only nodes itself can be changed.

#include <vector>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode* pOutput = NULL;
        ListNode* pCurr = head;
        ListNode* pLast = NULL;
        ListNode* pNext = NULL;
        ListNode* pLastCycleEnd = NULL;
        ListNode* pCurrCycleEnd = NULL;

        if ((pCurr) && (!pCurr->next)){
            // single node list
            pOutput = head;
        }
        else {
            // zero node, or more than two nodes 
            while (pCurr){
                pNext = pCurr->next;
                if (pCurrCycleEnd){
                    if (pLastCycleEnd){
                        pLastCycleEnd->next = pCurr;
                    }
                    else{
                        // first cycle ever
                        pOutput = pCurr;
                    }
                    pCurrCycleEnd->next = pNext;
                    pCurr->next = pLast;
                    pLastCycleEnd = pCurrCycleEnd;
                    pCurrCycleEnd = NULL;
                }
                else{
                    pCurrCycleEnd = pCurr;
                }
                pLast = pCurr;
                pCurr = pNext;
            }
        }
        
        return pOutput;
    }
};