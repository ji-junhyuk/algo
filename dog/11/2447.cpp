#include <bits/stdc++.h>
using namespace std;

/*
   함수의 정의: void recur(int a, int b, int n)
   종료조건: if (n == 1)
   				별찍기.
   재귀식:
   n != 1이 아니면 n /= 3을 하면서 계속 재귀호출
   별 못찍는 곳 처리.
*/

void recur(int i, int j, int n)
{
	if ((i / n) % 3 == 1 && (j / n) % 3 == 1)
		cout << ' ';
	else
	{
		if (n / 3 == 0)
			cout << '*';
		else
			recur(i, j, n / 3);
	}
}	

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			recur(i, j, N);
		cout << '\n';
	}
}
