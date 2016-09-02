/**
 * \brief it means reusing it when the creational operation is expensive. Another
 * thing is the clone the object with copy constructor
 */
#include <vector>
#include <string>
#include <iostream>
#include <memory>

class Human {
public:
    Human() {}
    void sayHello () const {
        std::cout << "I'm a good human." << std::endl;
    }
};

class Castle
{
private:
    Castle(const Castle &old) {} // stop copy constructor
    const Castle& operator=(const Castle &old) {} // stop assignment operator
    std::vector<Human> allHumans;
    Castle() {} // hide constructor
public:
    static Castle& instance() {
        static std::shared_ptr<Castle> ptr(new Castle);
        return *ptr;
    }

    void tell() const {
        for (const Human& h: allHumans) {
            h.sayHello();
        }
    }

    void addHuman(Human& h) {
        allHumans.push_back(h);
    }
};

int main() {
    Human h1, h2;
    Castle::instance().addHuman(h1);
    Castle::instance().addHuman(h2);
    Castle::instance().tell();
    return 0;
}
