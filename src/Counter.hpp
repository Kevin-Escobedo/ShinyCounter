#ifndef COUNTER_HPP
#define COUNTER_HPP

#include <iostream>

class Counter
{
private:
    int count;

public:
    Counter();
    Counter(int num);
    Counter(const Counter& c);
    Counter& operator =(const Counter& c);
    ~Counter();
    void up(const int step);
    void down(const int step);
    int getCount();
    void setCount(const int newCount);
    Counter& operator ++(); //Prefix
    Counter operator ++(int); //Postfix
    Counter& operator --();
    Counter operator --(int);
    friend std::ostream& operator <<(std::ostream& os, const Counter& c);
};

#endif /* COUNTER_HPP */
