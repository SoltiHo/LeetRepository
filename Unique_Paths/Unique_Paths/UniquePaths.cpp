
class Solution {
public:
    int uniquePaths(int m, int n) {
        unsigned int* A = new unsigned int[m * n];

        // set the base cases
        A[0] = 1;
        for (unsigned int x = n; x; --x){
            A[x-1] = 1;
        }
        for (unsigned int y = m; y; --y){
            A[(y-1) * n] = 1;
        }

        // start calculating the normal cases
        for (unsigned int x = 1; x < n; ++x){
            for (unsigned int y = 1; y < m; ++y){
                A[(y*n) + x] = A[((y - 1)*n) + x] + A[(y*n) + (x - 1)];
            }
        }

        return A[m*n - 1];
    }
};