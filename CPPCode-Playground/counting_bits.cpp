// https://leetcode.com/problems/counting-bits/
// idea: get rid of least significant, + 1

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> solu;
        solu.push_back(0);
        for(int i = 1; i <= num; ++i) {
            int val = i & (i - 1);
            solu.push_back(solu[val] + 1);
        }
        return solu;
    }
};