#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iostream>
using namespace std;

// 93. Restore IP Addresses - Leet Code
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iostream>
using namespace std;

class Solution {
public:

    bool valid(string& s) {
        if (s[0] == '0' && s.size() > 1) return false;
        if (s.size() < 3) return true; // 1, 2 character
        if (s.size() > 3) return false; // not more than 3
        // 3 character now
        if (s[0] >= '3') return false;
        if (s[0] == '2') return (s[1] <= '4') || (s[1] == '5' && s[2] <= '5'); // <= 4 or 5x (x <= 5)
        return true; // 0
    }

    void listIP(string& s, vector<string>& answer, vector<string>& solu, int st, int level) {
        // haven't reach level 4 and run out a character
        if (level < 4 && st >= s.size()) return;

        // if level 4, should start print now
        if (level == 4) {
            // if we level 4, and we cover all string
            if (st == s.size()) {
                answer.push_back(
                     solu[0] + "." +
                     solu[1] + "." +
                     solu[2] + "." + solu[3]
                    );  
            }
            return;
        }
        
        int n = s.size();
        for(int i = 1; i <= 3 && st + i <= n ; ++i) {
            string tmp = s.substr(st, i);
            if (valid(tmp)) {
                solu[level] = tmp;
                listIP(s, answer, solu, st + i, level + 1);
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> res(4);
        vector<string> answer;
        listIP(s, answer, res, 0, 0);
        return answer;
    }
};

int main() {
    Solution sl;
    string s = "35255511";
    vector<string> res = sl.restoreIpAddresses(s);
    std::cout << res.size() << std::endl;
    for(auto it = res.begin(); it != res.end(); ++it) {
        std::cout << *it << std::endl;
    }
    return 0;
}