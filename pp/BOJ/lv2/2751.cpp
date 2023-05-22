#include <bits/stdc++.h>
using namespace std;

int arr[1000000];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;

	cin >> N;
	for (int idx = 0; idx < N; idx++)
		cin >> arr[idx];
	sort(arr, arr + N);

	for (int idx = 0; idx < N; idx++)
		cout << arr[idx] << '\n';
}
