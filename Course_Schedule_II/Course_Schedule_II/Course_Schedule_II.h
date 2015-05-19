// There are a total of n courses you have to take, labeled from 0 to n - 1.
// 
// Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair : [0, 1]
// 
// Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.
// 
// There may be multiple correct orders, you just need to return one of them.If it is impossible to finish all courses, return an empty array.
// 
// For example :
// 
// 2, [[1, 0]]
// There are a total of 2 courses to take.To take course 1 you should have finished course 0. So the correct course order is[0, 1]
// 
// 4, [[1, 0], [2, 0], [3, 1], [3, 2]]
// There are a total of 4 courses to take.To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken 
// after you finished course 0. So one correct course order is[0, 1, 2, 3].Another correct ordering is[0, 2, 1, 3].
// 
// Note:
// The input prerequisites is a graph represented by a list of edges, not adjacency matrices.Read more about how a graph is represented.

#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <memory>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;
// http://en.wikipedia.org/wiki/Topological_sorting#Algorithms

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> output;
        if (numCourses > 0){
            // build the map first
            vector<unordered_set<int>> dependentMap(numCourses, unordered_set<int>());
            vector<bool> hasDependency(numCourses, false);
            for (auto p : prerequisites){
                dependentMap[p.second].insert(p.first);
                hasDependency[p.first] = true;
            }

            vector<int> S;
            for (int i = 0; i < numCourses; ++i){
                if (hasDependency[i] == false){
                    S.push_back(i);
                }
            }


            while (S.size() > 0){
                S
            }

        }
        return output;
    }
};


class Solution_WRONG_BFS {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> output;
        if (numCourses > 0){
            // build the map first
            vector<unordered_set<int>> dependencyMap(numCourses, unordered_set<int>());
            for (auto p : prerequisites){
                dependencyMap[p.first].insert(p.second);
            }

            vector<int> layer(numCourses, 0);
            bool loopDetected = false;
            for (int i = 0; i < numCourses; ++i){
                if (layer[i] == 0){
                    // not processed yet
                    queue<int> q;
                    q.push(i);
                    int order = 1;
                    vector<bool> onThePath(numCourses, false);
                    while (q.size() > 0) {
                        layer[q.front()] = max(layer[q.front()], order++);
                        if (onThePath[q.front()]){
                            // loop detected
                            loopDetected = true;
                            break;
                        }
                        onThePath[q.front()] = true;
                        if (dependencyMap[q.front()].size() > 0){
                            // has dependency
                            for (auto d : dependencyMap[q.front()]){
                                if ((layer[d] == 0) || (order > layer[d])){
                                    q.push(d);
                                }
                                layer[d] = max(layer[d], order);
                            }
                        }
                        q.pop();
                    }
                }
            }

            if (!loopDetected){
                for (auto& v : dependencyMap){
                    v.clear();
                }
                for (int i = 0; i < numCourses; ++i){
                    dependencyMap[layer[i] - 1].insert(i);
                }
                for (int i = numCourses - 1; i >= 0; --i){
                    for (auto n : dependencyMap[i]){
                        output.push_back(n);
                    }
                }
            }
        }
        return output;
    }
};


class Solution_DFS {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> output;
        if (numCourses > 0){
            // build the map first
            vector<unordered_set<int>> dependencyMap(numCourses, unordered_set<int>());
            for (auto p : prerequisites){
                dependencyMap[p.first].insert(p.second);
            }

            vector<int> position(numCourses, 0);
            int order = numCourses;
            bool loopFound = false;
            for (int i = 0; i < numCourses; ++i){
                if (position[i] == 0){
                    // not processed yet
                    if (topologicalSort(position, dependencyMap, i, order)){
                        // loop found
                        loopFound = true;
                        break;
                    }
                }
            }

            if (!loopFound){
                output.resize(numCourses, 0);
                for (int i = 0; i < numCourses; ++i){
                    output[numCourses - position[i]] = i;
                }
            }
        }
        return output;
    }

    bool topologicalSort(vector<int>& position, vector<unordered_set<int>>& dependencyMap, int currNode, int& order){
        if (position[currNode] == -1){
            // visited on the path
            return true;  // loop found
        }
        position[currNode] = -1; // mark it on the path

        if (dependencyMap[currNode].size() > 0){
            for (auto i : dependencyMap[currNode]){
                if (position[i] > 0){
                    continue; // already processed, so pass
                }
                if (topologicalSort(position, dependencyMap, i, order)){
                    return true;
                }
            }
        }

        position[currNode] = order;
        order--;
        return false; // no loop
    }
};
