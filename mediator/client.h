#ifndef CLIENT_H
#define CLIENT_H

#include <string>

#include "chatroom.h"

class Client {
    std::string name;
    ChatRoom* room = nullptr;

public:
    Client(std::string&& name, ChatRoom* room);
    ~Client();
    void Recieve(Client *author, std::string &message, MessageType type);
    void Message(std::string&& message);
    void DirectMessage(std::string destination_name, std::string&& message);
    std::string Name() { return name; }
};

#endif // CLIENT_H
