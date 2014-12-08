// Reverse a linked list from position m to n.Do it in - place and in one - pass.
// 
// For example :
// Given 1->2->3->4->5->NULL, m = 2 and n = 4,
// 
// return 1->4->3->2->5->NULL.
// 
// Note :
//      Given m, n satisfy the following condition :
// 1 <= m <= n <= length of list.

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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (m == n){
            return head;
        }

        ListNode* pOutput = head;
        ListNode* pCurr = head;
        ListNode* pLast = NULL;
        ListNode* pBeforeCycle = NULL;
        ListNode* pTail = NULL;
        ListNode* pNext = NULL;
        int nodeID = 1;
        while (pCurr) {
            if (nodeID == m){
                // found the start node
                if (m == 1){
                    // start from the first
                    pTail = pCurr;
                }
                else{
                    pBeforeCycle = pLast;
                    pTail = pCurr;
                    pOutput = head;
                }
            }

            if (pTail){
                // meaning in reverse mode
                if (pBeforeCycle){
                    pBeforeCycle->next = pCurr;
                }
                pNext = pCurr->next;
                pCurr->next = pLast;
                if (nodeID == n){
                    // closing
                    pTail->next = pNext;
                    if (!pBeforeCycle){
                        pOutput = pCurr;
                    }
                    break;
                }
            }
            else{
                // before the reversing period
                pNext = pCurr->next;
            }

            // going to the next
            pLast = pCurr;
            pCurr = pNext;
            nodeID++;
        }

        return pOutput;
    }
};