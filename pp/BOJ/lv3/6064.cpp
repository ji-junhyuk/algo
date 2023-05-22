#include <bits/stdc++.h>
using namespace std;

int find_gcd(int a, int b)
{
	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int find_lcm(int a, int b)
{
	return a * b / find_gcd(a, b);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	/*
	   M = 10, N = 12
	   (1, 1) (2, 2) (3, 3) (4, 4) (5, 5) (6, 6) (7, 7) (8, 8) (9, 9) (10, 10)
	   (1, 11) (2, 12) (3, 1) (4, 2) (5, 3) (6, 4) (7, 5) (8, 6) (9, 7) (10, 8)
	   (1, 9) (2, 10) (3, 11) (4, 12) (5, 1) (6, 2) (7, 3) (8, 4) (9, 5) (10, 6)
	   (1, 7) (2, 8) (3, 9) (4, 10) (5, 11) (6, 12) (7, 1) (8, 2) (9, 3) (10, 4)
	   (1, 5) (2, 6) (3, 7) (4, 8) (5, 9) (6, 10) (7, 11) (8, 12) (9, 1) (10, 2)
	   (1, 3) (2, 4) (3, 5) (4, 6) (5, 7) (6, 8) (7, 9) (8, 10) (9, 11) (10, 12)
	   - 종말의 해는 M,N의 최소공배수.
	   - 최소공배수가 될 때까지 X,Y로 표현되는 해가 없다면 -1출력
    */
	int T, M, N, x, y;
	int flag;

	cin >> T;
	while (T--)
	{
		cin >> M >> N >> x >> y;
		int last = find_lcm(M, N);
		for (int idx = x; idx <= last; idx += M)
		{
			flag = 0;
			int temp = (idx % N == 0) ? N : idx % N;
			/*
			   먼저 x를 고정시키고 그 순서를 찾음.
			   -> x == 1, 11, 21, 31, 41
			  	왜 N 으로 나머지 연산을 해주면 현재의 y값을 알 수 있을까?
				ex1) x == 1, 11번째 순서일 때 y값은? y: idx % N
				ex2) x == 1, 12번째 순서일 때 y값은? y: if (idx % N == 0) y = N;
			   	ex3) x == 2, 13번째 순서일 때 y값은? y: idx % N
			*/
			if (temp == y)
			{
				cout << idx << '\n';
				flag = 1;
				break;
			}
		}
		if (!flag)
			cout << "-1\n";
	}
}
