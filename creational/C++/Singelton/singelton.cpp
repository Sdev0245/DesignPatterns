#include <iostream>
#include <string>
#include <map>
#include <thread>
using namespace std;

class Singelton {
    private:
    static Singelton* instance;
    static std::mutex m; 
    Singelton() {

    }

    public:

    static Singelton *getInstance() {

        lock_guard <mutex> lock(m);
        if(instance == NULL) {

            instance = new Singelton();
        }        
        return instance;

    }

};


Singelton* Singelton:: instance = NULL;
std::mutex Singelton:: m;

void thread_a() {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singelton *instance = Singelton::getInstance();
    cout << instance << endl;
    return ;
}


void thread_b() {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singelton *instance = Singelton::getInstance();
    cout << instance << endl;
    return ;
}

int main(){
    thread a(thread_a);
    thread b(thread_b);

    a.join();
    b.join();
    return 0;
}