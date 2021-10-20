#include <gtest/gtest.h>
#include <math.hpp>

#define VALUE 2
#define POWER 10
#define RESULT 1024

using namespace osl;

TEST(Math, pow)
{
    EXPECT_EQ(pow(VALUE, POWER), RESULT);
}
