#include <iostream>
#include <string>

using namespace std;

class IButton {

    public:
    
    virtual void click() = 0;
};

class MacButton: public IButton {

    public:
    void click() {
        cout << "Mac Button Clicked!!" << endl;
    }
};

class WinButton: public IButton {

    public:
    void click() {
        cout << "Win Button Clicked!!" << endl;
    }
};

class ICheckBox {

    public:
    
    virtual void click() = 0;
};

class WinCheckBox: public ICheckBox {

    public:
    void click() {
        cout << "Win Checkbox Clicked!!" << endl;
    }
};

class MacCheckBox: public ICheckBox {

    public:
    void click() {
        cout << "Mac Checkbox Clicked!!" << endl;
    }
};



class GUIFactory {

    public:
        virtual IButton* createButton() = 0;
        virtual ICheckBox* createCheckBox() = 0;


};

class WinGUI: public GUIFactory{

    public:
        IButton* createButton(){
            return new WinButton();
        }
        ICheckBox* createCheckBox(){

                return new WinCheckBox();
        }


};

class MacGUI: public GUIFactory{

    public:
        IButton* createButton(){
            return new MacButton();
        }
        ICheckBox* createCheckBox(){

                return new MacCheckBox();
        }


};


class Application {

    public:
    GUIFactory* createGUI(string type_val) {

        if(type_val == "mac")
            return new MacGUI();

        else
            return new WinGUI();
    }
};

int main() {

    string type_val;

    cin >> type_val;

    Application *app = new Application();
    GUIFactory *gui =  app->createGUI(type_val);

    IButton *btn = gui->createButton();
    ICheckBox *checkbox = gui->createCheckBox();
    btn->click();
    checkbox->click();
    return 0;

}