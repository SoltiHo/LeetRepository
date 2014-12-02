#include "gtest/gtest.h"  // access test macro
#include "Sort_List.h"

bool validateSortedList(ListNode* pRoot){
    if (pRoot == NULL){
        return false;
    }

    while (pRoot->next){
        if (pRoot->val > pRoot->next->val){
            return false;
        }
        pRoot = pRoot->next;
    }

    return true;
}

void deleteList(ListNode* pRoot){
    ListNode* pNext = NULL;
    while (pRoot){
        pNext = pRoot->next;
        delete pRoot;
        pRoot = pNext;
    }
}

TEST(Leet, Basic04){
    ListNode* pRoot = new ListNode(4);
    ListNode* pCurr = pRoot;
    pCurr->next = new ListNode(3);
    pCurr = pCurr->next;
    pCurr->next = new ListNode(2);
    pCurr = pCurr->next;
    pCurr->next = new ListNode(1);


    Solution sol;
    ListNode* pSorted = sol.sortList(pRoot);

    ASSERT_TRUE(validateSortedList(pSorted));
    deleteList(pSorted);
}


TEST(Leet, Basic03){
    ListNode* pRoot = new ListNode(1);
    ListNode* pCurr = pRoot;
    pCurr->next = new ListNode(2);
    pCurr = pCurr->next;
    pCurr->next = new ListNode(3);
    pCurr = pCurr->next;
    pCurr->next = new ListNode(4);


    Solution sol;
    ListNode* pSorted = sol.sortList(pRoot);

    ASSERT_TRUE(validateSortedList(pSorted));
    deleteList(pSorted);
}
TEST(Leet, Basic02){
    ListNode* pRoot = new ListNode(3);
    ListNode* pCurr = pRoot;
    pCurr->next = new ListNode(2);
    pCurr = pCurr->next;
    pCurr->next = new ListNode(4);

    Solution sol;
    ListNode* pSorted = sol.sortList(pRoot);

    ASSERT_TRUE(validateSortedList(pSorted));
    deleteList(pSorted);
}


TEST(Leet, Basic01){
    ListNode root(2);
    ListNode second(1);
    root.next = &second;
    Solution sol;
    ListNode* pSorted = sol.sortList(&root);

    ASSERT_TRUE(validateSortedList(pSorted));
}
