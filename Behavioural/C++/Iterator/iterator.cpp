#include <iostream>
#include <vector>
#include <string> 
using namespace std;

class Collection;

class Iterator {
    vector <int> ::iterator it;
    Collection *m_collection;
    public:

    Iterator(vector <int> &vec, Collection *c): it(vec.begin()), m_collection(c) {

    }

    vector <int> ::iterator next() {
        if(!hasNext())
            exit(0);

        return ++it;
    }
    bool hasNext();
    vector <int> ::iterator getData() {

        return it;
    }


};


class Collection {

    friend class Iterator;
    private:
    vector <int> arr;

    public:


    Collection() {
        
    } 

    void addData(int data) {
        arr.push_back(data);
    }

    Iterator* getIterator() {
        return new Iterator(arr, this);
    }
};


bool Iterator::hasNext() {
    
        return m_collection->arr.end() != it;
    
}


int main() {
    Collection *c = new Collection();

    c->addData(10);
    c->addData(20);
    c->addData(30);
    Iterator *it = c->getIterator();
    
    while(it->hasNext()) {
        cout << *(it->getData()) << endl;
        it->next();
    }
}