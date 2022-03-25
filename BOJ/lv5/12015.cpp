#include <iostream>
#include <vector>
#include <climits>
# define MAX 1000001
using namespace std;

int	N;
int arr[MAX];
vector<int> LIS;

void 	binary_search(int find)
{
	int left = 0;
	int right = LIS.size() - 1;
	int mid;
	int index = INT_MAX;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (LIS[mid] >= find)
		{
			if (index > mid)
				index = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	LIS[index] = find;
}

void	find_LIS()
{
	LIS.push_back(arr[0]);
	for (int idx = 1; idx < N; ++idx)
	{
		if (LIS.back() < arr[idx])
		{
			LIS.push_back(arr[idx]);
		}
		else
		{
			binary_search(arr[idx]);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int idx = 0; idx < N; ++idx)
	{
		cin >> arr[idx];
	}
	find_LIS();
	cout << LIS.size();
}
