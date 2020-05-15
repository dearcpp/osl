#include <stack.hpp>
#include <cstdio>

int main() {
    osl::stack<int> stack_list;
    stack_list.push(2);
    printf("value: %i\n", stack_list.top());
    return 0;
}
