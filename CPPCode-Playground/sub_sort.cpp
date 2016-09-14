#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <utility>
#include <limits>
using namespace std;

/*
This is a very interesting problem. The idae of problem is to
maintain an array that its left is smaller than its self and
its right is bigger than it.
- Find the right part is in decreasing order.
- Find the left part is increasing order.
- Find minimum, maximum, between.
- Shift right until not less than maximum,
- Shift left until not greater than maximum
*/

int potentialRightEnd(vector<int>& arr) {
	// assume not empty array
	for(int i = arr.size() - 2; i >= 0; --i) {
		if (arr[i] > arr[i + 1]) return i + 1;
	}
	return 0;
}

int potentialLeftEnd(vector<int>& arr) {
	// assume not empty array
	for(int i = 1; i < arr.size(); ++i) {
		if (arr[i] < arr[i - 1]) return i - 1;
	}
	return arr.size();
}

pair<int, int> minimum_maximum(vector<int>& arr) {
	// assume not empty array from here
	int right = potentialRightEnd(arr);
	if (potentialRightEnd == 0) return {-1, -1}; // nothing need to be done
	int left = potentialLeftEnd(arr);

	// left [ ... ] right
	int minimum = numeric_limits<int>::max(),
		maximum = numeric_limits<int>::min();
	for(int i = left + 1; i < right - 1; ++i) {
		if (arr[i] > maximum) maximum = arr[i];
		if (arr[i] < minimum) minimum = arr[i];
	}
	// shift left
	while(left >= 0 && arr[left] > minimum) {
		--left;
	}
	// shift right;
	while(right < arr.size() && arr[right] < maximum) {
		++ right;
	}
	return {left, right};
}

int main() {
	vector<int> arr = {1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19};
	auto result = minimum_maximum(arr);
	std::cout << result.first << " " << result.second << std::endl;
	return 0;
}