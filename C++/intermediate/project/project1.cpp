#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int xplus(int a, int b) 
{
    return a + b;
}

int main()
{
    vector<int> x { 1,2,3,4,5,6,7,8,9,10 };
//    int x[10]{ 1,2,3,4,5,6,7,8,9,10 };
//    int y[10];
    vector<int> y;
    y.resize(10);
    int v1 = 10;
    vector<int> v2(10, v1);
// x의 모든 요소에 v1를 더해서 y 에 넣어 주세요
// 조건 1. x 와 y가 배열이 아닌 vector인 경우도 코드 변경없이 실행되게 해주세요..
    transform(begin(x), end(x), begin(v2), begin(y), xplus);

    //transform(x.begin(), x.end(), y.begin(),[=](int i){ return x[i-1] + v1;} );
    for (auto n : y)
        cout << n << endl; // 11,12,13,14,15,16,17,18,19,20 나와야 합니다.

    cout << endl;
// 조건 2. 람다 표현식을 사용해 주세요.
    transform(&x[0], &x[0]+10, &y[0],[=](int m){ return m + v1;} );

    for (auto n : y)
    cout << n << endl; // 11,12,13,14,15,16,17,18,19,20 나와야 합니다.
}
