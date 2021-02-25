#include <cstdio>

#include <memory.hpp>

using namespace osl;

int main(int, char**) {
    safe_ptr<int> obj(5);
    printf("%i\n", **obj);
    return 0;
}
