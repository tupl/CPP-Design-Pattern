#include <iostream>
#include <map>
#include <unordered_map>
#include <fstream>
#include <unordered_set>
#include <algorithm>
#include <cstring>
#include <utility>
#include <string>
using namespace std;

int charToDigit(char c) {
	if (c >= 'a' && c <= 'c') return 2;
	if (c >= 'd' && c <= 'f') return 3;
	if (c >= 'g' && c <= 'i') return 4;
	if (c >= 'j' && c <= 'l') return 5;
	if (c >= 'm' && c <= 'o') return 6;
	if (c >= 'p' && c <= 's') return 7;
	if (c >= 't' && c <= 'v') return 8;
	if (c >= 'w' && c <= 'z') return 9;
}

int stringToNumber(string str) {
	int sum = 0;
	for(int i = 0; i < str.size(); ++i) {
		sum = sum * 10 + charToDigit(str[i]);
	}
	return sum;
}

unordered_map<int, vector<string>> preCompute(const vector<string>& v) {
	unordered_map<int, vector<string>> _map;
	for(int i = 0; i < v.size(); ++i) {
		int num = stringToNumber(v[i]);
		_map[num].push_back(v[i]);
	}
	return _map;
}

int main() {
	unordered_map<int, vector<string>> _map = preCompute({"tree", "used", "apple"});
	int num = 8733;
	for(auto iter = _map[num].begin(); iter != _map[num].end(); ++iter) {
		std::cout << *iter << std::endl;
	}
	return 0;
}