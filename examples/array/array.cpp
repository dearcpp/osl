#include <cstdio>

#include <array.hpp>

int main() {
    osl::array<int, 5> arr;
    for (size_t i = 0; i < arr.size(); i++) {
        printf("%i\n", arr[i] = i);
    }
    return 0;
}