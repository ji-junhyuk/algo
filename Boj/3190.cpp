#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

// s_head.push{1, 1};
//
// move;
//
// s_head.pop();
// s_head = y + d , x + d;
// 1. 머리가 움직인 부분이 내 몸에 닿았는지 확인
// 3. 벽에 닿았는지 확인
// 2. 머리가 움직인 부분에 사과가 있다면,
// 사과가 있다면 몸통 움직이고 s_body(y, x);
//

// 기존 방향 ->

//	L => d = (d + 3) % 4; 정리해두고 싶네.
//	R => d = (d + 1) % 4;
//
//	XXXXXXXXXXXXX
//	X           X
//	X           X
//	XXXXXXXXXXXXX
//	- X 또는 자기 몸에 닿으면 죽음.
//	- Vector자료구조보다 stack이나 q가 나을듯?
//	
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

int N, K, L;
int map[101][101];
queue<pair<int, char>> d_info;
queue<pair<int, int>> s_head;
queue<pair<int, int>> s_body;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < K; ++i) 
	{
		int y, x;
		cin >> y >> x;
		map[y][x] = 1;
	}
	cin >> L;
	for (int i = 0; i < L; ++i) 
	{
		int time;
		char c;
		cin >> time >> c;
		d_info.push({time, c});
	}
	s_head.push({1, 1});
	int d = 0;
	int cur_time = 0;
	while (1)
	{
		int time, c;
		tie(time, c) = d_info.front();
		if (cur_time == time)
		{
			d_info.pop();
			if (c == 'D')
			{
				d = (d + 1) % 4;
			}
			else 
			{
				d = (d + 3) % 4;
			}
		}
		auto cur = s_head.front();
		s_head.pop();
		int head_y = cur.first + dy[d];
		int head_x = cur.second + dx[d];
//		std::cout << "head_y: " << head_y << " head_x: " << head_x << '\n';
		if (head_y <= 0 || head_y > N || head_x <= 0 || head_x > N)
		{
			cout << cur_time + 1;
			return (0);
		}
		int body_size = s_body.size();
		if (body_size)
			s_body.push({cur.first, cur.second});
		for (int i = 0; i < body_size; ++i) 
		{
			int y, x;
			tie(y, x) = s_body.front();
			s_body.pop();
			if (head_y == y && head_x == x)
			{
				cout << cur_time + 1;
				return (0);
			}
			if (i != body_size - 1)
				s_body.push({y, x});
		}
		if (map[head_y][head_x] == 1)
		{
			s_body.push({head_y, head_x});
			map[head_y][head_x] = 0;
		}
		s_head.push({head_y, head_x});
		++cur_time;
	}
}
