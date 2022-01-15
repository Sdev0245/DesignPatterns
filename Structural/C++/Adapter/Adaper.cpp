#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;


class Target {
    public:
    virtual string Result() {
        return "This is a normal string";
    }
};


class Adaptee {

    public:
    string showSpecificResult() {
        return "This is specific result";
    }
};


class Adapter: public Target {

    Adaptee *adaptee;
    public:

    Adapter() {

    }

    void setAdaptee(Adaptee *a) {
        adaptee = a;
    }

    string Result() {
        string res = adaptee->showSpecificResult();
        return res;
    }
    
};

int main() {


    Adaptee* temp = new Adaptee();
    Adapter *a = new Adapter();

    a->setAdaptee(temp);
    cout << a->Result() << endl;
}