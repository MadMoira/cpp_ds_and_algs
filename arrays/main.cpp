#include <iostream>
#include "Array.h"

int main() {
    Array<int> a{};
    assert(a.IsEmpty());

    Array<int> b{10};
    assert(!b.IsEmpty());

    Array<int> c{3};
    c[0] = 10;
    c[1] = 20;
    c[2] = 0;

    std::cout << c[0] << std::endl;

    try {
        c[4];
    } catch (const IndexOutOfBoundsException& e) {
        std::cout << "Index out of bounds exception" << std::endl;
    }

    Array<int> d = c;
    d[0] = 20;

    std::cout << "c: " << c << std::endl;
    std::cout << "d: " << d << std::endl;

    return 0;
}
