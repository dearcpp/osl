#include <gtest/gtest.h>
#include <queue.hpp>

using osl::u32;
using int_queue = osl::queue<int>;

#define INITIALIZER_LIST int_queue::initializer_list({ 1, 2, 3, 4, 5 })

TEST(Queue, push)
{
    int_queue queue;

    for (int_queue::size_type i = 0; i < INITIALIZER_LIST.size(); ++i)
    {
        queue.push(INITIALIZER_LIST.begin()[i]);
        EXPECT_EQ(queue.front(), INITIALIZER_LIST.begin()[i]);
    }
}

TEST(Queue, pop)
{
    int_queue queue;

    for (int_queue::size_type i = 0; i < INITIALIZER_LIST.size(); ++i)
    {
        queue.push(INITIALIZER_LIST.begin()[i]);
    }

    for (int_queue::size_type i = 0; i < INITIALIZER_LIST.size(); ++i)
    {
        EXPECT_EQ(queue.back(), INITIALIZER_LIST.begin()[i]);
        queue.pop();
    }
}

TEST(Queue, ctor_list)
{
    int_queue queue = INITIALIZER_LIST;

    for (int_queue::size_type i = 0; i < INITIALIZER_LIST.size(); ++i)
    {
        EXPECT_EQ(queue.back(), INITIALIZER_LIST.begin()[i]);
        queue.pop();
    }
}
