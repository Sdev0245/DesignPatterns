#include <iostream>
#include <string>
using namespace std;


class AbstractNotifier {

    public:
    virtual void send() = 0;
};

class Notifier: public AbstractNotifier {

    public:

    void send() {
        cout << "Sending the email" << endl;
    }
};


class BaseNotifierDecorator: public AbstractNotifier {

    AbstractNotifier* _notifier;
    public:
    BaseNotifierDecorator(AbstractNotifier *notifier): _notifier(notifier) {
        
    }

    void send() {
        this->_notifier->send();
    }

};


class FaceBookNotifier: public BaseNotifierDecorator {  

    public: 

    FaceBookNotifier(AbstractNotifier *a): BaseNotifierDecorator(a) {

    }

    void send() {
        cout << "Sending Facebook Notification" << endl;
        BaseNotifierDecorator::send();
    }

};

int main() {

    AbstractNotifier *a = new Notifier();
    AbstractNotifier *simple = new BaseNotifierDecorator(a);
    AbstractNotifier *complex = new FaceBookNotifier(simple);
    complex->send();
    return 0;
}