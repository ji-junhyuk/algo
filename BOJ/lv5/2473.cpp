#include <iostream>
#include <climits>
#include <algorithm>
# define MAX 5000

using namespace std;
int i_n;
long long ll_arr[MAX];
long long ll_ans[3];
long long ll_result = LONG_MAX;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> i_n;
	for (int idx = 0; idx < i_n; ++idx)
		cin >> ll_arr[idx];
	sort(ll_arr, ll_arr + i_n);
	for (int idx = 0; idx < i_n - 2; ++idx)
	{
		int i_start = idx + 1;
		int i_end = i_n - 1;
		while (i_start < i_end)
		{
			long long ll_sum = ll_arr[idx] + ll_arr[i_start] + ll_arr[i_end];
			long long ll_sum_abs = abs(ll_sum);
			if (ll_result > ll_sum_abs)
			{
				ll_result = ll_sum_abs;
				ll_ans[0] = ll_arr[idx];
				ll_ans[1] = ll_arr[i_start];
				ll_ans[2] = ll_arr[i_end];
			}
			if (ll_sum < 0)
				i_start++;
			else
				i_end--;
		}
	}
	for (int idx = 0; idx < 3; ++idx)
		cout << ll_ans[idx] << ' ';
}
