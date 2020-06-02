 #include <iostream>
#include <string>
 #include <stdio.h>
 #include <vector>
 int main(){
    std::vector<int32_t> v;
    std::string s = "abcd";
    for(auto &a : s){
        int i = a;
        std::cout << i <<std::endl;
        v.push_back(a);
}
 printf("%s", v);
 }

