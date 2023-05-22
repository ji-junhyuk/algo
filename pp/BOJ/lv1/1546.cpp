#include <bits/stdc++.h>
using namespace std;

double arr[1000];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	int idx;
	int max;
	double sum;

	idx = -1;
	cin >> N;
	while (++idx < N)
		cin >> arr[idx];
	max = 0;
	idx = -1;
	while (++idx < N)
		if (arr[idx] > max)
			max = arr[idx];
	idx = -1;
	while (++idx < N)
		arr[idx] = arr[idx] * 100 / max;
	idx = -1;
	sum = 0;
	while (++idx < N)
		sum += arr[idx];
	cout << sum / N;
}
