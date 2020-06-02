#include <sstream>
#include <iostream>
int main(){
    uint8_t a = 13;
    int b = a;
    std::stringstream str;
    str << std::hex << b;
    std::cout << str.str();

}
