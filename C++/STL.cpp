// 융복합센터 플랫폼신기술Task 238414 이희진

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <ctime>

using namespace std;
void printVec(const vector<int>& vec);
int main()
{
	vector<int> v;
	srand((unsigned)time(NULL));

	for (int i = 0; i < 10; ++i) {
		v.push_back(rand() % 100);  //1. 난수 10개를 구해서 v에 넣으세요.
	//	cout << v[i] << endl;
	}

	int cmd = 0;
	while (1) {
		cin >> cmd;

		//2. cmd가 1이면 v의 모든 내용을 화면에 출력하세요.
		if (cmd == 1) {
			printVec(v);
		}
		//3. cmd가 2이면 v를 오름차순으로 정렬한 후 v의 내용을 화면에 출력해 주세요 비교 정책으로 함수 객체를 사용해서 만들어 주세요
		else if (cmd == 2) {
		    less<int> l;
			sort(v.begin(), v.end(), l);
			printVec(v);
		}
		//4. cmd가 3이면 v를 내림차수d으로 정렬한후 v의 내뇽을 화면에 출력해 주세요. 비교 정책으로 람다 표현식을 사용해 주세요.
		else if (cmd == 3) {
			sort(v.begin(), v.end(), [](int a, int b) {return a > b; });
			printVec(v);
		}
		//5. cmd가 4이면 또다른 숫자를 하나 입력 받으세요. 해당 숫자가 vector에 있으면 제거한 후 vector를 다시 출력해주세요.
		else if (cmd == 4) {
			int num;
			cin >> num;
			auto itr = find(v.begin(), v.end(), num);
			if (v.end() != itr) {
				v.erase(itr);
				printVec(v);
			}
		}
		//6.cmd 가 5이면 또다른 숫자를 하나 입력받으세요. 해당숫자를 찾아서 0으로 변경한 후 vector를 다시 출력해 주세요.
		else if (cmd == 5) {
			int num;
			cin >> num;
			auto itr = find(v.begin(), v.end(), num);
			if (v.end() != itr) {
				replace(v.begin(), v.end(), num, 0);
				printVec(v);
			}
		}
		//7. cmd가 6이면 v의 size를 20개로 늘린후 v의 내용을 출력해 주세요.
		else if (cmd == 6) {
			v.resize(20);
			printVec(v);
		}
		else {
			return 0;
		}

	}
	
}

void printVec(const vector<int>& vec) {
	for (auto &n : vec)
		cout << n << "  ";
	cout << endl;
}
