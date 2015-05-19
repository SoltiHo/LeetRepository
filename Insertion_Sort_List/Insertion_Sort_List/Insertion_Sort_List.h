// Sort a linked list using insertion sort.

#include <vector>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class SolutionLatestTrial {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummyHead = new ListNode(INT_MIN);
        while (head){
            ListNode* pNext = head->next;
            ListNode* pSorted = dummyHead;
            ListNode* pLast = NULL;
            while ((pSorted) && (pSorted->val <= head->val)){
                pLast = pSorted;
                pSorted = pSorted->next;
            }

            pLast->next = head;
            head->next = pSorted;
            head = pNext;
        }
        head = dummyHead->next;
        delete dummyHead;
        
        return head;
    }
};


class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (head == NULL){
            return NULL;
        }

        if (head->next == NULL){
            return head;
        }

        this->pSortedListHead = head;
        ListNode* pLast = head;
        ListNode* pCurr = head->next;
        ListNode* pNext = pCurr->next;
        while (pCurr){
            if (pLast->val > pCurr->val){
                pLast->next = pCurr->next;
                insert(pCurr);
                pCurr = pLast->next;
            }
            else{
                pLast = pCurr;
                pCurr = pCurr->next;
            }
        }

        return this->pSortedListHead;
    }

    void insert(ListNode* pNew){
        if (pNew->val <= this->pSortedListHead->val){
            pNew->next = this->pSortedListHead;
            this->pSortedListHead = pNew;
        }
        else{
            ListNode* pTemp = this->pSortedListHead;
            while (pNew->val > pTemp->next->val){
                pTemp = pTemp->next;
            }
            pNew->next = pTemp->next;
            pTemp->next = pNew;
        }
    }

    ListNode* pSortedListHead;
};