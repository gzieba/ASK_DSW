#include "concreteMemento.h"
#include <ctime>

ConcreteMemento::ConcreteMemento(std::string _state)
: state(_state)
{
    std::time_t now = std::time(0);
    date = std::ctime(&now);
}

std::string ConcreteMemento::getName() const
{
    return date + " / (" + state.substr(0, 9) + "...)";
}

std::string ConcreteMemento::getDate() const
{
    return date;
}

std::string ConcreteMemento::getState() const
{
    return state;
}