#include <iostream>
#include <climits>

using namespace std;
int i_n;
int i_arr[100001];
int i_near_zero_x;
int i_near_zero_y;
int i_ans = INT_MAX;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> i_n;
	for (int idx = 0; idx < i_n; ++idx)
		cin >> i_arr[idx];
	int i_start = 0;
	int i_end = i_n - 1;
	while (i_start < i_end)
	{
		int i_sum = i_arr[i_start] + i_arr[i_end];
		int i_sum_abs = abs(i_sum);
		if (i_ans > i_sum_abs)
		{
			i_ans = i_sum_abs;
			i_near_zero_x = i_arr[i_start];
			i_near_zero_y = i_arr[i_end];
		}
		if (i_sum < 0)
			i_start++;
		else
			i_end--;
	}
	cout << i_near_zero_x << ' ' << i_near_zero_y;
}
