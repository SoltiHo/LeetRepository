// Given a list, rotate the list to the right by k places, where k is non - negative.
// 
// For example :
// Given 1->2->3->4->5->NULL and k = 2,
// return 4->5->1->2->3->NULL.

#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        ListNode* pNewHead = head;
        if ((head) && (k > 0)){
            ListNode* pCurr = head;
            ListNode* pLast = NULL;
            int nodeCount = 0;
            while (pCurr){
                nodeCount++;
                pLast = pCurr;
                pCurr = pCurr->next;
            }

            // make it a cycle
            pLast->next = head;

            // find the new head
            pNewHead = head;
            const int rotateCount = nodeCount - (k % nodeCount);
            for (int i = 0; i < rotateCount; ++i){
                pLast = pNewHead;
                pNewHead = pNewHead->next;
            }
            pLast->next = NULL;

        }
        return pNewHead;
    }
};