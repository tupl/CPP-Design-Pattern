/*
+ Purpose: Extend functionalities of an object by keep
decorating object with new stuff. The approach is
bottom-up approach.

+ Procedure:
- Base Class
- Decorator inherits Base
- (Optional) a list of Exteneds Decorator
- Each Optional called its wrapper before called itself

+ Example:
- Human
- Human with gun
- Human with handknife
- Human with both gun and handknife

+ Reference:
- https://sourcemaking.com/design_patterns/structural_patterns
*/
#include <string>
#include <iostream>

class Entity {
public:
    Entity() {}
    virtual ~Entity() {}
    virtual void talk() const = 0;
};

class Human: public Entity {
private:
    std::string _name;
public:
    Human(std::string o_name): _name(o_name) {}
    virtual void talk() const {
        std::cout << "I'm " << _name;
    }
};

class Decorator: public Entity {
private:
    Entity* _entity;
public:
    Decorator(Entity * o_entity): _entity(o_entity) {}
    ~Decorator () {
        delete _entity;
    }
    virtual void talk() const {
        _entity->talk();
    }
};

class KnifeDecorator: public Decorator {
public:
    KnifeDecorator(Entity* o_entity): Decorator(o_entity) {}
    virtual void talk() const {
        Decorator::talk();
        std::cout << " with knife";
    }
};

class GunDecorator: public Decorator {
public:
    GunDecorator(Entity* o_entity): Decorator(o_entity) {}
    virtual void talk() const {
        Decorator::talk();
        std::cout << " with gun";
    }
};

int main() {
    Entity* humanOnly = new Human("Adam");
    Entity* humanWithGun = new GunDecorator(new Human("Adam"));
    Entity* humanWithKnife = new KnifeDecorator(new Human("Adam"));
    Entity* humanWithGunKnife = new KnifeDecorator(
            new GunDecorator(
                new Human("Adam")
            )
        );
    humanOnly->talk();
    std::cout << std::endl;
    humanWithGun->talk();
    std::cout << std::endl;
    humanWithKnife->talk();
    std::cout << std::endl;
    humanWithGunKnife->talk();
    std::cout << std::endl;
    return 0;
}
