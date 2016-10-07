// https://leetcode.com/problems/search-for-a-range/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n;
        int idx = -1;
        while(low <= high) {
            int mid = (low + high) >> 1;
            if (nums[mid] == target) {
                idx = mid; break;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        if (idx == -1) {
            return {-1, -1};
        } else {
            low = idx, high = idx;
            while(low >=0 && nums[low] == target) --low;
            while(high < n && nums[high] == target) ++high;
            return {low + 1, high - 1};
        }
    }
};
