#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

int N, K;
int visited[100001];
int path[100001][500];

void bfs()
{
    queue<tuple<int, int, int>> Q;  // before, Subin, Time
    visited[N] = 1;
    Q.push({N, N, 0});

    while (!Q.empty())
    {
		int before, subin, time;
		tie(before, subin, time) = Q.front();
		Q.pop();
//		cout << before << ' ' << subin << ' ' << time << '\n';
		path[subin][time] = before;
        if (subin == K)
        {
			stack<int> S;
			S.push(subin);
			cout << time << '\n';
			while (time >= 1)
			{
				S.push(path[subin][time]);
				subin = path[subin][time];
				--time;
			}
			while (!S.empty())
			{
				cout << S.top() << ' ';
				S.pop();
			}
            break;
        }
        if (subin * 2 <= 100000 && !visited[subin * 2])
        {
            visited[subin * 2] = 1;
            Q.push({subin, subin * 2, time + 1});
        }
        if (subin + 1 <= 100000 && !visited[subin + 1])
        {
            visited[subin + 1] = 1;
            Q.push({subin, subin + 1, time + 1});
        }
        if (subin - 1 >= 0 && !visited[subin - 1])
        {
            visited[subin - 1] = 1;
            Q.push({subin, subin - 1, time + 1});
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
	bfs();

    return 0;
}

