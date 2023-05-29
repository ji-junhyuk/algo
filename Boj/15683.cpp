#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

int N, M;

int office[8][8];
int temp[8][8];
vector<pair<int, int>> cctv;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
int ans;

bool OOB(int a, int b){ // Out Of Bounds 확인
  return a < 0 || a >= N || b < 0 || b >= M;
}

void fill_cctv_path(int dir, int idx)
{
	int y, x;
	tie(y, x) = cctv[idx];

	while(1){
    x += dx[dir];
    y += dy[dir];
    if(OOB(x,y) || temp[x][y] == 6) return; // 범위를 벗어났거나 벽을 만나면 함수를 탈출
    if(temp[x][y] != 0) continue; // 해당 칸이 빈칸이 아닐 경우(=cctv가 있을 경우) 넘어감
    temp[x][y] = 7; // 빈칸을 7로 덮음
  }
//	int ny = y;
//	int nx = x;
//	while (1)
//	{
//		if (temp[ny][nx] == 6)
//			break ;
//		if (ny < 0 || nx < 0 || ny >= N || nx >= M)
//			break ;
//		if (temp[ny][nx] == 0)
//			temp[ny][nx] = 8;
//		ny += dy[direct];
//		nx += dx[direct];
//	}

}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < M; ++j) 
		{
			cin >> office[i][j];
			if (office[i][j] >= 1 && office[i][j] <= 5)
				cctv.push_back({i, j});
			if (office[i][j] == 0)
				ans++;
		}
	}
//	cout << cctv.size() << '\n';

	int cctv_size = cctv.size();
	for (int i = 0; i < (1 << (2 * cctv_size)); ++i) 
	{
		for (int i = 0; i < N; ++i) 
		{
			for (int j = 0; j < M; ++j)  // -> 디버깅 30분.. N N.. T_T
			{
				temp[i][j] = office[i][j];
			}
		}
		int brute[8] = {};
		int idx = 0;
		int number = i;
		for (int j = 0; j < cctv_size; ++j) 
		{
			brute[idx++] = number % 4;
			number /= 4;
		}
		for (int j = 0; j < cctv_size; ++j) 
		{
			/*
			 * brute-> 0 1 2 3 들어가 있어.
			 */
			int num = office[cctv[j].first][cctv[j].second];
			if (num == 1)
			{
				fill_cctv_path(brute[j], j); // 3
			}
			else if (num == 2) // 0 1 2 3
							   // (0 1) (2 3)
			{
				if (brute[j] == 0)
				{
					fill_cctv_path(0, j);
					fill_cctv_path(1, j);
				}
				else if (brute[j] == 1)
				{
					fill_cctv_path(0, j);
					fill_cctv_path(1, j);
				}
				else if (brute[j] == 2)
				{
					fill_cctv_path(2, j);
					fill_cctv_path(3, j);
				}
				else
				{
					fill_cctv_path(2, j);
					fill_cctv_path(3, j);
				}
			}
			else if (num == 3) // 0 1 2 3
							   // {0, 3} {3, 1}, {1, 2}, {2, 0}
			{
				if (brute[j] == 0)
				{
					fill_cctv_path(0, j);
					fill_cctv_path(3, j);
				}
				else if (brute[j] == 1)
				{
					fill_cctv_path(3, j);
					fill_cctv_path(1, j);
				}
				else if (brute[j] == 2)
				{
					fill_cctv_path(1, j);
					fill_cctv_path(2, j);
				}
				else
				{
					fill_cctv_path(2, j);
					fill_cctv_path(0, j);
				}
			}

			else if (num == 4)
			{
				if (brute[j] == 0)
				{
					fill_cctv_path(0, j);
					fill_cctv_path(2, j);
					fill_cctv_path(3, j);
				}
				else if (brute[j] == 1)
				{
					fill_cctv_path(0, j);
					fill_cctv_path(1, j);
					fill_cctv_path(3, j);
				}
				else if (brute[j] == 2)
				{
					fill_cctv_path(1, j);
					fill_cctv_path(2, j);
					fill_cctv_path(3, j);
				}
				else
				{
					fill_cctv_path(0, j);
					fill_cctv_path(1, j);
					fill_cctv_path(2, j);
				}
			}
			else if (num == 5)
			{
				fill_cctv_path(0, j);
				fill_cctv_path(1, j);
				fill_cctv_path(2, j);
				fill_cctv_path(3, j);
			}
		}
		int cnt = 0;
		for (int i = 0; i < N; ++i) 
		{
			for (int j = 0; j < M; ++j) 
			{
				if (temp[i][j] == 0)
				{
					++cnt;
				}
			}
		}
			cout << '\n';
		for (int i = 0; i < N; ++i) 
		{
			for (int j = 0; j < M; ++j) 
			{
				cout << temp[i][j] << ' ';
			}
			cout << '\n';
		}
			cout << '\n';
		ans = min(ans, cnt);
	}
	cout << ans;
}
