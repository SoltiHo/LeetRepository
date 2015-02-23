// A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
// 
// Return a deep copy of the list.
#include <stdio.h>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// Definition for singly-linked list with a random pointer.
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution_LatestTrial_Fast {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode* output = NULL;
        if (head){
            // clone the nodes and insert in between the old nodes
            RandomListNode* currNode = head;
            RandomListNode* temp = NULL;
            while (currNode){
                temp = currNode->next;
                currNode->next = new RandomListNode(currNode->label);
                currNode->next->next = temp;
                currNode = temp;
            }

            // set the random pointer
            currNode = head;
            while (currNode){
                if (currNode->random){
                    currNode->next->random = currNode->random->next;
                }
                currNode = currNode->next->next;
            }

            currNode = head;
            temp = output = head->next;
            RandomListNode* nextOldNode = NULL;
            while (currNode->next->next){
                nextOldNode = currNode->next->next;
                temp->next = currNode->next->next->next;
                currNode->next = nextOldNode;
                currNode = nextOldNode;
                temp = currNode->next;
            }
            currNode->next = NULL;
        }
        
        return output;
    }
};

class Solution_LatestTrial_Naive {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode* output = NULL;
        if (head){
            unordered_map<RandomListNode*, RandomListNode*> map;
            // copy the root
            output = new RandomListNode(head->label);
            map[head] = output;

            // copy the rest of the list
            RandomListNode* currNode = head;
            RandomListNode* newListTail = output;
            while (currNode->next){
                newListTail->next = new RandomListNode(currNode->next->label);
                currNode = currNode->next;
                newListTail = newListTail->next;
                map[currNode] = newListTail;
            }

            // set the random pointers
            currNode = head;
            newListTail = output;
            while (currNode){
                if (currNode->random){
                    newListTail->random = map[currNode->random];
                }
                currNode = currNode->next;
                newListTail = newListTail->next;
            }

        }

        return output;
    }
};


unsigned int HashTableSize = 65536;

unsigned int HashPointer(void* Ptr)
{
    // Thomas Wang's Hashing function for integers
    unsigned int Value = (unsigned int)Ptr;
    Value = ~Value + (Value << 15);
    Value = Value ^ (Value >> 12);
    Value = Value + (Value << 2);
    Value = Value ^ (Value >> 4);
    Value = Value * 2057;
    Value = Value ^ (Value >> 16);
    return (Value & 0xFF);
}


struct Record {
    RandomListNode* nodeAddress;
    unsigned int indexInList;  // 1 based.  0 is preserved for emply slots
    Record* next;  // to handle hashing conflict
};

void insertRecord(Record* hashTable, const unsigned int index, Record& newRecord){
    if (hashTable[index].indexInList == 0){
        // empty slot
        hashTable[index].indexInList = newRecord.indexInList;
        hashTable[index].nodeAddress = newRecord.nodeAddress;
    }
    else{
        // already occupied
        Record* temp = hashTable + index;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new Record;
        temp->next->indexInList = newRecord.indexInList;
        temp->next->nodeAddress = newRecord.nodeAddress;
        temp->next->next = NULL;
    }
}

unsigned int lookUp(Record* hashTable, RandomListNode* pNode){
    unsigned int key = HashPointer(pNode);

    if (hashTable[key].indexInList == 0){
        // empty slot, something wrong.
        return 0;
    }
    else if (hashTable[key].nodeAddress == pNode){
        return hashTable[key].indexInList;
    }
    else{
        // should be in the later node in the linked list
        Record* temp = hashTable[key].next;
        while (temp){
            if (temp->nodeAddress == pNode){
                return temp->indexInList;
            }
            temp = temp->next;
        }
        // can't find, somethign wrong
        return 0;
    }
}

void deleteHashTableLinkedList(Record* hashTable){
    Record* temp;
    Record* toBeDeleted;
    for (unsigned int i = 0; i < HashTableSize; ++i){
        toBeDeleted = hashTable[i].next;
        while (toBeDeleted){
            temp = toBeDeleted->next;
            delete toBeDeleted;
            toBeDeleted = temp;
        }
    }
}
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL){
            return NULL;
        }

        // first scan to build the node hash table and deep copy without setting random pointers
        Record* hashTable = new Record[HashTableSize];
        memset(hashTable, 0, sizeof(Record)* HashTableSize);
        
        Record tempRecord = {NULL, 0, NULL};
        unsigned int indexInList = 0;
        unsigned int key = 0;

        vector<RandomListNode*> newListNodes;
        RandomListNode* currentNode = head;
        RandomListNode* newNode = NULL;
        RandomListNode* lastNewNode = NULL;
        while (currentNode){
            // clone current node
            newNode = new RandomListNode(currentNode->label);

            // add new node's address to the vector
            newListNodes.push_back(newNode);

            // point the last new node to the current 
            if (lastNewNode){
                lastNewNode->next = newNode;
            }

            // fill the hash table
            indexInList++;
            key = HashPointer(currentNode);
            tempRecord.indexInList = indexInList;
            tempRecord.nodeAddress = currentNode;
            insertRecord(hashTable, key, tempRecord);

            // prepare for the next iteration
            lastNewNode = newNode;
            currentNode = currentNode->next;
        }

        // second second to set the random pointers
        currentNode = head;
        indexInList = 0;
        while (currentNode){
            if (currentNode->random){
                // this key is the index in the original list
                key = lookUp(hashTable, currentNode->random);
                newListNodes[indexInList]->random = newListNodes[key - 1];
            }
            indexInList++;
            currentNode = currentNode->next;
        }

        deleteHashTableLinkedList(hashTable);
        delete[] hashTable;

        return newListNodes[0];
    }
};