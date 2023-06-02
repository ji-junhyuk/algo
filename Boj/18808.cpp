#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

pair<int, int> info[100]; // cnt
int sticker[10][10][100]; // h w cnt
/*
// 1. 스티커를 하나씩 붙인다.
//  - 붙일 수 있는 스티커인지 확인한다 bfs;
//  - 매 스티커마다 좌표 0, 0부터 확인한다.
//  - 붙일 수 없다면, 회전시킨다.
//  - 4번 회전시켜서 못붙이면 건너뛴다.
*/
int N, M, K;
int note[40][40];

void rotate_sticker(int rotate, int index)
{
	int temp[10][10] = {};
	int y, x;
	tie(y, x) = info[index];
	for (int i = 0; i < y; ++i) 
	{
		for (int j = 0; j < x; ++j) 
		{
			temp[i][j] = sticker[i][j][index];
		}
	}
	if (rotate > 0)
	{
		for (int i = 0; i < y; ++i) 
		{
			for (int j = 0; j < x; ++j) 
			{
				sticker[j][y - 1 - i][index] = temp[i][j];
			}
		}
		swap(info[index].first, info[index].second);
	}
}

bool is_sticker_connected(int index)
{
	int y, x;
	tie(y, x) = info[index];
	queue<pair<int, int>> Q;
	bool is_visited[10][10] = {};
	bool is_first = 1;
	int dy[] = {-1, 1, 0, 0};
	int dx[] = {0, 0, -1, 1};
	for (int i = 0; i < y; ++i) 
	{
		if (!is_first)
			break ;
		for (int j = 0; j < x; ++j) 
		{
			if (sticker[i][j][index] == 1 && is_first)
			{
				is_visited[i][j] = true;
				Q.push({i, j});
				is_first = 0;
				break ;
			}
		}
	}
	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; ++dir) 
		{
			int ny = cur.first + dy[dir];
			int nx = cur.second + dx[dir];
			if (ny < 0 || ny >= y || nx < 0 || nx >= x)
				continue ;
			if (is_visited[ny][nx] || !sticker[ny][nx][index])
				continue ;
			is_visited[ny][nx] = 1;
			Q.push({ny, nx});
		}
	}
	for (int i = 0; i < y; ++i) 
	{
		for (int j = 0; j < x; ++j) 
		{
			if (sticker[i][j][index] == 1 && !is_visited[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

/*
 * X X X
 * X X X Y Y
 * X X X Y Y
 */

bool is_no_sticker(int i, int j, int sy, int sx, int index)
{
//	cout << "sy: " << sy << ' ' << "sx: " << sx <<'\n';
	for (int n = i; n < i + sy; ++n) 
	{
		for (int m = j; m < j + sx; ++m) 
		{
			if (note[n][m] == 1 && sticker[n - i][m - j][index] == 1)
			{
//				cout << "n: " << n << "m: " << m << '\n';
				return false;
			}
		}
	}
	return true;
}
bool put_sticker_possible(int index)
{
	int sy, sx;
	tie(sy, sx) = info[index];
	for (int i = 0; i <= N - sy; ++i) 
	{
		for (int j = 0; j <= M - sx; ++j) 
		{
//			std::cout << "put_sticker: " << index << '\n';
//			std::cout << "i: " << i << " j: " << j << '\n';
			if (is_no_sticker(i, j, sy, sx, index))
			{
				for (int n = i; n < i + sy; ++n) 
				{
					for (int m = j; m < j + sx; ++m) 
					{
						if (sticker[n - i][m - j][index])
							note[n][m] = sticker[n - i][m - j][index];
					}
				}
				return true;
			}
		}
	}
	return false;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 0; i < K; ++i) 
	{
		int y, x;
		cin >> y >> x;
		info[i].first = y; info[i].second = x;
		for (int j = 0; j < info[i].first; ++j) 
		{
			for (int k = 0; k < info[i].second; ++k) 
			{
				cin >> sticker[j][k][i];
			}
		}
	}
	for (int i = 0; i < K; ++i) 
	{
		if (is_sticker_connected(i))
		{
//			cout << i << '\n';
//				cout << '\n';
//			for (int ndx = 0; ndx < N; ++ndx) 
//			{
//				for (int mdx = 0; mdx < M; ++mdx) 
//				{
//					cout << note[ndx][mdx] << ' ';
//				}
//				cout << '\n';
//			}
//				cout << '\n';
			for (int ro = 0; ro < 4; ++ro) 
			{
				rotate_sticker(ro, i);
//				cout << '\n';
//				for (int j = 0; j < info[i].first; ++j) 
//				{
//					for (int k = 0; k < info[i].second; ++k) 
//					{
//						cout << sticker[j][k][i] << ' ';
//					}
//					cout << '\n';
//				}
//				cout << '\n';
				if (put_sticker_possible(i))
				{
//					cout << '\n';
//					for (int idx = 0; idx < N; ++idx) 
//					{
//						for (int jdx = 0; jdx < M; ++jdx) 
//						{
//							cout << note[idx][jdx] << ' ';
//						}
//						cout << '\n';
//					}
//					cout << '\n';
					break ;
				}
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < M; ++j) 
		{
			if (note[i][j])
				++cnt;
		}
	}
	cout << cnt << '\n';
}
