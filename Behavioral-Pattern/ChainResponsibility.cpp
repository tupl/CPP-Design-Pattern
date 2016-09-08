/*




*/
#include <iostream>
#include <string>

class Burger {
public:
    int flour = 0;
    int vegetable = 0;

    Burger() {

    }

    ~Burger() {}

    void tell() const {
        std::cout << flour << " "
            << vegetable << std::endl;
    }
};

class Handler {
 private:
    Handler* next;
 public:

    Handler() {
        next = 0;
    }

    virtual ~Handler() {}

    void setNext(Handler* o_next) {
        next = o_next;
    }

    void add(Handler* o_next) {
        if (next) {
            next->add(o_next);
        } else {
            next = o_next;
        }
    }

    virtual void handle(Burger* burger) {
        if (next)
            next->handle(burger);
    }
};
class FlourHandler: public Handler {
 public:
    FlourHandler() {}
    ~FlourHandler() {}
    virtual void handle(Burger* burger) {
        burger->flour = 10;
        Handler::handle(burger);
    }
};

class VegetableHandler: public Handler {
 public:
    VegetableHandler() {}
    ~VegetableHandler() {}
    virtual void handle(Burger* burger) {
        burger->vegetable = 15;
        Handler::handle(burger);
    }
};

int main() {
    Burger burger;
    VegetableHandler vhler;
    FlourHandler fher;
    fher.add(&vhler);
    fher.handle(&burger);
    burger.tell();
    return 0;
}
