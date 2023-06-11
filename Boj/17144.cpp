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

int R, C, T;

int room[1002][1002];
int ans;

int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};
pair<int, int> cleaner_head;
pair<int, int> cleaner_tail;
void clean_air()
{
	int air[200] = {};
	int dir = 0;
	int start_y = cleaner_head.first;
	int start_x = cleaner_head.second;

	int idx = 0;
	while (1)
	{
		start_y += dy[dir];
		start_x += dx[dir];
		if (room[start_y][start_x] == -1)
			break ;
		air[idx++] = room[start_y][start_x];
		if ((start_x == C && start_y == cleaner_head.first) 
			|| (start_x == C && start_y == 1)
				|| (start_x == 1 && start_y == 1))
		{
//			cout << start_y << ' ' << start_x << '\n';
			dir = (dir + 1) % 4;
		}
	}
//	cout << '\n';
//	for (int i = 0; i < idx; ++i) 
//	{
//		cout << air[i] << ' ';
//	}
//	cout << '\n';
	dir = 0;
	start_y = cleaner_head.first;
	start_x = cleaner_head.second + 1;
	room[start_y][start_x] = 0;
	idx = 0;
	while (1)
	{
		start_y += dy[dir];
		start_x += dx[dir];
		if (room[start_y][start_x] == -1)
			break ;
//		cout << "idx: " << idx << '\n';
		room[start_y][start_x] = air[idx++];
		if ((start_x == C && start_y == cleaner_head.first) 
			|| (start_x == C && start_y == 1)
				|| (start_x == 1 && start_y == 1))
		{
//			cout << start_y << ' ' << start_x << '\n';
			dir = (dir + 1) % 4;
		}
	}
	dir = 0;
	start_y = cleaner_tail.first;
	start_x = cleaner_tail.second;
	idx = 0;
	while (1)
	{
		start_y += dy[dir];
		start_x += dx[dir];
		if (room[start_y][start_x] == -1)
			break ;
//		cout << "start_y: " << start_y << " start_x: " << start_x << '\n';
		air[idx++] = room[start_y][start_x];
		if ((start_x == C && start_y == cleaner_tail.first) 
			|| (start_x == C && start_y == R)
				|| (start_x == 1 && start_y == R))
		{
//			cout << start_y << ' ' << start_x << '\n';
			dir = (dir + 3) % 4;
		}
	}
	dir = 0;
	start_y = cleaner_tail.first;
	start_x = cleaner_tail.second + 1;
	room[start_y][start_x] = 0;
	idx = 0;
	while (1)
	{
		start_y += dy[dir];
		start_x += dx[dir];
		if (room[start_y][start_x] == -1)
			break ;
//		cout << "idx: " << idx << '\n';
		room[start_y][start_x] = air[idx++];
		if ((start_x == C && start_y == cleaner_tail.first) 
			|| (start_x == C && start_y == R)
				|| (start_x == 1 && start_y == R))
		{
//			cout << start_y << ' ' << start_x << '\n';
			dir = (dir + 3) % 4;
		}
	}
//	cout << '\n';
//	for (int i = 1; i <= R; ++i) 
//	{
//		for (int j = 1; j <= C; ++j) 
//		{
//			cout << room[i][j] << ' ';
//		}
//		cout << '\n';
//	}
//	cout << '\n';

}
void spread_dust()
{
	int temp[52][52] = {};
	temp[cleaner_head.first][cleaner_head.second] = -1;
	temp[cleaner_tail.first][cleaner_tail.second] = -1;

	for (int i = 1; i <= R; ++i) 
	{
		for (int j = 1; j <= C; ++j) 
		{	
			if (room[i][j] && room[i][j] != -1)
			{
				int spread_cnt = 0;
				int spread_amount = 0;
				for (int dir = 0; dir < 4; ++dir) 
				{	
					int y = i + dy[dir];
					int x = j + dx[dir];
					if (y < 1 || y > R || x < 1 || x > C)
						continue ;
					if (room[y][x] == -1)
						continue ;
					++spread_cnt;
				}
				spread_amount = room[i][j] / 5; // 0이 들어올 상황은 없다.
				for (int dir = 0; dir < 4; ++dir) 
				{
					int y = i + dy[dir];
					int x = j + dx[dir];
					if (y < 1 || y > R || x < 1 || x > C)
						continue ;
					if (room[y][x] == -1)
						continue ;
					temp[y][x] += spread_amount;
				}
				temp[i][j] += (room[i][j] - (spread_amount * spread_cnt));
			}
		}
	}
	for (int i = 1; i <= R; ++i) 
	{
		for (int j = 1; j <= C; ++j) 
		{
			room[i][j] = temp[i][j];
		}
	}
//	cout << '\n';
//	for (int i = 1; i <= R; ++i) 
//	{
//		for (int j = 1; j <= C; ++j) 
//		{
//			cout << room[i][j] << ' ';
//		}
//		cout << '\n';
//	}
//	cout << '\n';
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C >> T;
	bool head = true;
	for (int i = 1; i <= R; ++i) 
	{
		for (int j = 1; j <= C; ++j) 
		{
			cin >> room[i][j];
			if (room[i][j] == -1)
			{
				if (head)
					cleaner_head = {i, j};
				if (!head)
					cleaner_tail = {i, j};
				head = false;
			}
		}
	}
	for (int i = 0; i < T; ++i) 
	{
		spread_dust(); // 흩뿌리고 
		clean_air(); // room을 이동시켜서 정화.
					 // cleaner_head
					 // cleaner_tail
					 // 1. 큰 1차원 배열을 만들어서
					 // 우 하 좌 상을 회전하면서 배열에 담아
					 // 배열을 한칸씩 밀어.
					 // 우 하 좌상에 하나씩 넣어줘. 
					 // 우에선 C랑 같으면 방향 90도 회전
					 // 아래서 R랑 같으면 방향 90도 회전
					 // 좌에선 1이랑 같으면 방향 90도 회전
		
	}
	for (int i = 1; i <= R; ++i) 
	{
		for (int j = 1; j <= C; ++j) 
		{
			if (room[i][j] != -1)
			{
				ans += room[i][j];
			}
		}
	}
	cout << ans << '\n';
}
