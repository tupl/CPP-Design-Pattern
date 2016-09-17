// remember 'range'
// remember base case itself

class Solution {
public:
    void recur(vector<vector<int>>& all, vector<int>& solu, int cur, int n) {
        if (n == 1) {
            if (solu.size() > 1) all.push_back(solu);
        } else {
            for(int i = cur; i <= n; ++i) {
                if (n % i == 0) {
                    solu.push_back(i);
                    recur(all, solu, i, n / i);
                    solu.pop_back();   
                }
            }
        }
    }

    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> all;
        vector<int> solu;
        recur(all, solu, 2, n);
        return all;
    }
};