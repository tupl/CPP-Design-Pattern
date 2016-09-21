// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
// using min_heap & counting table

#include <algorithm>
#include <queue>
#include <utility>

class Solution {
public:
    struct Val {
        int val;
        int col;
    };
    
    struct CmpVal {
        bool operator()(const Val& fr, const Val& sec) {
            return fr.val > sec.val;
        }  
    };

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        vector<int> col(n, 1);
        priority_queue<Val, vector<Val>, CmpVal> mhp;
        
        for(int i = 0; i < n; ++i) {
            mhp.push({matrix[0][i], i});
        }
        int v;
        while(k--) {
            Val myval = mhp.top(); mhp.pop();
            v = myval.val;
            int _col = myval.col;
            if (col[_col] < n) {
                mhp.push({matrix[col[_col]][_col], _col});
            }
            ++ col[_col];
        }
        return v;
    }
};