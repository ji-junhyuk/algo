#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int student[2][7] = {};

	int N, K;

	cin >> N >> K;
	for (int i = 0; i < N; ++i) 
	{
		int x, y;
		cin >> x >> y;
		student[x][y]++;
	}
	int room = 0;
	for (int i = 1; i <= 6; ++i) 
	{
		for (int j = 0; j < 2; ++j) 
		{
			if (student[j][i] < 1)
				continue ;
			if (student[j][i] > K)
			{
				room += student[j][i] / K;
				if (student[j][i] % K != 0)
					room += 1;
			}
			else
			{
				++room;
			}
		}
	}
	cout << room;
}
