//Write a program to find the node at which the intersection of two singly linked lists begins.
//
//
//For example, the following two linked lists :
//
//A :       a1 -> a2
//                  \
//                   c1 -> c2 -> c3
//                  /
//B : b1 -> b2 -> b3
//    begin to intersect at node c1.
//
//
//Notes :
//
//      If the two linked lists have no intersection at all, return null.
//      The linked lists must retain their original structure after the function returns.
//      You may assume there are no cycles anywhere in the entire linked structure.
//      Your code should preferably run in O(n) time and use only O(1) memory.

#include <vector>
#include <unordered_set>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // count the length
        ListNode* pOutput = NULL;
        if ((headA) && (headB)){
            if (headA != headB){
                ListNode* cursor = NULL;
                unsigned int lengthA = 0;
                cursor = headA;
                while (cursor){
                    lengthA++;
                    cursor = cursor->next;
                }

                unsigned int lengthB = 0;
                cursor = headB;
                while (cursor){
                    lengthB++;
                    cursor = cursor->next;
                }

                if (lengthA > lengthB){
                    while (lengthA != lengthB){
                        headA = headA->next;
                        lengthA--;
                    }
                }
                else if (lengthB > lengthA){
                    while (lengthA != lengthB){
                        headB = headB->next;
                        lengthB--;
                    }
                }

                while (headA) {
                    if (headA == headB){
                        pOutput = headA;
                        break;
                    }
                    headA = headA->next;
                    headB = headB->next;
                }
            }
            else{
                pOutput = headA;
            }
        }
        return pOutput;
    }
};

class Solution_HashTable {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pOutput = NULL;
        if ((headA) && (headB)){
            if (headA != headB){
                unordered_set<ListNode*> map;
                while (headA && headB){
                    // handle A first
                    if (map.count(headA->next) == 0){
                        // not found
                        map.insert(headA->next);
                        headA = headA->next;
                    }
                    else{
                        pOutput = headA->next;
                        break;
                    }
                    
                    // handle B 
                    if (map.count(headB->next) == 0){
                        // not found
                        map.insert(headB->next);
                        headB = headB->next;
                    }
                    else{
                        pOutput = headB->next;
                        break;
                    }
                }

                if (!pOutput){
                    if (headA){
                        // remaining on A
                        while (headA){
                            if (map.count(headA->next) != 0){
                                pOutput = headA->next;
                            }
                            headA = headA->next;
                        }
                    }
                    else{
                        // remaining on B
                        while (headB){
                            if (map.count(headB->next) != 0){
                                pOutput = headB->next;
                            }
                            headB = headB->next;
                        }
                    }
                }
            }
            else{
                pOutput = headA;
            }
            
        }
        return pOutput;
    }
};