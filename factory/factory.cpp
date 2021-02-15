#include "factory.h"
#include <stdexcept>
#include <iostream>

std::unique_ptr<IInterface> Factory::create(ObjectType type)
{
    switch (type)
    {
    case ObjectType::EntityOne:
        return std::make_unique<EntityOne>();
    case ObjectType::EntityTwo:
        return std::make_unique<EntityTwo>();
    default:
    {
        std::cout << "Unsupported type" << std::endl;
        std::__throw_bad_typeid;
        return std::unique_ptr<IInterface>();
    }
    }
}