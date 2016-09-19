// https://leetcode.com/problems/wiggle-sort/
// moving at odd position
// sort left and right

#include <utility>
#include <algorithm>

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i += 2) {
            if (i - 2 >=0 && nums[i-2] < nums[i-1]) swap(nums[i-2], nums[i - 1]);
            if (nums[i - 1] > nums[i]) swap(nums[i-1], nums[i]);
            if (i + 1 < nums.size() && nums[i] < nums[i+1]) swap(nums[i], nums[i+1]);
        }
    }
};