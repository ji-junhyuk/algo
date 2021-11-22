#include <bits/stdc++.h>
using namespace std;

/*
   함수 정의: void recur(int x, int y, h) // 높이와 x,y좌표 전달
   종료조건: if (h == 3) 출력
   재귀식: 
   x + 1
*/
char arr[3073][6144];

void draw(int x, int y)
{
	arr[x][y] = '*';
	arr[x + 1][y - 1] = '*';
	arr[x + 1][y + 1] = '*';
	for (int i = 0; i < 5; i++)
		arr[x + 2][y - 2 + i] = '*';
}

void recur(int x, int y, int h)
{
	if (h == 3)
	{
		draw(x, y);
		return ;
	}
	h = (h >> 1);
	recur(x, y, h);
	recur(x + h, y - h, h);
	recur(x + h, y + h, h);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;

	cin >> N;
			
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 2 * N - 1; j++)
			arr[i][j] = ' ';
	recur(0, N - 1, N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 2 * N - 1; j++)
			cout << arr[i][j];
		cout << '\n';
	}
	return (0);
}
