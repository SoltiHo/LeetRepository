// Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
// 
// You should preserve the original relative order of the nodes in each of the two partitions.
// 
// For example,
// Given 1->4->3->2->5->2 and x = 3,
// return 1->2->2->4->3->5.

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
    ListNode *partition(ListNode *head, int x) {
        ListNode* pSmallerThan = NULL;
        ListNode* pSmallerThanTail = NULL;
        ListNode* pGreaterOrEqual = NULL;
        ListNode* pGreaterOrEqualTail = NULL;
        ListNode* pCurr = head;
        while (pCurr){
            if (pCurr->val < x){
                // smaller than part
                if (pSmallerThanTail){
                    pSmallerThanTail->next = pCurr;
                    pSmallerThanTail = pSmallerThanTail->next;
                }
                else{
                    pSmallerThan = pSmallerThanTail = pCurr;
                }
            }
            else{
                // greater or equal
                if (pGreaterOrEqualTail){
                    pGreaterOrEqualTail->next = pCurr;
                    pGreaterOrEqualTail = pGreaterOrEqualTail->next;
                }
                else{
                    pGreaterOrEqual = pGreaterOrEqualTail = pCurr;
                }
            }
            pCurr = pCurr->next;
        }

        if ((pSmallerThan) && (pGreaterOrEqual)){
            // contain both lists
            pSmallerThanTail->next = pGreaterOrEqual;
            pGreaterOrEqualTail->next = NULL;
        }
        else if (pGreaterOrEqual){
            // only greater than or equal
            pSmallerThan = pGreaterOrEqual;
            pGreaterOrEqualTail->next = NULL;
        }

        return pSmallerThan;
    }
};