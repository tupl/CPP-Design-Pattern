// https://leetcode.com/problems/product-of-array-except-self/
// product of array with extra space

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left;
        vector<int> right;
        int n = nums.size();
        int prod = 1;
        left.push_back(prod);
        for(int i = 0; i < nums.size(); ++i) {
            prod *= nums[i];
            left.push_back(prod);
        }
        prod = 1;
        right.push_back(prod);
        for(int i = nums.size() - 1; i >= 0; --i) {
            prod *= nums[i];
            right.push_back(prod);
        }
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i) {
            res.push_back(left[i] * right[n - i - 1]);
        }
        return res;
    }
};

// constant space