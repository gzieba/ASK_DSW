#include "adapter.h"
#include <algorithm>

Adapter::Adapter(std::unique_ptr<Adaptee>&& _adaptee)
: adaptee(std::move(_adaptee))
{

}

std::string Adapter::request() const
{
    auto reverse = adaptee->specificRequest();
    std::reverse(reverse.begin(), reverse.end());
    return "Adapter: " + reverse;
}