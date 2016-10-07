// https://leetcode.com/problems/subsets/

class Solution {
public:
    void recur(vector<vector<int>>& ans, vector<bool>& mark, vector<int>& nums, int idx) {
        int n = nums.size();
        if (idx == n) {
            vector<int> tmp;
            for(int i = 0; i < n; ++i) {
                if (mark[i]) {
                    tmp.push_back(nums[i]);
                }
            }
            ans.push_back(tmp);
        } else {
            mark[idx] = true;
            recur(ans, mark, nums, idx + 1);
            mark[idx] = false;
            recur(ans, mark, nums, idx + 1);
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<bool> mark(n);
        recur(ans, mark, nums, 0);
        return ans;
    }
};
