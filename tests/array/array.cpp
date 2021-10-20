#include <gtest/gtest.h>
#include <array.hpp>

#define INITIALIZER_LIST { 1, 2, 3, 4, 5 }
#define INDEX 3
#define VALUE 9

using osl::u32;
using int_array = osl::array<int, 5>;

TEST(Array, ctor_array)
{
    int_array array = INITIALIZER_LIST;
    for (u32 i = 0; i < array.size(); ++i)
    {
        EXPECT_EQ(array[i], int_array::initializer_list(INITIALIZER_LIST).begin()[i]);
    }
}

TEST(Array, operator_brackets)
{
    int_array array;
    array[INDEX] = VALUE;
    EXPECT_EQ(array[INDEX], VALUE);
}
