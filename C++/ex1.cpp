#include<iostream>

namespace util{
void Swap(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}
}

int main()
{
    int a = 10, b = 20;
    Swap(a, b);
    cout << a << ", " << b << endl;
}
