#include <bits/stdc++.h>
using namespace std;

int graph[101][101];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;

	cin >> N;
	for (int idx = 0; idx < N; idx++)
		for (int jdx = 0; jdx <N; jdx++)
			cin >> graph[idx][jdx];
	for (int kdx = 0; kdx < N; kdx++) // 거쳐가는 노드
		for (int idx = 0; idx < N; idx++) // 출발 노드
			for (int jdx = 0; jdx < N; jdx++) // 도착 노드
				if (graph[idx][kdx] && graph[kdx][jdx])
					graph[idx][jdx] = 1;
	for (int idx = 0; idx < N; idx++)
	{
		for (int jdx = 0; jdx < N; jdx++)
		{
			cout << graph[idx][jdx] << " ";
		}
		cout << '\n';
	}
}
