#include <list.hpp>
#include <cstdio>

int main() {

    osl::list<int> buffer;
    buffer.push_back(1);
    buffer.push_back(2);
    buffer.push_back(3);

    const osl::list<int> list = buffer;
    for (auto it = list.start(); it != ++list.end(); ++it) {
        printf("%i\n", *it);
    }

    for (auto it = list.end(); it != --list.start(); --it) {
        printf("%i\n", *it);
    }

    return 0;
}