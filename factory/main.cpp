#include "factory.h"
#include "classes.h"

#include <iostream>

int main()
{
    auto factory = Factory();
    auto obj1 = factory.create(ObjectType::EntityOne);
    std::cout << obj1->getName() << std::endl;
    auto obj2 = factory.create(ObjectType::EntityTwo);
    std::cout << obj2->getName() << std::endl;
    return 0;
}