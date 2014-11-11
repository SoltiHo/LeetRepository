//  Given n non - negative integers representing the histogram's bar height where the width of each bar is 1, 
//  find the area of largest rectangle in the histogram.
//  
//  For example,
//  Given height = [2, 1, 5, 6, 2, 3],
//  return 10.


// algorithm: http://www.geeksforgeeks.org/largest-rectangle-under-histogram/

#include <vector>
#include <stack>
using namespace std;


class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        const int size = height.size();
        if (size == 0){
            return 0;
        }

        stack<int> idxStack;

        int maxArea = 0;
        int currentArea = 0;
        int currentHeight = 0;
        for (int i = 0; i < size; ++i){
            if ((idxStack.size() == 0) || (height[i] >= height[idxStack.top()])){
                idxStack.push(i);
            }
            else{
                while ((idxStack.size() > 0) && (height[idxStack.top()] > height[i])){
                    currentHeight = height[idxStack.top()];
                    idxStack.pop();
                    if (idxStack.size() > 0){
                        currentArea = (i - idxStack.top() - 1) * currentHeight;
                    }
                    else{
                        currentArea = i * currentHeight;
                    }
                    if (maxArea < currentArea){
                        maxArea = currentArea;
                    }
                }
                if ((idxStack.empty()) || (height[i] >= height[idxStack.top()])){
                    idxStack.push(i);
                }
            }
        }

        while (idxStack.size() > 0){
            currentHeight = height[idxStack.top()];
            idxStack.pop();
            if (idxStack.size() > 0){
                currentArea = (size - 1 - idxStack.top()) * currentHeight;
            }
            else{
                currentArea = size * currentHeight;
            }
            if (maxArea < currentArea){
                maxArea = currentArea;
            }
        }

        return maxArea;
    }
};