#include <iostream>
#include <cassert>
#include "src.hpp"

int main() {
    int **p = nullptr;
    int n = 1;
    Init(p, n);
    for (int i = 1; i <= 1000000; ++i) {
        Add_element(p, 1, i);
    }
    for (int i = 1; i <= 1000000; ++i) {
        assert(Get_element(p, 1, i) == i);
    }
    Clear(p, n);
    std::cout << "All tests passed!" << std::endl;
    return 0;
}