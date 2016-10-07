class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int less1 = 0, curr = 0, greater1 = n - 1;
        while(curr <= greater1) {
            if (nums[curr] == 0) {
                swap(nums[less1], nums[curr]);
                ++ less1, ++ curr;
            } else if (nums[curr] == 1) {
                ++ curr;
            } else {
                // > 1
                swap(nums[curr], nums[greater1]);
                -- greater1;
            }
        }
    }
};
