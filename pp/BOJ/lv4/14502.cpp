#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
 
using namespace std;
 
int N, M;
int empty_size, safe_max;
int board[8][8];
int copy_board[8][8];
bool check[8 * 8];
bool visited[8][8];
vector<pair<int, int>> q_empty, q_virus; 
 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
 
 
void make_board(void)
{
    for (int idx = 0; idx < N; idx++)
        for (int jdx = 0; jdx < M; jdx++)
            copy_board[idx][jdx] = board[idx][jdx];
}
 
void bfs(int a, int b)
{
    queue<pair<int, int>> q;
    q.push({a, b});
    visited[a][b] = true;
    
    while (q.empty() == 0)
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
 
        for (int idx = 0; idx < 4; idx++)
        {
            int nx = x + dx[idx];
            int ny = y + dy[idx];
 
            if (nx >= 0 && ny >= 0 && nx < N && ny < M)
            {
                if (visited[nx][ny] == false && copy_board[nx][ny] == 0)
                {
                    copy_board[nx][ny] = 2;
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
}
 
int count_safe_zone()
{
    int cnt = 0;
    for (int idx = 0; idx < N; ++idx)
        for (int jdx = 0; jdx < M; ++jdx)
            if (copy_board[idx][jdx] == 0) 
				cnt++;
    return cnt;
}
 
void spread_virus()
{
    int cnt = 0;
    make_board();
    memset(visited, false, sizeof(visited));
 
    for (int idx = 0; idx < empty_size; idx++)
    {
        if (cnt == 3) break;
        if (check[idx] == true)
        {
            int x = q_empty[idx].first;
            int y = q_empty[idx].second;
            copy_board[x][y] = 1;
            cnt++;
        }
    }
 
    for (int idx = 0; idx < q_virus.size(); idx++)
    {
        int x = q_virus[idx].first;
        int y = q_virus[idx].second;
        bfs(x, y);
    }
    int temp = count_safe_zone();
    safe_max = max(safe_max, temp);
}
 
void make_wall(int index, int cnt)
{
    if (cnt == 3)
	{
        spread_virus();
        return;
    }
    for (int idx = index; idx < empty_size; idx++)
    {
        if (check[idx] == true)
			continue;
        check[idx] = true;
        make_wall(idx, cnt + 1);
        check[idx] = false;        
    }
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	cin >> N >> M;
	for (int idx = 0; idx < N; ++idx)
	{
		for (int jdx = 0; jdx < M; ++jdx)
		{
			cin >> board[idx][jdx];
			if (board[idx][jdx] == 0)
				q_empty.push_back({idx, jdx});
			else if (board[idx][jdx] == 2)
				q_virus.push_back({idx, jdx});
		}
	}
	empty_size = q_empty.size();
	make_wall(0, 0);	
	cout << safe_max;
    return 0;
}
