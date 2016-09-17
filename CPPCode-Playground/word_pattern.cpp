#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> out;
        unordered_map<string, char> in;
        vector<string> strList;
        istringstream is(str);
        string val;
        while(is >> val) {
            strList.push_back(val);
        }
        
        if (strList.size() != pattern.size()) return false;
        
        for(int i = 0; i < pattern.size(); ++i) {
            char fr = pattern[i];
            string to = strList[i];
            auto it1 = out.find(fr);
            if (it1 != out.end()) {
                if (it1->second != to) return false;
            } else {
                out[fr] = to;
            }
            
            auto it2 = in.find(to);
            if (it2 != in.end()) {
                if (it2->second != fr) return false;
            } else {
                in[to] = fr;
            }            
        }
        
        return true;
    }
};


int main() {
	string s = "word to word list";
	Solution sl;
	std::cout << (true == sl.wordPattern("abac", s)) << std::endl;
	return 0;
}