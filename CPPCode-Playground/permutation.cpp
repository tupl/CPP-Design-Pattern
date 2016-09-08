#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>
#include <unordered_set>

std::unordered_set<std::string> _set;

void permutation(std::string& solu, int idx, int n) {
    if (idx == solu.size()) {
        auto it = _set.find(solu);
        if (it != _set.end()) {
            std::cout << "Something wrong" << std::endl;
            std::cout << "-" << solu << std::endl;
        }
        std::cout << solu << std::endl;
        _set.insert(solu);
    } else {
        char last;
        for(int i = idx; i < n; ++i) {
            if (i == idx || solu[i] != last) {
                std::swap(solu[i], solu[idx]);
                permutation(solu, idx + 1, n);
                std::swap(solu[i], solu[idx]);
                last = solu[i];
            }
        }
    }
}

int main() {
    std::string s = "abbcd";
    std::sort(s.begin(), s.end());
    permutation(s, 0, s.size());
    return 0;
}
