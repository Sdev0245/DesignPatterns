#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BaseState;

class Context {

    BaseState *state;
    public:

    Context(BaseState *st): state(nullptr) {
        this->setState(st);
    }


    void setState(BaseState *st);
};

class BaseState {

    public:
    
   virtual void transition(Context *) =0;
};

class ConcreteState: public BaseState {
    Context *ctx;
    public:
    void transition(Context *ctx) {
        this->ctx = ctx;
    }
};


void Context::setState(BaseState *st) {
    
    this->state = st;
    this->state->transition(this);
    
}
int main() {

    BaseState *st = new ConcreteState();

    Context *c = new Context(st);
    return 0;
}