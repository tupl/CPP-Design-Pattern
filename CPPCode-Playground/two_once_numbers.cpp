// https://leetcode.com/problems/single-number-iii/

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = 0;
        for(int i = 0; i < nums.size(); ++i) {
            diff ^= nums[i];
        }
        int least = diff & ~(diff - 1); // keep the least significant
        int a = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if (nums[i] & least) {
                a ^= nums[i];
            }
        }
        return {a, diff ^ a};
    }
};