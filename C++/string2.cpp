//융복합 238414 이희진
#include <cstring>
#include <iostream>
using namespace std;

class Str{
	char* buff;
	int size;
	int ref;

public:
	Str()
	{
        size = 0;
        buff = new char[size + 1];
		strcpy(buff, "");
		ref = 1;

	}
	Str(const char* s)
	{
		size = strlen(s);
		buff = new char[size + 1];
		strcpy(buff, s);
		ref = 1;
	}
	Str(const Str& s) :buff(s.buff), size(s.size), ref(s.ref){}
    void increseRef()
    {
        ++ref;
    }
    void decreseRef()
    {
        --ref;
    }
    int getRef() const
    {
        return ref;
    }
    const char* getBuff() const
    {
         return buff;
    }
	~Str(){}
};

class String{
   Str* str;
public:
            
	String(const char* s)
	{
       str = new Str(s);

	}
	String(Str* s = 0) :str(s)
    {
        if(s ==0)
            str = new Str();
    
    }
	~String() 
    { 
        str->decreseRef();
        if(str->getRef() ==0)
        {
            str->~Str();
        }
        delete str;
    }

    Str* operator->() {return str;}
    Str operator*(){return *str;}
	String& operator=(String& s)
    {
        if(&s == this)
           return *this;
//        delete str;
        *this = s;
        str->increseRef();
    }
    friend ostream& operator<<(ostream& os, const String& s);
};
ostream& operator<<(ostream& os, String& s)
{
	os << (*s).getBuff();
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
