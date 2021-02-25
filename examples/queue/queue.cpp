#include <cstdio>

#include <queue.hpp>

using namespace osl;

int main(int, char**) {
    queue<int> queue_1;
    for (u32 i = 0; i < 10; ++i)
        queue_1.push(i);

    queue<int> queue_2 = queue_1;
    for (u32 i = 0; i < 10; ++i)
        printf("%i\n", queue_2.top()), queue_2.pop();

    return 0;
}
