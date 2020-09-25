#include <cstdio>

#include <string.hpp>

int main() {
    osl::basic_string<char> str = "Hello World";
    printf("Allocated: %llu\nLength: %llu\nString: %s", str.allocated(), str.length(), str.data());
    return 0;
}