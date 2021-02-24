#include <cstdio>

#include <queue.hpp>

int main(int, char**) {
    osl::queue<int> queue;
    for (osl::u32 i = 0; i < 10; i++) {
        queue.push(i);
    }
    printf("%i\n", queue.top());
    return 0;
}
