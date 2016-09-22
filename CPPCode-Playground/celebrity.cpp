// https://leetcode.com/problems/find-the-celebrity/

// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        int a = 0, b = 1;
        while(b < n) {
            if (knows(a, b)) {
                a = b; ++b;
            } else {
                ++b;
            }
        }
        for(int i = 0; i < n; ++i) {
            if (i != a) {
                if (!knows(i, a) || knows(a, i)) return -1;
            }
        }
        return a;
    }
};