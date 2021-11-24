#include <bits/stdc++.h>
using namespace std;

/*
   조건: <가장 위>에 있는 원판만 <자기보다 큰 원반> 위로 <하나씩> 옮길 수 있음.
   함수: void hanoi(int a, int c, int num)
   종료조건: num == 1 원판을 옮긴다.
   재귀식: 
   		1. n - 1원판을 a 에서 b로 옮긴다
		2. a에 있는 가장 큰 원판을 c로 옮긴다
		3. n - 1 원판을 b에서 c로 옮긴다.
*/

void hanoi(int a, int c, int num)
{
	if (num == 1)
	{
		cout << a << ' ' << c << '\n';
		return ;
	}
	else
	{
		hanoi(a, 6 - a - c, num - 1);
		cout << a << ' ' << c << '\n';
		hanoi(6 - a - c, c, num - 1);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int a, c;

	cin >> n;
	cout << (1 << n) - 1 << '\n';

	hanoi(1, 3, n); 
}
