#include <bits/stdc++.h>
using namespace std;

/*
    num1~5가 4일때,

  	num1 &= 5;     // 5(0000 0101) AND 연산 후 할당
    num2 |= 2;     // 2(0000 0010) OR 연산 후 할당
    num3 ^= 3;     // 3(0000 0011) XOR 연산 후 할당
	cf. XOR연산: 대응하는 두 비트가 다르면 1, 같으면 0할당
    num4 <<= 2;    // 비트를 왼쪽으로 2번 이동한 후 할당
    num5 >>= 2;    // 비트를 오른쪽으로 2번 이동한 후 할당
	cf. ~: 비트반전연산자
*/

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int M;
	int number; 
	int bit;

	number = 0;
	bit = 0;
	cin >> M;
	while (M--)
	{
		string op;
		cin >> op;
		if (op == "add")
		{
			cin >> number;
			bit |= (1 << number);
		}
		else if (op == "remove")
		{
			cin >> number;
			bit &= ~(1 << number);
		}
		else if (op == "check")
		{
			cin >> number;
			if (bit & (1 << number))
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (op == "toggle")
		{
			cin >> number;
			bit ^= (1 << number);
		}
		else if (op == "all")
			bit = (1 << 21) - 1;
		else
		{
			bit = 0;
		}
	}
}
