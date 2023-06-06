#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

int N;
int table[20][20];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < N; ++j) 
		{
			cin >> table[i][j];
		}
	}
	vector<int> selected(N, 1);
	fill(selected.begin(), selected.begin() + N / 2, 0);
	int ans = 0x7fffffff;
	do {
		int first = 1;
		int start_team = 0;
		int link_team = 0;
		for (int i = 0; i < N; ++i) 
		{
			for (int j = i + 1; j < N; ++j) 
			{
				if (selected[i] != selected[j])
					continue ;
				if (selected[i] == 0)
				{
					start_team += table[i][j];
					start_team += table[j][i];
				}
				else
				{
					link_team += table[i][j];
					link_team += table[j][i];
				}
			}
		}
//		cout << start_team << ' ' << link_team << '\n';
		ans = min(ans, abs(start_team - link_team));
	} while (next_permutation(selected.begin(), selected.end()));
	cout << ans << '\n';
}
