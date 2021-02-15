#include "originator.h"
#include <iostream>
#include "concreteMemento.h"

Originator::Originator(std::string _state)
: state(_state)
{
    std::cout << "Initial state: " << state << std::endl;
}

void Originator::doStuff()
{
    std::cout << "Originator: doing" << std::endl;
    state = genRandomString(30);
    std::cout << "Originator: changed: " << state << std::endl;
}

std::shared_ptr<Memento> Originator::save()
{
    return std::make_shared<ConcreteMemento>(state);
}

void Originator::restore(std::shared_ptr<Memento> memento)
{
    state = memento->getState();
    std::cout << "Originator: changed: " << state << std::endl;
}

std::string Originator::genRandomString(int len)
{
    const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    int stringLength = sizeof(alphanum) - 1;

    std::string random_string;
    for (int i = 0; i < len; i++) {
      random_string += alphanum[std::rand() % stringLength];
    }
    return random_string;
}