// Definition for singly-linked list.
#include <vector>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct nodeData {
    ListNode ** pNextPointer;
    ListNode * pNode;
};
class Solution {
public:
    void reorderList(ListNode *head) {
        if (head == NULL){
            return;
        }
        std::vector<nodeData> nodes;
        nodeData temp = { 0 };
        
        ListNode* currNode = head;
        while (currNode){
            temp.pNextPointer = &(currNode->next);
            temp.pNode = currNode;
            nodes.push_back(temp);
            currNode = currNode->next;
        }

        int nodeCount = nodes.size();
        // if 6 nodes, need to do (0, 5), (1, 4), (2, 3)
        // if 5 nodes, need to do (0, 4), (1, 3)
        // 6 >> 1 = 3,  5 >> 1 = 2

        for (int i = 0; i < (nodeCount >> 1); ++i){
            (*(nodes[i].pNextPointer)) = nodes[nodeCount - 1 - i].pNode;
            (*(nodes[nodeCount - 1 - i].pNextPointer)) = nodes[i + 1].pNode;
        }

        // solve the self looping or infinite looping
        (*nodes[nodeCount >> 1].pNextPointer) = NULL;
    }
};