#include <vector>
#include <iostream>
#include <fstream>
#include <utility>
#include <algorithm>
#include <limits>

#include <cmath>

int smallest_different(
    std::vector<int>& A,
    std::vector<int>& B,
    std::pair<int, int>& p
) {
    int n = A.size();
    int m = B.size();
    int i = 0, j = 0;
    int best = std::numeric_limits<int>::max();

    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());

    while(i < n && j < m) {
        int val = std::abs(A[i] - B[j]);
        best = std::min(best, val);
        if (A[i] < B[j]) {
            ++i;
        } else {
            ++j;
        }
    }

    return best;
}

int main() {
    std::vector<int> A = {1, 3, 15, 11, 2};
    std::vector<int> B = {23, 127, 235, 19, 8};
    std::pair<int, int> p;
    std::cout << smallest_different(A, B, p) << std::endl;
    return 0;
}
