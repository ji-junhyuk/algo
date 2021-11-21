#include <bits/stdc++.h>
using namespace std;

/*
   함수의 정의: void recur(int x,int y, int n)
   종료조건: n == 1, for (i < n) for (j < n) if (arr[i][j] == 1) cnt++;;
   재귀식: n / 2;
   recur(int x, int y, int n)
   recur(x + n, y, int n)
   recur(x, y + n, int n)
   recur(x + n, y + n, int n)
*/

int arr[128][128];
int w_cnt;
int b_cnt;
void recur(int x, int y, int n)
{

	int one;

	one = 0;
	for (int idx = x; idx < x + n; idx++)
	{
			for (int jdx = y; jdx < y + n; jdx++)
			{
					if (arr[idx][jdx])
							one++;
			}
	}
	if (!one)
			w_cnt++;
	else if (one == n * n)
			b_cnt++;
	else
	{
		n = n >> 1;
		for (int idx = 0; idx < 2; idx++)
			for (int jdx = 0; jdx < 2; jdx++)
				recur(x + idx * n, y + jdx * n, n);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;

	cin >> N;
	for (int idx = 0; idx < N; idx++)
			for (int jdx = 0; jdx < N; jdx++)
					cin >> arr[idx][jdx];
	recur(0, 0, N);
	cout << w_cnt << '\n' << b_cnt;
}
