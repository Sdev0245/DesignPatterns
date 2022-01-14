import abc
from itertools import product

class ProductA:
    list_content = []

    def print_all_values(self):
        for content in self.list_content:
            print(content)
    
    def add_part(self, part):
        self.list_content.append(part)



class AbstractBuilder:
    @abc.abstractmethod
    def add_part_a(self):
        pass

    @abc.abstractmethod
    def add_part_b(self):
        pass

    @abc.abstractmethod
    def add_part_c(self):
        pass
    
    @abc.abstractmethod
    def print_values(self):
        pass



class ConcreteBuilder(AbstractBuilder):
    product: ProductA

    def __init__(self) -> None:
        self.product = ProductA()
    
    def add_part_a(self):
        self.product.add_part("part_a")
    
    def add_part_b(self):
        self.product.add_part("part_b")

    def add_part_c(self):
        self.product.add_part("part_c")
    
    def print_values(self):
        self.product.print_all_values()



class Director:
    builder: AbstractBuilder

    def set_builder(self, m_builder):
        self.builder = m_builder

    def build_mvp(self):
        self.builder.add_part_a()
    
    def build_full_product(self):
        self.builder.add_part_a()
        self.builder.add_part_b()
        self.builder.add_part_c()




def client(director: Director):
    concrete_product: ConcreteBuilder = ConcreteBuilder()
    director.set_builder(concrete_product)

    director.build_full_product()
    concrete_product.print_values()


if __name__ == '__main__':
    director = Director()
    client(director)
