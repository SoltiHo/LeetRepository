// Reverse a singly linked list.



// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pOutput = NULL;
        if (head){
            ListNode* pCurr = head;
            ListNode* pLast = NULL;
            while (pCurr){
                pOutput = pCurr->next;
                pCurr->next = pLast;

                pLast = pCurr;
                pCurr = pOutput;
            }
            pOutput = pLast;
        }
        return pOutput;
    }
};