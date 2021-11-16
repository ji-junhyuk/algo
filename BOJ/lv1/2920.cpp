#include <bits/stdc++.h>
using namespace std;

int arr[8];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	int idx;
	int A;
	int ascending;
	int descending;

	N = 8;
	idx = -1;
	while (++idx < 8)
		cin >> arr[idx];
	idx = -1;
	while (++idx < 8)
		cout << arr[idx] << ' ';
	idx = -1;
	ascending = 1;
	descending = 1;
	while (++idx < 7) // 여기서 실수했음.
	{
		if (arr[idx] >= arr[idx + 1])
			ascending = 0;
		if (arr[idx] <= arr[idx + 1])
			descending = 0;
	}
	if (!ascending && !descending)
		cout << "mixed";
	else if (ascending)
		cout << "ascending";
	else
		cout << "descending";

}
