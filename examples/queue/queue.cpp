#include <cstdio>

#include <queue.hpp>

using namespace osl;

int main(int, char**) {
    queue<int> queue;

    for (u32 i = 0; i < 10; ++i)
        queue.push(i);

    for (u32 i = 0; i < 10; ++i) {
        printf("%i\n", queue.back());
        queue.pop();
    }

    return 0;
}
