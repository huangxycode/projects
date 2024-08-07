#include <iostream>

class Product{
public:
    double left;
    double right;
    virtual double cacl() = 0;
};

class Product_add : public Product {
    double cacl() override {
        return left + right;
    }
};

class Product_sub : public Product {
    double cacl() override {
        return left - right;
    }
};

class Product_mul : public Product {
    double cacl() override {
        return left * right;
    }
};

class Product_div : public Product {
    double cacl() override {
        return left / right;
    }
};

class Factory{
public:
    static Product* createProduct(char c){
        switch (c)
        {
        case '+':
            return new Product_add;
            break;

        case '-':
            return new Product_sub;
            break;

        case '*':
            return new Product_mul;
            break;

        case '/':
            return new Product_div;
            break;
        
        default:
            std::cout << "null" << std::endl;
            return 0;
            break;
        }
        return 0;
    }
};

int main() {
    Product * add = Factory::createProduct('+');
    add->left = 3;
    add->right = 4;
    std::cout << add->cacl() << std::endl;

    Product * sub = Factory::createProduct('-');
    sub->left = 3;
    sub->right = 4;
    std::cout << sub->cacl() << std::endl;

    Product * mul = Factory::createProduct('*');
    mul->left = 3;
    mul->right = 4;
    std::cout << mul->cacl() << std::endl;

    Product * div = Factory::createProduct('/');
    div->left = 3;
    div->right = 4;
    std::cout << div->cacl() << std::endl;

    Product * def = Factory::createProduct('=');
    def->left = 3;
    def->right = 4;
    std::cout << def->cacl() << std::endl;

    return 0;
}