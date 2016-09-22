// https://leetcode.com/problems/container-with-most-water/
// interesting, move left, right pointer at same time

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxArea = 0;
        while(left <= right) {
            int valArea = min(height[left], height[right]) * (right - left);
            maxArea = max(maxArea, valArea);
            if (height[left] < height[right]) {
                ++ left;
            } else if (height[left] > height[right]) {
                -- right;   
            } else {
                ++ left, -- right;
            }
        }
        return maxArea;
    }
};