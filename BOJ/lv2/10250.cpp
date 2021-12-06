#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	int H, W, N;
	cin >> T;
	while (T--)
	{
		cin >> H >> W >> N;
		/*
		   층수결정: 손님(N)을 층수(H)로 나누었을 때 몫
		   1) 손님이 층수랑 같을 때 -> 층수는 손님
		   2) 손님이 층수보다 작을 때 -> 
		   3) 손님이 층수보다 클 때 -> 층수는 몫
		   호수결정: 손님(N)을 층수(H)로 나누었을 때 몫
		*/
		if (N < H)
			cout << 1;
		else if (N == H)
			cout << N;
		else
		{
			if (N % H == 0)
				cout << H;
			else
				cout << N % H;
		}
		// 호수 결정
		if (N / H < 10)
			cout << 0;
		if (N % H == 0)
			cout << N / H << '\n';
		else
			cout << N / H + 1 << '\n';
	}
}
