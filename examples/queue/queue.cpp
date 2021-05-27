#include <cstdio>

#include <queue.hpp>

using namespace osl;

int main(int, char**) {
    queue<int> queue = {
        9, 8, 7, 6, 5, 4, 3, 2, 1, 0
    };

    for (u32 i = 0; i < 10; ++i) {
        printf("%i\n", queue.front());
        queue.pop();
    }

    return 0;
}
