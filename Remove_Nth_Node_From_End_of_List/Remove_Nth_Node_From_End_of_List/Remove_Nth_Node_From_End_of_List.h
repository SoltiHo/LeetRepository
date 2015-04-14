// Given a linked list, remove the nth node from the end of list and return its head.
// 
// For example,
// 
// Given linked list : 1->2->3->4->5, and n = 2.
// 
// After removing the second node from the end, the linked list becomes 1->2->3->5.
// Note :
//      Given n will always be valid.
//      Try to do this in one pass.

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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        vector<ListNode*> buffer;  // need to maintain at size n + 1, pushback, popfront
        ListNode* pOutput = head;
        while (head){
            buffer.push_back(head);
            if (buffer.size() == n + 2){
                buffer.erase(buffer.begin());
            }
            head = head->next;
        }

        
        if (buffer.size() == n + 1){
            buffer[0]->next = buffer[1]->next;
            delete buffer[1];
        }
        else if (buffer.size() == n){
            pOutput = pOutput->next;
            delete buffer[0];
        }
    
        return pOutput;
    }
};