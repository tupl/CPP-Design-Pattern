// https://leetcode.com/problems/top-k-frequent-elements/

// bucket idea

#include <unordered_map>
#include <algorithm>
#include <vector>
#include <utility>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int i = 0; i < nums.size(); ++i) {
            ++ freq[nums[i]];
        }
        int n = nums.size();
        vector< vector<int> > counter(n + 1);
        for(auto it = freq.begin(); it != freq.end(); ++it) {
            pair<int, int> pr = *it;
            counter[it->second].push_back(it->first);
        }
        vector<int> res;
        for(int i = n; i >= 0; --i) {
            vector<int> keys = counter[i];
            if (keys.size() != 0) {
                for(int j = 0; j < keys.size(); ++j) {
                    if (res.size() >= k) break; // we get enouhg
                    res.push_back(keys[j]);
                }
            }
        }
        return res;
    }
};

// using heap
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>

#include <unordered_map>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>

#include <unordered_map>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>

#include <unordered_map>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>

class Solution {
public:
    struct FreqKey {
        int freq;
        int key;
        FreqKey(int _freq, int _key): freq(_freq), key(_key) {}
    };

    struct CmpFreqKey {
        bool operator()(const FreqKey& fr, const FreqKey& sec) {
            return fr.freq > sec.freq;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int n = nums.size();
        for(int i = 0; i < nums.size(); ++i) {
            ++ freq[nums[i]];
        }
        priority_queue<FreqKey, vector<FreqKey>, CmpFreqKey > pq;
        for(auto it = freq.begin(); it != freq.end(); ++it) {
            pq.push(FreqKey(it->second, it->first));
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        vector<int> res;
        while(!pq.empty()) {
            FreqKey top = pq.top(); pq.pop();
            res.push_back(top.key);
        }
        return res;
    }
};