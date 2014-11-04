//  Two elements of a binary search tree(BST) are swapped by mistake.
//  
//  Recover the tree without changing its structure.
//  
//  Note:
//  A solution using O(n) space is pretty straight forward. 
//  Could you devise a constant space solution ?
//  confused what "{1,#,2,3}" means ? > read more on how binary tree is serialized on OJ.
//  
//  
//  OJ's Binary Tree Serialization:
//  The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.
//  
//  Here's an example:
//    1
//   / \
//  2   3
//     /
//    4
//     \
//      5
//  The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".

using namespace std;


// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


struct Boundary {
    int Min;
    int Max;
    TreeNode* pMin;
    TreeNode* pMax;
    Boundary() : Min(INT_MAX), Max(INT_MIN), pMin(NULL), pMax(NULL){}
    ~Boundary(){}
    Boundary(const Boundary& other) : Min(other.Min), Max(other.Max), pMin(other.pMin), pMax(other.pMax){}
    Boundary& operator=(const Boundary &rhs) {
        this->Max = rhs.Max;
        this->Min = rhs.Min;
        this->pMax = rhs.pMax;
        this->pMin = rhs.pMin;
        return *this;  // Return a reference to myself.
    }
};

struct incorrectLog{
    int depth;
    int numOfError; // 1 means only 1 substree has incorrect data, 2 means both left and right have incorrect data
    TreeNode* ToBeSwapped1;
    TreeNode* ToBeSwapped2;

    incorrectLog() : depth(INT_MAX), numOfError(0), ToBeSwapped1(NULL), ToBeSwapped2(NULL){}
    ~incorrectLog(){}
};

incorrectLog topError;

Boundary findBondariesAndErrors(TreeNode* root, const int depth){
    Boundary output;
    if (root == NULL){
        return output;
    }
    if ((root->left == NULL) && (root->right == NULL)){
        output.Max = root->val;
        output.Min = root->val;
        output.pMax = output.pMin = root;
        return output;
    }

    Boundary leftSubtreeBoundaries;
    Boundary rightSubtreeBoundaries;

    if (root->left){
        leftSubtreeBoundaries = findBondariesAndErrors(root->left, depth + 1);
    }

    if (root->right){
        rightSubtreeBoundaries = findBondariesAndErrors(root->right, depth + 1);
    }

    if ((leftSubtreeBoundaries.Max > root->val) && (rightSubtreeBoundaries.Min < root->val)){
        // sibling swap
        if (topError.depth > depth){
            topError.depth = depth;
            topError.numOfError = 2;
            topError.ToBeSwapped1 = leftSubtreeBoundaries.pMax;
            topError.ToBeSwapped2 = rightSubtreeBoundaries.pMin;
        }
    }
    else if (leftSubtreeBoundaries.Max > root->val){
        // left subtree incorrect
        if (topError.depth > depth){
            topError.depth = depth;
            topError.numOfError = 1;
            topError.ToBeSwapped1 = leftSubtreeBoundaries.pMax;
            topError.ToBeSwapped2 = root;
        }
    }
    else if (rightSubtreeBoundaries.Min < root->val){
        // right subtree incorrect
        if (topError.depth > depth){
            topError.depth = depth;
            topError.numOfError = 1;
            topError.ToBeSwapped1 = rightSubtreeBoundaries.pMin;
            topError.ToBeSwapped2 = root;
        }
    }

    // record the max
    if (leftSubtreeBoundaries.Max > rightSubtreeBoundaries.Max){
        if (root->val > leftSubtreeBoundaries.Max){
            output.Max = root->val;
            output.pMax = root;
        }
        else{
            output.Max = leftSubtreeBoundaries.Max;
            output.pMax = leftSubtreeBoundaries.pMax;
        }
    }
    else{
        if (root->val > rightSubtreeBoundaries.Max){
            output.Max = root->val;
            output.pMax = root;
        }
        else{
            output.Max = rightSubtreeBoundaries.Max;
            output.pMax = rightSubtreeBoundaries.pMax;
        }
    }

    // record the min
    if (leftSubtreeBoundaries.Min < rightSubtreeBoundaries.Min){
        if (root->val < leftSubtreeBoundaries.Min){
            output.Min = root->val;
            output.pMin = root;
        }
        else{
            output.Min = leftSubtreeBoundaries.Min;
            output.pMin = leftSubtreeBoundaries.pMin;
        }
    }
    else{
        if (root->val < rightSubtreeBoundaries.Min){
            output.Min = root->val;
            output.pMin = root;
        }
        else{
            output.Min = rightSubtreeBoundaries.Min;
            output.pMin = rightSubtreeBoundaries.pMin;
        }
    }

    return output;
}

class Solution {
public:
    void recoverTree(TreeNode *root) {
        // filter out basic cases
        if (root == NULL){
            // zero node
            return;
        }
        if ((root->left == NULL) && (root->right == NULL)){
            // single node
            return;
        }

        topError.depth = INT_MAX;
        topError.numOfError = 0;
        topError.ToBeSwapped1 = NULL;
        topError.ToBeSwapped2 = NULL;
        findBondariesAndErrors(root, 0);
        if (topError.depth != INT_MAX){
            swap(topError.ToBeSwapped1->val, topError.ToBeSwapped2->val);
        }

    }
};