class Solution {
public:
    int get(char c) {
        if (c == 'I') return 1;
        if (c == 'V') return 5;
        if (c == 'X') return 10;
        if (c == 'L') return 50;
        if (c == 'C') return 100;
        if (c == 'D') return 500;
        if (c == 'M') return 1000;
        return 0;
    }

    int romanToInt(string s) {
        if (s.empty()) return 0;
        int sum = 0;
        for(int i = 0; i < s.size(); ++i) {
            sum += get(s[i]);
            if (i != 0 && get(s[i]) > get(s[i-1])) {
                sum -= 2 * get(s[i-1]);
            }
        }
        return sum;
    }
};