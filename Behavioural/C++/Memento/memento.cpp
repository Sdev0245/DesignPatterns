#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;
class IMemento {
   
    public:
    virtual string state() = 0;
};

class Mememento: public IMemento {
    string _state;
    public:
    Mememento() = delete;
    Mememento(string curr_state) {
        this->_state = curr_state;
    }
    string state() {
        return _state;
    }
};


class Editor {
    string _state;
    public:
    Editor(): _state("") {

    }

    void writeSomething(string data) {
        _state = _state + data;
    }

    IMemento* save() {
        return new Mememento(_state);
    }

    void backup(IMemento*  m) {
        this->_state = m->state();
    }

    void print_state() {
        cout << this->_state << endl;
    }


};




class Caretaker {
    stack <IMemento*> stk;
    Editor *editor;
    public:
    Caretaker(Editor *editor) {
        this->editor = editor;
    }

    void dosomething(string _data) {
        editor->writeSomething(_data);
    }

    void backup() {
        stk.push(this->editor->save());
    }

    void undo() {

        if(!stk.empty()) {
            IMemento *m = stk.top();
            this->editor->backup(m);
            stk.pop();
        }
    }

    void print_state() {
        this->editor->print_state();
    }
};
int main() {

    Editor *e = new Editor();
    Caretaker *c = new Caretaker(e);

    e->writeSomething("Hello I'am Deven ");
    c->backup();
    e->writeSomething("Hello I'am Deven ");
    c->print_state();
    c->backup();
    cout << "Undoing the state" << endl;
    c->undo();
    c->undo();
    c->print_state();
    return 0;  
}