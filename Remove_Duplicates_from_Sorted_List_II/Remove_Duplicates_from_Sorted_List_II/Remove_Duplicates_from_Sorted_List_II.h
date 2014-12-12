// Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
// 
// For example,
// Given 1->2->3->3->4->4->5, return 1->2->5.
// Given 1->1->1->2->3, return 2->3.

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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode* pOutput = NULL;
        if ((head) && (head->next == NULL)){
            // single node list
            pOutput = head;
        }
        else if(head) {
            // multiple nodes
            ListNode* pCurr = head;
            ListNode* pLastDistinctNumber = NULL;
            ListNode* pCurrCandidate = NULL;
            ListNode* pTail = NULL;
            bool duplicateFound = false;
            while (pCurr){
                if (pCurrCandidate){
                    if (pCurr->val == pCurrCandidate->val){
                        duplicateFound = true;
                    }
                    else{
                        if (!duplicateFound){
                            // take this number
                            if (pLastDistinctNumber){
                                pTail = pLastDistinctNumber->next = pCurrCandidate;
                                pLastDistinctNumber = pLastDistinctNumber->next;
                            }
                            else{
                                pTail = pOutput = pLastDistinctNumber = pCurrCandidate;
                            }
                        }
                        pCurrCandidate = pCurr;
                        duplicateFound = false;
                    }
                }
                else{
                    // first number
                    pCurrCandidate = pCurr;
                    duplicateFound = false;
                }
                pCurr = pCurr->next;
            }

            if (!duplicateFound){
                // take this number
                if (pLastDistinctNumber){
                    pTail = pLastDistinctNumber->next = pCurrCandidate;
                }
                else{
                    pTail = pOutput = pLastDistinctNumber = pCurrCandidate;
                }
            }

            if (pTail){
                pTail->next = NULL;
            }
        }
        return pOutput;

    }
};
