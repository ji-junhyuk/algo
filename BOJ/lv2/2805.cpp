#include <bits/stdc++.h>
using namespace std;

int trees[1000001];

int is_possible(unsigned int height, int N, int M)
{
	unsigned int result = 0;
	for (int idx = 0; idx < N; idx++)
	{
		if (trees[idx] >= height)
			result += (trees[idx] - height);
		if (result >= M)
			return result;
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;

	cin >> N >> M;
	for (int idx = 0; idx < N; idx++)
		cin >> trees[idx];
	
	unsigned int left;
	unsigned int right;
	unsigned int center;
	unsigned int result;

	left = 0;
	right = 1000000000;
	while (left <= right)
	{
		center = (left + right) / 2;
		if (is_possible(center, N, M))
		{
			result = center;
			left = center + 1;
		}
		else
			right = center - 1;
	}
	cout << result;
}
