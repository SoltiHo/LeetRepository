// Sort a linked list in O(n log n) time using constant space complexity.

#include <vector>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (head == NULL){
            return NULL;
        }

        ListNode* pCurr = head;
        int listLength = 1;
        while (pCurr->next){
            listLength++;
            pCurr = pCurr->next;
        }

        if (listLength == 1){
            // single node list, no need to sort
            return head;
        }


        int length = 1;
        int counter = 0;
        ListNode* pLeft = NULL;
        ListNode* pRight = head;
        ListNode* pRightStart = NULL;
        ListNode* pTail = NULL;
        ListNode* pLastPieceTail = NULL;
        ListNode* pCurrHead = NULL;
        bool connectedWithLastPiece = false;
        bool firstPieceCompleted = false;
        while (true){
            while (true){
                // at the beginning, pTail is pointing to the first candidate
                pRightStart = pLeft = pRight;
                // determine the left half and the right half
                while ((counter < length) && (pRightStart->next)){
                    counter++;
                    pRightStart = pRightStart->next;
                }

                if (counter < length){
                    // meanning no right half since can't get enough for the left
                    pLastPieceTail->next = pLeft;
                    break;
                }

                // decide the length of the right half
                counter = 0;
                pRight = pRightStart;
                while ((pRight) && (counter < length)){
                    counter++;
                    pRight = pRight->next;
                }

                pRight = pRightStart;
                while ((pLeft != pRightStart) || (counter > 0)){
                    // pLeft == pRightStart is the ending condition for the left
                    // counter == 0 is the ending condition for the right
                    if (pCurrHead){
                        if (counter){
                            // right has some remaining
                            if (pLeft != pRightStart){
                                // left has some remaining
                                if (pLeft->val <= pRight->val){
                                    // take left
                                    pTail->next = pLeft;
                                    pLeft = pLeft->next;
                                    pTail->next->next = NULL;
                                }
                                else{
                                    // take right
                                    pTail->next = pRight;
                                    pRight = pRight->next;
                                    pTail->next->next = NULL;
                                    counter--;
                                }
                            }
                            else{
                                // left is done, dump the remaining right elements
                                pTail->next = pRight;
                                pRight = pRight->next;
                                pTail->next->next = NULL;
                                counter--;
                            }
                        }
                        else{
                            // right half is done, dump the remaining left elements
                            pTail->next = pLeft;
                            pLeft = pLeft->next;
                            pTail->next->next = NULL;
                        }
                        pTail = pTail->next;
                        if ((firstPieceCompleted) && (!connectedWithLastPiece)){
                            pLastPieceTail->next = pTail;
                            connectedWithLastPiece = true;
                        }
                    }
                    else{
                        // the very first node of the first piece
                        if (pLeft->val <= pRight->val){
                            // take left
                            pCurrHead = pTail = pLeft;
                            pLeft = pLeft->next;
                        }
                        else{
                            pCurrHead = pTail = pRight;
                            pRight = pRight->next;
                            counter--;
                        }
                    }
                }
                // completed one piece
                pLastPieceTail = pTail;
                connectedWithLastPiece = false;
                firstPieceCompleted = true;
                if (!pRight){
                    break;
                }
            }

            // completed one iteration
            length <<= 1;
            if (length >= listLength){
                break;
            }
            pRight = pCurrHead;
            pCurrHead = NULL;
            pLastPieceTail = NULL;
            connectedWithLastPiece = false;
            firstPieceCompleted = false;
            counter = 0;

        }

        return pCurrHead;
    }

};