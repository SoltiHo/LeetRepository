// There are a total of n courses you have to take, labeled from 0 to n - 1.
// 
// Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair : [0, 1]
// 
// Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses ?
// 
// For example :
// 
// 2, [[1, 0]]
// There are a total of 2 courses to take.To take course 1 you should have finished course 0. So it is possible.
// 
// 2, [[1, 0], [0, 1]]
// There are a total of 2 courses to take.To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
// 
// click to show more hints.
// 
// Hints:
// This problem is equivalent to finding if a cycle exists in a directed graph.If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
// There are several ways to represent a graph.For example, the input prerequisites is a graph represented by a list of edges.Is this graph representation appropriate ?
// Topological Sort via DFS - A great video tutorial(21 minutes) on Coursera explaining the basic concepts of Topological Sort.
// Topological sort could also be done via BFS.
#include <vector>
#include <unordered_set>
#include <stack>
#include <memory>

using namespace std;



class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        bool output = true;
        if (numCourses > 0){
            vector<unordered_set<int>> table(numCourses, unordered_set<int>());

            for (auto p : prerequisites){
                if (DFS(p[0], p[1], table)){
                    // found
                    output = false;
                    break;
                }
                table[p[0]].insert(p[1]);
            }
        }
        return output;
    }


    bool DFS(int searchTarget, int root, vector<unordered_set<int>>& table){
        bool found = false;
        stack<int> s;
        s.push(root);
        while (s.size() > 0){
            int currKey = s.top();
            s.pop();
            if (table[currKey].size() > 0){
                // has dependency
                if (table[currKey].count(searchTarget) != 0){
                    // loop detected
                    found = true;
                    break;
                }
                else{
                    // doesn't exist in current level
                    // push all of the dependency into the stack
                    for (auto i : table[currKey]){
                        s.push(i);
                    }
                }
            }
        }
        return found;
    }
};
