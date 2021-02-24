#include <iostream>

#include <vector.hpp>

int main(int, char**) {
    osl::vector<int> v = { 1, 2, 3, 4, 5 };
    v.pop_front();
    v.push_front(2);
    v.push_back(2);
    v.push_back(3);
    v.pop_back();

    for (osl::u32 i = 0; i < v.length(); ++i)
        std::cout << v[i] << std::endl;

    return 0;
}
