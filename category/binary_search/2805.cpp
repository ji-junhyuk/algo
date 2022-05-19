#include <iostream>
#define MAX_HEIGHT 1000000000
#define TREE_COUNT 1000000
using namespace std;

int N, M;
int	low, high, center, ans;
int tree[TREE_COUNT];

int is_possible(int height, int N, int M)
{
	int sum = 0;

	for (int idx = 0; idx < N; idx++)
	{
		if (tree[idx] >= height)
			sum += (tree[idx] - height);
		if (sum >= M)
			return (1);
	}
	return (0);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int idx = 0; idx < N; idx++)
		cin >> tree[idx];
	low = 0;
	high = MAX_HEIGHT;
	while (low <= high)
	{
		center = (low + high) / 2;
		if (is_possible(center, N, M))
		{
				ans = center;
				low = center + 1;
		}
		else
				high = center - 1;
	}
	cout << ans;
}
