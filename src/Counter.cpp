#include "Counter.hpp"

Counter::Counter()
:count(0)
{

}

Counter::Counter(int num)
:count(num)
{

}

Counter::Counter(const Counter& c)
:count(c.count)
{

}

Counter& Counter::operator =(const Counter& c)
{
    count = c.count;
    return *this;
}

Counter::~Counter()
{

}

void Counter::up(const int step)
{
    count += step;
}

void Counter::down(const int step)
{
    count -= step;
}

int Counter::getCount()
{
    return count;
}

void Counter::setCount(const int newCount)
{
    count = newCount;
}

Counter& Counter::operator ++()
{
    count++;
    return *this;
}

Counter& Counter::operator--()
{
    count--;
    return *this;
}

Counter Counter::operator ++(int)
{
    Counter c(count);
    count++;

    return c;
}

Counter Counter::operator--(int)
{
    Counter c(count);
    count--;
    return c;
}

std::ostream& operator <<(std::ostream& os, const Counter& c)
{
    os<<c.count;

    return os;
}
