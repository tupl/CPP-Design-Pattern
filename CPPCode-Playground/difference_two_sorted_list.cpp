vector<int> top = lst[word1];
vector<int> bot = lst[word2];
int i = 0, j = 0;
int prev, curr;
int n = top.size(), m = bot.size();
int best = numeric_limits<int>::max();
int a, b;
while(i < n && j < m) {
    if (top[i] < bot[j]) {
        a = top[i]; ++i;
        b = bot[j];
    } else {
        a = bot[j]; ++j;
        b = top[i];
    }
    best = min(best, abs(a - b));
}

// only compare the merge sort

return best;