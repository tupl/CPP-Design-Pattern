// https://leetcode.com/problems/summary-ranges/

#include <sstream>
#include <string>
#include <cmath>
#include <vector>

class Solution {
public:
    string format(int bg, int end) {
        ostringstream tmp("");
        tmp << bg;
        if (end > bg) {
            tmp << "->" << end;
        }
        return tmp.str();
    }

    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 0) {
            return {};
        }
        int bg = nums[0], end = nums[0];
        int n = nums.size();
        vector<string> summaries;
        for(int i = 1; i < n; ++i) {
            int val = nums[i];
            if (val > end + 1) {
                // has to make a new range
                summaries.push_back(format(bg, end));
                bg = end = val;
            } else {
                // next one;
                end = max(val, end);
            }
        }
        summaries.push_back(format(bg, end));
        return summaries;
    }
};
