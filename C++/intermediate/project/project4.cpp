#include <string>
#include <iostream>

using namespace std;

class People
{
    string name;
    string addr;
    int age;
public:
    People(string n, string add, int a) : name(n), addr(add), age(a) { } //cout << name << addr << age <<endl;}
    // 복사 생성자, 대입연산자, Move 생성자, Move 대입연산자를 만드세요..
    // 실행 여부를 확인하기 위해 logging 해주세요
    People(const People& p) : name(p.name), addr(p.addr), age(p.age) { cout << "copy" << endl; }
    People& operator=(const People& p)
    {
        cout << "copy=" << endl;
        name = p.name;
        addr = p.addr;
        age = p.age;

        return *this;
    }

    People(People&& p) noexcept : name(move(p.name)), addr(move(p.addr)), age(move(p.age)) { cout <<"move" <<endl; }
    People& operator=(People&& p)
    {
        cout << "move=" << endl;
        name = move(p.name);
        addr = move(p.addr);
        age = move(p.age);

        return *this;
    }

	void print() const
    {
		cout << name << addr << age <<endl;
	}

};

int main()
{
// 1. People을 힙에 10개 생성해 보세요..
// People{"홍길동", "서울", 20} 으로 초기화 하세요..
// 힌트) 메모리 할당과 생성자 호출을 분리 하세요
    People* p1 = static_cast<People*>(operator new(sizeof(People) * 10));

    for(int i=0; i<10; i++) {
        new(&p1[i]) People("홍길동", "서울", 20);
    }
// 2. 위에서 만드는 배열(버퍼)를 20개 키워 보세요..
// A. 20개 버퍼를 새로 할당하고
// B. 기존에 버퍼의 내용을 새로운 버퍼에 옮기세요.
// move 생성자에 예외가 없다면 move 생성자로,
// 예외가 있다면 복사 생성자로 옮기세요
// C. 버퍼의 새로운 공간은 {"unknwon", "unknown", 0} 으로 초기화 하세요
    People* p2 = static_cast<People*>(operator new(sizeof(People) * 20));
	for(int i=0; i<10; i++) {
		new(&p2[i]) People(move_if_noexcept(p1[i]));
	}
	for(int i=10; i<20; i++) {
		new(&p2[i]) People("unknown", "unknown", 0);
	}

// 3. 새로운 버퍼의 새용을 출력하세요.

	cout << endl << "print new people" <<endl;
	for(int i=0; i<20; i++) {
		p2[i].print();
	}

// 4. 버퍼을 줄이지는 말고 버퍼 끝에 있는 3개 객체를 파괴(명시적 소멸자 호출)해보세요.
	for(int i=19; i>=17; i--) {
		p2[i].~People();
	}
}
