//  Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.
//  
//  For example,
//  Given n = 3, your program should return all 5 unique BST's shown below.
//  
//  1         3     3      2      1
//   \       /     /      / \      \
//    3     2     1      1   3      2
//   /     /       \                 \
//  2     1         2                 3

#include <vector>
#include <queue>
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
    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode*> output;
        if (n == 0){
            output.push_back(NULL);
        }
        else{
            output = buildPossibleSubtrees(1, n);
        }
        return output;
    }

    vector<TreeNode*> buildPossibleSubtrees(int lowerBound, int upperBound){
        // pick a root
        vector<TreeNode*> output;
        if (lowerBound <= upperBound){
            for (int rootNumber = lowerBound; rootNumber <= upperBound; ++rootNumber){
                vector<TreeNode*> leftSubtrees = buildPossibleSubtrees(lowerBound, rootNumber - 1);
                vector<TreeNode*> rightSubtrees = buildPossibleSubtrees(rootNumber + 1, upperBound);
                for (int leftSubtreeIdx = 0; leftSubtreeIdx < leftSubtrees.size(); ++leftSubtreeIdx){
                    for (int rightSubtreeIdx = 0; rightSubtreeIdx < rightSubtrees.size(); ++rightSubtreeIdx){
                        TreeNode* pNewSubtrees = new TreeNode(rootNumber);
                        pNewSubtrees->left = leftSubtrees[leftSubtreeIdx];
                        pNewSubtrees->right = rightSubtrees[rightSubtreeIdx];
                        output.push_back(pNewSubtrees);
                    }
                }   
            }
        }
        else{
            output.push_back(NULL);
        }
        return output;
    }
};


class Solution_DP {
public:
    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode*> output;
        vector<TreeNode*> outputBuffer;
        if (n == 0){
            output.push_back(NULL);
        }
        else{
            TreeNode* pRoot = new TreeNode(1); // seed
            output.push_back(pRoot);
            TreeNode* pNewSolutionRoot = NULL;
            TreeNode* pNewNode = NULL;
            TreeNode* pCurr = NULL;
            TreeNode* pCopy = NULL;
            TreeNode* pInsertPoint = NULL;

            for (int i = 2; i <= n; ++i){
                for (auto t : output){
                    pNewNode = new TreeNode(i);
                    // new node to be its parent
                    pNewSolutionRoot = pNewNode;
                    pNewSolutionRoot->left = deepCopy(t);
                    outputBuffer.push_back(pNewSolutionRoot);

                    // then start trying to be a child
                    pCurr = t;
                    int level = 0;
                    while (pCurr){
                        pCopy = deepCopy(t);
                        pNewNode = new TreeNode(i);

                        pInsertPoint = pCopy;
                        for (int l = 0; l < level; ++l){
                            pInsertPoint = pInsertPoint->right;
                        }

                        pNewNode->left = pInsertPoint->right;
                        level++;

                        pInsertPoint->right = pNewNode;
                        outputBuffer.push_back(pCopy);

                        pCurr = pCurr->right;
                    }
                }

                for (auto t : output){
                    deleteTree(t);
                }
                output.clear();
                output = outputBuffer;
                outputBuffer.clear();
            }
        }

        return output;
    }



    void deleteTree(TreeNode *pRoot){
        if (pRoot){
            queue<TreeNode*> toBeDeleted;
            TreeNode* pCurr = NULL;
            toBeDeleted.push(pRoot);
            while (toBeDeleted.size() > 0){
                pCurr = toBeDeleted.front();
                toBeDeleted.pop();
                if (pCurr->left){
                    toBeDeleted.push(pCurr->left);
                }
                if (pCurr->right){
                    toBeDeleted.push(pCurr->right);
                }
                delete pCurr;
            }
        }
    }

    TreeNode* deepCopy(TreeNode* pRoot){
        TreeNode* pOutput = NULL;
        TreeNode* pCurr = NULL;
        TreeNode* pOutputCurr = NULL;
        queue<TreeNode*> treeNodes;
        queue<TreeNode*> treeNodeCopy;
        if (pRoot){
            treeNodes.push(pRoot);
            pOutput = new TreeNode(pRoot->val);
            treeNodeCopy.push(pOutput);
            while (treeNodes.size() > 0){
                pCurr = treeNodes.front();
                treeNodes.pop();
                pOutputCurr = treeNodeCopy.front();
                treeNodeCopy.pop();

                if (pCurr->left){
                    pOutputCurr->left = new TreeNode(pCurr->left->val);
                    treeNodes.push(pCurr->left);
                    treeNodeCopy.push(pOutputCurr->left);
                }
                if (pCurr->right){
                    pOutputCurr->right = new TreeNode(pCurr->right->val);
                    treeNodes.push(pCurr->right);
                    treeNodeCopy.push(pOutputCurr->right);
                }
            }
        }
        return pOutput;
    }
};

class Solution_Permutation {
public:
    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode*> output;
        if (n == 0){
            output.push_back(NULL);
        }
        else{
            output = constructTree(1, n);
        }
        return output;

    }

    vector<TreeNode*> constructTree(const int startNum, const int endNum){
        TreeNode* pRoot = NULL;
        vector<TreeNode*> possibleLeftSubtrees;
        vector<TreeNode*> possibleRightSubtrees;
        vector<TreeNode*> possibleOutputs;
        for (int i = startNum; i <= endNum; ++i){
            if (i > startNum){
                // there is left subtree
                possibleLeftSubtrees = constructTree(startNum, i - 1);
            }
            if (i < endNum){
                // there is right subtree
                possibleRightSubtrees = constructTree(i + 1, endNum);
            }

            const int leftSubtreeCount = possibleLeftSubtrees.size();
            const int rightSubtreeCount = possibleRightSubtrees.size();
            if ((leftSubtreeCount > 0) && (rightSubtreeCount > 0)){
                for (int l = 0; l < leftSubtreeCount; ++l){
                    for (int r = 0; r < rightSubtreeCount; ++r){
                        pRoot = new TreeNode(i);
                        pRoot->left = possibleLeftSubtrees[l];
                        pRoot->right = possibleRightSubtrees[r];
                        possibleOutputs.push_back(pRoot);
                    }
                }
            }
            else if (leftSubtreeCount > 0){
                // left subtree only
                for (int l = 0; l < leftSubtreeCount; ++l){
                    pRoot = new TreeNode(i);
                    pRoot->left = possibleLeftSubtrees[l];
                    possibleOutputs.push_back(pRoot);
                }

            }
            else if (rightSubtreeCount > 0){
                // right subtree only
                for (int r = 0; r < rightSubtreeCount; ++r){
                    pRoot = new TreeNode(i);
                    pRoot->right = possibleRightSubtrees[r];
                    possibleOutputs.push_back(pRoot);
                }
            }
            else{
                // no subtrees
                pRoot = new TreeNode(i);
                possibleOutputs.push_back(pRoot);
            }
            possibleLeftSubtrees.clear();
            possibleRightSubtrees.clear();
        }

        return possibleOutputs;
    }
};