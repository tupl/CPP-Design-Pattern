struct Call {
    int level;
};

class Employee {
 private:
    bool status;
 public:
    void handleCall(Call& c);
    bool isFree() {
        return status;
    }
};

class CallQueue {
 private:
    std::map<int, std::queue<Employee>> _levels;
    std::map<int, std::queue<Call>> _calls;
    CallQueue() {}
 public:
    Call getNextCall(int level);

    void putCall(Call& c) {
        _calls[c.level].push(c);
    }

    void dispatchCall(Call &c) {

    }
};
