#pragma once
#include "memento.h"
#include <memory>

class Originator
{
public:
    Originator(std::string state);
    void doStuff();
    std::shared_ptr<Memento> save();
    void restore(std::shared_ptr<Memento> memento);

private:
    std::string genRandomString(int len = 10);

    std::string state;
};