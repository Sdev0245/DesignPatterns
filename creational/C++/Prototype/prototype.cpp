#include <iostream>
#include <string> 
#include <map>

using namespace std;

class Shape {
    public:
    virtual Shape* Clone() = 0;
    virtual void PrintValues() = 0;
};

enum Shapes {
    RECTANGLE_SHAPE=1,
    CIRCLE_SHAPE
};
class Rectangle: public Shape {

    public:
    int len, bre;
    Rectangle(int len, int bre): len(len), bre(bre) {

    }
    void PrintValues() {
        cout << this->len << " " << this->bre << endl;
    }
    Shape* Clone() {
        return new Rectangle(*this);
    }
};

class Circle: public Shape {

    public:
    int radius;
    Circle(int radiud): radius(radiud) {

    }
    void PrintValues() {
        cout << this->radius << endl;
    }
    Shape* Clone() {
        return new Circle(*this);
    }
};

class PrototyeRegistry {

    public:
    map <int, Shape*> mp;
    PrototyeRegistry() {
        
        mp[RECTANGLE_SHAPE] = new Rectangle(10, 20);
        mp[CIRCLE_SHAPE] = new Circle(10);
    }

    Shape* createPrototype(Shapes shape) {
        return mp[shape]->Clone();
    }
};

int main() {

    PrototyeRegistry *reg = new PrototyeRegistry();
    Shape *s = reg->createPrototype(RECTANGLE_SHAPE);
    s->PrintValues();
    return 0;
}