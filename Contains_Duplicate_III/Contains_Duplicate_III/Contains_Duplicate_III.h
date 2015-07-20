// Given an array of integers, find out whether there are two distinct indices i and j in the array 
// such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.
#include <vector>
#include <set>
#include <memory>
#include <set>
#include <queue>
using namespace std;



class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        const int numsCount = nums.size();
        if ((numsCount > 1) && (k > 0)){
            multiset<int> map;
            queue<int> numbersInRange;

            for (int i = 0; i < numsCount && i <= k; ++i){
                numbersInRange.push(nums[i]);
                map.insert(nums[i]);
            }
            if (abs(*map.rbegin() - *map.begin()) <= t){
                return true;
            }

            for (int i = k + 1; i < numsCount; ++i){
                map.erase(map.find(numbersInRange.front()));
                map.insert(nums[i]);
                numbersInRange.pop();
                numbersInRange.push(nums[i]);
                if (abs(*map.rbegin() - *map.begin()) <= t){
                    return true;
                }
            }
        }
        return false;

    }
};


class SolutionOld {
public:
    struct TreeNode {
        int key;
        int count;
        unique_ptr<TreeNode> left; // smaller
        unique_ptr<TreeNode> right; // bigger

        TreeNode(int v) : key(v), left(unique_ptr<TreeNode>()), right(unique_ptr<TreeNode>()), count(1){}
        TreeNode(int v, int c) : key(v), left(unique_ptr<TreeNode>()), right(unique_ptr<TreeNode>()), count(c){}
    };
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> existing;


    }
    TreeNode* extractMin(TreeNode* pParent, TreeNode* pCurr){
        // invariant: pParent cannot be NULL.
        if (pCurr->left){
            return extractMin(pCurr, pCurr->left.get());
        }
        else{
            // this is min
            TreeNode* pOutput = new TreeNode(pCurr->key, pCurr->count);
            pParent->left.reset(pCurr->right.get());
            return pOutput;
        }
    }
    void deleteNode(unique_ptr<TreeNode>* ppCurr, const int toBeDeletedValue){
        TreeNode* pCurr = (*ppCurr).get();
        if (pCurr){
            if (pCurr->key == toBeDeletedValue){
                if (pCurr->count == 1){
                    // need to remove the curr node
                    if ((pCurr->right) && (pCurr->left)){
                        TreeNode* pSuccesscor = extractMin(pCurr, pCurr->right.get());
                        pSuccesscor->left.reset();// to be done
                        (*ppCurr).reset(pSuccesscor);
                    }
                    else if (pCurr->left){
                        // only left
                        (*ppCurr).reset(pCurr->left.get());
                    }
                    else{
                        // only right or both NULL
                        (*ppCurr).reset(pCurr->right.get());
                    }
                }
                else{
                    pCurr->count--;
                }
            }
            else{
                if (pCurr->key > toBeDeletedValue){
                    // go to right
                    deleteNode(&(pCurr->right), toBeDeletedValue);
                }
                else{ // (pCurr->key < toBeDeletedValue)
                    deleteNode(&(pCurr->left), toBeDeletedValue);
                }
            }
        }
    }

    void insertNode(TreeNode* pRoot, const int newValue){
        if (pRoot){
            if (newValue < pRoot->key){
                if (pRoot->left){
                    // already has left node
                    insertNode(pRoot->left.get(), newValue);
                }
                else{
                    // left is empty, so create the node
                    pRoot->left.reset(new TreeNode(newValue));
                }
            }
            else if (newValue > pRoot->key){
                if (pRoot->right){
                    // already has right node
                    insertNode(pRoot->right.get(), newValue);
                }
                else{
                    // right is empty, so create the node
                    pRoot->right.reset(new TreeNode(newValue));
                }
            }
            else{
                // repeated key
                pRoot->count++;
            }
        }
    }
    bool foundInRange(TreeNode* pRoot, const int range, const int target){
        if ((pRoot) && (pRoot->key + range >= target) && (pRoot->key - range <= target)){
            return true;
        }
        else if ((pRoot) && (pRoot->key + range < target)){
            // go to right
            return foundInRange(pRoot->right.get(), range, target);
        }
        else if ((pRoot) && (pRoot->key - range > target)){
            // go to left
            return foundInRange(pRoot->left.get(), range, target);
        }
        else{
            return false;
        }
    }
};

