#include <iostream>
using namespace std;

unsigned int Make_Data(unsigned int rcv);

// 작성할 함수
unsigned int Make_Data(unsigned int rcv)
{
	unsigned int sol = 0;
	unsigned int mask[] = {0xFC000000, 0x03800000, 0x00780000, 0x00078000, 0x00007800, 0x00000600, 0x000001F0, 0x0000000F};
	int shift[] = {8, 10, 19, -9, 7, -7, -4, -28};
	for (int i = 0; i < 8; ++i) {
		if(shift[i]>0)
			sol |= (rcv & mask[i]) >> shift[i];
		else
			sol |= (rcv & mask[i]) << (shift[i] * -1);
	}
	
	return sol;
}

int main(void)
{
	unsigned int rcv=0,sol;
	
	// 입력 받는 부분
	cin >> hex >> uppercase >> rcv;
	
	sol = Make_Data(rcv);

	cout << hex << uppercase << sol;
}
