#include <iostream>
#include <string>
#include <fstream>

class MyVector {
public:

    class iterator {
    private:
        int* _vec;
        int idx;
    public:
        iterator(int* o_vec, int o_idx);
        ~iterator();
        iterator operator++();
        int operator*();
        bool operator!=(iterator o_other);
        bool operator==(iterator o_other);
    };

    MyVector();
    ~MyVector();

    void push(int o_v);

    iterator begin();
    iterator end();

private:
    int tail = 0;
    int num[10];
};

MyVector::MyVector() {}
MyVector::~MyVector() {}

void MyVector::push(int o_v) {
    num[tail++] = o_v;
}

MyVector::iterator MyVector::begin() {
    return MyVector::iterator(num, 0);
}

MyVector::iterator MyVector::end() {
    return MyVector::iterator(num, tail);
}

MyVector::iterator::iterator(int* o_vec, int o_idx):
    _vec(o_vec), idx(o_idx) {}

MyVector::iterator::~iterator() {}

MyVector::iterator MyVector::iterator::operator++() {
    ++idx;
    return *this;
}

int MyVector::iterator::operator*() {
    return _vec[idx];
}

bool MyVector::iterator::operator!=(iterator o_other) {
    return idx != o_other.idx;
}

bool MyVector::iterator::operator==(iterator o_other) {
    return idx == o_other.idx;
}

int main() {
    MyVector v;
    v.push(5);
    v.push(3);
    v.push(2);
    for(auto it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << std::endl;
    }
    return 0;
}
