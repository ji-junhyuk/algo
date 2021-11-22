#include <bits/stdc++.h>
using namespace std;

/*
   함수의 정의: void recur(int x, int y, len)
   종료조건: if (n == 2)
   arr[x][y] == cnt++;
   *2 가 될수록 cnt 증가 방향이 90도씩 회전하는데 이걸 어떻게 표현하지?  
   // 2^k에서 k가 홀수인경우, 2^k에서 k가 짝수인 경우로 나눠서 접근
   재귀함수: 
   else
   {
   len = (len >> 1);
   recur(x, y, len);
   recur(x, y + n, len);
   recur(x + len, y, len);
   recur(x + len, y + len, len);

   }
*/
int cnt = 1;
int arr[32768][32768];

void recur(int x, int y, int len)
{
	if (len == 2)
	{
		for (int i = 0; i < len; i++)
			for (int j = 0; j < len; j++)
			   arr[i][j] = cnt++;	
		return ;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int len;
	int walk;
	int x, y;
	int br;

	br = 0;
	cin >> len >> walk;
	recur(1, 1, len);
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (cnt == walk)
			{
				x = i;
				y = j;
				br = 1;
				break;
			}
		}
		if (br)
			break;
	}
	cout << x << ' ' << y;
}
