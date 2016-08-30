/**
 * \brief
 *
 *
 *
 *
 *
 */
#include <iostream>

class Character {
public:
    virtual ~Character() {};
    virtual void sayHello() const = 0;
};

class Human: public Character {
public:
    ~Human () {}
    void sayHello() const {
        std::cout << "I'm a human" << std::endl;
    }
};

class Evil: public Character {
public:
    ~Evil () {}
    void sayHello() const {
        std::cout << "I'm an evil" << std::endl;
    }
};

class Builder {
public:
    virtual ~Builder() {}
    virtual Character* build() = 0;
};

class HumanBuilder: public Builder {
public:
    Character* build() {
        return new Human;
    }
};

class EvilBuilder: public Builder {
public:
    Character* build() {
        return new Evil;
    }
};

int main() {
    Builder* bdler = new HumanBuilder();
    (bdler->build())->sayHello();
    bdler = new EvilBuilder();
    (bdler->build())->sayHello();
    return 0;
}
