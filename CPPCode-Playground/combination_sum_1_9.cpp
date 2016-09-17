// https://leetcode.com/problems/combination-sum-iii/

class Solution {
public:
    void recur(vector<vector<int>> & all,
        vector<int>& solu,
        int low,
        int high,
        int lvl,
        int k,
        int sum) {
        if (lvl < k && low > high) return;
        if (lvl > k) return;
        if (lvl == k) {
            if (sum == 0) {
                all.push_back(solu);
            }
        }
        
        for(int i = low; i <= high; ++i) {
            solu.push_back(i);
            recur(all, solu, i + 1, high, lvl + 1, k, sum - i);
            solu.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> all;
        vector<int> solu;
        recur(all, solu, 1, 9, 0, k, n);
        return all;
    }
};