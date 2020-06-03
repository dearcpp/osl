#include <cstdio>

#include <stack.hpp>

int main() {
    osl::stack<int> stack_list;
    for (size_t i = 0; i < 10; i++) {
        stack_list.push(i);
    }
    printf("%i\n", stack_list.top());
    return 0;
}