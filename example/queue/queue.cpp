#include <cstdio>

#include <queue.hpp>

int main() {
    osl::queue<int> queue;
    for (size_t i = 0; i < 10; i++) {
        queue.push(i);
    }
    printf("%i\n", queue.top());
    return 0;
}