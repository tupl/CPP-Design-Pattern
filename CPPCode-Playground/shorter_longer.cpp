// ideas is simple, take p shorter & K - P longer
#include <iostream>
#include <map>
#include <cmath>
#include <algorithm>
#include <unordered_set>

int count(int k, int shorter, int longer) {
	std::unordered_set<int> vals;
	for(int i = 0; i < k; ++i) {
		vals.insert(i * shorter + (k - i) * longer);
	}
	return vals.size();	
}

int main() {
	std::cout << count(4, 3, 5) << std::endl;
	return 0;
}