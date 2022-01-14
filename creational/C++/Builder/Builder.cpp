#include <iostream>
#include <vector>
#include <string>
using namespace std;
class AbstractBuilder {

    public:

    virtual void producePartA() = 0;
    virtual void producePartB() = 0;
    virtual void producePartC() = 0;
    virtual void printAllValues() = 0;
};

class Product {
    private:
        vector <string> s;
    public:
    
    Product() {

    }

    void addPart(string part) {
        s.__emplace_back(part);
        return ;
    }

    void printAllValues() {
        for(int i = 0 ; i< s.size() ; i ++) {
            cout << s[i] << endl;
        }
    }



};

class ConcreteBuilder : public AbstractBuilder {

    Product *p;

    public:

        ConcreteBuilder() {

            p = new Product();
        }
        void producePartA(){
            p->addPart("part_a");
        }
        void producePartB(){
           p->addPart("part_b"); 
        }

        void producePartC(){
            p->addPart("part_c"); 
        }

        void printAllValues() {
            p->printAllValues();
        }

};

class Director {

    AbstractBuilder *builder;

    public:

    Director() {

      
    }

    void setBuilder(AbstractBuilder *m) {
        builder = m;
    }

    void buildMVP(){
        builder->producePartA();
    }

    void buildFullProduct() {
        builder->producePartA();
        builder->producePartB();
        builder->producePartC();
    }
};



void client(Director &director) {

    AbstractBuilder *builder = new ConcreteBuilder();
    director.setBuilder(builder);

    director.buildFullProduct();
    builder->printAllValues();
    
}

int main() {
    Director d;
    client(d);
    return 0;
}