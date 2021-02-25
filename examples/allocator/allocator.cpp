#include <cstdio>

#include <allocator.hpp>

using namespace osl;

int main(int, char**) {
    allocator<int> obj(10);

    for (u32 i = 0; i < obj.allocated(); ++i)
        printf("%i\n", obj[i] = i);

    return 0;
}
