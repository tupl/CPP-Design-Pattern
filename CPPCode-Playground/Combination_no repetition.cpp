#include <algorithm>
#include <string>
#include <cmath>
#include <sstream>

class Solution {
public:
    void recur(vector<vector<int>>& combi, vector<int>& solu, int level, int k, int cur, const int& n) {
        // if we haven't achieve enough & run out of cur 
        if (level < k && cur > n) return;
        
        // if we found enough, print it
        if (level == k) {
            combi.push_back(solu);
            return;
        } 

        // valid, pick from cur to n
        for(int i = cur; i <= n; ++i) {
            solu[level] = i;
            recur(combi, solu, level + 1, k, i + 1, n);
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> combi;
        vector<int> solu(k);
        recur(combi, solu, 0, k, 1, n);
        return combi;
    }
};