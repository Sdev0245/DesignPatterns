#include <iostream>
using namespace std;

class AbstractButton;
class AbstractButton{
    public:

    virtual void click() = 0;
};

class WindowsButton : public AbstractButton {

    public:
    void click() {
        cout << "Windows Button Clicked!!" << endl;
    }
};

class MacButton: public AbstractButton {
    public:
    void click()  {
        cout << "Mac Button Clicked!!" << endl;
    }
};


class AbstractButtonCreator {
    public:
    virtual  AbstractButton* createButton() = 0 ;
};

class WindowsButtonCreator: public  AbstractButtonCreator {
    public:

    AbstractButton* createButton() {
        // will create some specific type of button
        return new WindowsButton();
    }
};

class MacButtonCreator: public AbstractButtonCreator {
    public:
    AbstractButton* createButton() {
        return new MacButton();
    }
};

AbstractButton* clientCreator(string button){
    AbstractButton* newButton;
    if(button == "win") {
        AbstractButtonCreator* creator = new WindowsButtonCreator();
        newButton = creator->createButton();
    }
    else if(button == "mac") {
        AbstractButtonCreator* creator = new WindowsButtonCreator();
        newButton = creator->createButton();
    }

    return newButton;
}
int main() {

    AbstractButton *button = clientCreator("mac");
    button->click();
    
    return 0;
}