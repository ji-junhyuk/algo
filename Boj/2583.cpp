#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

int paper[100][100];
int visited[100][100];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int h, w, k;
	cin >> h >> w >> k;
	for (int i = 0; i < k; ++i) 
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (a > c)
			swap(a, c);
		if (b > d)
			swap(b, d);
		for (int j = b; j < d; ++j) 
		{
			for (int k = a; k < c; ++k) 
			{
				paper[j][k] = 1;
			}
		}
	}
//	for (int i = 0; i < h; ++i) 
//	{
//		for (int j = 0; j < w; ++j) 
//		{
//			cout << paper[i][j] << ' ';
//		}
//		cout << '\n';
//	}
	vector<int> V;
	queue<pair<int, int>> Q;
	int cnt = 0;
	for (int i = 0; i < h; ++i) 
	{
		for (int j = 0; j < w; ++j) 
		{
			if (paper[i][j] == 0 && !visited[i][j])
			{
				++cnt;
				Q.push({i, j});
				int q_cnt = 0;
				while (!Q.empty())
				{
					auto cur = Q.front();
					Q.pop();
					for (int dir = 0; dir < 4; ++dir) 
					{
						int ny = cur.first + dy[dir];
						int nx = cur.second + dx[dir];
						if (ny < 0 || ny >= h || nx < 0 || nx >= w)
							continue ;
						if (visited[ny][nx] || paper[ny][nx] == 1)
							continue ;
						visited[ny][nx] = 1;
						Q.push({ny, nx});
						++q_cnt;
					}
				}
				if (q_cnt == 0)
					V.push_back(1);
				else
					V.push_back(q_cnt);
			}
		}
	}
	cout << cnt << '\n';
	sort(V.begin(), V.end());
	for (int i = 0; i < V.size(); ++i) 
	{
		cout << V[i] << ' ';
	}
}
