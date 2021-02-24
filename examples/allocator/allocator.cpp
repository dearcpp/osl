#include <cstdio>

#include <allocator.hpp>

int main(int, char**) {
    osl::allocator<int> obj(10);
    for (osl::u32 i = 0; i < obj.allocated(); i++) {
        printf("%i\n", obj[i] = i);
    }
    return 0;
}
