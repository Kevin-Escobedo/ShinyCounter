#include <gtest/gtest.h>
#include "../src/Counter.hpp"

TEST(counter_tests, canConstructWithDefaultArguments)
{
    Counter c;
    EXPECT_EQ(c.getCount(), 0);
}

TEST(counter_tests, canConstructWithArgument)
{
    Counter c(10);
    EXPECT_EQ(c.getCount(), 10);
}

TEST(counter_tests, canConstructFromOtherCounter)
{
    Counter c(100);
    Counter d(c);

    EXPECT_EQ(d.getCount(), c.getCount());
}

TEST(counter_tests, testAssignment)
{
    Counter c(20);
    Counter d = c;

    EXPECT_EQ(d.getCount(), c.getCount());
}

TEST(counter_tests, canAddToCounter)
{
    Counter c;
    c.up(10);
    c.up(5);
    c.up(5);

    EXPECT_EQ(c.getCount(), 20);
}

TEST(counter_tests, canSubtractFromCounter)
{
    Counter c;
    c.down(5);
    c.down(10);
    c.down(5);

    EXPECT_EQ(c.getCount(), -20);
}

TEST(counter_tests, testGetCount)
{
    Counter c;

    for(int i = 0; i <= 1000; i++)
    {
        EXPECT_EQ(c.getCount(), i);
        c.up(1);
    }
}

TEST(counter_tests, testSetCount)
{
    Counter c;
    EXPECT_EQ(c.getCount(), 0);

    c.setCount(10);
    EXPECT_EQ(c.getCount(), 10);

    c.setCount(1000);
    EXPECT_EQ(c.getCount(), 1000);

    c.setCount(0);
    EXPECT_EQ(c.getCount(), 0);

    c.setCount(-10);
    EXPECT_EQ(c.getCount(), -10);
}

TEST(counter_tests, testPrefixIncrement)
{
    Counter c;
    EXPECT_EQ(c.getCount(), 0);
    Counter d = ++c;

    EXPECT_EQ(d.getCount(), 1);
    EXPECT_EQ(c.getCount(), 1);
}

TEST(counter_tests, testPostfixIncrement)
{
    Counter c;
    EXPECT_EQ(c.getCount(), 0);

    Counter d = c++;

    EXPECT_EQ(d.getCount(), 0);
    EXPECT_EQ(c.getCount(), 1);
}

TEST(counter_tests, testPrefixDecrement)
{
    Counter c;
    EXPECT_EQ(c.getCount(), 0);
    Counter d = --c;

    EXPECT_EQ(d.getCount(), -1);
    EXPECT_EQ(c.getCount(), -1);
}

TEST(counter_tests, testPostfixDecrement)
{
    Counter c;
    EXPECT_EQ(c.getCount(), 0);

    Counter d = c--;

    EXPECT_EQ(d.getCount(), 0);
    EXPECT_EQ(c.getCount(), -1);
}
