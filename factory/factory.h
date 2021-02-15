#pragma once
#include "classes.h"
#include <memory>

enum class ObjectType
{
    EntityOne,
    EntityTwo
};

class Factory
{
public:
    Factory() = default;
    
    std::unique_ptr<IInterface> create(ObjectType type);
};