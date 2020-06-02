#include <iostream>
#include <string>
#include <vector>

std::vector<int32_t> getVec();
int main(){

    constexpr int BYTE = sizeof(uint8_t) ;
    std::string s ="0011110000000000";
    int temp, value=0; 
    std::vector<int32_t> vec;
  /*  while(s.size() >= 4){
        int i = 0;
        for(i = 0; i< 3; i++) {
            temp = s.at(i) - '0';
            std::cout << temp << std::endl;
            value +=temp;
            value <<=1;
        }
        std::cout <<" i = : " << i <<std::endl;
        value += temp = s.at(i) -'0';
        vec.push_back(value);
        value=0;
        s = s.substr(4, s.size()-4);
    }

    while(s.size() >= BYTE ){
        for(int i = 0; i< BYTE; i++) {
            temp = s.at(i) - '0';
            std::cout << temp << std::endl;
            value +=temp;
            value <<=1;
        }
        value>>=1;
        vec.push_back(value);
        s = s.substr(BYTE, s.size()- BYTE);
        value = 0;
    }
//    value>>=1;

    std::cout << "value : " << value << std::endl;

    for(auto a : vec){
        std::cout <<"vec : " << std::hex << a << std::endl;
        }
    std::string a = "101011";
    a+='0';
    std::cout << a <<std::endl;
    */for(auto &a : getVec() ){
        std::cout << a <<std::endl;
    }
    std::cout << sizeof(getVec()) <<std::endl;
}

std::vector<int32_t> getVec() {
    std::vector<int32_t> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    return vec;
}


