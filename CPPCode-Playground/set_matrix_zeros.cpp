// https://leetcode.com/problems/set-matrix-zeroes/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix.front().size();
        vector<bool> columns(n, false);
        vector<bool> rows(m, false);
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    columns[j] = true;
                    rows[i] = true;
                }
            }
        }

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if (rows[i] || columns[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
