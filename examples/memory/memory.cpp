#include <cstdio>

#include <memory.hpp>

int main(int, char**) {
    osl::safe_ptr<int> obj(5);
    printf("%i\n", **obj);
    return 0;
}
