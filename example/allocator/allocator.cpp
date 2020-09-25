#include <cstdio>

#include <allocator.hpp>

int main() {
    osl::allocator<int> obj(10);
    for (size_t i = 0; i < obj.allocated(); i++) {
        printf("%i\n", obj[i] = i);
    }
    return 0;
}