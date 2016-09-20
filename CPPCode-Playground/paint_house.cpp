// https://leetcode.com/problems/paint-house/

#include <cmath>
#include <vector>

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        // T[i][0], minimum cost of painting house from
        // 0 to i - 1 with red, blue, green
        // it mean T[0][k] = 0 for any k
        // T[i][0] = cost[i-1][0] + min(T[i-1][1], T[i-1][2]);
        // curr_red = cost[i-1][0] + min(prev_blue, prev_green);
        int prev_red = 0, prev_blue = 0, prev_green = 0;
        int curr_red, curr_blue, curr_green;
        for(int i = 1; i <= costs.size(); ++i) {
            curr_red = costs[i-1][0] + min(prev_blue, prev_green);
            curr_green = costs[i-1][1] + min(prev_red, prev_blue);
            curr_blue = costs[i-1][2] + min(prev_red, prev_green);
            prev_red = curr_red;
            prev_blue = curr_green;
            prev_green = curr_blue;
        }
        return min(prev_red, prev_blue, prev_green);
    }
};