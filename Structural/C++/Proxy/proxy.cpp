#include <iostream>
#include <string>
using namespace std;


class DatabaseInterface {

    public:

    virtual void write() = 0;
};

class Database: public DatabaseInterface {

    public:

    void write() {
        cout << "Writing to the database" << endl;
    }
};

class Proxy : public DatabaseInterface {

    DatabaseInterface* interface;

    public:

    Proxy(DatabaseInterface *interface){
        this->interface = interface;
    }

    bool haspermission() {
        return true;
    }

    void write() {

        if(this->haspermission())
            this->interface->write();
    }
};

int main() {


    DatabaseInterface *interface = new Database();
    Proxy *p = new Proxy(interface);

    p->write();
}