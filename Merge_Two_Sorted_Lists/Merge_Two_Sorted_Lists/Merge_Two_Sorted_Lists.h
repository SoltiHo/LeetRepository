// Merge two sorted linked lists and return it as a new list.The new list should be made by splicing together the nodes of the first two lists.


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};



class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode* pTail = new ListNode(0); // dummy node
        ListNode* pHead = pTail;
        while (l1 && l2){
            if (l1->val > l2->val){
                // take the smaller one, l2
                pTail->next = l2;
                l2 = l2->next;
            }
            else{
                // take l1
                pTail->next = l1;
                l1 = l1->next;
            }
            pTail = pTail->next;
        }

        // attach the remaining
        if (l1){
            pTail->next = l1;
        }
        else if (l2){
            pTail->next = l2;
        }

        // need to de-allocate the dummy node
        pTail = pHead;
        pHead = pHead->next;
        delete pTail;
        return pHead;
    }
};