#include <memory.hpp>
#include <cstdio>

int main() {
    osl::allocator<int> alloc(5);
    alloc.reallocate(10);
    for (size_t i = 0; i < alloc.allocated(); i++) {
        alloc[i] = (int)i;
        printf("value: %i\n", alloc[i]);
    }
    return 0;
}
