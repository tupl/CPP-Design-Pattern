// https://leetcode.com/problems/anagrams/

#include <unordered_map>
#include <algorithm>
#include <string>
#include <utility>

class Solution {
public:
    void visit(unordered_map<string, vector<string>>& sets, string val) {
        string hash = val;
        sort(hash.begin(), hash.end());
        sets[hash].push_back(val);
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> sets;
        for(int i = 0; i < strs.size(); ++i) {
            visit(sets, strs[i]);
        }
        vector<vector<string>> map;
        for(auto it = sets.begin(); it != sets.end(); ++it) {
            map.push_back(it->second);
        }
        return map;
    }
};
