#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

int N, K;
int arrived[2][500001];
int temp[1010];
int moving[1010];

void	run_subin()
{
	memset(arrived, -1, sizeof(arrived));
	queue<pair<int, int>> Q; // subin, time
	Q.push({N, 0});
	while (!Q.empty())
	{
		int subin, time;
		tie(subin, time) = Q.front();
		Q.pop();
		if (subin <= 0 || subin > 500000)
			continue ;
		if (arrived[time % 2][subin] != -1)
			continue ;
		arrived[time % 2][subin] = time;
		Q.push({subin * 2, time + 1});
		Q.push({subin + 1, time + 1});
		Q.push({subin - 1, time + 1});
	}
//	for (int i = 0; i < 10; ++i) 
//	{
//		cout << arrived[0][i] << '\n';
//	}
//	cout << '\n';
//	for (int i = 0; i < 10; ++i) 
//	{
//		cout << arrived[1][i] << '\n';
//	}
}

void	run_bro()
{
	int time = 0;
	while (1)
	{
		int cur = K + moving[time];
		if (cur > 500000)
		{
			cout << -1 << '\n';
			return ;
		}
		if (arrived[time % 2][cur] != -1 && arrived[time % 2][cur] <= time)
			break ;
		++time;
	}
	cout << time << '\n';
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	temp[0] = 0;
	temp[1] = 0;
	temp[2] = 1;
	for (int i = 1; i < 1010; ++i) 
	{
		temp[i] = temp[i - 1] + i - 1;
		moving[i - 1] = temp[i];
	}
	run_subin();
	run_bro();
}
