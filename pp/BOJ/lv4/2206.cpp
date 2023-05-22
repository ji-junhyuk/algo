#include <bits/stdc++.h> 
using namespace std;
 
int N, M;
int board[1001][1001];
int visited[1001][1001][2];
int ans;
 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
 
 
int bfs()
{
    queue<pair<pair<int, int>, pair<int,int>>> Q;
    Q.push(make_pair(make_pair(0, 0), make_pair(0, 1)));
    visited[0][0][0] = 1;
 
    while (Q.empty() == 0)
    {
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int z = Q.front().second.first;
        int cnt = Q.front().second.second;
        Q.pop();
 
        if (x == N - 1 && y == M - 1)
        {
            return cnt;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
 
            if (nx >= 0 && ny >= 0 && nx < N && ny < M)
            {
                if (board[nx][ny] == 1 && z == 0)
                {
                    visited[nx][ny][z+1] = 1;
                    Q.push(make_pair(make_pair(nx, ny), make_pair(z + 1, cnt + 1)));
                }
                else if (board[nx][ny] == 0 && visited[nx][ny][z] == 0)
                {
                    visited[nx][ny][z] = 1;
                    Q.push(make_pair(make_pair(nx, ny), make_pair(z, cnt + 1)));
                }
            }
        }
    }
    return -1;
}
 
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++)
        {
            int num = s[j] - '0';
            board[i][j] = num;
        }
    }
	ans = bfs();
	cout << ans;
 
    return 0;
}
