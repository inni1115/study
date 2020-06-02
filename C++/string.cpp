//융복합 238414 이희진
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
using namespace std;

class String{
    char* buff;
    int size;
    int* ref;

public:
    String()
    {
        size = 0;
        buff = new char[size + 1];
        strcpy(buff, "");
        ref = new int;
        *ref = 1;
    }
    
    String(const char* s)
    {
        size = strlen(s);
        buff = new char[size + 1];
        strcpy(buff, s);
        ref = new int;
        *ref = 1;
    }
    String(const String& s) :buff(s.buff), size(s.size), ref(s.ref)
    {
        ++(*ref);
    }

    String& operator=(const String& s)
    {
        if (&s == this)
            return *this;

        size = s.size;
        delete[] buff;
        delete ref;
        buff = s.buff;
        strcpy(buff, s.buff);
        ref = s.ref;
        ++(*ref);
        return *this;
    }

        ~String()
    {
        if (--(*ref) == 0)
        {
            delete[] buff;
            delete ref;
        }
    }
    friend ostream& operator<<(ostream& os, const String& s);
};

ostream& operator<<(ostream& os, const String& s)
{
    os << s.buff;
    return os;
}
int main()
{
    //1단계 생성자, 소멸자, 화면출력
    String s1 = "hello";
    cout << s1 << endl;

    //2단계 복사 생성자
    String s2 = s1;
    cout << s2 << endl;

    //3단계. 대입 연산자
    String s3 = "student";
    s3 = s1;
    cout << s3 << endl;

    //4단계. 자신과의 대입
    s1 = s1;
    cout << s1 << endl;

    //5단계 디폴트 생성자
    String s4;
    cout << s4 << endl;
}
