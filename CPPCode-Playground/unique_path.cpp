// https://leetcode.com/problems/unique-paths/

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> mat(m, vector<int>(n, 0));
        mat[0][0] = 1;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                mat[i][j] += (i - 1 >= 0 ? mat[i-1][j] : 0);
                mat[i][j] += (j - 1 >= 0 ? mat[i][j-1] : 0);
            }
        }
        return mat[m - 1][n - 1];
    }
};