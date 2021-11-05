#include <bits/stdc++.h>
using namespace std;

int arr[21];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int i;
	int j;
	int k;
	int x;
	int y;
	int temp;

	i = 0;
	while (++i < 21)
		arr[i] = i;
	i = 0;
	while (i < 10)
	{
		cin >> x >> y;;
		while (x < y)
		{
			temp = arr[x];
			arr[x] = arr[y];
			arr[y] = temp;
			x++;
			y--;
		}
		i++;
	}
	i = 0;
	while (++i < 21)
		cout << arr[i] << ' ';
}
