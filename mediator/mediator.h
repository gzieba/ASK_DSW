#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <string>

class Client;

struct Mediator {
    virtual ~Mediator() {}
    virtual void Message(Client* origin, std::string& message) = 0;
    virtual void DirectMessage(Client* origin, std::string dest_name,
                             std::string& message) = 0;
};

#endif // MEDIATOR_H
