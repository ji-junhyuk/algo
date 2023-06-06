#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

int N;
int O[4];
int arr[11];
vector<int> Oper;
int min_value = 0x7fffffff;
int max_value = 0x80000000;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i) 
	{
		cin >> arr[i];
	}
	for (int i = 0; i < 4; ++i) 
	{
		int num;
		cin >> num;
		for (int j = 0; j < num; ++j) 
		{
			Oper.push_back({i + 1});
		}
	}

	do {
		int sum = 0;
		int num_idx = 0;
		for (int i = 0; i < Oper.size(); ++i) 
		{
			if (i == 0)
			{
				if (Oper[i] == 1)
				{
					sum = arr[num_idx] + arr[num_idx + 1];
				}
				else if (Oper[i] == 2)
				{
					sum = arr[num_idx] - arr[num_idx + 1];
				}
				else if (Oper[i] == 3)
				{
					sum = arr[num_idx] * arr[num_idx + 1];
				}
				else
				{
					sum = arr[num_idx] / arr[num_idx + 1];
				}
				num_idx += 2;
			}
			else
			{
				if (Oper[i] == 1)
				{
					sum += arr[num_idx];
				}
				else if (Oper[i] == 2)
				{
					sum -= arr[num_idx];
				}
				else if (Oper[i] == 3)
				{
					sum *= arr[num_idx];
				}
				else
				{
					sum /= arr[num_idx];
				}
				++num_idx;
			}
		}
		min_value = min(min_value, sum);
		max_value = max(max_value, sum);
	} while (next_permutation(Oper.begin(), Oper.end()));
	cout << max_value << '\n';
	cout << min_value << '\n';
// 1 2 3
//

}
