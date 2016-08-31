#include <iostream>
#include <string>

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

class CharacterFactory {
private:
    CharacterFactory() {}
public:
    static Character* create(const std::string& desc) {
        if (desc == "human") return new Human;
        if (desc == "evil") return new Evil;
    }
};

int main() {
    (CharacterFactory::create("human"))->sayHello();
    (CharacterFactory::create("evil"))->sayHello();
    return 0;
}
