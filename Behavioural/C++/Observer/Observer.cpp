#include <iostream>
#include <string> 
#include <vector>
#include <list>

using namespace std;

class IObserver {
    public:

    virtual void update(string messgae) = 0;
};

class Observer: public IObserver {

    public:

    Observer() {

    }
    void update(string message){
        cout << message << endl;
    }
};

class Publisher {

    list <IObserver*> observers;
    public:
    Publisher() {

    }

    void addObserver(IObserver *observer) {
        observers.push_back(observer);
    }

    void notify(string message) {
        
        list <IObserver*>:: iterator it = observers.begin();

        while(it != observers.end()) {
            (*it)->update(message);
            it++;
        }
    }

    void remove(IObserver *obs) {
        observers.remove(obs);
    }


};
int main() {

    Publisher *p = new Publisher();
    IObserver *obs1 = new Observer();
    IObserver *obs2 = new Observer();
    p->addObserver(obs2);
    p->addObserver(obs1);
    p->notify("Your order has arrived.....");

    return 0;
}