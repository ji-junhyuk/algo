#include <bits/stdc++.h>
using namespace std;

int N;
int board[21][21];
int check[21][21];
int shark_x, shark_y; 
int eat_cnt, shark_size = 2;
int min_dist, min_x, min_y, result;

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

struct info{
    int x, y;
};

void init_check()
{
    min_dist = 400;
    min_x = 21;
    min_y = 21;
    
    for (int idx = 0; idx < N; idx++)
        for (int jdx = 0; jdx < N; jdx++)
            check[idx][jdx] = -1;
}

void bfs(int x, int y) 
{
    queue<info> q;
    check[x][y] = 0;
    q.push({x, y});
    
    while (!q.empty())
	{
        info cur = q.front();
        q.pop();
        int x = cur.x;
        int y = cur.y;
        
        for (int idx = 0; idx < 4; idx++)
		{
            int nx = x + dx[idx];
            int ny = y + dy[idx];
            
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) 
				continue;
            if (check[nx][ny] != -1 || board[nx][ny] > shark_size) 
				continue;
            check[nx][ny] = check[x][y] + 1;
            if (board[nx][ny] != 0 && board[nx][ny] < shark_size)
			{
                if (min_dist > check[nx][ny])
				{
                    min_x = nx;
                    min_y = ny;
                    min_dist = check[nx][ny];
                }
                else if (min_dist == check[nx][ny])
				{
                    if (min_x == nx)
					{
                        if (min_y > ny)
						{
                            min_x = nx;
                            min_y = ny;
                        }
                    } 
					else if (min_x > nx)
					{
                        min_x = nx;
                        min_y = ny;
                    }
                }
            }
            q.push({nx, ny});
        }
    }
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
    for (int idx = 0; idx < N; idx++)
	{
        for (int jdx = 0; jdx < N; jdx++)
		{
			cin >> board[idx][jdx];
            if (board[idx][jdx] == 9)
			{
                shark_x = idx;
                shark_y = jdx;
                board[idx][jdx] = 0;
            }
        }
    }
    while (1)
	{
        init_check();
        bfs(shark_x, shark_y);
        if (min_x != 21 && min_y != 21)
		{
            result += check[min_x][min_y];
            eat_cnt++;
            if (eat_cnt == shark_size)
			{
                shark_size++;
                eat_cnt = 0;
            }
            board[min_x][min_y] = 0;
            shark_x = min_x;
            shark_y = min_y;
        }
        else
            break;
    }
	cout << result;
}
