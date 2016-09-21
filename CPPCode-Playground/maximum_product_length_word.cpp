// https://leetcode.com/problems/maximum-product-of-word-lengths/
// canonical representation

#include <string>
#include <cmath>

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> cano_words(n, 0);
        for(int i = 0; i < n; ++i) {
            for(char c: words[i]) {
                cano_words[i] |= 1 << (c - 'a');
            }
        }
        
        int best = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if (!(cano_words[i] &cano_words[j])) {
                    best = max(best, (int) words[i].size() * (int) words[j].size() );
                }
            }
        }
        return best;
    }
};