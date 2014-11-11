// Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.

#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int largestRectangleArea(int* height, const int size) {
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
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        const int height = matrix.size();
        if (height == 0){
            return 0;
        }

        const int width = matrix[0].size();
        if (width == 0){
            return 0;
        }

        if (height == 1){

        }
        else if (width == 1){

        }


        int* accumulatedOnes = new int[width];
        memset(accumulatedOnes, 0, sizeof(int)*width);

        int currentArea = 0;
        int maxArea = 0;
        for (int y = 0; y < height; ++y){
            for (int x = 0; x < width; ++x){
                if (matrix[y][x] == '1'){
                    accumulatedOnes[x]++;
                }
                else{
                    // '0'
                    accumulatedOnes[x] = 0;
                }
            }

            // calculate area
            currentArea = largestRectangleArea(accumulatedOnes, width);
            maxArea = max(maxArea, currentArea);

        }

        return maxArea;
    }
};