#include <gtest/gtest.h>
#include <deque.hpp>

using osl::u32;
using int_deque = osl::deque<int>;

#define INITIALIZER_LIST int_deque::initializer_list({ 1, 2, 3, 4, 5 })

TEST(Deque, push_front)
{
    int_deque deque = INITIALIZER_LIST;

    for (int_deque::size_type i = 0; i < INITIALIZER_LIST.size(); ++i)
    {
        deque.push_front(INITIALIZER_LIST.begin()[i]);
        EXPECT_EQ(deque.front(), INITIALIZER_LIST.begin()[i]);
    }
}

TEST(Deque, push_back)
{
    int_deque deque = INITIALIZER_LIST;

    for (int_deque::size_type i = 0; i < INITIALIZER_LIST.size(); ++i)
    {
        deque.push_back(INITIALIZER_LIST.begin()[i]);
        EXPECT_EQ(deque.back(), INITIALIZER_LIST.begin()[i]);
    }
}

TEST(Deque, pop_front)
{
    int_deque deque;

    for (int_deque::size_type i = 0; i < INITIALIZER_LIST.size(); ++i)
    {
        deque.push_back(INITIALIZER_LIST.begin()[i]);
    }

    for (int_deque::size_type i = 0; i < INITIALIZER_LIST.size(); ++i)
    {
        EXPECT_EQ(deque.front(), INITIALIZER_LIST.begin()[i]);
        deque.pop_front();
    }
}

TEST(Deque, pop_back)
{
    int_deque deque;

    for (int_deque::size_type i = 0; i < INITIALIZER_LIST.size(); ++i)
    {
        deque.push_front(INITIALIZER_LIST.begin()[i]);
    }

    for (int_deque::size_type i = 0; i < INITIALIZER_LIST.size(); ++i)
    {
        EXPECT_EQ(deque.back(), INITIALIZER_LIST.begin()[i]);
        deque.pop_back();
    }
}

TEST(Deque, ctor_list)
{
    int_deque deque = INITIALIZER_LIST;

    for (int_deque::size_type i = 0; i < INITIALIZER_LIST.size(); ++i)
    {
        EXPECT_EQ(deque.front(), INITIALIZER_LIST.begin()[i]);
        deque.pop_front();
    }
}

TEST(Deque, operator_brackets)
{
    int_deque deque = INITIALIZER_LIST;

    for (int_deque::size_type i = 0; i < INITIALIZER_LIST.size(); ++i)
    {
        EXPECT_EQ(deque[i], INITIALIZER_LIST.begin()[i]);
    }
}
