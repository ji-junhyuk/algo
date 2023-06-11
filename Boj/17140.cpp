#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <map>
#include <list>
using namespace std;

int arr[101][101];
int row = 3;
int col = 3;
int r, c, k;

//num[101]으로 체크하는 것보다 map 자료를 쓰자.
bool cmp(pair<int, int>& L, pair<int, int>& R)
{
	if (L.second != R.second)
		return (L.second < R.second);
	return (L.first < R.first);
}

void c_cal()
{
	map<int, int> m;
	for (int i = 1; i <= col; ++i) 
	{
		vector<pair<int, int>> line;
		for (int j = 1; j <= row; ++j) 
		{
			if (arr[j][i])
			{
				m[arr[j][i]]++;
				arr[j][i] = 0;
			}
		}
		for (auto c : m)
			line.push_back(c);
		sort(line.begin(), line.end(), cmp);
		int cnt = 1;
		for (auto c : line)
		{
			arr[cnt][i] = c.first;
			arr[cnt + 1][i] = c.second;
			cnt += 2;
		}
		row = max(row, cnt);
		line.clear();
		m.clear();
	}
}

void r_cal()
{
	map<int, int> m;
	for (int i = 1; i <= row; ++i) 
	{
		vector<pair<int, int>> line;
		for (int j = 1; j <= col; ++j) 
		{
			if (arr[i][j])
			{
				m[arr[i][j]]++;
				arr[i][j] = 0;
			}
		}
		for (auto c : m)
			line.push_back(c);
		sort(line.begin(), line.end(), cmp);
		int cnt = 1;
		for (auto c : line)
		{
			arr[i][cnt] = c.first;
			arr[i][cnt + 1] = c.second;
			cnt += 2;
		}
		col = max(col, cnt);
		line.clear();
		m.clear();
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> r >> c >> k;
	for (int i = 1; i <= 3; ++i) 
	{
		for (int j = 1; j <= 3; ++j) 
		{
			cin >> arr[i][j];
		}
	}
	if (arr[r][c] == k)
	{
		cout << 0 << '\n';
		return 0;
	}
	for (int i = 1; i <= 100; ++i) 
	{
		if (row >= col)
			r_cal();
		else
			c_cal();
		if (arr[r][c] == k)
		{
			cout << i << '\n';
			return 0;
		}
	}
	cout << -1 << '\n';
	return (0);
}
