#include <iostream>

#include <string.hpp>

int main() {
    osl::basic_string<char> str = "Hello World";
    if (str != "nothing") {
        std::cout << "Allocated: " << str.allocated() << ", Length: " << str.length() << ", String: " << str.data() << std::endl;
    }
    return 0;
}