#include <bits/stdc++.h>
using namespace std;

int arr[2000001];
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int x;
	int i;
	int j;
	int count;
	int number;

	cin >> n;
	count = 0;
	i = -1;
	while (++i < n)
	{
		cin >> number;
		arr[number]++;
	}
	cin >> x;
	i = 0;
	while (++i < (n + 1) / 2)
		if (arr[i] == 1 && arr[x - i] == 1)
			count++;
	cout << count;
}
/*

#include <bits/stdc++.h>
using namespace std;

int arr[1000001];
int check[2000001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int i;
	int x;
	int count;

	cin >> n;
	i = -1;
	while (++i < n)
			cin >> arr[i];
	cin >> x;
	count = 0;
	i = -1;
	while (++i < n)
	{
		if (x - arr[i] >= 0 && check[x - arr[i]])
			count++;
		check[arr[i]] = 1;
	}
	cout << count;
}
*/
