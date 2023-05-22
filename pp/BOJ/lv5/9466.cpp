/*
   3 1 3 7 3 4 6

   사이클이 형성된 경우 finished 배열이 false.
   1->3->3 // now3, next3 team_cnt = 1;
   4->7->6->4 // now6, next 4 team_cnt = 3;
   총 4명이 팀. 7 - 4 = 3;
*/
#include <iostream>
#include <cstring>
#define MAX 100000
using namespace std;

int T;
int n, team_cnt;
int student[MAX];
bool visited[MAX];
bool finished[MAX];

void dfs(int now)
{
    visited[now] = true;
    int next = student[now];
    if (!visited[next])
		dfs(next);
    else
	{
        if (!finished[next])
		{
            for (int idx = next; idx != now; idx = student[idx])
                team_cnt++;
            team_cnt += 1;
        }
    }
    finished[now] = true;
}

int main() 
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int idx = 0; idx < T; ++idx)
	{
        cin >> n;
        for (int idx = 1; idx <= n; ++idx)
            cin >> student[idx];
        memset(visited, false, sizeof(visited));
        memset(finished, false, sizeof(finished));
		team_cnt = 0;
        for (int i = 1; i <= n; ++i)
		{
            if (!visited[i])
				dfs(i);
        }
        cout << n - team_cnt << "\n";
    }
}
