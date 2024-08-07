#include <iostream>

class Singleton
{
public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }

    void test() {
        std::cout << "A" << std::endl;
    }

private:
    Singleton(){};
    ~Singleton(){};

    Singleton(const Singleton&) = delete;
    Singleton(Singleton &&) = delete;
    Singleton operator=(const Singleton&) = delete;
    Singleton operator=(Singleton &&) = delete;
};


int main() {
    Singleton::getInstance().test();

    return 0;
}