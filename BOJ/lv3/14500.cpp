#include <iostream>
#include <algorithm>

using namespace std;

int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

int board[501][501], visited[501][501];
int ans;
int N, M;

void find_normal(int y, int x, int score, int depth)
{
    if (depth == 3)
    {
        ans = max(ans, score);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
	   	int nx = x + dx[i];
        int ny = y + dy[i];
        if (ny < 0 || nx < 0 || ny >= N || nx >= M)
            continue;
        if (visited[ny][nx])
            continue;
        visited[ny][nx] = true;
        find_normal(ny, nx, score + board[ny][nx], depth + 1);
        visited[ny][nx] = false;
    }
}

void find_special(int y, int x)
{
    // ㅜ
    if (y + 1 < N && x + 2 < M)
        ans = max(ans, board[y][x] + board[y][x + 1] + board[y][x + 2] + board[y + 1][x + 1]);
    // ㅏ
    if (y + 2 < N && x + 1 < M)
        ans = max(ans, board[y][x] + board[y + 1][x] + board[y + 1][x + 1] + board[y + 2][x]);
    // ㅗ
    if (y - 1 >= 0 && x + 2 < M)
        ans = max(ans, board[y][x] + board[y][x + 1] + board[y][x + 2] + board[y - 1][x + 1]);
    // ㅓ
    if (y + 2 < N && x - 1 >= 0)
        ans = max(ans, board[y][x] + board[y + 1][x] + board[y + 1][x - 1] + board[y + 2][x]);
}

void findMax(int y, int x)
{
    find_special(y, x);
    visited[y][x] = true;
    find_normal(y, x, board[y][x], 0);
    visited[y][x] = false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int idx = 0; idx < N; idx++)
        for (int jdx = 0; jdx < M; jdx++)
            cin >> board[idx][jdx];
    for (int idx = 0; idx < N; idx++)
        for (int jdx = 0; jdx < M; jdx++)
            findMax(idx, jdx);
    cout << ans << '\n';
}
