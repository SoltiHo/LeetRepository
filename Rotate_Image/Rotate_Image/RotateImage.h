//  You are given an n x n 2D matrix representing an image.
//  
//  Rotate the image by 90 degrees(clockwise).
//  
//  Follow up :
//  Could you do this in - place ?

#include <vector>
using namespace std;

void swap_inplace(int Xa, int Ya, int Xb, int Yb, vector<vector<int> > &matrix){
    matrix[Xa][Ya] = matrix[Xa][Ya] ^ matrix[Xb][Yb];
    matrix[Xb][Yb] = matrix[Xa][Ya] ^ matrix[Xb][Yb];
    matrix[Xa][Ya] = matrix[Xa][Ya] ^ matrix[Xb][Yb];
}

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int matrixSize = matrix.size();
        int cycleOrigin_x = 0;
        int cycleOrigin_y = 0;
        int cycleEdgeSize = 0;
        for (int layer = 0; layer < (matrixSize >> 1); ++layer){
            cycleOrigin_x = cycleOrigin_y = layer;
            cycleEdgeSize = matrixSize - 1 - (layer << 1);
            for (int x_offset = 0; x_offset < cycleEdgeSize; ++x_offset){
                swap_inplace(cycleOrigin_x + cycleEdgeSize - x_offset, cycleOrigin_y + cycleEdgeSize, cycleOrigin_x + cycleEdgeSize, cycleOrigin_y + x_offset, matrix);
                swap_inplace(cycleOrigin_x, cycleOrigin_y + cycleEdgeSize - x_offset, cycleOrigin_x + cycleEdgeSize - x_offset, cycleOrigin_y + cycleEdgeSize, matrix);
                swap_inplace(cycleOrigin_x + x_offset, cycleOrigin_y, cycleOrigin_x, cycleOrigin_y + cycleEdgeSize - x_offset, matrix);
            }
        }
    }
};