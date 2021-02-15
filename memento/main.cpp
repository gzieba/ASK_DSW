#include "caretaker.h"
#include "originator.h"
#include "memento.h"
#include <iostream>
#include <ctime>

void clientCode()
{
    auto originator = std::make_shared<Originator>("ASD");
    auto caretaker = std::make_unique<Caretaker>(originator);
    caretaker->backup();
    originator->doStuff();
    caretaker->backup();
    originator->doStuff();
    caretaker->backup();
    originator->doStuff();
    std::cout << "reverting" << std::endl;
    caretaker->undo();
    caretaker->undo();
 }

 int main()
 {
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    clientCode();
    return 0;
 }