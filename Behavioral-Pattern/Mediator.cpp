/*
- Identify a collection of object benefit from mutual decoupling
- Encapsulate these class into new class
- make all class work together

*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Handler {
public:
    Handler() {}
    virtual ~Handler() {}
    virtual void receive(std::string message) = 0;
};

class Mediator {
private:
    std::unordered_map<std::string, std::vector<Handler*>> _unordMap;
    Mediator () {}
public:
    static Mediator& instance() {
        static Mediator* singletonMediator = new Mediator;
        return *singletonMediator;
    }

    void subscribe(std::string channel, Handler* handle) {
        _unordMap[channel].push_back(handle);
    }

    void send(Handler* handler, std::string channel, std::string message) {
        auto it = _unordMap.find(channel);
        if (it != _unordMap.end()) {
            std::vector<Handler*> handlers(it->second);
            for(auto iter = handlers.begin(); iter != handlers.end(); ++iter) {
                if (*iter != handler) {
                    (*iter)->receive(message);
                }
            }
        }
    }
};

class Student: public Handler {
private:
    std::string mess;
public:
    Student(std::string o_mess): mess(o_mess) {}
    void receive(std::string message) {
        std::cout << "Student " << mess << " received " << message << std::endl;
    }

    void talk(std::string o_message) {
        Mediator::instance().send(this, "STUDENT_CHANNEL", o_message);
    }
};

int main() {
    Student std1("1");
    Student std2("2");
    Mediator::instance().subscribe("STUDENT_CHANNEL", &std1);
    Mediator::instance().subscribe("STUDENT_CHANNEL", &std2);
    std1.talk("Haha");
    std2.talk("Yaya");
    return 0;
}
