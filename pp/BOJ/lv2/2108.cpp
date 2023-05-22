#include <bits/stdc++.h>
using namespace std;

int arr[500001];
int mode[8001];

void find_arithmetic_mean(int sum, int N)
{
	cout << round(sum / (double)N) << '\n';
}

void find_median(int arr[], int N)
{
	int med;

	med = 0;
	sort(arr, arr + N);
	if (N % 2)
	{
		med += arr[N / 2];
	}
	else
	{
		med += arr[N / 2];
		med += arr[N / 2 - 1];
		med /= 2;
	}
	cout << med << '\n';
}

void find_mode(int arr[], int N)
{
	int max;
	int flag;

	max = 0;
	for (int idx = 0; idx < 8001; idx++)
	{
		if (mode[idx] > max)
		{
			max = mode[idx];
			flag = idx;
		}
	}
	for (int idx = flag + 1; idx < 8001; idx++)
	{
		if (mode[idx] == max)
		{
			flag = idx;
			break;
		}
	}
	cout << flag - 4000 << '\n';
}

void find_range(int arr[], int N)
{
	cout << arr[N - 1] - arr[0];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	int sum;

	sum = 0;
	cin >> N;
	for (int idx = 0; idx < N; idx++)
	{
		cin >> arr[idx];
		sum += arr[idx];
		mode[arr[idx] + 4000]++;
	}
	sort(arr, arr + N);
	find_arithmetic_mean(sum, N);
	find_median(arr, N);
	find_mode(arr, N);
	find_range(arr, N);
}
