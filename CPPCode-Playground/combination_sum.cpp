#include <algorithm>
#include <string>

// https://leetcode.com/problems/combination-sum-ii/
// keep track of previous character
// allow for repeated one number

class Solution {
public:

    void putSolution(vector<vector<int>>& combi, vector<int>& solu) {
        combi.push_back(solu);
    }

    void recur(vector<vector<int>>& combi, vector<int>& solu, vector<int>& candidates,
        int target, int cur
    ) {
        int n = candidates.size();
        if (target < 0) return;
        if (target == 0) {
            putSolution(combi, solu);
        }
        if (cur < n) {
            int prev = -1;
            for(int i = cur; i < n; ++i) {
                if (i == cur || candidates[i] != prev) {
                    solu.push_back(candidates[i]);
                    recur(combi, solu, candidates, target - candidates[i], i + 1);
                    solu.pop_back();
                    prev = candidates[i];
                }
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> combi;
        vector<int> solu;
        recur(combi, solu, candidates, target, 0);
        return combi;
    }
};