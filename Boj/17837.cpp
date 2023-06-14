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

int N, K;
int chess[13][13];

deque<pair<int, int>> knight[13][13]; // identity, dir
vector<pair<int, int>> pos; // location 
// {1, 1} {1, 1} {1, 1} {위치4}
int dy[] = {0, 0, -1, 1};
int dx[] = {1, -1, 0, 0};

// [1][1] = {0, 1, 2};
//
// 이동할 수 없으면 방향 바꾸는 것만 1턴으로 잡는다.
// 이 문제 짜증나는 부분은 예제에서 4번이 왜 안사라지고 방향만 바뀌는지

void show()
{
	cout << "show, size\n";
	for (int i = 1; i <= N; ++i) 
	{
		for (int j = 1; j <= N; ++j) 
		{
//			cout << "i, j: " << i << ' ' << j << '\n';
			cout << knight[i][j].size() << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
	for (int i = 1; i <= N; ++i) 
	{
		for (int j = 1; j <= N; ++j) 
		{
			for (int k = 0; k < knight[i][j].size(); ++k) 
			{
				cout << knight[i][j][k].first << ' ' << knight[i][j][k].second << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}
	cout << '\n';
}

bool move_knight(int turn) // turn = identity
{
	int y, x;
	tie(y, x) = pos[turn]; 
	int dir = knight[y][x][turn].second;

	// 내 위에 몇개의 말이 있는지 계산해야함.
	int size = knight[y][x].size();

	int index;
	for (int i = 0; i < size; ++i) 
	{
		cout << knight[y][x][i].first << ' ';
		if (turn == knight[y][x][i].first)
		{
			index = i;
			break ;
		}
	}
	cout << '\n';
	cout << "y, x: " << y << ' ' << x << '\n';
	cout << "index: " << index << '\n';
	// y, x현재 좌표랑 방향 담겨있음.
	int ny = y + dy[dir];
	int nx = x + dx[dir];
	if (chess[ny][nx] == 0)
	{
		for (int i = index; i < size; ++i) 
		{
			int identity, dir;
			tie(identity, dir) = knight[y][x][i];
			knight[y][x].erase(knight[y][x].begin() + index);
			if (dir == 0)
			{
				if (nx == N)
					dir = 1;
			}
			else if (dir == 1)
			{
				if (nx == 1)
					dir = 0;
			}
			else if (dir == 2)
			{
				if (ny == 1)
					dir = 3;
			}
			else if (dir == 3)
			{
				if (ny == N)
					dir = 2;
			}
			knight[ny][nx].push_back({identity, dir});
			pos[identity] = {ny, nx};
		}
		show();
		if (knight[ny][nx].size() >= 4)
			return true;
	}
	else if (chess[ny][nx] == 1) {
		for (int i = size - 1; i >= index; ++i) 
		{
			int identity, dir;
			tie(identity, dir) = knight[y][x][i];
			knight[y][x].erase(knight[y][x].end() - 1);
			if (dir == 0)
			{
				if (nx == N)
					dir = 1;
			}
			else if (dir == 1)
			{
				if (nx == 1)
					dir = 0;
			}
			else if (dir == 2)
			{
				if (ny == 1)
					dir = 3;
			}
			else if (dir == 3)
			{
				if (ny == N)
					dir = 2;
			}
			knight[ny][nx].push_back({identity, dir});
			pos[identity] = {ny, nx};
		}
		show();
		if (knight[ny][nx].size() >= 4)
			return true;
	}
	else
	{
		int identity, dir;
		tie(identity, dir) = knight[y][x][index];
		if (dir == 0 || dir == 1)
			dir = 1 - dir;
		else if (dir == 2 || dir == 3)
			dir = 5 - dir;
		ny = y + dy[dir];
		nx = x + dx[dir];
		if (!(ny < 1 || ny > N || nx < 1 || nx > N))
		{
			if (chess[ny][nx] != 2)
			{
				knight[y][x].erase(knight[y][x].begin() + index);
				knight[ny][nx].push_back({identity, dir});
				pos[identity] = {ny, nx};
			}
		}
		show();
		if (knight[ny][nx].size() >= 4)
			return true;
	}
	return false;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	for (int i = 1; i <= N; ++i) 
	{
		for (int j = 1; j <= N; ++j) 
		{
			cin >> chess[i][j];
		}
	}
	for (int i = 1; i <= K; ++i) 
	{
		int y, x, dir;
		cin >> y >> x >> dir;
		knight[y][x].push_back({i, dir - 1});
		pos.push_back({y, x});
	}
	int turn = 0;
	bool game_end = false;
	// 4개 K
	// 0 1 2 3
	show();
	move_knight(0);
//	for (int time = 0; time < 1000; ++time) 
//	{
//		if (turn == K)
//			turn = 0;
//		game_end = move_knight(turn);
//		// 만약에 turn의 사이즈가 4보다 작다면 game_end = true;
//		if (game_end)
//		{
//			cout << turn + 1 << '\n';
//			return 0;
//		}
//		++turn;
//		// 한 칸에 4명이 있다면
//		// break ;
//	}
	cout << -1 << '\n';
}
