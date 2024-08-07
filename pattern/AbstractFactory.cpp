#include <iostream>
#include <math.h>

class Product {
    virtual double cacl() = 0;
};

class add : public Product {

};

class sub : public Product {

};

class mul : public Product {

};

class div1 : public Product {

};

class single_digit_add : public add {
public:
    double number;
    double cacl() override {
        return number + number;
    }
};

class double_digit_add : public add {
public:
    double left;
    double right;
    double cacl() override {
        return left + right;
    }
};

class single_digit_sub : public sub {
public:
    double number;
    double cacl() override {
        return number - number;
    }
};

class double_digit_sub : public sub {
public:
    double left;
    double right;
    double cacl() override {
        return left - right;
    }
};

class single_digit_mul : public mul {
public:
    double number;
    double cacl() override {
        return number * number;
    }
};

class double_digit_mul : public mul {
public:
    double left;
    double right;
    double cacl() override {
        return left * right;
    }
};

class single_digit_div : public div1 {
public:
    double number;
    double cacl() override {
        return number / number;
    }
};

class double_digit_div : public div1 {
public:
    double left;
    double right;
    double cacl() override {
        return left / right;
    }
};

class Factory {
public:
    virtual add* create_add() = 0;
    virtual sub* create_sub() = 0;
    virtual mul* create_mul() = 0;
    virtual div1* create_div() = 0;
};

class single_digit_factory : public Factory {
    add* create_add() {
        return new single_digit_add;
    }

    sub* create_sub(){
        return new single_digit_sub;
    }

    mul* create_mul(){
        return new single_digit_mul;
    }

    div1* create_div(){
        return new single_digit_div;
    }
};

class double_digit_factory : public Factory {
    add* create_add() {
        return new double_digit_add;
    }

    sub* create_sub(){
        return new double_digit_sub;
    }

    mul* create_mul(){
        return new double_digit_mul;
    }

    div1* create_div(){
        return new double_digit_div;
    }
};



int main() {
    Factory * factory = new single_digit_factory;
    add* a = factory->create_add();
    a->number = 3;
    a->cacl();
    sub* s = factory->create_sub();

    return 0;
}