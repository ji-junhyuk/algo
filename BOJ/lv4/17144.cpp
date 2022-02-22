#include<iostream>
 
#define MAX 50
using namespace std;
 
int R, C, T;
int board[MAX][MAX];
int c_board[MAX][MAX];
 
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
pair<int, int> air_cleaner[2];
 
void copy_board(int A[][MAX], int B[][MAX])
{
    for (int idx = 0; idx < R; ++idx)
    {
        for (int jdx = 0; jdx < C; ++jdx)
        {
            A[idx][jdx] = B[idx][jdx];
        }
    }
}
 
void expand_dust()
{
    copy_board(c_board, board);
    for (int idx = 0; idx < R; ++idx)
    {
        for (int jdx = 0; jdx < C; ++jdx)
        {
            if (board[idx][jdx] != 0 && board[idx][jdx] != -1)
            {
                int Cnt = 0;
                int Value = board[idx][jdx] / 5;
                for (int kdx = 0; kdx < 4; ++kdx)
                {
                    int nx = idx + dx[kdx];
                    int ny = jdx + dy[kdx];
 
                    if (nx >= 0 && ny >= 0 && nx < R && ny < C)
                    {
                        if (board[nx][ny] != -1)
                        {
                            c_board[nx][ny] = c_board[nx][ny] + Value;
                            Cnt++;
                        }
                    }
                }
                c_board[idx][jdx] = c_board[idx][jdx] - (Cnt * Value);
            }
        }
    }
    copy_board(board, c_board);
}
 
void move_dust()
{
    for (int index = 0; index < 2; ++index)
    {
        if (index == 0)
        {
            for (int idx = air_cleaner[index].first - 1; idx > 0; --idx)
            {
                board[idx][0] = board[idx - 1][0];
            }
            for (int idx = 0; idx < C - 1; ++idx)
            {
                board[0][idx] = board[0][idx + 1];
            }
            for (int idx = 1; idx <= air_cleaner[index].first; ++idx)
            {
                board[idx - 1][C - 1] = board[idx][C - 1];
            }
            for (int idx = C - 1; idx > 1; --idx)
            {
                board[air_cleaner[index].first][idx] = board[air_cleaner[index].first][idx - 1];
            }
            board[air_cleaner[index].first][1] = 0;
        }
        else
        {
            for (int idx = air_cleaner[index].first + 1; idx < R - 1; ++idx)
            {
                board[idx][0] = board[idx + 1][0];
            }
            for (int idx = 0; idx < C - 1; ++idx)
            {
                board[R - 1][idx] = board[R - 1][idx + 1];
            }
            for (int idx = R - 1; idx >= air_cleaner[index].first; --idx)
            {
                board[idx][C - 1] = board[idx - 1][C - 1];
            }
            for (int idx = C - 1; idx > 1; --idx)
            {
                board[air_cleaner[index].first][idx] = board[air_cleaner[index].first][idx - 1];
            }
            board[air_cleaner[index].first][1] = 0;
        }
    }
}
 
void count_dust()
{
    int Sum = 0;
    for (int idx = 0; idx < R; ++idx)
    {
        for (int jdx = 0; jdx < C; ++jdx)
        {
            if (board[idx][jdx] == -1) 
				continue;
            Sum += board[idx][jdx];
        }
    }
	cout << Sum;
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> R >> C >> T;
    int index = 0;
    for (int idx = 0; idx < R; idx++)
    {
        for (int jdx = 0; jdx < C; jdx++)
        {
            cin >> board[idx][jdx];
            if (board[idx][jdx] == -1)
            {
                air_cleaner[index].first = idx;
                air_cleaner[index].second = jdx;
                index++;
            }
        }
    }
    for (int idx = 0; idx < T; idx++)
    {
        expand_dust();
        move_dust();
    }
	count_dust();
    return 0;
}
