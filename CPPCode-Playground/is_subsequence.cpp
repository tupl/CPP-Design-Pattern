// https://leetcode.com/problems/is-subsequence/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int lt = 0, rt = 0;
        int n = s.size(), m = t.size();
        while(lt < n && rt < m) {
            if (s[lt] == t[rt]) {
                ++lt, ++rt;
            } else {
                ++rt;
            }
        }
        return lt == n;
    }
};