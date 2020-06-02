#include <iostream>
#include <vector>
#include <stdint.h>

using namespace std;
int main(){

    uint64_t a;
    a = 0x12345678;

    cout <<hex <<a<<endl;
    cout <<unsigned(((uint8_t*) &a)[0])<<endl;
    cout <<unsigned(((uint8_t*) &a)[1])<<endl;
    cout <<((uint8_t*) &a)[2]<<endl;
    cout <<((uint8_t*) &a)[3]<<endl;

    vector<uint64_t> vec;
    vec.push_back(0x1111111111111999);
    vec.push_back(0x2222222222222222);
    vec.push_back(0x3333333333333333);

    cout<<unsigned(((uint8_t*) &(vec[0]))[0])<<endl;
    cout<<unsigned(((uint8_t*) &(vec[0]))[1])<<endl;
    cout<<unsigned(((uint8_t*) &(vec[0]))[2])<<endl;
    cout<<unsigned(((uint8_t*) &(vec[1]))[0])<<endl;
    cout<<unsigned(((uint8_t*) &(vec[1]))[1])<<endl;
    cout<<unsigned(((uint8_t*) &(vec[1]))[2])<<endl;


    a = 3.34;
    cout << a <<endl;

    a = 3.65;
    cout << a <<endl;

    a = 17/5;
    cout <<a <<endl;

}
