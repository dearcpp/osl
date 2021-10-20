#include <gtest/gtest.h>
#include <allocator.hpp>

#define ALLOC_SZ 3
#define REALLOC_SZ 6

#define INDEX 0
#define VALUE 256

using int_allocator = osl::allocator<int>;

TEST(Allocator, ctor_size)
{
    int_allocator allocator(ALLOC_SZ);
    EXPECT_NE(allocator.data(), (int*)0);

    allocator[INDEX] = VALUE;

    EXPECT_EQ(allocator.allocated(), ALLOC_SZ);
    EXPECT_EQ(allocator[INDEX], VALUE);

    allocator.free();
    EXPECT_EQ(allocator.data(), (int*)0);
    EXPECT_EQ(allocator.allocated(), 0);
}

TEST(Allocator, allocate)
{
    int_allocator allocator;
    EXPECT_EQ(allocator.data(), (int*)0);

    allocator.allocate(ALLOC_SZ);
    EXPECT_NE(allocator.data(), (int*)0);

    allocator[INDEX] = VALUE;

    EXPECT_EQ(allocator.allocated(), ALLOC_SZ);
    EXPECT_EQ(allocator[INDEX], VALUE);

    allocator.free();
    EXPECT_EQ(allocator.data(), (int*)0);
    EXPECT_EQ(allocator.allocated(), 0);
}

TEST(Allocator, reallocate)
{
    int_allocator allocator(ALLOC_SZ);
    EXPECT_NE(allocator.data(), (int*)0);

    allocator[INDEX] = VALUE;

    EXPECT_EQ(allocator.allocated(), ALLOC_SZ);
    EXPECT_EQ(allocator[INDEX], VALUE);

    allocator.reallocate(REALLOC_SZ);
    EXPECT_EQ(allocator.allocated(), REALLOC_SZ);
    EXPECT_EQ(allocator[INDEX], VALUE);

    allocator.free();
    EXPECT_EQ(allocator.data(), (int*)0);
    EXPECT_EQ(allocator.allocated(), 0);
}
