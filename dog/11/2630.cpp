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
int check(int x, int y, int n)
{
	for (int idx = x; idx < x + n; idx++)
	{
		for (int jdx = y; jdx < y + n; jdx++)
			if (arr[x][y] == 0)
				return 0;
	}
	return 1;
//	for (int idx = x; idx < x + n; idx++)
//	{
//		for (int jdx = y; jdx < y + n; jdx++)
//			if (arr[x][y] == 0 || arr[x][y] != arr[idx][jdx])
//				return 0;
//	}
//	return 1;
}
/*
0 0 2

1 1
0 0 

 */

void recur(int x, int y, int n)
{

	if (check(x, y, n))
	{
		b_cnt++;
		return ;
	}
	//for (int idx = 0; idx < n; i++)
	//	for (int jdx = 0; jdx < n; j++)
	//		recur(x + idx * n, y + jdx * n, n);
	recur(x, y, n / 2);
    recur(x, y + n / 2, n / 2);
    recur(x + n / 2, y, n / 2);
    recur(x + n / 2, y + n / 2, n / 2);
//		recur (x + n, y, n); 
//	cout << "3번째 recur후 cnt값: " << cnt << '\n';
	//	recur (x + n, y + n, n);
//	cout << "4번째 recur후 cnt값: " << cnt << '\n';
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
	cout << b_cnt;
}
