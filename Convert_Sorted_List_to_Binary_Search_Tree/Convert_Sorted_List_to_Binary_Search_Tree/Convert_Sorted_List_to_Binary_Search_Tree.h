// Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        int totalNodeCount = 0;
        ListNode* pCurr = head;
        while (pCurr){
            totalNodeCount++;
            pCurr = pCurr->next;
        }

        if (totalNodeCount == 0){
            return NULL;
        }

        return constructTree(&head, 1, totalNodeCount);

    }

    TreeNode* constructTree(ListNode** ppListHead, int startIdx, int endIdx){
        if (startIdx > endIdx){
            return NULL;
        }

        const int currIdx = startIdx + ((endIdx - startIdx) >> 1);
        TreeNode* pLeftSubtree = constructTree(ppListHead,startIdx, currIdx - 1);
        TreeNode* pCurrNode = new TreeNode((*ppListHead)->val);
        (*ppListHead) = (*ppListHead)->next;
        TreeNode* pRightSubtree = constructTree(ppListHead, currIdx + 1, endIdx);
        
        pCurrNode->left = pLeftSubtree;
        pCurrNode->right = pRightSubtree;
        
        return pCurrNode;
    }
};

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        vector<int> numbers;
        while (head){
            numbers.push_back(head->val);
            head = head->next;
        }

        TreeNode* pRoot = NULL;
        const int numCount = numbers.size();
        if (numCount == 0){
            return NULL;
        }

        return constructTree(numbers, 0, numbers.size() - 1);

    }

    TreeNode* constructTree(vector<int>& numbers, int startIdx, int endIdx){
        const int size = endIdx - startIdx + 1;
        if (size == 1){
            // no subtree
            return new TreeNode(numbers[startIdx]);
        }

        const int rootIdx = startIdx + (size >> 1);
        const int leftSubtreeStart = rootIdx == startIdx ? -1 : startIdx;
        const int leftSubtreeEnd = rootIdx == startIdx ? -1 : rootIdx - 1;
        const int rightSubtreeStart = rootIdx == endIdx ? -1 : rootIdx + 1;
        const int rightSubtreeEnd = rootIdx == endIdx ? -1 : endIdx;

        TreeNode* pRoot = new TreeNode(numbers[rootIdx]);
        TreeNode* pLeftSubtree = NULL;
        TreeNode* pRightSubtree = NULL;
        if (leftSubtreeStart != -1){
            pLeftSubtree = constructTree(numbers, leftSubtreeStart, leftSubtreeEnd);
        }

        if (rightSubtreeStart != -1){
            pRightSubtree = constructTree(numbers, rightSubtreeStart, rightSubtreeEnd);
        }

        pRoot->left = pLeftSubtree;
        pRoot->right = pRightSubtree;

        return pRoot;
    }
};