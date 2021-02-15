#pragma once
#include "memento.h"

class ConcreteMemento : public Memento
{
public:
    ConcreteMemento(std::string state);
    virtual ~ConcreteMemento() = default;

    std::string getName() const override;
    std::string getDate() const override;
    std::string getState() const override;

private:
    std::string state;
    std::string date;
};