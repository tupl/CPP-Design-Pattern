#include <algorithm>
#include <unordered_map>
#include <map>

// first solution
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() - t.size() != 0) return false;
        
        unordered_map<char, unordered_set<char>> in;
        unordered_map<char, unordered_set<char>> out;
        
        for(int i = 0; i < s.size(); ++i) {
            char a = s[i];
            char b = t[i];
            out[a].insert(b);
            in[b].insert(a);
            if (in[a].size() > 1 || in[b].size() > 1 || out[a].size() > 1 ||
                out[b].size() > 1) return false;
        }
        
        return true;
    }
};

// second solution

#include <algorithm>
#include <unordered_map>
#include <map>

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() - t.size() != 0) return false;
        
        unordered_map<char, char> in;
        unordered_map<char, char> out;
        
        for(int i = 0; i < s.size(); ++i) {
            char a = s[i];
            char b = t[i];
            
            auto it1 = out.find(a);
            if (it1 != out.end()) {
                if (it1->second != b) return false;
            } else {
                out[a] = b;
            }
   
            auto it2 = in.find(b);
            if (it2 != in.end()) {
                if (it2->second != a) return false;
            } else {
                in[b] = a;
            }
        }
        
        return true;
    }
};