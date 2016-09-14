#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <map>
#include <fstream>
#include <unordered_map>
using namespace std;

pair<int, int> find(vector<int>& A, vector<int>& B, int k) {
	unordered_map<int, int> _map;
	for(int i = 0; i < A.size(); ++i) {
		_map[A[i]] = i;
	}

	for(int i = 0; i < B.size(); ++i) {
		int val = B[i] + k;
		auto it = _map.find(val);
		if (it != _map.end()) {
			int idx = it->second;
			return {idx, i};
		}
	}
	return {-1, -1};
}

int sum_array(vector<int>& A) {
	int sum = 0;
	for_each(A.begin(), A.end(), [&](int n) {
		sum += n;
	});
	return sum;
}

pair<int, int> sum_swap(vector<int>& A, vector<int>& B) {
	int sumA = sum_array(A);
	int sumB = sum_array(B);
	pair<int, int> result = find(A, B, sumA - sumB);
	return result;
}

int main() {
	vector<int> A = {4, 1, 2, 1, 1, 2};
	vector<int> B = {3, 6, 3, 3};
	auto it = sum_swap(A, B);
	std::cout << it.first << " " << it.second << std::endl;
	return 0;
}