//  Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
//  
//  For example,
//  Given[100, 4, 200, 1, 3, 2],
//  The longest consecutive elements sequence is[1, 2, 3, 4].Return its length : 4.
//  
//  Your algorithm should run in O(n) complexity.

// algorithm learn from LeetCode Forum.  
//    doubt: why consider hash table accessing as constant time?  conflict?
//    doubt: why not caring about table size?  just leave it to hash table to handle
// probably we can have the two assumptions above when using Hash table

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

unsigned int HashTableSize = 0xFFFF;


unsigned int HashInt(int value)
{
    // Thomas Wang's Hashing function for integers
    unsigned int Value = value;
    Value = ~Value + (Value << 15);
    Value = Value ^ (Value >> 12);
    Value = Value + (Value << 2);
    Value = Value ^ (Value >> 4);
    Value = Value * 2057;
    Value = Value ^ (Value >> 16);
    return (Value & HashTableSize);
}

struct record {
    int key;
    int value;
    record* next;

    record() : key(0), value(0), next(NULL){}
    record(int k, int v) : key(k), value(v), next(NULL){}
};

record* hashTable = NULL;

void insert(int key, int value){
    unsigned int idx = HashInt(key);

    if (hashTable[idx].value != 0xFFFFFFFF){
        // check if matched or not
        if (hashTable[idx].key == key){
            hashTable[idx].value = value;
            return;
        }
        // conflict
        record* temp = hashTable + idx;

        while (temp->next){
            if (temp->next->key == key){
                temp->next->value = value;
                return;
            }
            else{
                temp = temp->next;
            }
        }
        temp->next = new record(key, value);
    }
    else{
        // first
        hashTable[idx].key = key;
        hashTable[idx].value = value;
        hashTable[idx].next = NULL;
    }
}

record* lookup(int key){
    unsigned int idx = HashInt(key);
    if (hashTable[idx].value != 0xFFFFFFFF){
        // check if the key exist
        record* temp = hashTable + idx;
        while (temp){
            if (temp->key == key){
                // found
                return temp;
            }
            else{
                temp = temp->next;
            }
        }
    }

    // not exist
    return NULL;
}

void deleteHashTableLinkedList(){
    record* pEntry = NULL;
    record* pToBeDeleted = NULL;
    for (unsigned int i = 0; i < HashTableSize; ++i){
        if (hashTable[i].value != 0xFFFFFFFF){
            // filled entry, need to free its linked list
            pEntry = hashTable[i].next;
            while (pEntry){
                pToBeDeleted = pEntry;
                pEntry = pEntry->next;
                delete pToBeDeleted;
            }
        }
    }
}
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, int> map;
        unordered_map<int, int>::iterator it;

        const int size = num.size();
        int lowerBound = 0;
        int upperBound = 0;
        int longest = 0;
        for (int i = 0; i < size; ++i) {
            lowerBound = upperBound = num[i];

            it = map.find(num[i]);
            if (it != map.end()){
                continue;
            }

            it = map.find(num[i] - 1);
            if (it != map.end()){
                lowerBound = it->second;
            }

            it = map.find(num[i] + 1);
            if (it != map.end()){
                upperBound = it->second;
            }

            longest = max(longest, (upperBound - lowerBound + 1));

            
            map[num[i]] = num[i];
            map[lowerBound] = upperBound;
            map[upperBound] = lowerBound;
        }

        return longest;
    }


    int longestConsecutive_myHashTable(vector<int> &num) {
        hashTable = new record[HashTableSize];
        memset(hashTable, 0xFF, sizeof(record)*HashTableSize);

        const int size = num.size();
        int lowerBound = 0;
        int upperBound = 0;
        int longest = 0;

        record* pRecord = NULL;
        for (int i = 0; i < size; ++i) {
            lowerBound = upperBound = num[i];

            pRecord = lookup(num[i] - 1);
            if (pRecord){
                lowerBound = pRecord->value;
            }

            pRecord = lookup(num[i] + 1);
            if (pRecord){
                upperBound = pRecord->value;
            }

            longest = max(longest, (upperBound - lowerBound + 1));

            insert(num[i], num[i]);

            insert(lowerBound, upperBound);

            insert(upperBound, lowerBound);
        }

        deleteHashTableLinkedList();
        delete[] hashTable;
        return longest;
    }
};