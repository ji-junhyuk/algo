/*
 * 테두리에서 검사하고 싶다면 (0, 0 ~ 4)
 * 							  (0 ~ 4, 0)
 * 							  (4, 0 ~ 4)
 * 							  (0 ~ 4, 4)
 *
 * - - -
 * - - -
 * - - -
 *
 *
 *  1. 문서가 있다. 
 *  	-> 추가
 *  2. 문이다
 *      -> 열쇠가 있다면, 지나갈 수 있음.
 *      -> 없다면 들어가고 싶은 문 목록에 추가.
 *  3. 열쇠다
 *  	-> 열쇠가 있다고 체크한다.
 *      -> 여태까지 방문한 문들의 위치를 큐에 푸시한다.(열어보기 위함)
 *  
 *  처음 구현에 실패한 이유: 문->문 인 경우에 지나가는 로직을 만들기가 까다로웠음.
 */

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

int T, R, C;
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	while (T--)
	{
		bool key[26] = {};
		char map[110][110] = {};
		bool is_visited[110][110] = {};
		int ans = 0;
		cin >> R >> C;
		for (int i = 1; i <= R; ++i) 
		{
			for (int j = 1; j <= C; ++j)
			{
				cin >> map[i][j];
			}
		}
		string strkey;
		cin >> strkey;
		for (auto c : strkey)
		{
			key[c - 'a'] = 1;
		}
		queue<pair<int, int>> Q;
		queue<pair<int, int>> door[26];
		Q.push({0, 0});
		is_visited[0][0] = 1;
		while (!Q.empty())
		{
			int y = Q.front().first;
			int x = Q.front().second;
			Q.pop();
			for (int dir = 0; dir < 4; ++dir) 
			{
				int ny = y + dy[dir];
				int nx = x + dx[dir];
				if (ny < 0 || ny > R + 1 || nx < 0 || nx > C + 1)
					continue ;
				if (is_visited[ny][nx] || map[ny][nx] == '*')
					continue ;
				is_visited[ny][nx] = 1;
				if (map[ny][nx] == '$')
				{
					++ans;
				}
				else if (map[ny][nx] >= 'A' && map[ny][nx] <= 'Z') //door
				{
					int k = map[ny][nx] - 'A';
					if (!key[k])
					{
						door[k].push({ny, nx});
						continue ;
					}
				}
				else if (map[ny][nx] >= 'a' && map[ny][nx] <= 'z')
				{
					int k = map[ny][nx] - 'a';
					key[k] = 1;
					while (!door[k].empty())
					{
						auto c = door[k].front();
						door[k].pop();
						Q.push({c.first, c.second});
					}
				}
				Q.push({ny, nx});
			}
		}
		cout << ans << '\n';
	}
}
