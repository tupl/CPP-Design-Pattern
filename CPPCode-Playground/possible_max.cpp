// https://leetcode.com/problems/jump-game/

#include <cmath>

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int possibleMax = 0;
        int n = nums.size();
        for(int i = 0; i < nums.size(); ++i) {
            if (i <= possibleMax) {
                int val = nums[i];
                possibleMax = max(possibleMax, i + val);
            }
        }
        return possibleMax >= n - 1;
    }
};
