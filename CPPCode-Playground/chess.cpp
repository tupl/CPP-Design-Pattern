#include <vector>
#include <string>
#include <cstdlib>
#include <climits>
#include <iostream>
#include <algorithm>

bool valid(std::vector<int>& posi, int idx) {
    for(int i = 0; i < idx; ++i) {
        int diff = std::abs(posi[idx] - posi[i]);
        if (diff == 0 || diff == idx - i) return false;
    }
    return true;
}

void check(std::vector<int>& posi, int idx, int n) {
    if (idx == n) {
        std::for_each(posi.begin(), posi.end(), [](int ptr) {
            std::cout << ptr << " ";
        });
        std::cout << std::endl;
    } else {
        for(int i = 0; i < n; ++i) {
            posi[idx] = i;
            if (valid(posi, idx)) {
                check(posi, idx + 1, n);
            }
        }
    }
}

int main () {
    int n = 8;
    std::vector<int> posi(n, 0);
    check(posi, 0, n);
    return 0;
}
