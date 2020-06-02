#include <iostream>
#include <stdint.h>
int main() {
    uint32_t a = 0x123;
    uint8_t b = ((uint8_t*) &a)[0];
    uint8_t c =( (uint8_t*) &a)[1];

    std::cout << std::hex << a <<std::endl;
    std::cout << unsigned(b) << std::endl;
    std::cout << unsigned(c) << std::endl;

    return 0;

}
