#include "gtest/gtest.h"  // access test macro
#include "MergeKSortedLists.h"

bool compareTwoList(ListNode* list1, ListNode* list2){
    while (list1 && list2){
        if (list1->val != list2->val){
            return false;
        }
        list1 = list1->next;
        list2 = list2->next;
    }

    if ((list1 == NULL) && (list2 == NULL)){
        return true;
    }
    else{
        return false;
    }
}

TEST(SingleList, SingleNode){
    vector<ListNode *> lists;
    ListNode* root = new ListNode(3);
    lists.push_back(root);

    Solution sol;
    ListNode* answer;
    answer = sol.mergeKLists(lists);

    ListNode* expected = new ListNode(3);
    ASSERT_TRUE(compareTwoList(answer, expected));

}

TEST(SingleList, MultipleNodes){
    vector<ListNode *> lists;
    ListNode* root = new ListNode(0);
    ListNode* pCurrentNode = root;
    for (unsigned int i = 0; i < 10; ++i){
        pCurrentNode->next = new ListNode(i + 1);
        pCurrentNode = pCurrentNode->next;
    }
    lists.push_back(root);


    Solution sol;
    ListNode* answer;
    answer = sol.mergeKLists(lists);

    ListNode* expected = new ListNode(0);
    pCurrentNode = expected;
    for (unsigned int i = 0; i < 10; ++i){
        pCurrentNode->next = new ListNode(i + 1);
        pCurrentNode = pCurrentNode->next;
    }
    ASSERT_TRUE(compareTwoList(answer, expected));

}


TEST(MultipleLists, SingleNode){
    vector<ListNode *> lists;
    ListNode* root = new ListNode(3);
    lists.push_back(root);

    root = new ListNode(1);
    lists.push_back(root);

    Solution sol;
    ListNode* answer;
    answer = sol.mergeKLists(lists);

    ListNode* expected = new ListNode(1);
    expected->next = new ListNode(3);
    ASSERT_TRUE(compareTwoList(answer, expected));

}

TEST(MultipleLists, MultipleNodes){
    vector<ListNode *> lists;
    ListNode* root = new ListNode(0);
    ListNode* pCurrentNode = root;
    for (unsigned int i = 1; i < 10; ++i){
        pCurrentNode->next = new ListNode(i << 1);
        pCurrentNode = pCurrentNode->next;
    }
    lists.push_back(root);

    root = new ListNode(1);
    pCurrentNode = root;
    for (unsigned int i = 1; i < 10; ++i){
        pCurrentNode->next = new ListNode((i << 1) + 1);
        pCurrentNode = pCurrentNode->next;
    }
    lists.push_back(root);


    Solution sol;
    ListNode* answer;
    answer = sol.mergeKLists(lists);

    ListNode* expected = new ListNode(0);
    pCurrentNode = expected;
    for (unsigned int i = 0; i < 19; ++i){
        pCurrentNode->next = new ListNode(i + 1);
        pCurrentNode = pCurrentNode->next;
    }
    ASSERT_TRUE(compareTwoList(answer, expected));

}