#include <gtest/gtest.h>
#include <vector.hpp>

using int_vector = osl::vector<int>;

#define INITIALIZER_LIST int_vector::initializer_list({ 1, 2, 3, 4, 5 })

TEST(Vector, push_front)
{
    int_vector vector;

    for (int_vector::size_type i = 0; i < INITIALIZER_LIST.size(); ++i)
    {
        vector.push_front(INITIALIZER_LIST.begin()[i]);
        EXPECT_EQ(vector.front(), INITIALIZER_LIST.begin()[i]);
    }
}

TEST(Vector, push_back)
{
    int_vector vector;

    for (int_vector::size_type i = 0; i < INITIALIZER_LIST.size(); ++i)
    {
        vector.push_back(INITIALIZER_LIST.begin()[i]);
        EXPECT_EQ(vector.back(), INITIALIZER_LIST.begin()[i]);
    }
}

TEST(Vector, pop_front)
{
    int_vector vector = INITIALIZER_LIST;

    for (int_vector::size_type i = 0; i < INITIALIZER_LIST.size(); ++i)
    {
        EXPECT_EQ(vector.front(), INITIALIZER_LIST.begin()[i]);
        vector.pop_front();
    }
}

TEST(Vector, pop_back)
{
    int_vector vector = INITIALIZER_LIST;

    for (int_vector::size_type i = 0; i < INITIALIZER_LIST.size(); ++i)
    {
        EXPECT_EQ(vector.back(), INITIALIZER_LIST.begin()[INITIALIZER_LIST.size() - i - 1]);
        vector.pop_back();
    }
}
