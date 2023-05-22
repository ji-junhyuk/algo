#include <iostream>
#include <algorithm>
#define MAX 21
#define MAX2 5

int N;
int board[MAX][MAX];
int c_board[MAX][MAX];
bool visited[MAX][MAX];
int selected[MAX2];
int ans;
using namespace std;


void copy_board()
{
    for (int idx = 0; idx < N; ++idx)
    {
	   for (int jdx = 0; jdx < N; ++jdx)
	   {
		  c_board[idx][jdx] = board[idx][jdx];
	   }
    }
}

void move_left()
{
    for (int idx = 0; idx < N; ++idx)
    {
        for (int jdx = 0; jdx < N - 1; ++jdx)
        {
            bool check = false;
            if (c_board[idx][jdx] == 0)
            {
                int kdx = jdx + 1;
                while (kdx <= N - 1)
                {
                    if (c_board[idx][kdx] != 0)
                    {
                        check = true;
                        break;
                    }
                    ++kdx;
                }
                if (check == true)
                {
                    c_board[idx][jdx] = c_board[idx][kdx];
                    c_board[idx][kdx] = 0;
                }
            }
        }
    }
 
    for (int idx = 0; idx < N; ++idx)
    {
        for (int jdx = 0; jdx < N - 1; ++jdx)
        {
            if (c_board[idx][jdx] == c_board[idx][jdx + 1])
            {
                c_board[idx][jdx] = c_board[idx][jdx] * 2;
                c_board[idx][jdx + 1] = 0;
            }
        }
    }
 
    for (int idx = 0; idx < N; ++idx)
    {
        for (int jdx = 0; jdx < N - 1; ++jdx)
        {
            bool check = false;
            if (c_board[idx][jdx] == 0)
            {
                int kdx = jdx + 1;
                while (kdx <= N - 1)
                {
                    if (c_board[idx][kdx] != 0)
                    {
                        check = true;
                        break;
                    }
                    ++kdx;
                }
                if (check == true)
                {
                    c_board[idx][jdx] = c_board[idx][kdx];
                    c_board[idx][kdx] = 0;
                }
            }
        }
    }
}
 
void move_right()
{
    for (int idx = 0; idx < N; ++idx)
    {
        for (int jdx = N - 1; jdx > 0; --jdx)
        {
            bool check = false;
            if (c_board[idx][jdx] == 0)
            {
                int kdx = jdx - 1;
                while (kdx >= 0)
                {
                    if (c_board[idx][kdx] != 0)
                    {
                        check = true;
                        break;
                    }
                    --kdx;
                }
                if (check == true)
                {
                    c_board[idx][jdx] = c_board[idx][kdx];
                    c_board[idx][kdx] = 0;
                }
            }
        }
    }
 
    for (int idx = 0; idx < N; ++idx)
    {
        for (int jdx = N - 1; jdx > 0; --jdx)
        {
            if (c_board[idx][jdx] == c_board[idx][jdx - 1])
            {
                c_board[idx][jdx] = c_board[idx][jdx] * 2;
                c_board[idx][jdx - 1] = 0;
            }
        }
    }
 
    for (int idx = 0; idx < N; ++idx)
    {
        for (int jdx = N - 1; jdx > 0; --jdx)
        {
            bool check = false;
            if (c_board[idx][jdx] == 0)
            {
                int kdx = jdx - 1;
                while (kdx >= 0)
                {
                    if (c_board[idx][kdx] != 0)
                    {
                        check = true;
                        break;
                    }
                    --kdx;
                }
                if (check == true)
                {
                    c_board[idx][jdx] = c_board[idx][kdx];
                    c_board[idx][kdx] = 0;
                }
            }
        }
    }
}
 
void move_up()
{
    for (int idx = 0; idx < N - 1; ++idx)
    {
        for (int jdx = 0; jdx < N; ++jdx)
        {
            bool check = false;
            if (c_board[idx][jdx] == 0)
            {
                int kdx = idx + 1;
                while (kdx <= N - 1)
                {
                    if (c_board[kdx][jdx] != 0)
                    {
                        check = true;
                        break;
                    }
                    ++kdx;
                }
                if (check == true)
                {
                    c_board[idx][jdx] = c_board[kdx][jdx];
                    c_board[kdx][jdx] = 0;
                }
            }
        }
    }
    for (int idx = 0; idx < N - 1; ++idx)
    {
        for (int jdx = 0; jdx < N; ++jdx)
        {
            if (c_board[idx][jdx] == c_board[idx + 1][jdx])
            {
                c_board[idx][jdx] = c_board[idx][jdx] * 2;
                c_board[idx + 1][jdx] = 0;
            }
        }
    }
    for (int idx = 0; idx < N - 1; ++idx)
    {
        for (int jdx = 0; jdx < N; ++jdx)
        {
            bool check = false;
            if (c_board[idx][jdx] == 0)
            {
                int kdx = idx + 1;
                while (kdx <= N - 1)
                {
                    if (c_board[kdx][jdx] != 0)
                    {
                        check = true;
                        break;
                    }
                    ++kdx;
                }
                if (check == true)
                {
                    c_board[idx][jdx] = c_board[kdx][jdx];
                    c_board[kdx][jdx] = 0;
                }
            }
        }
    }
}
 
void move_down()
{
    for (int idx = N - 1; idx > 0; --idx)
    {
        for (int jdx = 0; jdx < N; ++jdx)
        {
            bool check = false;
            if (c_board[idx][jdx] == 0)
            {
                int kdx = idx - 1;
                while (kdx >= 0)
                {
                    if (c_board[kdx][jdx] != 0)
                    {
                        check = true;
                        break;
                    }
                    --kdx;
                }
                if (check == true)
                {
                    c_board[idx][jdx] = c_board[kdx][jdx];
                    c_board[kdx][jdx] = 0;
                }
            }
        }
    }
 
    for (int idx = N - 1; idx > 0; --idx)
    {
        for (int jdx = 0; jdx < N; ++jdx)
        {
            if (c_board[idx - 1][jdx] == c_board[idx][jdx])
            {
                c_board[idx][jdx] = c_board[idx][jdx] * 2;
                c_board[idx - 1][jdx] = 0;
            }
        }
    }
    for (int idx = N - 1; idx > 0; --idx)
    {
        for (int jdx = 0; jdx < N; ++jdx)
        {
            bool check = false;
            if (c_board[idx][jdx] == 0)
            {
                int kdx = idx - 1;
                while (kdx >= 0)
                {
                    if (c_board[kdx][jdx] != 0)
                    {
                        check = true;
                        break;
                    }
                    --kdx;
                }
                if (check == true)
                {
                    c_board[idx][jdx] = c_board[kdx][jdx];
                    c_board[kdx][jdx] = 0;
                }
            }
        }
    }
 
}

int find_max()
{
    int biggest = 0;
    for (int idx = 0; idx < N; ++idx)
    {
	   for (int jdx = 0; jdx < N; ++jdx)
	   {
		  if (c_board[idx][jdx] > biggest)
			 biggest = c_board[idx][jdx];
	   }
    }
    return biggest;
}

void move()
{
    for (int idx = 0; idx < 5; ++idx)
    {
	   int dir = selected[idx];
	   if (dir == 0) 
		  move_right();
	   else if (dir == 1)
		  move_left();
	   else if (dir == 2)
		  move_down();
	   else if (dir == 3)
		  move_up();
    }
    ans = max(ans, find_max());
}

void dfs(int cnt)
{
    if (cnt == 5)
    {
	   copy_board();
	   move();
	   return ;
    }
    for (int idx = 0; idx < 4; ++idx)
    {
	   selected[cnt] = idx;
	   dfs(cnt + 1);
    }
}
		  
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int idx = 0; idx < N; ++idx)
    {
	   for (int jdx = 0; jdx < N; ++jdx)
	   {
		  cin >> board[idx][jdx];
	   }
    }
    dfs(0);
	cout << ans;
}
