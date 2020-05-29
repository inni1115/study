#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

int main(){

    vector<uint8_t> bytes = {0x1,0x2,0xff};

    uint8_t a = 0x1;
    //bytes.resize(3);

  //  bytes.emplace(a);
   // bytes.emplace(a+1);
    //bytes.emplace(a+2);

    cout<< bytes[0]<<endl;

    cout << bytes[1] <<endl;
    cout <<bytes[2]<<endl;

    cout << "cast" << endl;

    cout <<static_cast<int32_t>(bytes[0]) <<endl;
    cout <<static_cast<int32_t>(bytes[1]) <<endl;
    cout <<static_cast<int32_t>(bytes[2]) <<endl;

    return 0;
    }

