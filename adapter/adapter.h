#pragma once
#include "adaptee.h"
#include "target.h"
#include <memory>

class Adapter : public Target
{
public:
    Adapter(std::unique_ptr<Adaptee>&& adaptee);
    std::string request() const override;

private:
    std::unique_ptr<Adaptee> adaptee;
};