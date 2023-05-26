#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

int N, S;
int arr[20];
int cnt;

void	bt(int depth, int sum)
{
	if (depth == N)
	{
		if (sum == S)
			++cnt;
		return ;
	}
	bt(depth + 1, sum);
	bt(depth + 1, sum + arr[depth]);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> S;
	for (int i = 0; i < N; ++i) 
	{
		cin >> arr[i];
	}
	bt(0, 0); // depth, sum
	if (!S)
		--cnt;
	cout << cnt << '\n';
}
