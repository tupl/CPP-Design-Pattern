/*
Idea of Composite is to represent object like a tree. This practice is used
in drawing object. The idea is top-down expand with different component.
However, it has to share the same basic interface. It's should recursively work
on it and expands it gradually. It's combination of Primitive and Composition.
When we expands the object, we expands it with top down approach.

Procedure:
- Define a base functionalities, called 'Primitive'
- Define composition functionalities, called 'Compositive'
*/
#include <string>
#include <iostream>
#include <vector>

class Entity {
public:
    Entity() {}
    virtual ~Entity() {}
    virtual void talk() = 0;
};

class Human: public Entity {
private:
    std::string name;
public:
    Human(std::string o_name): name(o_name) {}
    virtual void talk() {
        std::cout << "I'm a " << name << std::endl;
    }
};

class Room: public Entity {
private:
    std::vector<Entity*> _children;
public:
    Room() {}
    void addChildren(Entity* o_obj) {
        _children.push_back(o_obj);
    }
    virtual void talk() {
        std::cout << "This is a room" << std::endl;
        for(int i = 0; i < _children.size(); ++i) {
            _children[i]->talk();
        }
    }
};

class Castle: public Entity {
private:
    std::vector<Entity*> _children;
public:
    Castle() {}
    void addChildren(Entity* o_obj) {
        _children.push_back(o_obj);
    }
    virtual void talk() {
        std::cout << "This is a castle" << std::endl;
        for(int i = 0; i < _children.size(); ++i) {
            _children[i]->talk();
        }
    }
};

int main() {
    Castle castle;
    Room room1, room2;
    room1.addChildren(new Human("Adam"));
    room1.addChildren(new Human("Eve"));
    room2.addChildren(new Human("Wolf"));
    castle.addChildren(&room1);
    castle.addChildren(&room2);
    castle.talk();
    return 0;
}
