// maximum size subarray equals k
// https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/

#include <unordered_map>
#include <algorithm>

#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int best = 0;
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            
            // if sum if k, check it
            if (sum == k) {
                best = max(best, i + 1);
            }
            
            // check if sum - k in the map
            int val = sum - k;
            auto it = map.find(val);
            if (it != map.end()) {
                best = max(best, i - it->second);
            } else {
                // if not in the map, put in
                if (!map.count(sum)) {
                    map[sum] = i;
                }
            }
        }
        return best;
    }
};