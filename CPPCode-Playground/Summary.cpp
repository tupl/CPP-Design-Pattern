List of required summaries:

- Unique Binary Search Trees
  Equal to Catalan number Cn

  C n + 1 = sum C i * C n - i for 0

- Summary Maximum subarray with non empty

#include <cmath>
#include <limits>

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum_best = nums[0];
        int sum_sofar = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            sum_sofar = max(sum_sofar + nums[i], nums[i]);
            sum_best = max(sum_best, sum_sofar);
        }
        return sum_best;
    }
};
