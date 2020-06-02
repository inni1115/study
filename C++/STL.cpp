// �����ռ��� �÷����ű��Task 238414 ������

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
		v.push_back(rand() % 100);  //1. ���� 10���� ���ؼ� v�� ��������.
	//	cout << v[i] << endl;
	}

	int cmd = 0;
	while (1) {
		cin >> cmd;

		//2. cmd�� 1�̸� v�� ��� ������ ȭ�鿡 ����ϼ���.
		if (cmd == 1) {
			printVec(v);
		}
		//3. cmd�� 2�̸� v�� ������������ ������ �� v�� ������ ȭ�鿡 ����� �ּ��� �� ��å���� �Լ� ��ü�� ����ؼ� ����� �ּ���
		else if (cmd == 2) {
		    less<int> l;
			sort(v.begin(), v.end(), l);
			printVec(v);
		}
		//4. cmd�� 3�̸� v�� ��������d���� �������� v�� ������ ȭ�鿡 ����� �ּ���. �� ��å���� ���� ǥ������ ����� �ּ���.
		else if (cmd == 3) {
			sort(v.begin(), v.end(), [](int a, int b) {return a > b; });
			printVec(v);
		}
		//5. cmd�� 4�̸� �Ǵٸ� ���ڸ� �ϳ� �Է� ��������. �ش� ���ڰ� vector�� ������ ������ �� vector�� �ٽ� ������ּ���.
		else if (cmd == 4) {
			int num;
			cin >> num;
			auto itr = find(v.begin(), v.end(), num);
			if (v.end() != itr) {
				v.erase(itr);
				printVec(v);
			}
		}
		//6.cmd �� 5�̸� �Ǵٸ� ���ڸ� �ϳ� �Է¹�������. �ش���ڸ� ã�Ƽ� 0���� ������ �� vector�� �ٽ� ����� �ּ���.
		else if (cmd == 5) {
			int num;
			cin >> num;
			auto itr = find(v.begin(), v.end(), num);
			if (v.end() != itr) {
				replace(v.begin(), v.end(), num, 0);
				printVec(v);
			}
		}
		//7. cmd�� 6�̸� v�� size�� 20���� �ø��� v�� ������ ����� �ּ���.
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
