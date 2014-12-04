#include "gtest/gtest.h"  // access test macro
#include "Add_Two_Numbers.h"

bool validateList(ListNode* list1, ListNode* list2){
    while ((list1) && (list2)){
        if (list1->val != list2->val){
            return false;
        }
        list1 = list1->next;
        list2 = list2->next;
    }

    if (((list1 == NULL) && (list2 != NULL)) ||
        ((list1 != NULL) && (list2 == NULL)))
    {
        return false;
    }
    else{
        return true;
    }
}

void deleteList(ListNode* p){
    ListNode* pNext = NULL;
    while (p){
        pNext = p->next;
        delete p;
        p = pNext;
    }
}
TEST(Leet, Basic01){
    ListNode *pL1Root = new ListNode(9);
    ListNode *pCurr = pL1Root;

    ListNode *pL2Root = new ListNode(1);
    pCurr = pL2Root;
    pCurr->next = new ListNode(9);
    pCurr = pCurr->next;
    pCurr->next = new ListNode(9);
    pCurr = pCurr->next;
    pCurr->next = new ListNode(9);
    pCurr = pCurr->next;
    pCurr->next = new ListNode(9);
    pCurr = pCurr->next;
    pCurr->next = new ListNode(9);
    pCurr = pCurr->next;
    pCurr->next = new ListNode(9);
    pCurr = pCurr->next;
    pCurr->next = new ListNode(9);
    pCurr = pCurr->next;
    pCurr->next = new ListNode(9);
    pCurr = pCurr->next;
    pCurr->next = new ListNode(9);
    pCurr = pCurr->next;

    Solution sol;
    ListNode *pOutput = sol.addTwoNumbers(pL1Root, pL2Root);

    ListNode *pExpected = new ListNode(0);
    pCurr = pExpected;
    pCurr->next = new ListNode(0);
    pCurr = pCurr->next;
    pCurr->next = new ListNode(0);
    pCurr = pCurr->next;
    pCurr->next = new ListNode(0);
    pCurr = pCurr->next;
    pCurr->next = new ListNode(0);
    pCurr = pCurr->next;
    pCurr->next = new ListNode(0);
    pCurr = pCurr->next;
    pCurr->next = new ListNode(0);
    pCurr = pCurr->next;
    pCurr->next = new ListNode(0);
    pCurr = pCurr->next;
    pCurr->next = new ListNode(0);
    pCurr = pCurr->next;
    pCurr->next = new ListNode(0);
    pCurr = pCurr->next;
    pCurr->next = new ListNode(1);

    ASSERT_TRUE(validateList(pOutput, pExpected));
    deleteList(pOutput);
    deleteList(pExpected);
    deleteList(pL1Root);
    deleteList(pL2Root);
}

// --------------------------------------------------------------------

