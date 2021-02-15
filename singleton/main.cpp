#include "singleton.h"
#include <iostream>

int main()
{
    std::cout << Singleton::instance().getAddress() << std::endl;
    std::cout << Singleton::instance().getAddress() << std::endl;
    return 0;
}