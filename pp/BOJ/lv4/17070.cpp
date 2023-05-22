#include<iostream>
#include<queue>
 
using namespace std;
 
int N;
int cnt;
int board[16][16];
queue<pair<pair<int, int>, int>> q;
 
int dx[] = {0, 1, 1};
int dy[] = {1, 0, 1};
 
void bfs()
{
    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dir = q.front().second;
        q.pop();
        if (x == N - 1 && y == N - 1)
        {
            cnt++;
            continue;
        }
        if (dir == 0)
        {    
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx >= 0 && ny >= 0 && nx < N && ny < N)
            {
                if (board[nx][ny] == 0)
                    q.push({{nx, ny}, dir});
            }
            nx = x + dx[2];
            ny = y + dy[2];
            if (nx >= 0 && ny >= 0 && nx < N && ny < N)
            {
                if (board[nx][ny] == 0 && board[x + 1][y] == 0 && board[x][y + 1] == 0)
                    q.push({{nx, ny}, 2});
            }
        }
        else if (dir == 1)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx >= 0 && ny >= 0 && nx < N && ny < N)
            {
                if (board[nx][ny] == 0)
                    q.push({{nx, ny}, dir});
            }
            nx = x + dx[2];
            ny = y + dy[2];
            if (nx >= 0 && ny >= 0 && nx < N && ny < N)
            {
                if (board[nx][ny] == 0 && board[x + 1][y] == 0 && board[x][y + 1] == 0)
                    q.push({{nx, ny}, 2});
            }
        }
        else if (dir == 2)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx >= 0 && ny >= 0 && nx < N && ny < N)
            {
                if (board[nx][ny] == 0 && board[x + 1][y] == 0 && board[x][y + 1] == 0)
                    q.push({{nx, ny}, dir});
            }
            for (int idx = 0; idx < 2; idx++)
            {
                nx = x + dx[idx];
                ny = y + dy[idx];
                if (nx >= 0 && ny >= 0 && nx < N  && ny < N)
                {
                    if (board[nx][ny] == 0)
                        q.push({{nx, ny}, idx});
                }
            }
        }
    }
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int idx = 0; idx < N; idx++)
        for (int jdx = 0; jdx < N; jdx++)
            cin >> board[idx][jdx];
    q.push({{0, 1}, 0});
    bfs();
    cout << cnt;
    return 0;
}
