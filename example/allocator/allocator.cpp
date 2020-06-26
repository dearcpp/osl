#include <cstdio>

#include <allocator.hpp>

int main() {
    osl::allocator<int> alloc(10);
    for (size_t i = 0; i < alloc.allocated(); i++) {
        printf("%i\n", alloc[i] = i);
    }
    return 0;
}