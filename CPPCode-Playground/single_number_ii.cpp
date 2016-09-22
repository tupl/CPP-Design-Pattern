// https://leetcode.com/problems/single-number-ii/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0;
        int n_one, n_two;
        for(int i = 0; i < nums.size(); ++i) {
            int x = nums[i];
            n_one = (~one & ~two & x) | (one & ~x);
            n_two = (one & x) | (two & ~x);
            one = n_one;
            two = n_two;
        }
        return one;
    }
};