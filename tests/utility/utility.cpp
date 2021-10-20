#include <gtest/gtest.h>
#include <utility.hpp>

using osl::swap;

TEST(Utility, swap)
{
    int i1 = 1, i2 = 2;

    swap(i1, i2);
    EXPECT_EQ(i1, 2);
    EXPECT_EQ(i2, 1);

    float f1 = 1.f, f2 = 2.f;

    swap(f1, f2);
    EXPECT_EQ(f1, 2.f);
    EXPECT_EQ(f2, 1.f);
}
