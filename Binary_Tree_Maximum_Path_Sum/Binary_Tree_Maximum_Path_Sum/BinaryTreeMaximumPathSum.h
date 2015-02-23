// Given a binary tree, find the maximum path sum.
// 
// The path may start and end at any node in the tree.

#include <algorithm>
#include <iostream>
using namespace std;

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};







class Solution_latestTrial {
public:
    int maxPathSum(TreeNode *root) {
        int output = 0;
        if (root){
            output = INT_MIN;
            bestSum(root, output);
        }
        return output;
    }

    int bestSum(TreeNode* root, int& maxSum){
        int leftBestSum = INT_MIN;
        int rightBestSum = INT_MIN;
        if (root->left){
            leftBestSum = bestSum(root->left, maxSum);
        }
        if (root->right){
            rightBestSum = bestSum(root->right, maxSum);
        }

        // present a maxSum candidate
        int bestSum = root->val;
        if (rightBestSum > 0){
            bestSum += rightBestSum;
        }
        if (leftBestSum > 0){
            bestSum += leftBestSum;
        }
        maxSum = max(maxSum, bestSum);

        // return the best one direction sum including current node
        bestSum = root->val;
        int largerChildSum = max(leftBestSum, rightBestSum);
        if  (largerChildSum> 0){
            bestSum += largerChildSum;
        }

        return bestSum;
    }
};












int maxPathValue = INT_MIN;

int reportMaxPathToParent(TreeNode* child){
    int leftValue = INT_MIN;
    int rightValue = INT_MIN;
    if (child->left){
        leftValue = reportMaxPathToParent(child->left);
    }

    if (child->right){
        rightValue = reportMaxPathToParent(child->right);
    }

    if ((child->left) && (child->right)){
        // the "child" can be a turnning point only when it has two children
        int theValueIfThisNodeIsTurnningPoint = child->val + leftValue + rightValue;
        if (theValueIfThisNodeIsTurnningPoint > maxPathValue){
            maxPathValue = theValueIfThisNodeIsTurnningPoint;
        }
    }

    int theValueIfThePathEndsHere = child->val + max(0, max(leftValue, rightValue));
        
    if (theValueIfThePathEndsHere > maxPathValue){
        maxPathValue = theValueIfThePathEndsHere;
    }
    return theValueIfThePathEndsHere;
}

class Solution {
public:
    int maxPathSum(TreeNode *root) {
        maxPathValue = INT_MIN;

        if (root == NULL){
            return 0;
        }
        reportMaxPathToParent(root);

        return maxPathValue;
    }
};