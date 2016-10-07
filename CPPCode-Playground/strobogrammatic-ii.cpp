// https://leetcode.com/problems/strobogrammatic-number-ii/
// pay attention to 0 in the begining

#include <iostream>

class Solution {
private:
    vector<string> pair_char = { "11", "69", "96", "88" };
public:
    void recur(vector<string>& ans, string& solu, int l, int r) {
        if (l > r) {
            ans.push_back(solu);
        } else if (l == r) {
            // must be odd
            vector<char> valid = {'0', '1', '8'};
            for(int i = 0; i < valid.size(); ++i) {
                solu[l] = valid[i];
                ans.push_back(solu);
            }
        } else if (l < r){
            if (l > 0) {
                solu[l] = '0';
                solu[r] = '0';
                recur(ans, solu, l + 1, r - 1);
            }
            for(int i = 0; i < pair_char.size(); ++i) {
                solu[l] = pair_char[i][0];
                solu[r] = pair_char[i][1];
                recur(ans, solu, l + 1, r - 1);
            }
        }
    }

    vector<string> findStrobogrammatic(int n) {
        vector<string> ans;
        string solu; solu.resize(n);
        recur(ans, solu, 0, n - 1);
        return ans;
    }
};
