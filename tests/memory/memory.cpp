#include <gtest/gtest.h>
#include <memory.hpp>

#define HELLO_STRING "Hello"
#define HELLO_STRING_LEN 5

#define WORLD_STRING " World"
#define WORLD_STRING_LEN 6

using osl::string_compare;

TEST(Memory, string_compare)
{
    EXPECT_TRUE(string_compare(HELLO_STRING, HELLO_STRING));
    EXPECT_FALSE(string_compare(HELLO_STRING, WORLD_STRING));
    EXPECT_TRUE(string_compare(WORLD_STRING, WORLD_STRING));
}

using osl::string_length;

TEST(Memory, string_length)
{
    EXPECT_EQ(string_length(HELLO_STRING), HELLO_STRING_LEN);
    EXPECT_EQ(string_length(HELLO_STRING WORLD_STRING), HELLO_STRING_LEN + WORLD_STRING_LEN);
    EXPECT_NE(string_length(WORLD_STRING), HELLO_STRING_LEN);
}

using osl::memory_set;

TEST(Memory, memory_set)
{
    int val = 5;
    memory_set(&val, 0, sizeof(val));
    EXPECT_EQ(val, 0);
}

using osl::memory_copy;

TEST(Memory, memory_copy)
{
    char str[HELLO_STRING_LEN + 1];
    memory_copy(str, HELLO_STRING, sizeof(str));
    EXPECT_TRUE(string_compare<const char>(str, HELLO_STRING));
}

using osl::safe_ptr;

TEST(Memory, safe_ptr)
{
    safe_ptr<int> sptr(10);
    EXPECT_NE(sptr.get(), (int*)0);

    int *ptr = sptr.release();
    EXPECT_EQ(sptr.get(), (int*)0);
    EXPECT_NE(ptr, (int*)0);

    delete ptr;
}
