#include <iostream>
#include <stdint.h>
#include <unordered_map>

enum class ADASISV2MsgType : int32_t {
    PROFILE_SHORT = 0x01,
    PROFILE_LONG = 0x02,
    POSITION = 0x03,
    SEGMENT = 0x04,
    STUB = 0x05,
    META_DATA = 0x06,
};

int main() {
std::unordered_map<int32_t, uint32_t> mAdasisV2MsgMap = {
{0x1 , 0x25E }
 };


auto type = mAdasisV2MsgMap.find(0x1);
std::cout << std::hex << (unsigned)((uint8_t*) &(type->second))[0]<< " : " << ((uint8_t*) &(type->second))[1] <<std::endl;
return 0;
}
