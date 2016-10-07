// https://leetcode.com/problems/minimum-path-sum/

#include <cmath>
#include <limits>

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.front().size();
        vector<vector<int>> mat(m, vector<int>(n));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) {
                    mat[0][0] = grid[0][0];
                } else {
                    mat[i][j] = numeric_limits<int>::max();
                    if (i - 1 >= 0) mat[i][j] = min(mat[i][j], grid[i][j] + mat[i - 1][j]);
                    if (j - 1 >= 0) mat[i][j] = min(mat[i][j], grid[i][j] + mat[i][j - 1]);
                }
            }
        }
        return mat[m - 1][n - 1];
    }
};
