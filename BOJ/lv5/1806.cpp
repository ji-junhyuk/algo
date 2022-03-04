#include <iostream>
#include <climits>

#define MAX 100000
using namespace std;
int i_n;
int i_target;
int i_arr[MAX];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> i_n;
	cin >> i_target;
	for (int idx = 0; idx < i_n; ++idx)
		cin >> i_arr[idx];
	int i_start = 0;
	int i_end = 0;
	int i_sum = 0;
	int i_length = INT_MAX;
	while (i_start <= i_end)
	{
		if (i_sum >= i_target)
		{
			i_length = min(i_length, i_end - i_start);
			i_sum -= i_arr[i_start];
			i_start++;
		}
		else if (i_end == i_n)
			break;
		else
		{
			i_sum += i_arr[i_end];
			i_end++;
		}
	}
	if (i_length == INT_MAX)
		cout << '0';
	else	
		cout << i_length;
}
