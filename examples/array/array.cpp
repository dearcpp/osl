#include <cstdio>

#include <array.hpp>

int main(int, char**) {
    osl::array<int, 5> arr;
    for (osl::u32 i = 0; i < arr.size(); i++) {
        printf("%i\n", arr[i] = i);
    }
    return 0;
}
