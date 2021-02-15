#include "adapter.h"
#include <iostream>

void clientCode(const std::unique_ptr<Target>& target)
{
    std::cout << target->request() << std::endl;
}

int main()
{
    auto target = std::make_unique<Target>();
    clientCode(target);

    auto adaptee = std::make_unique<Adaptee>();
    std::cout << adaptee->specificRequest() << std::endl;

    std::unique_ptr<Target> adapter = std::make_unique<Adapter>(std::move(adaptee));
    clientCode(adapter);

    return 0;
}