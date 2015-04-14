// Clone an undirected graph.Each node in the graph contains a label and a list of its neighbors.
// 
// 
// OJ's undirected graph serialization:
// Nodes are labeled uniquely.
// 
// We use # as a separator for each node, and, as a separator for node label and each neighbor of the node.
// As an example, consider the serialized graph{ 0, 1, 2#1, 2#2, 2 }.
// 
// The graph has a total of three nodes, and therefore contains three parts as separated by #.
// 
// First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
// Second node is labeled as 1. Connect node 1 to node 2.
// Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self - cycle.
// Visually, the graph looks like the following :
// 
//     1
//    / \
//   /   \
//  0 --- 2
//       / \
//       \_/

#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// Definition for undirected graph.
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

// try BFS
class Solution {  // memory limit exceed
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        UndirectedGraphNode* pOutput = NULL;
        if (node){
            queue<UndirectedGraphNode*> q;  // maintain the nodes in the original graph
            unordered_map<int, UndirectedGraphNode*> newNodes;
            UndirectedGraphNode* pCurr = NULL;
            q.push(node);
            while (q.size() > 0){
                pCurr = new UndirectedGraphNode(q.front()->label);
                newNodes[node->label] = pCurr;
                if (pOutput == NULL){
                    pOutput = pCurr;
                }

                // scan through the neighbors, connect the existed
                for (auto pN : q.front()->neighbors){
                    if (newNodes.find(pN->label) != newNodes.end()){
                        // neighbor exists, meaning that node was visited
                        pCurr->neighbors.push_back(newNodes[pN->label]);
                        newNodes[pN->label]->neighbors.push_back(pCurr);
                    }
                    else{
                        // new node required, not visited before
                        q.push(pN);
                    }
                }
                q.pop();
            }
        }
        return pOutput;
    }
};

// try DFS
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        UndirectedGraphNode* pOutput = NULL;
        if (node){
            unordered_map<int, UndirectedGraphNode*> newNodes;
            pOutput = new UndirectedGraphNode(node->label);
            newNodes[node->label] = pOutput;
            DFS(node, pOutput, newNodes);
        }
        return pOutput;
    }

    void DFS(UndirectedGraphNode* pOld, UndirectedGraphNode* pCurr, unordered_map<int, UndirectedGraphNode*>& newNodes){
        for (auto pN : pOld->neighbors){
            if (newNodes.find(pN->label) == newNodes.end()){
                // not visited yet
                UndirectedGraphNode* pNew = new UndirectedGraphNode(pN->label);
                newNodes[pN->label] = pNew;
                pCurr->neighbors.push_back(pNew);
                DFS(pN, pNew, newNodes);
            }
            else{
                // already visited
                pCurr->neighbors.push_back(newNodes[pN->label]);
            }
        }
    }
};