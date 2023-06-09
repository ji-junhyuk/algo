#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

// erase할 때 범위 지정 실수 조심!
int N, M, K;

deque<int> tree[12][12];
int land_nutrition[12][12];
int s2d2[12][12];

void spring_summer()
{
	for (int i = 1; i <= N; ++i) 
	{
		for (int j = 1; j <= N; ++j) 
		{
			for (int k = 0; k < tree[i][j].size(); ++k) 
			{
				// 1 1 2
				int age = tree[i][j][k];

				if (age > land_nutrition[i][j])
				{
					int dead_nutrition = 0;
					for (int l = k; l < tree[i][j].size(); ++l) 
					{
						dead_nutrition += (tree[i][j][l] / 2);
					}
					land_nutrition[i][j] += dead_nutrition;
					tree[i][j].erase(tree[i][j].begin() + k, tree[i][j].end());
					break; 

				}
				else
				{
					land_nutrition[i][j] -= age;
					tree[i][j][k]++;
				}
			}
		}
	}
}
int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
void fall()
{
	for (int i = 1; i <= N; ++i) 
	{
		for (int j = 1; j <= N; ++j) 
		{
			for (int k = 0; k < tree[i][j].size(); ++k) 
			{
				if (tree[i][j][k] && tree[i][j][k] % 5 == 0)
				{
//					cout << "tree[i][j]: " << i << ' ' << j << '\n';
					for (int dir = 0; dir < 8; ++dir) 
					{
						int ny = i + dy[dir];
						int nx = j + dx[dir];
						tree[ny][nx].push_front(1);
					}
				}
			}
		}
	}
}

void winter()
{
	for (int i = 1; i <= N; ++i) 
	{
		for (int j = 1; j <= N; ++j) 
		{
			land_nutrition[i][j] += s2d2[i][j];
		}
	}
}

void status()
{
	cout << "tree_status\n";
	for (int i = 1; i <= N; ++i) 
	{
		for (int j = 1; j <= N; ++j) 
		{
			for (int k = 0; k < tree[i][j].size(); ++k) 
			{
				cout << tree[i][j][k] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}
	cout << '\n';

	cout << "land_nutrition\n";
	for (int i = 1; i <= N; ++i) 
	{
		for (int j = 1; j <= N; ++j) 
		{
			cout << land_nutrition[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; ++i) 
	{
		for (int j = 1; j <= N; ++j) 
		{
			cin >> s2d2[i][j];
			land_nutrition[i][j] += 5;
		}
	}
	for (int i = 0; i < M; ++i) 
	{
		int y, x, age;
		cin >> y >> x >> age;
		tree[y][x].push_back(age);
	}
	for (int i = 0; i < K; ++i) 
	{
		spring_summer();
		fall();
		winter();
//		cout << "year: " << i + 1 << '\n';
//		status();
	}
	int cnt = 0;
	for (int i = 1; i <= N; ++i) 
	{
		for (int j = 1; j <= N; ++j) 
		{
			cnt += tree[i][j].size();
		}
	}
	cout << cnt << '\n';

}
