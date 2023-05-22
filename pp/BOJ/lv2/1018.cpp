#include <bits/stdc++.h>
using namespace std;

// int min = n * m;
char chess[51][51];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> chess[i][j];
	}
	int min = N * M;
	int cnt = 0;
	//WB
	for (int x = 0; x + 7 < N; x++)
	{
		for (int y = 0; y + 7 < M; y++)
		{
			cnt = 0;
			for (int i = x; i < x + 8; i++)
			{
				for (int j = y; j < y + 8; j++)
				{
					if ((i + j) % 2 == 0)
					{
						if (chess[i][j] != 'B')
							cnt++;
					}
					else
						if (chess[i][j] != 'W')
							cnt++;
					if (cnt > min) break;
				}
			}
			if (cnt < min) min = cnt;
		}
	}
	//BW
	for (int x = 0; x + 7 < N; x++)
	{
		for (int y = 0; y + 7 < M; y++)
		{
			cnt = 0;
			for (int i = x; i < x + 8; i++)
			{
				for (int j = y; j < y + 8; j++)
				{
					if ((i + j) % 2 == 0)
					{
						if (chess[i][j] != 'W')
							cnt++;
					}
					else
						if (chess[i][j] != 'B')
							cnt++;
					if (cnt > min) break;
				}
			}
			if (cnt < min) min = cnt;
		}
	}
	cout << min;
}
