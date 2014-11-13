// Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
// 
// For example,
// S = "ADOBECODEBANC"
// T = "ABC"
// Minimum window is "BANC".
// 
// Note:
// If there is no such window in S that covers all characters in T, return the emtpy string "".
// 
// If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
        const unsigned int SSize = S.size();
        const unsigned int TSize = T.size();
        string EmptyOutput = "";
        if ((SSize == 0) || (TSize == 0) || (TSize > SSize)){
            return EmptyOutput;
        }
        else if ((SSize == 1) && (TSize == 1)){
            if (S[0] == T[0]){
                return S;
            }
            else{
                return EmptyOutput;
            }
        }

        //  compute the histogram
        this->histogram = new unsigned int[256]();  // assume only captial char
        for (unsigned int i = 0; i < TSize; ++i){
            this->histogram[T[i]]++;
        }

        // create container queues.
        this->containerArray = new vector<ListNode*>*[256]();
        for (unsigned int i = 0; i < 256; ++i){
            if (this->histogram[i] > 0){
                this->containerArray[i] = new vector<ListNode*>;
            }
        }

        // Scan through S
        ListNode* pNewListNode = NULL;
        unsigned int key = 0;
        int minWindowStartIdx = 0;
        int minWindowLength = INT_MAX;
        int currWindowLength = 0;
        for (unsigned int SIdx = 0; SIdx < SSize; ++SIdx){
            key = S[SIdx];
            if (this->histogram[key] > 0){
                // the char match
                pNewListNode = new ListNode(SIdx);
                this->containerArray[key]->push_back(pNewListNode);
                this->matchedCharCount++;

                // delete the oldest if necessary
                deleteTheOldestMatch(key);

                if (this->tail){
                    this->tail->next = pNewListNode;
                    pNewListNode->prev = this->tail;
                }
                this->tail = pNewListNode;

                if (this->head == NULL){
                    // single node scenario
                    this->head = this->tail;
                }

                if (this->matchedCharCount == TSize){
                    currWindowLength = SIdx - this->head->charIdx + 1;
                    if (minWindowLength > currWindowLength){
                        minWindowLength = currWindowLength;
                        minWindowStartIdx = this->head->charIdx;
                    }
                }
            }
        }

        for (int i = 0; i < 256; ++i){
            if (this->containerArray[i]){
                while (this->containerArray[i]->size() > 0){
                    delete this->containerArray[i]->at(0);
                    this->containerArray[i]->erase(this->containerArray[i]->begin());
                }
            }
            delete this->containerArray[i];
        }
        delete[] this->containerArray;
        delete[] this->histogram;

        if (minWindowLength == INT_MAX){
            // nothing matched
            return "";
        }
        else{
            return S.substr(minWindowStartIdx, minWindowLength);
        }
        
    }

    struct ListNode {
        int charIdx;
        ListNode* next;
        ListNode* prev;
        ListNode(int v) : charIdx(v), next(NULL), prev(NULL){};
    };

    unsigned int matchedCharCount;
    ListNode* head;
    ListNode* tail;
    ListNode* list;
    unsigned int* histogram;
    vector<ListNode*>** containerArray;

    Solution() : matchedCharCount(0), head(NULL), tail(NULL), list(NULL), histogram(NULL), containerArray(NULL){};

    void deleteTheOldestMatch(unsigned key){
        if (this->containerArray[key]->size() > this->histogram[key]){
            // need to delete the oldest node
            if ((this->containerArray[key])->at(0)->prev){
                (this->containerArray[key])->at(0)->prev->next = (this->containerArray[key])->at(0)->next;
            }
            if ((this->containerArray[key])->at(0)->next){
                (this->containerArray[key])->at(0)->next->prev = (this->containerArray[key])->at(0)->prev;
            }

            if (this->head == this->containerArray[key]->at(0)){
                // the to-be-delete is the head
                // if single node, then head pointer is pointing to NULL temporarily
                this->head = this->head->next;
            }

            if (this->tail == this->containerArray[key]->at(0)){
                // the to-be-delete is the tail
                // if single node, then tail pointer is pointing to NULL temporarily
                this->tail = this->tail->prev;
            }

            // delete the first node, which is the oldest
            delete this->containerArray[key]->at(0);
            this->containerArray[key]->erase(this->containerArray[key]->begin());
            this->matchedCharCount--;
        }
    }
};