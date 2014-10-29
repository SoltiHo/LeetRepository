// Merge k sorted linked lists and return it as one sorted list.Analyze and describe its complexity.

#include <vector>
#include <algorithm>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


struct Record {
    int val;
    unsigned int listIndex;
    inline bool operator< (const Record& rhs){
        return (this->val > rhs.val);
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode** candidates = new ListNode*[lists.size()];
        if (candidates == NULL){
            return NULL;
        }

        // init
        unsigned int numDepletedLists = 0;
        vector<Record> candidateHeap;
        make_heap(candidateHeap.begin(), candidateHeap.end());

        Record temp;
        for (int i = 0; i < lists.size(); ++i){
            candidates[i] = lists[i];
            if (candidates[i] == NULL){
                numDepletedLists++;
            }
            else{
                temp.val = candidates[i]->val;
                temp.listIndex = i;
                candidateHeap.push_back(temp);
                push_heap(candidateHeap.begin(), candidateHeap.end());
            }
        }

        // start consuming data
        vector<int> answerKeys;
        while (numDepletedLists < lists.size()){
            temp = candidateHeap[0];
            // consumed, so poped out
            pop_heap(candidateHeap.begin(), candidateHeap.end());
            candidateHeap.pop_back();

            // save the int for later linked list creation
            answerKeys.push_back(temp.val);

            // move the pointer
            candidates[temp.listIndex] = candidates[temp.listIndex]->next;
            if (candidates[temp.listIndex]){
                temp.val = candidates[temp.listIndex]->val;
                // temp.listIndex remain unchanged
                candidateHeap.push_back(temp);
                push_heap(candidateHeap.begin(), candidateHeap.end());
            }
            else{
                // otherwise, another list is done
                numDepletedLists++;
            }
        }
        delete[] candidates;

        // create the output linked list
        ListNode* pNewNode = NULL;
        ListNode* pOutputList = NULL;
        for (unsigned int i = 0; i < answerKeys.size(); ++i){
            if (i == 0){
                pNewNode = new ListNode(answerKeys[i]);
                pOutputList = pNewNode;
            }
            else{
                pNewNode->next = new ListNode(answerKeys[i]);
                pNewNode = pNewNode->next;
            }
        }

        return pOutputList;
    }
};