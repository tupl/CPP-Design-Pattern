// https://leetcode.com/problems/find-leaves-of-binary-tree/
// keeping get rid of leaves O(n^2)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
 
class Solution {
public:
    void getLeaves(vector<int>& solu, TreeNode*& root) {
        // if it is a leaf
        if (!root) return;
        if (!root->left && !root->right) {
            solu.push_back(root->val);
            root = nullptr;
        } else {
            getLeaves(solu, root->right);
            getLeaves(solu, root->left);
        }
    }

    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> solu;
        while(root) {
            vector<int> tmp;
            getLeaves(tmp, root);
            solu.push_back(tmp);
        }
        return solu;
    }
};

// second solution, calculate depth at each node and print O(n)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
 
class Solution {
public:
    int depth(vector<vector<int>>& solu, TreeNode* root) {
        if (!root) return -1;
        int dpt = 1 + max(depth(solu, root->left), depth(solu, root->right));
        if (dpt >= solu.size()) solu.resize(dpt + 1);
        solu[dpt].push_back(root->val);
        return dpt;
    }

    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> solu;
        depth(solu, root);
        return solu;
    }
};