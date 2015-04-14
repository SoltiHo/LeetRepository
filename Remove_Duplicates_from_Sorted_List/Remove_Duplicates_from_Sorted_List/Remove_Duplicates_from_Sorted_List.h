// Given a sorted linked list, delete all duplicates such that each element appear only once.
// 
// For example,
// Given 1->1->2, return 1->2.
// Given 1->1->2->3->3, return 1->2->3.


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head){
            ListNode* pCurr = head;
            ListNode* pTemp = NULL;
            while (pCurr->next){
                if (pCurr->val == pCurr->next->val){
                    pTemp = pCurr->next;
                    pCurr->next = pCurr->next->next;
                    delete pTemp;
                }
                else{
                    pCurr = pCurr->next;
                }
            }
        }
        return head;
    }
};