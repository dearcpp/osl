#include <memory.hpp>
#include <cstdio>

int main() {
    osl::safe_ptr<int> obj1(5);
    printf("value: %i\n", **obj1);
    return 0;
}
