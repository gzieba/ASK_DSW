#pragma once
#include <string>

class Memento
{
public:
    virtual ~Memento() = default;
    virtual std::string getName() const = 0;
    virtual std::string getDate() const = 0;
    virtual std::string getState() const = 0;
};