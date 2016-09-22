// https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMax(n);
        vector<int> rightMax(n);
        for(int i = 0, maxi = 0; i < n; ++i) {
            maxi = max(maxi, height[i]);
            leftMax[i] = maxi;
        }

        for(int i = n - 1, maxi = 0; i >= 0; --i) {
            maxi = max(maxi, height[i]);
            rightMax[i] = maxi;
        }

        int total = 0;
        for(int i = 0; i < n; ++i) {
            total += min(leftMax[i], rightMax[i]) - height[i];
        }
        return total;
    }
};