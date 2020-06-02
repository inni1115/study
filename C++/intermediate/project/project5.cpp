#include <iostream>

using namespace std;

// 아래 Point 에는 디폴트 생성자가 없습니다. 디폴트 생성자를 만들지 말고.
// 아래 상태에 과제를 진행해 주세요..
class Point
{
public:
	Point(int a, int b) {cout << "point(int,int)"<<endl;}
};

// 아래 main 함수가 실행되도록 Vector를 구현해야 합니다.
template<typename T> class Vector
{
	T* buff;
	int sz; // size
	int capa; // capacity ( 메모리 사용량)
public:
    Vector<T> (int size, T&& t) :sz (size), capa(size) 
    {
        cout<< "vector(int,T) size :" << size <<endl;
        buff = static_cast<T*>(operator new(sizeof(T) * size));
        
        for (int i=0; i<size; i++) {
            new(&buff[i]) T(t);
        }
    }
    
    Vector<T>( initializer_list<T> s) 
    {
        buff = static_cast<T*>(operator new(sizeof(T) * s.size()));

        cout << "initializer_list" <<endl;
        int i=0;
        for(auto iter= s.begin(); iter!=s.end(); ++iter){
            buff[i++] = *iter;
        }
        sz = s.size();
        capa = s.size();
    }    
    
    int size() const { return sz; }
    int capacity() const { return capa; }
    void resize(int s, T&& t) 
    {
        cout << "resize : from " << sz << " to : " << s <<endl; 
        if (s > sz) {
            T* temp = static_cast<T*>(operator new(sizeof(T) * s));

            for(int i=0; i<sz; i++) {
                new(&temp[i]) T(move(buff[i]));
            }

            for(int i=sz; i<s; i++) {
                new(&temp[i]) T(t);
            }
            sz = s;
            capa =s;
       } else if (s < sz) {
            for(int i =sz-1; i>=s; i--) {
                buff[i].~T();
            }
            sz =s;   
       }

    }
    T* begin(){ return &(buff[0]); }
    T* end() { return &(buff[0]) + sz;} 
};

int main()
{
// 1. 아래 한줄이 실행되게 해주세요..
// Point 10개를 위한 버퍼가 만들어져야 하고, Point(1,1)로 초기화 되어야 합니다.
	Vector<Point> v(10, Point(1,1));

// 2. 버퍼가 20개로 할당 되고 기존 10개는 이동(복사)하고,
// 새로운 10개는 Point(0,0)으로 초기화되게 하세요
	v.resize(20, Point(0,0));

// 3. 버퍼 크기를 다시 10개로 줄여 주세요. - 실제 메모리는 줄이지 말고, 객체만파괴(소멸자 호출)해 주세요
	v.resize(10, Point(0,0));
	cout << v.size() << endl; // 10
	cout << v.capacity() << endl; // 20

// 4. initializer_list 추가하기.
	Vector<int> v2{ 1,2,3,4,5,6,7,8,9,10 };

// 5. ranged for 지원 하기
	for (auto n : v2)
		cout << n << endl; // 1,2,3,4,5,6,7,8,9,10
}
