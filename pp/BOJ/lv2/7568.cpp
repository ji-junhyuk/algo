#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	int order;
	pair<int, int> arr[50];
	
	order = 1;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i].first >> arr[i].second;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i].first < arr[j].first && arr[i].second < arr[j].second)
				order++;
		}
		cout << order << ' ';
		order = 1;
	}
}
