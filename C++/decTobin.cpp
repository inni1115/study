#include <iostream>

using namespace std;
int main()
{
  int n, c, k, length;
 
    cout << "Enter an integer in decimal number system" << endl;
    cin >> n;
    cin >> length;
  cout <<n <<" in binary number system is:" <<endl;;
 
  for (c = length-1 ; c >=0; c--)
  {
    k = n >> c;
 
    if (k & 1)
      cout <<"1";
    else
      cout <<"0";
  }
 
    cout << endl;
 
  return 0;
  }
