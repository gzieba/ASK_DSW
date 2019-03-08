#include "client.h"

int main()
{
    ChatRoom room;
    Client* john = new Client("john", &room);
    Client* adam = new Client("adam", &room);
    Client* frank = new Client("frank", &room);

    ChatRoom room2;
    Client* john2 = new Client("john2", &room2);
    Client* adam2 = new Client("adam2", &room2);
    Client* frank2 = new Client("frank2", &room2);

    john->Message("message1");
    std::cout << std::endl;
    john2->Message("message2");
    std::cout << std::endl;

    adam->DirectMessage("frank", "directMessage");
    return 0;
}
