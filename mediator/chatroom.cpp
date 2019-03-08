#include "chatroom.h"
#include "client.h"

ChatRoom::ChatRoom() {}

void ChatRoom::RegisterClient(Client* client)
{
    if(!client)
        std::cout << "null" << std::endl;
    clients.emplace_back(client);
}

void ChatRoom::DisconnectClient(Client* client)
{
    auto client_to_disconnect = std::find(clients.begin(), clients.end(), client);
    clients.erase(client_to_disconnect);
}

void ChatRoom::Message(Client* origin, std::string& message)
{
    for (auto it : clients) {
        it->Recieve(origin, message, MessageType::BROADCAST);
    }
}

void ChatRoom::DirectMessage(Client* origin, std::string dest_name,
                             std::string& message)
{
    Client* destination = nullptr;
    for(auto it : clients)
    {
        if(dest_name == it->Name())
        {
            destination = it;
        }
    }
    destination->Recieve(origin, message, MessageType::DIRECT);
}
