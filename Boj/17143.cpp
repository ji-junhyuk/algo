#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
#include <map>
using namespace std;


int R, C, M;

vector<tuple<int, int, int>> shark[102][102]; // 위치, 속력, 이동방햐, 크기

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, 1, -1};
int ans = 0; // catch
void move_shark()
{
	vector<tuple<int, int, int>> temp[102][102]; // 위치, 속력, 이동방햐, 크기
	for (int i = 1; i <= R; ++i) 
	{
		for (int j = 1; j <= C; ++j) 
		{
			if (!shark[i][j].empty())
			{
				temp[i][j] = shark[i][j];
				shark[i][j].pop_back();
			}
		}
	}
	for (int i = 1; i <= R; ++i) 
	{
		for (int j = 1; j <= C; ++j) 
		{
			if (!temp[i][j].empty())
			{
				int speed, dir, size;
				int y, x;
				tie(speed, dir, size) = temp[i][j].front(); temp[i][j].pop_back();
				y = i, x = j;
				if (dir <= 1)
					speed = speed % (2 * (R - 1));
				else
					speed = speed % (2 * (C - 1));
				for (int k = 0; k < speed; ++k)  // 속력만큼 이동을 한다.
				{
					if (dir == 0)
					{
						// 위쪽으로 갈때
						if (y == 1)// 제일 위에 있으면 방향 아래로 바꿔줌
						{
							dir = 1;
							y += dy[dir];
							x += dx[dir];
							continue ;
						}
						y += dy[dir];
						x += dx[dir];
					}
					else if (dir == 1)
					{
						if (y == R)
						{
							dir = 0;
							y += dy[dir];
							x += dx[dir];
							continue ;
						}
						y += dy[dir];
						x += dx[dir];
					}
					else if (dir == 2)
					{
						if (x == C)
						{
							dir = 3;
							y += dy[dir];
							x += dx[dir];
							continue ;
						}
						y += dy[dir];
						x += dx[dir];
					}
					else
					{
						if (x == 1)
						{
							dir = 2;
							y += dy[dir];
							x += dx[dir];
							continue ;
						}
						y += dy[dir];
						x += dx[dir];
					}
				}
				// 이동을 마치고 끝난 자리
				if (shark[y][x].empty())
					shark[y][x].push_back({speed, dir, size});
				else //비어있지 않다면
				{
					if (get<2>(shark[y][x][0]) < size)
					{
						shark[y][x].pop_back();
						shark[y][x].push_back({speed, dir, size});
					}

				}
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C >> M;
	for (int i = 0; i < M; ++i) 
	{
		int r, c, s, d, z; // 속력 / 이동방향/ 크기
		cin >> r >> c >> s >> d >> z;
		shark[r][c].push_back({s, d - 1, z});
	}
	for (int king = 1; king <= C; ++king) 
	{
		//catch
		for (int i = 1; i <= R; ++i) 
		{
			if (!shark[i][king].empty())
			{
				ans += get<2>(shark[i][king].back());
				shark[i][king].pop_back();
				break ;
			}
		}
		move_shark();
	}
	cout << ans << '\n';
}
