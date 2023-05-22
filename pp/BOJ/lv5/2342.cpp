#include <cstring>
#include <iostream>
#include <vector>
# define MAX 100000
using namespace std;

vector<int> vec_i_num;
int i_dp[5][5][MAX + 1];

int move(int from, int to)
{
	if (from == 0)
		return 2;
	if (from == to)
		return 1;
	if (abs(from - to) == 2)
		return 4;
	return 3;
}

int dfs(int _left, int _right, int _index)
{
	if (_index == vec_i_num.size())
		return 0;
	if (i_dp[_left][_right][_index] != -1)
		return i_dp[_left][_right][_index];
	int left = dfs(vec_i_num[_index], _right, _index + 1) + move(_left, vec_i_num[_index]);
	int right = dfs(_left, vec_i_num[_index], _index + 1) + move(_right, vec_i_num[_index]);
	return (i_dp[_left][_right][_index] = min(left, right));
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (true)
	{
		int num;
		cin >> num;
		if (num == 0)
			break ;
		vec_i_num.push_back(num);
	}
	memset(i_dp, -1, sizeof(i_dp));
	cout << dfs(0, 0, 0);
}
