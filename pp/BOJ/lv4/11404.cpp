#include <bits/stdc++.h>
using namespace std;

#define INF 987654321
int	vertex, edge;
int arr[101][101];
int from, to, weight;

void floyd()
{
	for (int idx = 1; idx <= vertex; idx++)
	{
		for (int jdx = 1; jdx <= vertex; jdx++)
		{
			for (int kdx = 1; kdx <= vertex; kdx++)
			{
				arr[jdx][kdx] = min(arr[jdx][kdx], arr[jdx][idx] + arr[idx][kdx]);
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> vertex >> edge;
	for (int idx = 0; idx <= vertex; idx++)
	{
		for (int jdx = 0; jdx <= vertex; jdx++)
		{
			if (idx == jdx)
				arr[idx][jdx] = 0;
			else
				arr[idx][jdx] = INF;
		}
	}
	for (int idx = 0; idx < edge; idx++)
	{
		cin >> from >> to >> weight;
		arr[from][to] = min(arr[from][to], weight);
	}
	floyd();
	for (int idx = 1; idx <= vertex; idx++)
	{
		for (int jdx = 1; jdx <= vertex; jdx++)
		{
			if (idx == jdx || arr[idx][jdx] == INF)
				cout << 0 << " ";
			else
				cout << arr[idx][jdx] << " ";
		}
		cout << '\n';
	}
}
