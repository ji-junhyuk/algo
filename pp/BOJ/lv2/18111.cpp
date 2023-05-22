#include <bits/stdc++.h>
using namespace std;

int board[501][501];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M, B;
	int ans_time;
	int ans_height;

	ans_time = INT_MAX;
	ans_height = 0;
	cin >> N >> M >> B;
	for (int idx = 0; idx < N; idx++)
		for (int jdx = 0; jdx < M; jdx++)
			cin >> board[idx][jdx];
	for (int height = 0; height < 257; height++)
	{
		int add = 0;
		int remove = 0;
		for (int idx = 0; idx < N; idx++)
		{
			for (int jdx = 0; jdx < M; jdx++)
			{
				int differ_between = board[idx][jdx] - height;
				if (differ_between >= 0)
					remove += differ_between;
				else
					add -= differ_between;
			}
		}
		if (remove + B >= add) // 제거한 것들과 기존에 있는 블록 갯수를 합친게 추가해야 하는 것보다 같거나 크다면 만들 수 있으니까.
		{
			int take_time = 2 * remove + add;
			if (ans_time >= take_time)
			{
				ans_time = take_time;
				ans_height = height;
			}
		}
	}
	cout << ans_time << " " << ans_height;
}
