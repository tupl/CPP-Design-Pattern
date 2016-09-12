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
    static CallQueue& instance() {
        static cQueue = CallQueue();
        return cQueue;
    }

    Call getNextCall(int level) {
        if (!_calls[level].empty()) {
            Call c = _calls[level].front();
            _calls[level].pop();
            return c;
        }
        return nullptr;
    }

    void putCall(Call& c) {
        _calls[c.level].push(c);
    }

    void dispatchCall(Call &c) {
        int currentLevel = _levels[c.level];
        for(int i = 0; i < currentLevel.size(); ++i) {
            int employee = currentLevel[i];
            if (employee.isFree()) {
                employee.handleCall(c);
                return;
            }
        }
        putCall(c);
    }
};
