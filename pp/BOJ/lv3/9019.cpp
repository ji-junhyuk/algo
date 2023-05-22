#include <bits/stdc++.h>
using namespace std;

int visited[10001];

void bfs(int a, int b)
{
    int D, S, L, R, temp;
    queue<pair<int, string>> q;

    q.push({a, ""});
    visited[a] = 1;

    while (!q.empty())
    {
        int num = q.front().first;
        string op = q.front().second;
        q.pop();
        if (num == b)
        {
            cout << op << '\n';
            return;
        }
        D = (num * 2) % 10000;
        if (!visited[D])
        {
            visited[D] = 1;
            q.push({D, op + "D"});
        }
        S = (num - 1 < 0) ? 9999 : num - 1;
        if (!visited[S])
        {
            visited[S] = 1;
            q.push({S, op + "S"});
        }
        L = (num % 1000) * 10 + (num / 1000);
        if (!visited[L])
        {
            visited[L] = 1;
            q.push({L, op + "L"});
        }
        R = num / 10 + (num % 10) * 1000;
        if (!visited[R])
        {
            visited[R] = 1;
            q.push({R, op + "R"});
        }
    }
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    int T;
	int a, b;

    cin >> T;
    while (T--)
    {
        cin >> a >> b;
		fill(visited, visited + 10001, 0);
        bfs(a, b);
    }
}

