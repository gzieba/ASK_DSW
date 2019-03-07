#include <functional>
#include <algorithm>
#include <iostream>
#include <memory>
#include <thread>
#include <vector>
#include <queue>

#ifndef LEVEL1_DCACHE_LINESIZE
#define CACHE_LINESIZE 64
#elif
#define CACHE_LINESIZE LEVEL1_DCACHE_LINESIZE
#endif

struct Observer
{
    virtual void Update(const unsigned int& val)
    {
        std::cout << "Prime: " << val << "\n" << std::flush;
    }

    virtual ~Observer() {}
};

struct Subject
{
    std::vector<Observer*> observers;

    virtual ~Subject() {}

    virtual void AttachObserver(Observer* observer)
    {
        observers.emplace_back(observer);
    }

    virtual void DetachObserver(Observer* observer)
    {
        auto it = std::find(observers.begin(), observers.end(), observer);
        if(it != observers.end())
        {
            observers.erase(it);
        }
    }

    virtual void NotifyObservers(const unsigned int& val)
    {
        for(auto it : observers)
        {
            it->Update(val);
        }
    }
};

struct Primes : Subject
{

    void IsPrime(const unsigned int& val)
    {
        if(val <= 0)
            return;
        if(val == 1 || val == 2)
        {
            NotifyObservers(val);
            return;
        }
        for(unsigned int i = 3; i < val / 2 + 1; i++)
        {
            if(val % i == 0)
                return;
        }
        NotifyObservers(val);
        return;
    }
};

struct Queue
{
    std::queue<unsigned int> queue;
    unsigned int i;

    Queue()
    {
        i = 0;
        do
        {
            queue.emplace(++i);
        }while(i <= CACHE_LINESIZE / sizeof(unsigned int));
    }

    unsigned int Dequeue()
    {
        queue.emplace(++i);
        auto tmp = queue.front();
        queue.pop();
        return tmp;
    }

    bool Empty()
    {
        return queue.empty();
    }
};

void Primes_Wrapper(Queue queue)
{
    Observer* observer = new Observer();
    Primes prime;

    prime.AttachObserver(observer);

    while(!queue.Empty())
        prime.IsPrime(queue.Dequeue());

    prime.DetachObserver(observer);

    delete observer;
}

void main_fun(int number_of_threads)
{
    Queue queue;
    std::vector<std::thread> vec_t;

    for(int i = 0; i < number_of_threads; i++)
    {
        vec_t.emplace_back(std::thread(Primes_Wrapper, queue));
    }

    for(unsigned long i = 0; i < vec_t.size(); i++)
    {
        vec_t[i].join();
    }
}

void ParseArguments(int argc, char **argv, int& cpus)
{
    if(argc > 1)
        cpus = (int) *argv[1] - 48;
}

int main(int argc, char **argv)
{
    int number_of_threads = 1;

    ParseArguments(argc, argv, number_of_threads);

    main_fun(number_of_threads);

    return 0;
}
