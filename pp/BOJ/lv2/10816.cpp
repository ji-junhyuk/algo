#include <bits/stdc++.h>
using namespace std;

int card_sang[500001];
int card_key[500001];
int card_number[500001];
int lower_bound(int arr[], int size, int key) //찾고자 하는 값(이상)
{
	int left;
	int right;
	int center;

	left = 0;
	right = size - 1;
	while (left < right)
	{
		center = (left + right) / 2;
		if (arr[center] >= key)
			right = center;
		else
			left = center + 1;
	}
	return right;
}

int upper_bound(int arr[], int size, int key) // 찾고자 하는 값(초과)
{
	int left;
	int right;
	int center;

	left = 0;
	right = size - 1;
	while (left < right)
	{
		center = (left + right) / 2;
		if (arr[center] > key)
			right = center;
		else
			left = center + 1;
	}
	return right;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	
	cin >> N;
	for (int idx = 0; idx < N; idx++)
		cin >> card_sang[idx];
	sort(card_sang, card_sang + N);
	cin >> M;
	for (int idx = 0; idx < M; idx++)
		cin >> card_key[idx];
	for (int idx = 0; idx < M; idx++)
	{
		int lower = lower_bound(card_sang, N, card_key[idx]);
		int upper = upper_bound(card_sang, N, card_key[idx]);
		if (upper == N - 1 && card_sang[N - 1] == card_key[idx])
			upper++;
		card_number[idx] = upper - lower;
	}
	for (int idx = 0; idx < M; idx++)
		cout << card_number[idx] << ' ';
	return 0;
}
