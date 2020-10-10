#include <iostream>

#include <string.hpp>

int main() {
    osl::basic_string<char> str = "Hello World";
    std::cout << "Allocated: " << str.allocated() << ", Length: " << str.length() << ", String: " << str.data() << std::endl;
    return 0;
}