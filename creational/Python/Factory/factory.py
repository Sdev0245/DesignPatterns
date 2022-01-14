import abc 


class FactoryButtonCreator:
    @abc.abstractmethod
    def create(self):
        pass


class WindowsButtonCreator(FactoryButtonCreator):
    def create(self):
        return WindowsButton()
        



class MacButtonCreator(FactoryButtonCreator):
    def create(self):
        return MacButton()


class Button:
    @abc.abstractmethod
    def performOperation(self):
        pass

class WindowsButton(Button):
    def performOperation(self):
        print("Windows Button clicked !!")



class MacButton(Button):
    def performOperation(self):
        print("Mac Button clicked !!")






if __name__ == '__main__':
    btn = WindowsButtonCreator().create()
    btn.performOperation()