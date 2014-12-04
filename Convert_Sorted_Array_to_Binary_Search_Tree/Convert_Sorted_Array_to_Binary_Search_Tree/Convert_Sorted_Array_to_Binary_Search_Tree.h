// Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

#include <vector>
using namespace std;

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if (num.size() == 0){
            return NULL;
        }

        return constructTree(num, 0, num.size() - 1);
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