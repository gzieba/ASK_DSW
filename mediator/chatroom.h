#ifndef CHATROOM_H
#define CHATROOM_H

#include <iostream>
#include <algorithm>
#include <vector>

#include "mediator.h"

enum MessageType { DIRECT, BROADCAST };

class ChatRoom : public Mediator {

    std::vector<Client*> clients;

public:
    ChatRoom();

    void RegisterClient(Client* client);
    void DisconnectClient(Client* client);
    void Message(Client* origin, std::string& message) override;
    void DirectMessage(Client* origin, std::string dest_name,
                       std::string& message) override;
};

#endif // CHATROOM_H
