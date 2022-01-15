#include <iostream>
#include <string> 
#include <vector>
#include <list>

using namespace std;

class Startegy {

    public:
    
    virtual int Doalgorithm(vector <int>) = 0;
};

class Context {
    Startegy* strategy;
    public:

    Context() {

    }

    void setStrategy(Startegy *newStrategy) {
        this->strategy = newStrategy;
    }

    int runAlgorthim() {
        vector <int> arr;
        arr.push_back(10);
        arr.push_back(20);
        arr.push_back(41);

        return this->strategy->Doalgorithm(arr);
    }

};


class ConcreteStrategyA: public Startegy {

    public:
     int Doalgorithm(vector <int> arr) {
         int sum = 0;

         for(int i = 0 ; i< arr.size() ; i++) {
             int x = arr[i];
             if(x%2)
                sum = sum + x;
         }
         return sum;
     }
};
class ConcreteStrategyB: public Startegy {

    public:
     int Doalgorithm(vector <int> arr) {
         int sum = 0;

         for(int i = 0 ; i< arr.size() ; i++) {
             int x = arr[i];
             if(x%2 == 0)
                sum = sum + x;
         }
         return sum;
     }
};

int main() {

    Context *c = new Context();
    ConcreteStrategyA *s = new ConcreteStrategyA();
    c->setStrategy(s);
    cout << c->runAlgorthim() << endl;
    ConcreteStrategyB *x = new ConcreteStrategyB();

    c->setStrategy(x);
    cout << c->runAlgorthim() << endl;
    return 0;
}