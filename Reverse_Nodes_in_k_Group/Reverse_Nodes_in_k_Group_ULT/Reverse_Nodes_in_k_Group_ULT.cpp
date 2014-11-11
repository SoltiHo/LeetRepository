#include "gtest/gtest.h"  // access test macro
#include "Reverse_Nodes_in_k_Group.h"

bool verifyLinkedList(ListNode* list1, ListNode* list2){


    while (list1 && list2){
        if (list1->val != list2->val){
            return false;
        }
        list1 = list1->next;
        list2 = list2->next;
    }
    if (((list1 == NULL) && (list2 != NULL)) ||
        ((list1 != NULL) && (list2 == NULL))){
        return false;
    }
    else{
        return true;
    }
    
}

void deleteLinkedList(ListNode* pRoot){
    ListNode* pNext = NULL;
    while (pRoot){
        pNext = pRoot->next;
        delete pRoot;
        pRoot = pNext;
    }
}
TEST(LeetCode, Fail02){
    ListNode* pRoot = NULL;
    ListNode* pCurr = NULL;

    pRoot = pCurr = new ListNode(1);
    pCurr->next = new ListNode(2);
    pCurr = pCurr->next;
    pCurr->next = new ListNode(3);
    pCurr = pCurr->next;
    pCurr->next = new ListNode(4);
    pCurr = pCurr->next;

    Solution sol;
    ListNode* pOutput = sol.reverseKGroup(pRoot, 2);

    ListNode* pExpected = NULL;
    pExpected = pCurr = new ListNode(2);
    pCurr->next = new ListNode(1);
    pCurr = pCurr->next;
    pCurr->next = new ListNode(4);
    pCurr = pCurr->next;
    pCurr->next = new ListNode(3);
    pCurr = pCurr->next;


    ASSERT_TRUE(verifyLinkedList(pExpected, pOutput));
    deleteLinkedList(pExpected);
    deleteLinkedList(pRoot);
}


TEST(LeetCode, Fail01){
    ListNode* pRoot = NULL;
    ListNode* pCurr = NULL;

    pRoot = pCurr = new ListNode(1);
    pCurr->next = new ListNode(2);
    pCurr = pCurr->next;
    pCurr->next = new ListNode(3);
    pCurr = pCurr->next;

    Solution sol;
    ListNode* pOutput = sol.reverseKGroup(pRoot, 2);

    ListNode* pExpected = NULL;
    pExpected = pCurr = new ListNode(2);
    pCurr->next = new ListNode(1);
    pCurr = pCurr->next;
    pCurr->next = new ListNode(3);
    pCurr = pCurr->next;


    ASSERT_TRUE(verifyLinkedList(pExpected, pOutput));
    deleteLinkedList(pExpected);
    deleteLinkedList(pRoot);
}
