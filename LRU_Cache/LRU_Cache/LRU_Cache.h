//  Design and implement a data structure for Least Recently Used(LRU) cache.
//  It should support the following operations : get and set.
//  
//  get(key) - Get the value(will always be positive) of the key if the key exists 
//  in the cache, otherwise return -1.
//  set(key, value) - Set or insert the value if the key is not already present.
//  When the cache reached its capacity, it should invalidate the least recently 
//  used item before inserting a new item.

#include <unordered_map>
using namespace std;

class LRUCache{
public:
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v) : key(k), value(v), prev(NULL), next(NULL) {}
    };

    LRUCache(int capacity) : existingCount(0), maxCount(capacity), tail(NULL), head(NULL), it(hashTable.begin()){};

    int get(int key) {
        this->it = this->hashTable.find(key);
        if (this->it == this->hashTable.end()){
            // not found
            return -1;
        }
        else{
            // found
            // update the item to be the head.
            pullTheNodeToTheFront(it->second);

            // return the value
            return it->second->value;
        }
    }

    void set(int key, int value) {
        this->it = this->hashTable.find(key);
        if (this->it == this->hashTable.end()){
            // not found
            // create the new node
            Node* pNewNode;
            pNewNode = new Node(key, value);
            this->existingCount++;

            if (this->head){
                this->head->prev = pNewNode;
                pNewNode->next = this->head;
                this->head = pNewNode;

                // check if the length exceed the max
                if (this->existingCount > this->maxCount){
                    // need to delete the tail
                    // delete the hash table entry for the tail first
                    this->hashTable.erase(this->tail->key);

                    // then delete the tail from the linked list
                    this->tail = this->tail->prev;
                    delete this->tail->next;
                    this->tail->next = NULL;
                    this->existingCount--;
                }
            }
            else{
                // first node ever
                this->tail = this->head = pNewNode;
                this->head->next = this->tail;
                this->tail->prev = this->head;
            }

            // update the hash table
            this->hashTable.insert({ key, pNewNode });
        }
        else{
            // found, just need to update the value and pull the node to the front
            it->second->value = value;
            pullTheNodeToTheFront(it->second);
        }

    }

    void pullTheNodeToTheFront(Node* pNode){
        if (pNode != this->head){
            // update the previous node
            // since this node is not head, there is always a prev node
            pNode->prev->next = pNode->next;

            // update tail pointer
            if (pNode == this->tail){
                // tail is dragged to the front, need to find a new tail
                this->tail = pNode->prev;
            }
            else{
                // not the tail, then need to update the next node
                // since it's not the tail, it always has a next node
                pNode->next->prev = pNode->prev;
            }

            // update head pointer
            pNode->next = this->head;
            pNode->prev = NULL;
            this->head->prev = pNode;
            this->head = pNode;
        }
    }
    int existingCount;
    int maxCount;
    Node* tail;
    Node* head;
    unordered_map<int, Node*> hashTable;
    unordered_map<int, Node*>::iterator it;
};