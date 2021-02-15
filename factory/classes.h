#pragma once

#include <string>

class IInterface
{
public:
    virtual ~IInterface() = default;
    virtual std::string getName() const = 0;
};

class EntityOne : public IInterface
{
public:
    virtual ~EntityOne() = default;
    virtual std::string getName() const override
    {
        return "EntityOne";
    }
};

class EntityTwo : public IInterface
{
public:
    virtual ~EntityTwo() = default;
    virtual std::string getName() const override
    {
        return "EntityTwo";
    }
};