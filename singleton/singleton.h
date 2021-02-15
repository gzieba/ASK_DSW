#pragma once

class Singleton
{
public:
    static Singleton& instance()
    {
        static Singleton instance;
        return instance;
    }

    auto getAddress() const
    {
        return &(*this);
    }

private:
    Singleton() = default;
    Singleton(const Singleton&) = delete;
    void operator=(const Singleton&) = delete;
};