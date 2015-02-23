// Implement an iterator over a binary search tree(BST).Your iterator will be initialized with the root node of a BST.
// 
// Calling next() will return the next smallest number in the BST.
// 
// Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.


#include <stack>
using namespace std;

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// NULL root -> next() return 0, hasNext() returns false
// 1 node tree -> next() return the node and pNext to NULL, hasNext() returns false
// all the way right tree ->

class BSTIterator {
private:
    struct NodeRecord {
        TreeNode* pNode;
        bool visited;
    };

    TreeNode* pNext;  // pointing to the next node to return, it should not exist in parents
    stack<NodeRecord> parents; // the parent(s) of pNext

public:
    BSTIterator(TreeNode *root) : pNext(root) {
        if (pNext){
            findTheSmallestOfTheSubtree();
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (pNext != NULL);
    }

    /** @return the next smallest number */
    int next() {
        int output = 0;
        if (this->pNext){
            // consume this node
            output = this->pNext->val;

            // move pNext to the next node
            if (this->pNext->right){
                // find the smallest of the right subtree
                NodeRecord temp;
                temp.pNode = this->pNext;
                temp.visited = true;
                this->parents.push(temp);
                this->pNext = this->pNext->right;
                findTheSmallestOfTheSubtree();
            }
            else{
                // go up
                while ((this->parents.size() > 0) && (this->parents.top().visited)){
                    this->parents.pop();
                }
                if (this->parents.size() > 0){
                    this->pNext = this->parents.top().pNode;
                    this->parents.pop();  
                }
                else{
                    // no more node
                    this->pNext = NULL;
                }
            }
        }
        return output;
    }

    void findTheSmallestOfTheSubtree(){
        NodeRecord temp;
        while (this->pNext->left){
            temp.pNode = this->pNext;
            temp.visited = false;
            this->parents.push(temp);
            this->pNext = this->pNext->left;
        }
    }

};

/**
* Your BSTIterator will be called like this:
* BSTIterator i = BSTIterator(root);
* while (i.hasNext()) cout << i.next();
*/