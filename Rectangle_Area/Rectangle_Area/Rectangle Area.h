// Find the total area covered by two rectilinear rectangles in a 2D plane.
// 
// Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
// 
// Rectangle Area
// Assume that the total area is never beyond the maximum possible value of int.

#include <algorithm>
using namespace std;
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        // area of two rectangles
        int output = (C - A) * (D - B) + (G - E)* (H - F);
        // decide overlapped or not
        if (((A <= E) && (C >= E)) || ((A >= E) && (A <= G))){
            // X overlap
            if (((B <= F) && (D >= F)) || ((B >= F) && (B <= H))){
                // Y overlap
                int area_bottomLeft_X = max(A, E);
                int area_bottomLeft_Y = max(B, F);
                int area_TopRight_X = min(C, G);
                int area_TopRight_Y = min(D, H);
                output -= (area_TopRight_X - area_bottomLeft_X) * (area_TopRight_Y - area_bottomLeft_Y);
            }
        }

        return output;
    }
};

