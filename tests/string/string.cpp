#include <gtest/gtest.h>
#include <memory.hpp>
#include <string.hpp>

#define SINGLE_CHAR 'H'
#define SINGLE_CHAR_STRING "H"
#define STRING "Hello"

using osl::string_compare;
using string = osl::basic_string<char>;

TEST(String, ctor_char)
{
    string str(SINGLE_CHAR);
    EXPECT_TRUE(string_compare(str.c_str(), SINGLE_CHAR_STRING));
}

TEST(String, ctor_pointer)
{
    string str(STRING);
    EXPECT_TRUE(string_compare(str.c_str(), STRING));
}

TEST(String, ctor_object)
{
    string str1(STRING), str2(str1);
    EXPECT_TRUE(string_compare(str1.c_str(), str2.c_str()));
}

TEST(String, set_char)
{
    string str;
    str = SINGLE_CHAR;
    EXPECT_TRUE(string_compare(str.c_str(), SINGLE_CHAR_STRING));
}

TEST(String, set_pointer)
{
    string str;
    str = STRING;
    EXPECT_TRUE(string_compare(str.c_str(), STRING));
}

TEST(String, set_object)
{
    string str1(STRING);
    string str2 = str1;
    EXPECT_TRUE(string_compare(str2.c_str(), STRING));
}

TEST(String, concat_char)
{
    string str;
    str += SINGLE_CHAR;
    EXPECT_TRUE(string_compare(str.c_str(), SINGLE_CHAR_STRING));
}

TEST(String, concat_pointer)
{
    string str;
    str += STRING;
    EXPECT_TRUE(string_compare(str.c_str(), STRING));
}

TEST(String, concat_object)
{
    string str1(STRING), str2;
    str2 += str1;
    EXPECT_TRUE(string_compare(str2.c_str(), STRING));
}

TEST(String, comparison_char)
{
    string str = SINGLE_CHAR;
    EXPECT_TRUE(str == SINGLE_CHAR);
    str += SINGLE_CHAR;
    EXPECT_FALSE(str == SINGLE_CHAR);
}

TEST(String, comparison_pointer)
{
    string str = STRING;
    EXPECT_TRUE(str == STRING);
    str += STRING;
    EXPECT_FALSE(str == STRING);
}

TEST(String, comparison_object)
{
    string str1(STRING), str2(STRING);
    EXPECT_TRUE(str1 == str2);
    str1 += STRING;
    EXPECT_FALSE(str1 == str2);
}
