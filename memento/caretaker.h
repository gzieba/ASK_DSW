#pragma once
#include "memento.h"
#include "originator.h"
#include <vector>
#include <memory>

class Caretaker
{
public:
    Caretaker(std::shared_ptr<Originator> originator);
    void backup();
    void undo();
    void showHistory() const;

private:
    std::vector<std::shared_ptr<Memento>> mementos;

    std::shared_ptr<Originator> originator;

};