// https://leetcode.com/problems/range-addition/
// stupid idea: apply the problem

// thinking about put in a[i] and take it out a[i]

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
       vector<int> arr(length + 1, 0);
       for(int i = 0; i < updates.size(); ++i) {
           auto range = updates[i];
           int begin = range[0];
           int end = range[1] + 1;
           int val = range[2];
           arr[begin] += val;
           arr[end] -= val;
       }
       vector<int> res;
       int sum = 0;
       for(int i = 0; i < length; ++i) {
           sum += arr[i];
           res.push_back(sum);
       }
       return res;
    }
};
