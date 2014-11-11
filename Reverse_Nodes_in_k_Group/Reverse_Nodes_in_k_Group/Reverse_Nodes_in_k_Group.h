// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
// 
// If the number of nodes is not a multiple of k then left - out nodes in the end should remain as it is.
// 
// You may not alter the values in the nodes, only nodes itself may be changed.
// 
// Only constant memory is allowed.
// 
// For example,
// Given this linked list : 1->2->3->4->5
// 
// For k = 2, you should return : 2->1->4->3->5
// 
// For k = 3, you should return : 3->2->1->4->5

#include <vector>
#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode* pRoot){
    while (pRoot){
        cout << pRoot->val << " --> ";
        pRoot = pRoot->next;
    }
    cout << endl;
}

ListNode* reverseACycle(ListNode* pCycleStartNode, const int k){
    // guarantee a completed cycle
    ListNode *pCurr = pCycleStartNode->next, *pPrev = pCycleStartNode;
    ListNode *pTemp = NULL;
    ListNode *newCycleStart = NULL;
    for (int i = 0; i < k - 1; ++i){
        pTemp = pCurr->next;
        pCurr->next = pPrev;
        newCycleStart = pPrev = pCurr;
        pCurr = pTemp;
    }
    pCycleStartNode->next = pCurr;
    return newCycleStart;
}
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == NULL){
            return NULL;
        }

        if (k == 1){
            return head;
        }

        ListNode* currentNode = head;
        ListNode* cycleStart = NULL;
        ListNode* firstCycleHead = head;
        ListNode* nextNode = NULL;
        ListNode* lastCycleTail = NULL;
        ListNode* currentCycleTail = NULL;
        ListNode* currentCycleStart = NULL;
        bool firstCycleCompleted = false;
        int cycleCounter = 0;
        while (currentNode){
            cycleCounter++;
            nextNode = currentNode->next;
            if (cycleCounter == 1){
                cycleStart = currentNode;
            }
            if (cycleCounter == k){
                currentCycleTail = cycleStart;
                currentCycleStart = reverseACycle(cycleStart, k);
                
                if (lastCycleTail){
                    lastCycleTail->next = currentCycleStart;
                }
                lastCycleTail = currentCycleTail;
                cycleCounter = 0;
                if (firstCycleCompleted == false){
                    firstCycleHead = currentNode;
                    firstCycleCompleted = true;
                }
            }
            currentNode = nextNode;
        }
        return firstCycleHead;
    }
};