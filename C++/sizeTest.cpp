
#include <iostream>
#include <vector>
using namespace std;

int main() {

vector<int> data;
//cout << data.size() <<endl;
data.push_back(1);
//cout<< data.size() <<endl;
data.push_back(2);
data.push_back(3);

vector<int> temp;
temp.resize(data.size()-1);
copy(data.begin() +1, data.end(), temp.begin());

for(auto& i : temp) {
    cout << i<< endl;
    }

int i = 0x1234;
//cout << hex << ((i  & 0xff00) >> 8)  <<endl;
//cout << (i & 0xff) <<endl ;
return 0;


}
