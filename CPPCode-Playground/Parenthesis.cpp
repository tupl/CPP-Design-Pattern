#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>
#include <unordered_set>

void parenthesis(std::string& s, int l, int r) {
    // r - l + 1 == 2 * n
    if (l >= r) return;
    s[l] = '(';
    for(int i = l + 1; i <= r; i += 2) {
        parenthesis(s, l + 1, i - 1);
        s[i] = ')';
        parenthesis(s, i + 1, r);
        std::cout << s << std::endl;
    }
}

int main() {
    std::string s;
    s.resize(10);
    parenthesis(s, 0, 9);
    return 0;
}
