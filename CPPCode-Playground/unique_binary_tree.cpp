// https://leetcode.com/problems/unique-binary-search-trees/

class Solution {
public:
    int numTrees(int n) {
        vector<int> catalan(n + 1, 0);
        catalan[0] = 1;
        for(int i = 1 ; i <= n; ++i) {
            int val = 0;
            int m = i - 1;
            for(int j = 0; j <= m; ++j) {
                val += catalan[j] * catalan[m - j];
            }
            catalan[i] = val;
        }
        return catalan[n];
    }
};
