#include <cstdio>

#include <array.hpp>

using namespace osl;

int main(int, char**) {
    array<int, 5> array;

    for (u32 i = 0; i < array.size(); ++i)
        printf("%i\n", array[i] = i);

    return 0;
}
