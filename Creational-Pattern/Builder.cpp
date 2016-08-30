/**
 * \brief This is a fun project that show a used case for Builder Pattern
 * Generally, Builder pattern can be think like we have abstract interface
 * for all of our object. To create an object, we dont want to initialize
 * it since it mays have a very complex initialized parameter. One way to
 * do it is to create a Builder. Each builder responsible for some type of
 * object.
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
