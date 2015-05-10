// Remove all elements from a linked list of integers that have value val.
// 
// Example
// Given : 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
//     Return: 1 --> 2 --> 3 --> 4 --> 5
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* output = NULL;
        ListNode* curr = head;
        ListNode* lastNotEqual = NULL;
        ListNode* toBeDeleted = NULL;
        while (curr){
            if (curr->val == val){
                if (lastNotEqual){
                    lastNotEqual->next = curr->next;
                }
                toBeDeleted = curr;
            }
            else{
                if (!output){
                    output = curr;
                }
                lastNotEqual = curr;
            }
            curr = curr->next;
            if (toBeDeleted){
                delete toBeDeleted;
                toBeDeleted = NULL;
            }
        }
        return output;
    }
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* toBeDeleted = NULL;
        if (head == NULL){
            return NULL;
        }

        // find head first
        while ((head) && (head->val == val)){
            toBeDeleted = head;
            head = head->next;
            delete toBeDeleted;
            toBeDeleted = NULL;
        }

        if (head){
            ListNode* curr = head->next;
            ListNode* lastNotEqual = head;

            while (curr){
                if (curr->val == val){
                    lastNotEqual->next = curr->next;
                    toBeDeleted = curr;
                }
                else{
                    lastNotEqual = curr;
                }
                curr = curr->next;
                if (toBeDeleted){
                    delete toBeDeleted;
                    toBeDeleted = NULL;
                }
            }

        }
        return head;
    }
};