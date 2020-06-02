/*class Test
{
public:
    void foo() {}
};

int main()
{
    void (Test::*f)() = &Test::foo;

    Test* p = new Test;

    // p와 f를 사용해서  Test::foo 함수를 호출해 보세요
	(p->*f)();
}
*/

using LREF = int&;
using RREF = int&&;

int main()
{
    int n = 10;

    LREF&  r1 = n; // 1
    LREF&& r2 = n;  // 2
    RREF&  r3 = n;  // 3
    RREF&& r4 = n;  // 4
}
