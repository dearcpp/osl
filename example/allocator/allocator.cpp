#include <memory.hpp>
#include <cstdio>

int main() {
    osl::allocator<int> alloc(5);
    for (size_t i = 0; i < alloc.allocated(); i++) {
        alloc[i] = (int)i;
        printf("[elem %zu]: %i\n", i, alloc[i]);
    }
    return 0;
}
