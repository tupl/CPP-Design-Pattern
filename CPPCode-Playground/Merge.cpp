#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

void merge(std::vector<int>& A, std::vector<int>& B) {
    int m = A.size(), n = B.size();
    int total = m + n;
    --m, --n, --total;
    A.resize(total);
    while(m >=0 && n >= 0) {
        if (A[m] >= B[n]) {
            A[total] = A[m];
            --m;
        } else {
            A[total] = B[n];
            --n;
        }
        --total;
    }
    while(m >= 0) {
        A[total--] = A[m--];
    }
    while(n >= 0) {
        A[total--] = B[n--];
    }
}

int main() {
    std::vector<int> A = {1, 2, 3, 5, 9};
    std::vector<int> B = {-2, 3, 4, 8};
    merge(A, B);
    for(auto iter = A.begin(); iter != A.end(); ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
    return 0;
}
