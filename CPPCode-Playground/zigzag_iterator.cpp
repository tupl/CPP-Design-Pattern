class ZigzagIterator {
private:
    vector<int> _v1;
    vector<int> _v2;
    int i = 0, j = 0;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        _v1 = v1;
        _v2 = v2;
        i = 0, j = 0;
    }

    int next() {
        int n = _v1.size(), m = _v2.size();
        if (i < n && j < m) {
            if ((i + j) % 2 == 0) {
                return _v1[i++];
            } else {
                return _v2[j++];
            }
        }
        if (i < n) return _v1[i++];
        if (j < m) return _v2[j++];
        return -1;
    }

    bool hasNext() {
        return (i + j) < _v1.size() + _v2.size();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */