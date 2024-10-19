#include <iostream>

class Test{
public:
    Test(){
        std::cout << "Konstruktor" << std::endl;
    }

    ~Test(){
        std::cout << "Destruktor" << std::endl;
    }
};

int main(void){
    Test t;
    return 0; // destruktor se javlja ovdje
}