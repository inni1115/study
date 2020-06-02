#include <iostream>

#include <string>
#include<vector>

using namespace std;
void test(int&);
int main(){
 string s1;

// cout <<s1 <<endl;
// cout << s1.size();
 int* i = new int[8];
 for(int a=0;a<8;a++) {
    i[a] = a;
    }
 test(i);
}


void test(int& i) {
cout << i[0] <<endl;
 cout<< i[1]<< endl;
 cout<<i[2] << endl;
}
