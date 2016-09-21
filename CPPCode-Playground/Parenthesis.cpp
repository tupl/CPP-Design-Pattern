// https://leetcode.com/problems/generate-parentheses/
// 

#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>
#include <unordered_set>

class Solution {
public:
    void parenthesis(vector<string>& ans, std::string& s, int idx, int l, int r) {
        if (l == 0 && r == 0) {
            ans.push_back(s);
        }
        if (l < 0 || r < 0) return;
        // number of remaing left <= remaing right at any time
        if (l <= r) {
            // use one left
            s[idx] = '(';
            parenthesis(ans, s, idx + 1, l - 1, r);
            // or use one right
            s[idx] = ')';
            parenthesis(ans, s, idx + 1, l, r - 1);
        }
    }

    vector<string> generateParenthesis(int n) {
        string solu; solu.resize(2 * n);
        vector<string> ans;
        parenthesis(ans, solu, 0, n, n);
        return ans;
    }
};

int main() {
    std::string s;
    s.resize(10);
    parenthesis(s, 0, 9);
    return 0;
}
