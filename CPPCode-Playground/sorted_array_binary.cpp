// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
// sorted binary tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* recur(vector<int>& nums, int lf, int rt) {
        if (lf >= rt) return nullptr;
        int mid = (lf + rt) >> 1;
        TreeNode* cur = new TreeNode(nums[mid]);
        cur->left = recur(nums, lf, mid);
        cur->right = recur(nums, mid + 1, rt);
        return cur;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return recur(nums, 0, nums.size());
    }
};