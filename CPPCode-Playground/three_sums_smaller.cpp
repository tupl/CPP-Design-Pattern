// https://leetcode.com/problems/3sum-smaller/

class Solution {
public:
    int counting(vector<int>& nums, int i, int j, int target) {
        int count = 0;
        while(i < j) {
            if (nums[i] + nums[j] < target) {
                count += (j - i);
                ++i;
            } else {
                --j;
            }
        }
        return count;
    }

    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int total = 0;
        for(int i = 0; i < nums.size(); ++i) {
            total += counting(nums, 0, i - 1, target - nums[i]);
        }
        return total;
    }
};