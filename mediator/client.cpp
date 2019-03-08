#include "client.h"

Client::Client(std::string&& name, ChatRoom* room) : name(name), room(room)
{
    room->RegisterClient(this);
}

Client::~Client()
{
    room->DisconnectClient(this);
}

void Client::Recieve(Client* author, std::string& message, MessageType type)
{
    if(type == MessageType::DIRECT)
        std::cout << author->Name() << " whispers: " << message << " to: " << this->Name() << std::endl;
    else
        std::cout << author->Name() << ": " << message << " to: " << this->Name() << std::endl;
}

void Client::Message(std::string&& message)
{
    room->Message(this, message);
}

void Client::DirectMessage(std::string destination_name, std::string&& message)
{
    room->DirectMessage(this, destination_name, message);
}
