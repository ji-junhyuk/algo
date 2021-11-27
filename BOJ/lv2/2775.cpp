#include <bits/stdc++.h>
using namespace std;

/*
   함수: int recur(int floor, int n) 몇층 몇호에 사는 사람 수 반환
   종료조건: 0층일때, (1호일 땐 1명)
   재귀식: recur(floor - 1, n) + recur(floor, n - 1)
*/
int arr[15][14];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int num;
	long long sum;
	int k, n;
	int T;

	cin >> T;
	sum = 0;
	for (int idx = 0; idx < 14; idx++)
		arr[0][idx] = idx + 1;
	for (int idx = 0; idx < 14; idx++)
	{
		for (int jdx = 0; jdx < 14; jdx++)
		{
			sum += arr[idx][jdx];
			arr[idx + 1][jdx] = sum;
		}
		sum = 0;
	}
	while (T--)
	{
		cin >> k >> n;
		cout << arr[k][n - 1] << '\n';
	}
	return 0;
}
