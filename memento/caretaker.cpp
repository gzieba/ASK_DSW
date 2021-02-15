#include "caretaker.h"
#include <iostream>

Caretaker::Caretaker(std::shared_ptr<Originator> _originator)
: originator(_originator)
{

}

void Caretaker::backup()
{
    std::cout << "Caretaker: saving state" << std::endl;
    mementos.push_back(originator->save());
}

void Caretaker::undo()
{
    if(!mementos.size())
        return;
    auto memento = mementos.back();
    mementos.pop_back();
    std::cout << "Caretaker: restoring to: " << memento->getName() << std::endl;
    try
    {
        originator->restore(memento);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        undo();
    }
}

void Caretaker::showHistory() const
{
    std::cout << "Caretaker: list of mementos: " << std::endl;
    for(const auto& memento : mementos)
        std::cout << memento->getName() << std::endl;
}