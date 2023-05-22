#include <bits/stdc++.h>
using namespace std;

/*
   함수의 정의: void recur(int a, int b, int n)
   종료조건: (n == 1) if (arr[a][b]) one++;
   재귀식: 
   one이 n제곱이면 1을 출력 
   아니면 n >> 1후 recur(a, b, n) 4번.
*/

int arr[65][65];

void recur(int a, int b, int n)
{
	int one;
	int zero;
	
	if (n == 1)
	{
		cout << arr[a][b];
		return ;
	}
	one = 1;
	zero = 1;
	for (int i = a; i < a + n; i++)
	{
		for (int j = b; j < b + n; j++)
		{
			if (arr[i][j])
				zero = 0;
			else
				one = 0;
		}
	}
	if (zero)
		cout << 0;
	else if (one)
		cout << 1;
	else
	{
		n = (n >> 1); // 초기n은 2
		cout << "(";
		recur(a, b, n); // 0 0 1
		recur(a, b + n, n); // 첫번째 while문은 세로축을 나타냄.while문을 a문부터 돌렸고, 왼쪽위 다음 오른쪽 위를 출력하고 싶다면 b + n 을 먼저해야함.
		recur(a + n, b, n);  
		recur(a + n, b + n, n);
		cout << ")";
	}
	return ;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	char str[65];

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		for (int j = 0; j < N; j++)
			arr[i][j] = str[j] - '0';
	}
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//			cout << arr[i][j];
//		cout << '\n';
//	}
	recur(0, 0, N);
}
