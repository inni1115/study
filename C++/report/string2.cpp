//������ 238414 ������ 
#define _CRT_SECURE_NO_WARNINGS
#include <cstring> 
#include <iostream> 
using namespace std;

class Str {
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

	void increaseRef()
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
	~Str() 
	{
		if (ref == 0) {
			delete[] buff;
		}
	}
};

class String {
	Str* str;
public:
	String() {
		str = new Str();
	}
	String(const char* s)
	{
		str = new Str(s);
	}
	String(const String &s) :str(s.str) {

		str->increaseRef();
	}
	~String()
	{
		str->decreseRef();
		if (str->getRef() == 0)
		{
			delete str;
		}
	}

	Str* operator->() { return str; }
	Str operator*() { return *str; }
	String& operator=(String& s)
	{
		if (&s == this)
			return *this;
		delete str;
		this->str = s.str;
		str->increaseRef();
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
	//1�ܰ� ������, �Ҹ���, ȭ����� 
	String s1 = "hello";
	cout << s1 << endl;

	//2�ܰ� ���� ������ 
	String s2 = s1;
	cout << s2 << endl;

	//3�ܰ�. ���� ������ 
	String s3 = "student";
	s3 = s1; 
	cout << s3 << endl; 

	//4�ܰ�. �ڽŰ��� ���� 
	s1 = s1;
	cout << s1 << endl;

	//5�ܰ� ����Ʈ ������ 
	String s4; 
	cout << s4 << endl; 
}